/* Filename:	isOdd.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: check if a numebr is odd
 * Date:	1/24/2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	TWO, 2
	.equ	ONE, 1

	.global	isOdd

	.text
	.align	2

/* Function Name:	isOdd()
 * Function Prototype:  long isOdd( long value )
 * Return:		1 if odd; 0 if even
 */

isOdd:
	push	{fp, lr}  @ Save registers

	mov	r1, TWO   

	bl	rem

	pop	{fp, pc}  @ Restore fp; restore lr into pc for return
