// This test uses '<prefix>-SAME: {{^}}' to start matching immediately where the
// previous check finished matching (specifically, caret is not treated as
// matching a start of line when used like this in FileCheck).

// RUN: not %clang_cc1 -triple armv5--- -target-cpu not-a-cpu -fsyntax-only %s 2>&1 | FileCheck %s
// CHECK: error: unknown target CPU 'not-a-cpu'
// CHECK-NEXT: note: valid target CPU values are:
// CHECK-SAME: {{^}} arm8
// CHECK-SAME: {{^}}, arm810
// CHECK-SAME: {{^}}, strongarm
// CHECK-SAME: {{^}}, strongarm110
// CHECK-SAME: {{^}}, strongarm1100
// CHECK-SAME: {{^}}, strongarm1110
// CHECK-SAME: {{^}}, arm7tdmi
// CHECK-SAME: {{^}}, arm7tdmi-s
// CHECK-SAME: {{^}}, arm710t
// CHECK-SAME: {{^}}, arm720t
// CHECK-SAME: {{^}}, arm9
// CHECK-SAME: {{^}}, arm9tdmi
// CHECK-SAME: {{^}}, arm920
// CHECK-SAME: {{^}}, arm920t
// CHECK-SAME: {{^}}, arm922t
// CHECK-SAME: {{^}}, arm940t
// CHECK-SAME: {{^}}, ep9312
// CHECK-SAME: {{^}}, arm10tdmi
// CHECK-SAME: {{^}}, arm1020t
// CHECK-SAME: {{^}}, arm9e
// CHECK-SAME: {{^}}, arm946e-s
// CHECK-SAME: {{^}}, arm966e-s
// CHECK-SAME: {{^}}, arm968e-s
// CHECK-SAME: {{^}}, arm10e
// CHECK-SAME: {{^}}, arm1020e
// CHECK-SAME: {{^}}, arm1022e
// CHECK-SAME: {{^}}, arm926ej-s
// CHECK-SAME: {{^}}, arm1136j-s
// CHECK-SAME: {{^}}, arm1136jf-s
// CHECK-SAME: {{^}}, mpcore
// CHECK-SAME: {{^}}, mpcorenovfp
// CHECK-SAME: {{^}}, arm1176jz-s
// CHECK-SAME: {{^}}, arm1176jzf-s
// CHECK-SAME: {{^}}, arm1156t2-s
// CHECK-SAME: {{^}}, arm1156t2f-s
// CHECK-SAME: {{^}}, cortex-m0
// CHECK-SAME: {{^}}, cortex-m0plus
// CHECK-SAME: {{^}}, cortex-m1
// CHECK-SAME: {{^}}, sc000
// CHECK-SAME: {{^}}, cortex-a5
// CHECK-SAME: {{^}}, cortex-a7
// CHECK-SAME: {{^}}, cortex-a8
// CHECK-SAME: {{^}}, cortex-a9
// CHECK-SAME: {{^}}, cortex-a12
// CHECK-SAME: {{^}}, cortex-a15
// CHECK-SAME: {{^}}, cortex-a17
// CHECK-SAME: {{^}}, krait
// CHECK-SAME: {{^}}, cortex-r4
// CHECK-SAME: {{^}}, cortex-r4f
// CHECK-SAME: {{^}}, cortex-r5
// CHECK-SAME: {{^}}, cortex-r7
// CHECK-SAME: {{^}}, cortex-r8
// CHECK-SAME: {{^}}, cortex-r52
// CHECK-SAME: {{^}}, cortex-r52plus
// CHECK-SAME: {{^}}, sc300
// CHECK-SAME: {{^}}, cortex-m3
// CHECK-SAME: {{^}}, cortex-m4
// CHECK-SAME: {{^}}, cortex-m7
// CHECK-SAME: {{^}}, cortex-m23
// CHECK-SAME: {{^}}, cortex-m33
// CHECK-SAME: {{^}}, cortex-m35p
// CHECK-SAME: {{^}}, cortex-m55
// CHECK-SAME: {{^}}, cortex-m85
// CHECK-SAME: {{^}}, cortex-m52
// CHECK-SAME: {{^}}, cortex-a32
// CHECK-SAME: {{^}}, cortex-a35
// CHECK-SAME: {{^}}, cortex-a53
// CHECK-SAME: {{^}}, cortex-a55
// CHECK-SAME: {{^}}, cortex-a57
// CHECK-SAME: {{^}}, cortex-a72
// CHECK-SAME: {{^}}, cortex-a73
// CHECK-SAME: {{^}}, cortex-a75
// CHECK-SAME: {{^}}, cortex-a76
// CHECK-SAME: {{^}}, cortex-a76ae
// CHECK-SAME: {{^}}, cortex-a77
// CHECK-SAME: {{^}}, cortex-a78
// CHECK-SAME: {{^}}, cortex-a78ae
// CHECK-SAME: {{^}}, cortex-a78c
// CHECK-SAME: {{^}}, cortex-a710
// CHECK-SAME: {{^}}, cortex-x1
// CHECK-SAME: {{^}}, cortex-x1c
// CHECK-SAME: {{^}}, neoverse-n1
// CHECK-SAME: {{^}}, neoverse-n2
// CHECK-SAME: {{^}}, neoverse-v1
// CHECK-SAME: {{^}}, cyclone
// CHECK-SAME: {{^}}, exynos-m3
// CHECK-SAME: {{^}}, exynos-m4
// CHECK-SAME: {{^}}, exynos-m5
// CHECK-SAME: {{^}}, kryo
// CHECK-SAME: {{^}}, iwmmxt
// CHECK-SAME: {{^}}, xscale
// CHECK-SAME: {{^}}, swift
// CHECK-SAME: {{$}}
