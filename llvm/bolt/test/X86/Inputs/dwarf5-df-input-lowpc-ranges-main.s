# clang++ -fbasic-block-sections=all -ffunction-sections -g2 -gdwarf-5 -gsplit-dwarf
# __attribute__((always_inline))
# int doStuff(int val) {
#   if (val)
#     ++val;
#   return val;
# }
# __attribute__((always_inline))
# int doStuff2(int val) {
#   int foo = 3;
#   return val + foo;
# }
#
#
# int main(int argc, const char** argv) {
#     return  doStuff(argc) + doStuff2(argc);;
# }
	.text
	.file	"main.cpp"
	.section	.text._Z7doStuffi,"ax",@progbits
	.globl	_Z7doStuffi                     # -- Begin function _Z7doStuffi
	.p2align	4, 0x90
	.type	_Z7doStuffi,@function
_Z7doStuffi:                            # @_Z7doStuffi
.Lfunc_begin0:
	.file	0 "." "main.cpp" md5 0x69a746524dda095f8ea37f5a26dd1e9b
	.loc	0 2 0                           # main.cpp:2:0
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
.Ltmp0:
	.loc	0 3 7 prologue_end              # main.cpp:3:7
	cmpl	$0, -4(%rbp)
.Ltmp1:
	.loc	0 3 7 is_stmt 0                 # main.cpp:3:7
	je	_Z7doStuffi.__part.2
	jmp	_Z7doStuffi.__part.1
.LBB_END0_0:
	.cfi_endproc
	.section	.text._Z7doStuffi,"ax",@progbits,unique,1
_Z7doStuffi.__part.1:                   # %if.then
	.cfi_startproc
	.cfi_def_cfa %rbp, 16
	.cfi_offset %rbp, -16
	.loc	0 4 5 is_stmt 1                 # main.cpp:4:5
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	_Z7doStuffi.__part.2
.LBB_END0_1:
	.size	_Z7doStuffi.__part.1, .LBB_END0_1-_Z7doStuffi.__part.1
	.cfi_endproc
	.section	.text._Z7doStuffi,"ax",@progbits,unique,2
_Z7doStuffi.__part.2:                   # %if.end
	.cfi_startproc
	.cfi_def_cfa %rbp, 16
	.cfi_offset %rbp, -16
	.loc	0 5 10                          # main.cpp:5:10
	movl	-4(%rbp), %eax
	.loc	0 5 3 epilogue_begin is_stmt 0  # main.cpp:5:3
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB_END0_2:
	.size	_Z7doStuffi.__part.2, .LBB_END0_2-_Z7doStuffi.__part.2
	.cfi_endproc
	.section	.text._Z7doStuffi,"ax",@progbits
.Lfunc_end0:
	.size	_Z7doStuffi, .Lfunc_end0-_Z7doStuffi
                                        # -- End function
	.section	.text._Z8doStuff2i,"ax",@progbits
	.globl	_Z8doStuff2i                    # -- Begin function _Z8doStuff2i
	.p2align	4, 0x90
	.type	_Z8doStuff2i,@function
_Z8doStuff2i:                           # @_Z8doStuff2i
.Lfunc_begin1:
	.loc	0 8 0 is_stmt 1                 # main.cpp:8:0
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
.Ltmp2:
	.loc	0 9 7 prologue_end              # main.cpp:9:7
	movl	$3, -8(%rbp)
	.loc	0 10 10                         # main.cpp:10:10
	movl	-4(%rbp), %eax
	.loc	0 10 14 is_stmt 0               # main.cpp:10:14
	addl	-8(%rbp), %eax
	.loc	0 10 3 epilogue_begin           # main.cpp:10:3
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB_END1_0:
	.cfi_endproc
.Lfunc_end1:
	.size	_Z8doStuff2i, .Lfunc_end1-_Z8doStuff2i
                                        # -- End function
	.section	.text.main,"ax",@progbits
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin2:
	.loc	0 14 0 is_stmt 1                # main.cpp:14:0
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$0, -16(%rbp)
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
.Ltmp3:
	.loc	0 15 21 prologue_end            # main.cpp:15:21
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
.Ltmp4:
	.loc	0 3 7                           # main.cpp:3:7
	cmpl	$0, -12(%rbp)
.Ltmp5:
	.loc	0 3 7 is_stmt 0                 # main.cpp:3:7
	je	main.__part.2
	jmp	main.__part.1
.LBB_END2_0:
	.cfi_endproc
	.section	.text.main,"ax",@progbits,unique,3
main.__part.1:                          # %if.then.i
	.cfi_startproc
	.cfi_def_cfa %rbp, 16
	.cfi_offset %rbp, -16
	.loc	0 4 5 is_stmt 1                 # main.cpp:4:5
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	main.__part.2
.LBB_END2_1:
	.size	main.__part.1, .LBB_END2_1-main.__part.1
	.cfi_endproc
	.section	.text.main,"ax",@progbits,unique,4
main.__part.2:                          # %_Z7doStuffi.exit
	.cfi_startproc
	.cfi_def_cfa %rbp, 16
	.cfi_offset %rbp, -16
	.loc	0 5 10                          # main.cpp:5:10
	movl	-12(%rbp), %eax
.Ltmp6:
	.loc	0 15 38                         # main.cpp:15:38
	movl	-20(%rbp), %ecx
	movl	%ecx, -4(%rbp)
.Ltmp7:
	.loc	0 9 7                           # main.cpp:9:7
	movl	$3, -8(%rbp)
	.loc	0 10 10                         # main.cpp:10:10
	movl	-4(%rbp), %ecx
	.loc	0 10 14 is_stmt 0               # main.cpp:10:14
	addl	-8(%rbp), %ecx
.Ltmp8:
	.loc	0 15 27 is_stmt 1               # main.cpp:15:27
	addl	%ecx, %eax
	.loc	0 15 5 epilogue_begin is_stmt 0 # main.cpp:15:5
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB_END2_2:
	.size	main.__part.2, .LBB_END2_2-main.__part.2
	.cfi_endproc
	.section	.text.main,"ax",@progbits
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
                                        # -- End function
	.section	.debug_abbrev,"",@progbits
	.byte	1                               # Abbreviation Code
	.byte	74                              # DW_TAG_skeleton_unit
	.byte	0                               # DW_CHILDREN_no
	.byte	16                              # DW_AT_stmt_list
	.byte	23                              # DW_FORM_sec_offset
	.byte	114                             # DW_AT_str_offsets_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	27                              # DW_AT_comp_dir
	.byte	37                              # DW_FORM_strx1
	.ascii	"\264B"                         # DW_AT_GNU_pubnames
	.byte	25                              # DW_FORM_flag_present
	.byte	118                             # DW_AT_dwo_name
	.byte	37                              # DW_FORM_strx1
	.byte	17                              # DW_AT_low_pc
	.byte	1                               # DW_FORM_addr
	.byte	85                              # DW_AT_ranges
	.byte	35                              # DW_FORM_rnglistx
	.byte	115                             # DW_AT_addr_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	116                             # DW_AT_rnglists_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	0                               # EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.long	.Ldebug_info_end0-.Ldebug_info_start0 # Length of Unit
.Ldebug_info_start0:
	.short	5                               # DWARF version number
	.byte	4                               # DWARF Unit Type
	.byte	8                               # Address Size (in bytes)
	.long	.debug_abbrev                   # Offset Into Abbrev. Section
	.quad	1354107878901449185
	.byte	1                               # Abbrev [1] 0x14:0x1c DW_TAG_skeleton_unit
	.long	.Lline_table_start0             # DW_AT_stmt_list
	.long	.Lstr_offsets_base0             # DW_AT_str_offsets_base
	.byte	0                               # DW_AT_comp_dir
                                        # DW_AT_GNU_pubnames
	.byte	1                               # DW_AT_dwo_name
	.quad	0                               # DW_AT_low_pc
	.byte	0                               # DW_AT_ranges
	.long	.Laddr_table_base0              # DW_AT_addr_base
	.long	.Lrnglists_table_base0          # DW_AT_rnglists_base
.Ldebug_info_end0:
	.section	.debug_rnglists,"",@progbits
	.long	.Ldebug_list_header_end0-.Ldebug_list_header_start0 # Length
.Ldebug_list_header_start0:
	.short	5                               # Version
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
	.long	1                               # Offset entry count
.Lrnglists_table_base0:
	.long	.Ldebug_ranges4-.Lrnglists_table_base0
.Ldebug_ranges4:
	.byte	3                               # DW_RLE_startx_length
	.byte	0                               #   start index
	.uleb128 .LBB_END0_1-_Z7doStuffi.__part.1 #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	1                               #   start index
	.uleb128 .LBB_END0_2-_Z7doStuffi.__part.2 #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	2                               #   start index
	.uleb128 .Lfunc_end0-.Lfunc_begin0      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	3                               #   start index
	.uleb128 .Lfunc_end1-.Lfunc_begin1      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	4                               #   start index
	.uleb128 .LBB_END2_1-main.__part.1      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	5                               #   start index
	.uleb128 .LBB_END2_2-main.__part.2      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	6                               #   start index
	.uleb128 .Lfunc_end2-.Lfunc_begin2      #   length
	.byte	0                               # DW_RLE_end_of_list
.Ldebug_list_header_end0:
	.section	.debug_str_offsets,"",@progbits
	.long	12                              # Length of String Offsets Set
	.short	5
	.short	0
.Lstr_offsets_base0:
	.section	.debug_str,"MS",@progbits,1
.Lskel_string0:
	.asciz	"." # string offset=0
.Lskel_string1:
	.asciz	"main.dwo"                      # string offset=38
	.section	.debug_str_offsets,"",@progbits
	.long	.Lskel_string0
	.long	.Lskel_string1
	.section	.debug_str_offsets.dwo,"e",@progbits
	.long	60                              # Length of String Offsets Set
	.short	5
	.short	0
	.section	.debug_str.dwo,"eMS",@progbits,1
.Linfo_string0:
	.asciz	"_Z7doStuffi"                   # string offset=0
.Linfo_string1:
	.asciz	"doStuff"                       # string offset=12
.Linfo_string2:
	.asciz	"int"                           # string offset=20
.Linfo_string3:
	.asciz	"val"                           # string offset=24
.Linfo_string4:
	.asciz	"_Z8doStuff2i"                  # string offset=28
.Linfo_string5:
	.asciz	"doStuff2"                      # string offset=41
.Linfo_string6:
	.asciz	"foo"                           # string offset=50
.Linfo_string7:
	.asciz	"main"                          # string offset=54
.Linfo_string8:
	.asciz	"argc"                          # string offset=59
.Linfo_string9:
	.asciz	"argv"                          # string offset=64
.Linfo_string10:
	.asciz	"char"                          # string offset=69
.Linfo_string11:
	.asciz	"clang version 18.0.0 (git@github.com:llvm/llvm-project.git 3a8db0f4bfb57348f49d9603119fa157114bbf8e)" # string offset=74
.Linfo_string12:
	.asciz	"main.cpp"                      # string offset=175
.Linfo_string13:
	.asciz	"main.dwo"                      # string offset=184
	.section	.debug_str_offsets.dwo,"e",@progbits
	.long	0
	.long	12
	.long	20
	.long	24
	.long	28
	.long	41
	.long	50
	.long	54
	.long	59
	.long	64
	.long	69
	.long	74
	.long	175
	.long	184
	.section	.debug_info.dwo,"e",@progbits
	.long	.Ldebug_info_dwo_end0-.Ldebug_info_dwo_start0 # Length of Unit
.Ldebug_info_dwo_start0:
	.short	5                               # DWARF version number
	.byte	5                               # DWARF Unit Type
	.byte	8                               # Address Size (in bytes)
	.long	0                               # Offset Into Abbrev. Section
	.quad	1354107878901449185
	.byte	1                               # Abbrev [1] 0x14:0xc6 DW_TAG_compile_unit
	.byte	11                              # DW_AT_producer
	.short	33                              # DW_AT_language
	.byte	12                              # DW_AT_name
	.byte	13                              # DW_AT_dwo_name
	.byte	2                               # Abbrev [2] 0x1a:0x11 DW_TAG_subprogram
	.byte	0                               # DW_AT_ranges
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.long	72                              # DW_AT_abstract_origin
	.byte	3                               # Abbrev [3] 0x22:0x8 DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	124
	.long	81                              # DW_AT_abstract_origin
	.byte	0                               # End Of Children Mark
	.byte	4                               # Abbrev [4] 0x2b:0x1d DW_TAG_subprogram
	.byte	3                               # DW_AT_low_pc
	.long	.Lfunc_end1-.Lfunc_begin1       # DW_AT_high_pc
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.long	94                              # DW_AT_abstract_origin
	.byte	3                               # Abbrev [3] 0x37:0x8 DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	124
	.long	103                             # DW_AT_abstract_origin
	.byte	5                               # Abbrev [5] 0x3f:0x8 DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	120
	.long	111                             # DW_AT_abstract_origin
	.byte	0                               # End Of Children Mark
	.byte	6                               # Abbrev [6] 0x48:0x12 DW_TAG_subprogram
	.byte	0                               # DW_AT_linkage_name
	.byte	1                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	2                               # DW_AT_decl_line
	.long	90                              # DW_AT_type
                                        # DW_AT_external
                                        # DW_AT_inline
	.byte	7                               # Abbrev [7] 0x51:0x8 DW_TAG_formal_parameter
	.byte	3                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	2                               # DW_AT_decl_line
	.long	90                              # DW_AT_type
	.byte	0                               # End Of Children Mark
	.byte	8                               # Abbrev [8] 0x5a:0x4 DW_TAG_base_type
	.byte	2                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	4                               # DW_AT_byte_size
	.byte	6                               # Abbrev [6] 0x5e:0x1a DW_TAG_subprogram
	.byte	4                               # DW_AT_linkage_name
	.byte	5                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	8                               # DW_AT_decl_line
	.long	90                              # DW_AT_type
                                        # DW_AT_external
                                        # DW_AT_inline
	.byte	7                               # Abbrev [7] 0x67:0x8 DW_TAG_formal_parameter
	.byte	3                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	8                               # DW_AT_decl_line
	.long	90                              # DW_AT_type
	.byte	9                               # Abbrev [9] 0x6f:0x8 DW_TAG_variable
	.byte	6                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	9                               # DW_AT_decl_line
	.long	90                              # DW_AT_type
	.byte	0                               # End Of Children Mark
	.byte	10                              # Abbrev [10] 0x78:0x4e DW_TAG_subprogram
	.byte	1                               # DW_AT_ranges
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.byte	7                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	14                              # DW_AT_decl_line
	.long	90                              # DW_AT_type
                                        # DW_AT_external
	.byte	11                              # Abbrev [11] 0x83:0xb DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	108
	.byte	8                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	14                              # DW_AT_decl_line
	.long	90                              # DW_AT_type
	.byte	11                              # Abbrev [11] 0x8e:0xb DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	96
	.byte	9                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	14                              # DW_AT_decl_line
	.long	198                             # DW_AT_type
	.byte	12                              # Abbrev [12] 0x99:0x12 DW_TAG_inlined_subroutine
	.long	72                              # DW_AT_abstract_origin
	.byte	2                               # DW_AT_ranges
	.byte	0                               # DW_AT_call_file
	.byte	15                              # DW_AT_call_line
	.byte	13                              # DW_AT_call_column
	.byte	3                               # Abbrev [3] 0xa2:0x8 DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	116
	.long	81                              # DW_AT_abstract_origin
	.byte	0                               # End Of Children Mark
	.byte	12                              # Abbrev [12] 0xab:0x1a DW_TAG_inlined_subroutine
	.long	94                              # DW_AT_abstract_origin
	.byte	3                               # DW_AT_ranges
	.byte	0                               # DW_AT_call_file
	.byte	15                              # DW_AT_call_line
	.byte	29                              # DW_AT_call_column
	.byte	3                               # Abbrev [3] 0xb4:0x8 DW_TAG_formal_parameter
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	124
	.long	103                             # DW_AT_abstract_origin
	.byte	5                               # Abbrev [5] 0xbc:0x8 DW_TAG_variable
	.byte	2                               # DW_AT_location
	.byte	145
	.byte	120
	.long	111                             # DW_AT_abstract_origin
	.byte	0                               # End Of Children Mark
	.byte	0                               # End Of Children Mark
	.byte	13                              # Abbrev [13] 0xc6:0x5 DW_TAG_pointer_type
	.long	203                             # DW_AT_type
	.byte	13                              # Abbrev [13] 0xcb:0x5 DW_TAG_pointer_type
	.long	208                             # DW_AT_type
	.byte	14                              # Abbrev [14] 0xd0:0x5 DW_TAG_const_type
	.long	213                             # DW_AT_type
	.byte	8                               # Abbrev [8] 0xd5:0x4 DW_TAG_base_type
	.byte	10                              # DW_AT_name
	.byte	6                               # DW_AT_encoding
	.byte	1                               # DW_AT_byte_size
	.byte	0                               # End Of Children Mark
.Ldebug_info_dwo_end0:
	.section	.debug_abbrev.dwo,"e",@progbits
	.byte	1                               # Abbreviation Code
	.byte	17                              # DW_TAG_compile_unit
	.byte	1                               # DW_CHILDREN_yes
	.byte	37                              # DW_AT_producer
	.byte	37                              # DW_FORM_strx1
	.byte	19                              # DW_AT_language
	.byte	5                               # DW_FORM_data2
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	118                             # DW_AT_dwo_name
	.byte	37                              # DW_FORM_strx1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	2                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	85                              # DW_AT_ranges
	.byte	35                              # DW_FORM_rnglistx
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	49                              # DW_AT_abstract_origin
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	3                               # Abbreviation Code
	.byte	5                               # DW_TAG_formal_parameter
	.byte	0                               # DW_CHILDREN_no
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	49                              # DW_AT_abstract_origin
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	4                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	49                              # DW_AT_abstract_origin
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	5                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	49                              # DW_AT_abstract_origin
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	6                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	110                             # DW_AT_linkage_name
	.byte	37                              # DW_FORM_strx1
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	32                              # DW_AT_inline
	.byte	33                              # DW_FORM_implicit_const
	.byte	1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	7                               # Abbreviation Code
	.byte	5                               # DW_TAG_formal_parameter
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	8                               # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	9                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	10                              # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	1                               # DW_CHILDREN_yes
	.byte	85                              # DW_AT_ranges
	.byte	35                              # DW_FORM_rnglistx
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	11                              # Abbreviation Code
	.byte	5                               # DW_TAG_formal_parameter
	.byte	0                               # DW_CHILDREN_no
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	12                              # Abbreviation Code
	.byte	29                              # DW_TAG_inlined_subroutine
	.byte	1                               # DW_CHILDREN_yes
	.byte	49                              # DW_AT_abstract_origin
	.byte	19                              # DW_FORM_ref4
	.byte	85                              # DW_AT_ranges
	.byte	35                              # DW_FORM_rnglistx
	.byte	88                              # DW_AT_call_file
	.byte	11                              # DW_FORM_data1
	.byte	89                              # DW_AT_call_line
	.byte	11                              # DW_FORM_data1
	.byte	87                              # DW_AT_call_column
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	13                              # Abbreviation Code
	.byte	15                              # DW_TAG_pointer_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	14                              # Abbreviation Code
	.byte	38                              # DW_TAG_const_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	0                               # EOM(3)
	.section	.debug_rnglists.dwo,"e",@progbits
	.long	.Ldebug_list_header_end1-.Ldebug_list_header_start1 # Length
.Ldebug_list_header_start1:
	.short	5                               # Version
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
	.long	4                               # Offset entry count
.Lrnglists_dwo_table_base0:
	.long	.Ldebug_ranges0-.Lrnglists_dwo_table_base0
	.long	.Ldebug_ranges1-.Lrnglists_dwo_table_base0
	.long	.Ldebug_ranges2-.Lrnglists_dwo_table_base0
	.long	.Ldebug_ranges3-.Lrnglists_dwo_table_base0
.Ldebug_ranges0:
	.byte	3                               # DW_RLE_startx_length
	.byte	0                               #   start index
	.uleb128 .LBB_END0_1-_Z7doStuffi.__part.1 #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	1                               #   start index
	.uleb128 .LBB_END0_2-_Z7doStuffi.__part.2 #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	2                               #   start index
	.uleb128 .Lfunc_end0-.Lfunc_begin0      #   length
	.byte	0                               # DW_RLE_end_of_list
.Ldebug_ranges1:
	.byte	3                               # DW_RLE_startx_length
	.byte	4                               #   start index
	.uleb128 .LBB_END2_1-main.__part.1      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	5                               #   start index
	.uleb128 .LBB_END2_2-main.__part.2      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	6                               #   start index
	.uleb128 .Lfunc_end2-.Lfunc_begin2      #   length
	.byte	0                               # DW_RLE_end_of_list
.Ldebug_ranges2:
	.byte	1                               # DW_RLE_base_addressx
	.byte	6                               #   base address index
	.byte	4                               # DW_RLE_offset_pair
	.uleb128 .Ltmp4-.Lfunc_begin2           #   starting offset
	.uleb128 .Lfunc_end2-.Lfunc_begin2      #   ending offset
	.byte	3                               # DW_RLE_startx_length
	.byte	4                               #   start index
	.uleb128 .LBB_END2_1-main.__part.1      #   length
	.byte	3                               # DW_RLE_startx_length
	.byte	5                               #   start index
	.uleb128 .Ltmp6-main.__part.2           #   length
	.byte	0                               # DW_RLE_end_of_list
.Ldebug_ranges3:
	.byte	1                               # DW_RLE_base_addressx
	.byte	5                               #   base address index
	.byte	4                               # DW_RLE_offset_pair
	.uleb128 .Ltmp7-main.__part.2           #   starting offset
	.uleb128 .Ltmp8-main.__part.2           #   ending offset
	.byte	0                               # DW_RLE_end_of_list
.Ldebug_list_header_end1:
	.section	.debug_addr,"",@progbits
	.long	.Ldebug_addr_end0-.Ldebug_addr_start0 # Length of contribution
.Ldebug_addr_start0:
	.short	5                               # DWARF version number
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
.Laddr_table_base0:
	.quad	_Z7doStuffi.__part.1
	.quad	_Z7doStuffi.__part.2
	.quad	.Lfunc_begin0
	.quad	.Lfunc_begin1
	.quad	main.__part.1
	.quad	main.__part.2
	.quad	.Lfunc_begin2
.Ldebug_addr_end0:
	.section	.debug_gnu_pubnames,"",@progbits
	.long	.LpubNames_end0-.LpubNames_start0 # Length of Public Names Info
.LpubNames_start0:
	.short	2                               # DWARF Version
	.long	.Lcu_begin0                     # Offset of Compilation Unit Info
	.long	48                              # Compilation Unit Length
	.long	72                              # DIE offset
	.byte	48                              # Attributes: FUNCTION, EXTERNAL
	.asciz	"doStuff"                       # External Name
	.long	94                              # DIE offset
	.byte	48                              # Attributes: FUNCTION, EXTERNAL
	.asciz	"doStuff2"                      # External Name
	.long	120                             # DIE offset
	.byte	48                              # Attributes: FUNCTION, EXTERNAL
	.asciz	"main"                          # External Name
	.long	0                               # End Mark
.LpubNames_end0:
	.section	.debug_gnu_pubtypes,"",@progbits
	.long	.LpubTypes_end0-.LpubTypes_start0 # Length of Public Types Info
.LpubTypes_start0:
	.short	2                               # DWARF Version
	.long	.Lcu_begin0                     # Offset of Compilation Unit Info
	.long	48                              # Compilation Unit Length
	.long	90                              # DIE offset
	.byte	144                             # Attributes: TYPE, STATIC
	.asciz	"int"                           # External Name
	.long	213                             # DIE offset
	.byte	144                             # Attributes: TYPE, STATIC
	.asciz	"char"                          # External Name
	.long	0                               # End Mark
.LpubTypes_end0:
	.ident	"clang version 18.0.0 (git@github.com:llvm/llvm-project.git 3a8db0f4bfb57348f49d9603119fa157114bbf8e)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.section	.debug_line,"",@progbits
.Lline_table_start0:
