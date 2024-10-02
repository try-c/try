# REQUIRES: aarch64, x86
# RUN: split-file %s %t.dir && cd %t.dir

# RUN: llvm-mc -filetype=obj -triple=arm64ec-windows funcs.s -o funcs-arm64ec.obj
# RUN: llvm-mc -filetype=obj -triple=aarch64-windows native-funcs.s -o funcs-aarch64.obj
# RUN: llvm-mc -filetype=obj -triple=x86_64-windows space.s -o space-x86_64.obj
# RUN: llvm-mc -filetype=obj -triple=aarch64-windows space.s -o space-aarch64.obj
# RUN: llvm-mc -filetype=obj -triple=arm64ec-windows %S/Inputs/loadconfig-arm64ec.s -o loadconfig-arm64ec.obj


# Test generating range extension thunks for ARM64EC code. Place some x86_64 chunks in a middle
# and make sure that thunks stay in ARM64EC code range.

# RUN: lld-link -machine:arm64ec -noentry -dll funcs-arm64ec.obj space-x86_64.obj loadconfig-arm64ec.obj -out:test.dll \
# RUN:          -verbose 2>&1 | FileCheck -check-prefix=VERBOSE %s
# VERBOSE: Added 3 thunks with margin {{.*}} in 1 passes

# RUN: llvm-objdump -d test.dll | FileCheck --check-prefix=DISASM %s

# DISASM:      Disassembly of section .code1:
# DISASM-EMPTY:
# DISASM-NEXT: 0000000180003000 <.code1>:
# DISASM-NEXT: 180003000: 36000040     tbz     w0, #0x0, 0x180003008 <.code1+0x8>
# DISASM-NEXT: 180003004: d65f03c0     ret
# DISASM-NEXT: 180003008: b0000050     adrp    x16, 0x18000c000
# DISASM-NEXT: 18000300c: 91000210     add     x16, x16, #0x0
# DISASM-NEXT: 180003010: d61f0200     br      x16
# DISASM-EMPTY:
# DISASM-NEXT: Disassembly of section .code2:
# DISASM-EMPTY:
# DISASM-NEXT: 0000000180004000 <.code2>:
# DISASM-NEXT:                 ...
# DISASM-EMPTY:
# DISASM-NEXT: Disassembly of section .code3:
# DISASM-EMPTY:
# DISASM-NEXT: 0000000180005000 <.code3>:
# DISASM-NEXT:                 ...
# DISASM-NEXT: 18000c000: 36000060     tbz     w0, #0x0, 0x18000c00c <.code3+0x700c>
# DISASM-NEXT: 18000c004: d65f03c0     ret
# DISASM-NEXT: 18000c008: 00000000     udf     #0x0
# DISASM-NEXT: 18000c00c: 90000050     adrp    x16, 0x180014000 <.code3+0xf000>
# DISASM-NEXT: 18000c010: 91006210     add     x16, x16, #0x18
# DISASM-NEXT: 18000c014: d61f0200     br      x16
# DISASM-NEXT:                 ...
# DISASM-NEXT: 180014018: 36000040     tbz     w0, #0x0, 0x180014020 <.code3+0xf020>
# DISASM-NEXT: 18001401c: d65f03c0     ret
# DISASM-NEXT: 180014020: f0ffff70     adrp    x16, 0x180003000 <.code1>
# DISASM-NEXT: 180014024: 91000210     add     x16, x16, #0x0
# DISASM-NEXT: 180014028: d61f0200     br      x16

# RUN: llvm-readobj --coff-load-config test.dll | FileCheck --check-prefix=LOADCFG %s

# LOADCFG:       CodeMap [
# LOADCFG-NEXT:    0x3000 - 0x3014  ARM64EC
# LOADCFG-NEXT:    0x4000 - 0x4300  X64
# LOADCFG-NEXT:    0x5000 - 0x1402C  ARM64EC
# LOADCFG-NEXT:  ]


# A similar test using a hybrid binary and native placeholder chunks.

# RUN: lld-link -machine:arm64x -noentry -dll funcs-arm64ec.obj space-aarch64.obj loadconfig-arm64ec.obj -out:testx.dll \
# RUN:          -verbose 2>&1 | FileCheck -check-prefix=VERBOSE %s
# RUN: llvm-objdump -d testx.dll | FileCheck --check-prefix=DISASM %s

# RUN: llvm-readobj --coff-load-config testx.dll | FileCheck --check-prefix=LOADCFGX %s

# LOADCFGX:       CodeMap [
# LOADCFGX-NEXT:    0x3000 - 0x3014  ARM64EC
# LOADCFGX-NEXT:    0x4000 - 0x4300  ARM64
# LOADCFGX-NEXT:    0x5000 - 0x1402C  ARM64EC
# LOADCFGX-NEXT:  ]


# Test a hybrid ARM64X binary which requires range extension thunks for both native and EC relocations.

# RUN: lld-link -machine:arm64x -noentry -dll funcs-arm64ec.obj funcs-aarch64.obj loadconfig-arm64ec.obj -out:testx2.dll \
# RUN:          -verbose 2>&1 | FileCheck -check-prefix=VERBOSEX %s
# VERBOSEX: Added 5 thunks with margin {{.*}} in 1 passes

# RUN: llvm-objdump -d testx2.dll | FileCheck --check-prefix=DISASMX %s

# DISASMX:      Disassembly of section .code1:
# DISASMX-EMPTY:
# DISASMX-NEXT: 0000000180003000 <.code1>:
# DISASMX-NEXT: 180003000: 36000040     tbz     w0, #0x0, 0x180003008 <.code1+0x8>
# DISASMX-NEXT: 180003004: d65f03c0     ret
# DISASMX-NEXT: 180003008: b0000050     adrp    x16, 0x18000c000
# DISASMX-NEXT: 18000300c: 91000210     add     x16, x16, #0x0
# DISASMX-NEXT: 180003010: d61f0200     br      x16
# DISASMX-EMPTY:
# DISASMX-NEXT: Disassembly of section .code2:
# DISASMX-EMPTY:
# DISASMX-NEXT: 0000000180004000 <.code2>:
# DISASMX-NEXT: 180004000: 36000040     tbz     w0, #0x0, 0x180004008 <.code2+0x8>
# DISASMX-NEXT: 180004004: d65f03c0     ret
# DISASMX-NEXT: 180004008: b0000090     adrp    x16, 0x180015000
# DISASMX-NEXT: 18000400c: 91000210     add     x16, x16, #0x0
# DISASMX-NEXT: 180004010: d61f0200     br      x16
# DISASMX-EMPTY:
# DISASMX-NEXT: Disassembly of section .code3:
# DISASMX-EMPTY:
# DISASMX-NEXT: 0000000180005000 <.code3>:
# DISASMX-NEXT:                 ...
# DISASMX-NEXT: 18000c000: 36000060     tbz     w0, #0x0, 0x18000c00c <.code3+0x700c>
# DISASMX-NEXT: 18000c004: d65f03c0     ret
# DISASMX-NEXT: 18000c008: 00000000     udf     #0x0
# DISASMX-NEXT: 18000c00c: 90000050     adrp    x16, 0x180014000 <.code3+0xf000>
# DISASMX-NEXT: 18000c010: 91006210     add     x16, x16, #0x18
# DISASMX-NEXT: 18000c014: d61f0200     br      x16
# DISASMX-NEXT:                 ...
# DISASMX-NEXT: 180014018: 36000040     tbz     w0, #0x0, 0x180014020 <.code3+0xf020>
# DISASMX-NEXT: 18001401c: d65f03c0     ret
# DISASMX-NEXT: 180014020: f0ffff70     adrp    x16, 0x180003000 <.code1>
# DISASMX-NEXT: 180014024: 91000210     add     x16, x16, #0x0
# DISASMX-NEXT: 180014028: d61f0200     br      x16
# DISASMX-EMPTY:
# DISASMX-NEXT: Disassembly of section .code4:
# DISASMX-EMPTY:
# DISASMX-NEXT: 0000000180015000 <.code4>:
# DISASMX-NEXT: 180015000: 36000040     tbz     w0, #0x0, 0x180015008 <.code4+0x8>
# DISASMX-NEXT: 180015004: d65f03c0     ret
# DISASMX-NEXT: 180015008: f0ffff70     adrp    x16, 0x180004000 <.code2>
# DISASMX-NEXT: 18001500c: 91000210     add     x16, x16, #0x0
# DISASMX-NEXT: 180015010: d61f0200     br      x16

# RUN: llvm-readobj --coff-load-config testx2.dll | FileCheck --check-prefix=LOADCFGX2 %s

# LOADCFGX2:       CodeMap [
# LOADCFGX2-NEXT:    0x3000 - 0x3014  ARM64EC
# LOADCFGX2-NEXT:    0x4000 - 0x4014  ARM64
# LOADCFGX2-NEXT:    0x5000 - 0x1402C  ARM64EC
# LOADCFGX2-NEXT:    0x15000 - 0x15014  ARM64
# LOADCFGX2-NEXT:  ]


#--- funcs.s
        .globl main
        .globl func1
        .globl func2

        .section .code1, "xr"
main:
        tbz w0, #0, func1
        ret

        .section .code3$a, "xr"
        .space 0x7000

        .section .code3$b, "xr"
func1:
        tbz w0, #0, func2
        ret
        .space 1

        .section .code3$c, "xr"
        .space 0x8000

        .section .code3$d, "xr"
        .align 2
func2:
        tbz w0, #0, main
        ret

#--- space.s
        .section .code2$a, "xr"
        .space 0x100
        .section .code2$b, "xr"
        .space 0x100
        .section .code2$c, "xr"
        .space 0x100

#--- native-funcs.s
        .globl nmain
        .globl nfunc

        .section .code2, "xr"
nmain:
        tbz w0, #0, nfunc
        ret

        .section .code4, "xr"
        .align 2
nfunc:
        tbz w0, #0, nmain
        ret
