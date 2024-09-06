// RUN: %clang_cc1 -triple dxil-pc-shadermodel6.3-library -x hlsl -ast-dump -o - %s | FileCheck %s

// CHECK:HLSLBufferDecl 0x[[CB:[0-9a-f]+]] {{.*}} line:7:9 cbuffer CB
// CHECK:HLSLResourceClassAttr 0x{{[0-9a-f]+}} <<invalid sloc>> Implicit CBuffer
// CHECK-NEXT:HLSLResourceAttr {{.*}} <<invalid sloc>> Implicit CBuffer
// CHECK-NEXT:VarDecl 0x[[A:[0-9a-f]+]] {{.*}} col:9 used a 'float'
cbuffer CB {
  float a;
}

// CHECK:HLSLBufferDecl 0x[[TB:[0-9a-f]+]] {{.*}} line:15:9 tbuffer TB
// CHECK:HLSLResourceClassAttr 0x{{[0-9a-f]+}} <<invalid sloc>> Implicit SRV
// CHECK-NEXT:HLSLResourceAttr {{.*}} <<invalid sloc>> Implicit TBuffer
// CHECK-NEXT:VarDecl 0x[[B:[0-9a-f]+]] {{.*}} col:9 used b 'float'
tbuffer TB {
  float b;
}

float foo() {
// CHECK: BinaryOperator 0x{{[0-9a-f]+}} <col:10, col:14> 'float' '+'
// CHECK-NEXT: ImplicitCastExpr 0x{{[0-9a-f]+}} <col:10> 'float' <LValueToRValue>
// CHECK-NEXT: DeclRefExpr 0x{{[0-9a-f]+}} <col:10> 'float' lvalue Var 0x[[A]] 'a' 'float'
// CHECK-NEXT: ImplicitCastExpr 0x{{[0-9a-f]+}} <col:14> 'float' <LValueToRValue>
// CHECK-NEXT: DeclRefExpr 0x{{[0-9a-f]+}} <col:14> 'float' lvalue Var 0x[[B]] 'b' 'float'
  return a + b;
}
