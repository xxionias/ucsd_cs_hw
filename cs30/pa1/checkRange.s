/*
 * Filename:    checkRange.s
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: check if a number is between a range, inclusive
 * Date:	1/24/2018
 */
	.cpu	cortex-a53	
	.syntax	unified

	.global	checkRange
	.equ	ZERO, 0
	.equ 	ONE, 1
	.equ	NEGONE, -1
	.text
	.align	2

/*
 * Function Name:       checkRange()
 * Function Prototype:	long checkRange(long value, long minRange, long maxRange)
 * Description:		check a number if inside a range
 * Return:		return -1 if error;
 *			return 1 if in the range;
 *			return 0 if not in the range
 */

checkRange:
	
	push	{fp, lr} @ Save registers
	
	cmp	r2, r1   @ Check if the range parameter is reasonable
	blt	end_if

	cmp	r0, r1	 @ check if value is larger or equal to minRange
	blt	else

	cmp 	r2, r0   @ check if value is smaller or equal to maxRange
	blt	else
	
	mov	r0, ONE
	b	end_if_else

end_if:
	mov 	r0, NEGONE
	b	end_if_else
else:
	mov 	r0, ZERO

end_if_else:


	pop	{fp, pc} @ restore fp; restore lr into pc for return
