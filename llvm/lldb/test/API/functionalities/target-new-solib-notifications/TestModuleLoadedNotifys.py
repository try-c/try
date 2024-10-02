"""
Test how many times newly loaded binaries are notified;
they should be delivered in batches instead of one-by-one.
"""

import lldb
from lldbsuite.test.decorators import *
from lldbsuite.test.lldbtest import *
from lldbsuite.test import lldbutil


@skipUnlessPlatform(["linux"] + lldbplatformutil.getDarwinOSTriples())
class ModuleLoadedNotifysTestCase(TestBase):
    NO_DEBUG_INFO_TESTCASE = True

    # At least DynamicLoaderDarwin and DynamicLoaderPOSIXDYLD should batch up
    # notifications about newly added/removed libraries.  Other DynamicLoaders may
    # not be written this way.
    def setUp(self):
        # Call super's setUp().
        TestBase.setUp(self)
        # Find the line number to break inside main().
        self.line = line_number("main.cpp", "// breakpoint")

    def setup_test(self, solibs):
        if lldb.remote_platform:
            path = lldb.remote_platform.GetWorkingDirectory()
            for f in solibs:
                lldbutil.install_to_target(self, self.getBuildArtifact(f))
        else:
            path = self.getBuildDir()
            if self.dylibPath in os.environ:
                sep = self.platformContext.shlib_path_separator
                path = os.environ[self.dylibPath] + sep + path
        self.runCmd(
            "settings append target.env-vars '{}={}'".format(self.dylibPath, path)
        )
        self.default_path = path

    def test_launch_notifications(self):
        """Test that lldb broadcasts newly loaded libraries in batches."""

        expected_solibs = [
            "lib_a." + self.platformContext.shlib_extension,
            "lib_b." + self.platformContext.shlib_extension,
            "lib_c." + self.platformContext.shlib_extension,
            "lib_d." + self.platformContext.shlib_extension,
        ]

        self.build()
        self.setup_test(expected_solibs)

        exe = self.getBuildArtifact("a.out")
        self.dbg.SetAsync(False)

        listener = self.dbg.GetListener()
        listener.StartListeningForEventClass(
            self.dbg,
            lldb.SBTarget.GetBroadcasterClassName(),
            lldb.SBTarget.eBroadcastBitModulesLoaded
            | lldb.SBTarget.eBroadcastBitModulesUnloaded,
        )

        # Create a target by the debugger.
        target = self.dbg.CreateTarget(exe)
        self.assertTrue(target, VALID_TARGET)

        # break on main
        breakpoint = target.BreakpointCreateByName("main", "a.out")

        event = lldb.SBEvent()
        # CreateTarget() generated modules-loaded events; consume them & toss
        while listener.GetNextEvent(event):
            True

        error = lldb.SBError()
        flags = target.GetLaunchInfo().GetLaunchFlags()
        process = target.Launch(
            listener,
            None,  # argv
            None,  # envp
            None,  # stdin_path
            None,  # stdout_path
            None,  # stderr_path
            None,  # working directory
            flags,  # launch flags
            False,  # Stop at entry
            error,
        )  # error

        self.assertEqual(process.GetState(), lldb.eStateStopped, PROCESS_STOPPED)

        total_solibs_added = 0
        total_solibs_removed = 0
        total_modules_added_events = 0
        total_modules_removed_events = 0
        already_loaded_modules = []
        max_solibs_per_event = 0
        max_solib_chunk_per_event = []
        while listener.GetNextEvent(event):
            if lldb.SBTarget.EventIsTargetEvent(event):
                if event.GetType() == lldb.SBTarget.eBroadcastBitModulesLoaded:
                    solib_count = lldb.SBTarget.GetNumModulesFromEvent(event)
                    total_modules_added_events += 1
                    total_solibs_added += solib_count
                    added_files = []
                    for i in range(solib_count):
                        module = lldb.SBTarget.GetModuleAtIndexFromEvent(i, event)
                        # On macOS Ventura and later, dyld and the main binary
                        # will be loaded again when dyld moves itself into the
                        # shared cache. Use the basename so this also works
                        # when reading dyld from the expanded shared cache.
                        exe_basename = lldb.SBFileSpec(exe).basename
                        if module.file.basename not in ["dyld", exe_basename]:
                            self.assertNotIn(
                                module,
                                already_loaded_modules,
                                "{} is already loaded".format(module),
                            )
                        already_loaded_modules.append(module)
                        added_files.append(module.GetFileSpec().GetFilename())
                    if self.TraceOn():
                        # print all of the binaries that have been added
                        print("Loaded files: %s" % (", ".join(added_files)))

                    # We will check the latest biggest chunk of loaded solibs.
                    # We expect all of our solibs in the last chunk of loaded modules.
                    if solib_count >= max_solibs_per_event:
                        max_solib_chunk_per_event = added_files.copy()
                        max_solibs_per_event = solib_count

                if event.GetType() == lldb.SBTarget.eBroadcastBitModulesUnloaded:
                    solib_count = lldb.SBTarget.GetNumModulesFromEvent(event)
                    total_modules_removed_events += 1
                    total_solibs_removed += solib_count
                    if self.TraceOn():
                        # print all of the binaries that have been removed
                        removed_files = []
                        i = 0
                        while i < solib_count:
                            module = lldb.SBTarget.GetModuleAtIndexFromEvent(i, event)
                            removed_files.append(module.GetFileSpec().GetFilename())
                            i = i + 1
                        print("Unloaded files: %s" % (", ".join(removed_files)))

        # This is testing that we get back a small number of events with the loaded
        # binaries in batches.  Check that we got back more than 1 solib per event.
        # In practice on Darwin today, we get back two events for a do-nothing c
        # program: a.out and dyld, and then all the rest of the system libraries.
        # On Linux we get events for ld.so, [vdso], the binary and then all libraries,
        # but the different configurations could load a different number of .so modules
        # per event.
        self.assertLessEqual(set(expected_solibs), set(max_solib_chunk_per_event))
