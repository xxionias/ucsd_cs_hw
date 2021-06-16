/*
 * Filename:	numofDigitsEC.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: This function counts the number of digits in num in 
 *		the given base.
 * Date:	1.31.2018
 * Source:	course website
 */
	.cpu	cortex-a53
	.syntax	unified

	.global	numOfDigits
	.equ	RANGE_MIN, 2
	.equ	RANGE_MAX, 36
	.equ	FP_OFFSET, 4
	.text
	.align 	2

/* 
 * Function Name:	numOfDigits()
 * Function Prototype:	long numofDigits( long num, long base );
 * Description:		The function counts the number of digits 
 *			in the given base.
 * Return:		return the number of digits
 * Registers used:
 *	r0 - long num
 * 	r1 - long base
 */

numOfDigits:
	push	{fp, lr}	@ Save registers
	add	fp, sp, FP_OFFSET
	mov	r3, r0

	cmp	r1, RANGE_MIN	@ check if base <= RANGE_MIN
	blt	if

	cmp	r1, RANGE_MAX	@ check if base >= RANGE_MAX
	ble	else

if:
	mov	r0, -1		@ if base out of range, return -1
	b 	end_if_else

else:	
	mov	r2, 1
	sdiv	r3, r3, r1	@ calculate the number of digits
	cmp	r3, 0
	beq	end_loop

loop:	
	add	r2, r2, 1
	sdiv	r3, r3, r1	@ division loop
	cmp	r3, 0
	bgt	loop

end_loop:
	mov	r0, r2		@ save the number of digits to r0

end_if_else:	
	sub	fp, sp, FP_OFFSET
	pop	{fp, pc}
