/*
 * Filename: swapChars.s
 * Description: Assembly function that swaps two chars and determines how many
 *              unique characters had the same value
 */ 

	.cpu	cortex-a53
	.syntax unified

	.global	swapChars
	.type	swapChars, %function

	.text
	.align	2

	.equ	FP_OFFSET, 4	@ (# of saved regs - 1) * 4
	.equ	SCDP, 2		@ return value when chars same, ptrs diff

/*
 * Function name: swapChars()
 * Function prototype: int swapChars(char* c1, char* c2)
 * Description: Takes two pointers to chars and swaps the values.  Then compares
 *              values and ptrs to determine if the characters were the same
 *              and, if so, if the ptrs were pointing to the same place.
 * Parameters: r0 - address of first char to swap
 *             r1 - address of second char to swap
 *             r2 - first char to swap
 *             r3 - second char to swap
 * Side Effects: Swaps two characters in memory
 * Return Value: 0 if chars were different
 *               1 if chars were same, but ptrs were to the same address
 *               2 if chars were same and ptrs were to different addresses
 */

swapChars:

	push	{fp, lr}		@ DO NOT CHANGE THIS LINE.
	add	fp, sp, FP_OFFSET	@ DO NOT CHANGE THIS LINE.

	cmp	r0, r1		@ chars are same; if ptrs are same
	beq	samePtr		@ return 1

	ldrb	r2, [r0]	@ load first char
	ldrb	r3, [r1]	@ load second char

	strb	r2, [r1]	@ store first char in second spot
	strb	r3, [r0]	@ store second char in first spot

	mov	r0, 0		@ tentatively store 0 for return value

	cmp	r2, r3		@ if first char and second char aren't same,
	bne	notSame		@ return 0

	mov	r0, SCDP	@ chars are same, ptrs different -- return 2
	b	notSame

samePtr:

	mov	r0, 1		@ chars are same, ptrs are same -- return 1

notSame:

	sub	sp, fp, FP_OFFSET	@ Epilogue - Deallocate local vars
	pop	{fp, pc}		@ Return from function
