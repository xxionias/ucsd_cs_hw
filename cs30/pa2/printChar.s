/*
 * Filename:	printChar.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: This assembly module prints the character argument
 * 		to stdout.
 * Date:	1.30.2018
 */

	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.section	.rodata
	.equ	OFF_SET, 4
fmt:	.asciz	"%c"		
	
	.global	printChar

	.text

/* 
 * Function Name:	printChar()
 * Function Prototype:	void printChar( char ch );
 * Description:		Prints the input character.
 * Parameter:		ch - character input
 * Error Condition:	None.
 * 
 * Registers used:
 *	r0 - arg1 -- ch
 */
printChar:
	push	{fp, lr}	@ Saves registers on the stack.
	add	fp, sp, OFF_SET	@ Adjusts fp to be at bottom of current stack.
				@ Uses 4 because (#regs_saved - 1) * 4.
	mov	r1, r0		@ Copy of formal parameter to the second arg of printf.
	ldr	r0, =fmt	@ Gets address of format string.
	bl	printf		@ Calls printf

	sub	sp, fp, OFF_SET	
	pop	{fp, pc}	@Returns from function
