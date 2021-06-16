/*
 * Filename:    rem.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: calculate the remainder
 * Date:	1/24/2018
 */
	.cpu	cortex-a53
	.syntax	unified

	.global	rem

	.text
	.align	2

/*
 * Function Name:          rem
 * Function Prototype:	   long rem( long dividend, long divisor )
 * Description:		   return the remainder
 * Register Used:	   r0 -- dividend
 			   r1 -- divisor
			   r2 -- quotient
			   r3 -- product of r1 and r2
			   r4 -- remainder
*/

rem:
	push	{fp, lr}   @ save registers: fp, lr

	sdiv	r2, r0, r1 @ r2 = r0 / r1
	mul	r3, r2, r1 @ r3 = r2 * r1
	sub	r4, r0, r3 @ r4 = r0 - r3

	mov	r0, r4	   @ r0 = r4
	
	pop	{fp, pc}   @ Restore fp; restore lr into pc for return
