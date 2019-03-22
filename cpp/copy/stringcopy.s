	.text
	.file	"stringcopy.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function __cxx_global_var_init
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$_ZStL8__ioinit, %rdi
	callq	_ZNSt8ios_base4InitC1Ev
	movabsq	$_ZNSt8ios_base4InitD1Ev, %rdi
	movabsq	$_ZStL8__ioinit, %rsi
	movabsq	$__dso_handle, %rdx
	callq	__cxa_atexit
	movl	%eax, -4(%rbp)          # 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc
                                        # -- End function
	.text
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$336, %rsp              # imm = 0x150
	movl	$0, -4(%rbp)
	movl	$3, -8(%rbp)
	movl	$4, %eax
	movl	%eax, %edi
	callq	_Znwm
	movl	$4, (%rax)
	movq	%rax, -16(%rbp)
	leaq	-56(%rbp), %rax
	movq	%rax, %rdi
	movq	%rax, -176(%rbp)        # 8-byte Spill
	callq	_ZNSaIcEC1Ev
.Ltmp0:
	movl	$.L.str, %ecx
	movl	%ecx, %esi
	leaq	-48(%rbp), %rdi
	movq	-176(%rbp), %rdx        # 8-byte Reload
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.Ltmp1:
	jmp	.LBB1_1
.LBB1_1:
	leaq	-56(%rbp), %rdi
	callq	_ZNSaIcED1Ev
.Ltmp3:
	leaq	-104(%rbp), %rdi
	leaq	-48(%rbp), %rsi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
.Ltmp4:
	jmp	.LBB1_2
.LBB1_2:
	leaq	-48(%rbp), %rdi
	callq	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	leaq	-136(%rbp), %rdi
	movq	%rax, %rsi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_
.Ltmp6:
	leaq	-168(%rbp), %rdi
	leaq	-104(%rbp), %rsi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
.Ltmp7:
	jmp	.LBB1_3
.LBB1_3:
.Ltmp9:
	movl	$2, %eax
	movl	%eax, %esi
	leaq	-104(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
.Ltmp10:
	movq	%rax, -184(%rbp)        # 8-byte Spill
	jmp	.LBB1_4
.LBB1_4:
	movq	-184(%rbp), %rax        # 8-byte Reload
	movb	$75, (%rax)
.Ltmp11:
	movl	$2, %ecx
	movl	%ecx, %esi
	leaq	-168(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
.Ltmp12:
	movq	%rax, -192(%rbp)        # 8-byte Spill
	jmp	.LBB1_5
.LBB1_5:
	movq	-192(%rbp), %rax        # 8-byte Reload
	movb	$82, (%rax)
.Ltmp13:
	movl	$2, %ecx
	movl	%ecx, %esi
	leaq	-136(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm
.Ltmp14:
	movq	%rax, -200(%rbp)        # 8-byte Spill
	jmp	.LBB1_6
.LBB1_6:
	movq	-200(%rbp), %rax        # 8-byte Reload
	movb	$80, (%rax)
.Ltmp15:
	movl	$_ZSt4cout, %ecx
	movl	%ecx, %edi
	leaq	-8(%rbp), %rsi
	callq	_ZNSolsEPKv
.Ltmp16:
	movq	%rax, -208(%rbp)        # 8-byte Spill
	jmp	.LBB1_7
.LBB1_7:
.Ltmp17:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-208(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp18:
	movq	%rax, -216(%rbp)        # 8-byte Spill
	jmp	.LBB1_8
.LBB1_8:
	movq	-16(%rbp), %rsi
.Ltmp19:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	callq	_ZNSolsEPKv
.Ltmp20:
	movq	%rax, -224(%rbp)        # 8-byte Spill
	jmp	.LBB1_9
.LBB1_9:
.Ltmp21:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-224(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp22:
	movq	%rax, -232(%rbp)        # 8-byte Spill
	jmp	.LBB1_10
.LBB1_10:
.Ltmp23:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-48(%rbp), %rsi
	callq	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp24:
	movq	%rax, -240(%rbp)        # 8-byte Spill
	jmp	.LBB1_11
.LBB1_11:
.Ltmp25:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-240(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp26:
	movq	%rax, -248(%rbp)        # 8-byte Spill
	jmp	.LBB1_12
.LBB1_12:
.Ltmp27:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-104(%rbp), %rsi
	callq	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp28:
	movq	%rax, -256(%rbp)        # 8-byte Spill
	jmp	.LBB1_13
.LBB1_13:
.Ltmp29:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-256(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp30:
	movq	%rax, -264(%rbp)        # 8-byte Spill
	jmp	.LBB1_14
.LBB1_14:
.Ltmp31:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-136(%rbp), %rsi
	callq	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp32:
	movq	%rax, -272(%rbp)        # 8-byte Spill
	jmp	.LBB1_15
.LBB1_15:
.Ltmp33:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-272(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp34:
	movq	%rax, -280(%rbp)        # 8-byte Spill
	jmp	.LBB1_16
.LBB1_16:
.Ltmp35:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-168(%rbp), %rsi
	callq	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
.Ltmp36:
	movq	%rax, -288(%rbp)        # 8-byte Spill
	jmp	.LBB1_17
.LBB1_17:
.Ltmp37:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-288(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp38:
	movq	%rax, -296(%rbp)        # 8-byte Spill
	jmp	.LBB1_18
.LBB1_18:
.Ltmp39:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-48(%rbp), %rsi
	callq	_ZNSolsEPKv
.Ltmp40:
	movq	%rax, -304(%rbp)        # 8-byte Spill
	jmp	.LBB1_19
.LBB1_19:
.Ltmp41:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-304(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp42:
	movq	%rax, -312(%rbp)        # 8-byte Spill
	jmp	.LBB1_20
.LBB1_20:
.Ltmp43:
	movl	$_ZSt4cout, %eax
	movl	%eax, %edi
	leaq	-104(%rbp), %rsi
	callq	_ZNSolsEPKv
.Ltmp44:
	movq	%rax, -320(%rbp)        # 8-byte Spill
	jmp	.LBB1_21
.LBB1_21:
.Ltmp45:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %eax
	movl	%eax, %esi
	movq	-320(%rbp), %rdi        # 8-byte Reload
	callq	_ZNSolsEPFRSoS_E
.Ltmp46:
	movq	%rax, -328(%rbp)        # 8-byte Spill
	jmp	.LBB1_22
.LBB1_22:
	leaq	-168(%rbp), %rdi
	movl	$0, -4(%rbp)
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leaq	-136(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leaq	-104(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leaq	-48(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-4(%rbp), %eax
	addq	$336, %rsp              # imm = 0x150
	popq	%rbp
	retq
.LBB1_23:
.Ltmp2:
	leaq	-56(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
	callq	_ZNSaIcED1Ev
	jmp	.LBB1_29
.LBB1_24:
.Ltmp5:
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
	jmp	.LBB1_28
.LBB1_25:
.Ltmp8:
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
	jmp	.LBB1_27
.LBB1_26:
.Ltmp47:
	leaq	-168(%rbp), %rdi
	movl	%edx, %ecx
	movq	%rax, -64(%rbp)
	movl	%ecx, -68(%rbp)
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LBB1_27:
	leaq	-136(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leaq	-104(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LBB1_28:
	leaq	-48(%rbp), %rdi
	callq	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LBB1_29:
	movq	-64(%rbp), %rdi
	callq	_Unwind_Resume
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2
GCC_except_table1:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	3                       # @TType Encoding = udata4
	.asciz	"\320"                  # @TType base offset
	.byte	3                       # Call site Encoding = udata4
	.byte	78                      # Call site table length
	.long	.Lfunc_begin0-.Lfunc_begin0 # >> Call Site 1 <<
	.long	.Ltmp0-.Lfunc_begin0    #   Call between .Lfunc_begin0 and .Ltmp0
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.long	.Ltmp0-.Lfunc_begin0    # >> Call Site 2 <<
	.long	.Ltmp1-.Ltmp0           #   Call between .Ltmp0 and .Ltmp1
	.long	.Ltmp2-.Lfunc_begin0    #     jumps to .Ltmp2
	.byte	0                       #   On action: cleanup
	.long	.Ltmp3-.Lfunc_begin0    # >> Call Site 3 <<
	.long	.Ltmp4-.Ltmp3           #   Call between .Ltmp3 and .Ltmp4
	.long	.Ltmp5-.Lfunc_begin0    #     jumps to .Ltmp5
	.byte	0                       #   On action: cleanup
	.long	.Ltmp6-.Lfunc_begin0    # >> Call Site 4 <<
	.long	.Ltmp7-.Ltmp6           #   Call between .Ltmp6 and .Ltmp7
	.long	.Ltmp8-.Lfunc_begin0    #     jumps to .Ltmp8
	.byte	0                       #   On action: cleanup
	.long	.Ltmp9-.Lfunc_begin0    # >> Call Site 5 <<
	.long	.Ltmp46-.Ltmp9          #   Call between .Ltmp9 and .Ltmp46
	.long	.Ltmp47-.Lfunc_begin0   #     jumps to .Ltmp47
	.byte	0                       #   On action: cleanup
	.long	.Ltmp46-.Lfunc_begin0   # >> Call Site 6 <<
	.long	.Lfunc_end1-.Ltmp46     #   Call between .Ltmp46 and .Lfunc_end1
	.long	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.p2align	2
                                        # -- End function
	.section	.text._ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_,"axG",@progbits,_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_,comdat
	.weak	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_ # -- Begin function _ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	.p2align	4, 0x90
	.type	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_,@function
_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_: # @_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
.Lfunc_end2:
	.size	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_, .Lfunc_end2-_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function _GLOBAL__sub_I_stringcopy.cpp
	.type	_GLOBAL__sub_I_stringcopy.cpp,@function
_GLOBAL__sub_I_stringcopy.cpp:          # @_GLOBAL__sub_I_stringcopy.cpp
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	__cxx_global_var_init
	popq	%rbp
	retq
.Lfunc_end3:
	.size	_GLOBAL__sub_I_stringcopy.cpp, .Lfunc_end3-_GLOBAL__sub_I_stringcopy.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"HelloWorld"
	.size	.L.str, 11

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_stringcopy.cpp

	.ident	"clang version 6.0.0-1ubuntu2 (tags/RELEASE_600/final)"
	.section	".note.GNU-stack","",@progbits
