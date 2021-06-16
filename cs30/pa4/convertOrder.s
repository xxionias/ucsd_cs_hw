/* File Name:	convertOrder.s
 * Author:	Xinyi Bian
 * Userid: 	cs30xfw
 * Description:	convertOrder will convert the endianness of the byte sequence
 *		pointed to by the argument.
 * Date:	3/4/2018
 */

	.cpu	cortex-a53
	.syntax	unified
	.global	convertOrder

	.equ	FP_OFFSET, 4
	.equ	SECCHAR_OFFSET, 2
	.equ	THRCHAR_OFFSET, 3

/* Function Name:	convertOrder
 * Function Prototype:	void convertOrder( unsigned char * toConvert )
 * Desciption:		This function will convert the endianness of the byte
 *			sequence pointed to by the argument. Swap the first 
 *			byte with the last byte, and swap the second byte with
 *			the third byte.
 * Parameters:		r0 - *char
 * Regs Used:		r1 - swap char
 *			r2 - swap char
 * Return Value:	None
 */
convertOrder:
	push	{fp, lr}	@ save regs
	add	fp, sp, FP_OFFSET	
				@ set fp to base of saved regs
	ldrb	r1, [r0]	@ load first char to r1
	ldrb	r2, [r0, THRCHAR_OFFSET]	
				@ load fourth char to r2
	strb	r1, [r0, THRCHAR_OFFSET]	
				@ store first char to fourth char
	strb	r2, [r0]	@ store fourth char to first char

	ldrb	r1, [r0, 1]
				@ load second char to r1
	ldrb	r2, [r0, SECCHAR_OFFSET]
				@ load third char to r2
	strb	r1, [r0, SECCHAR_OFFSET]
				@ store second char to third char
	strb	r2, [r0, 1]
				@ store third char to second char
 
	sub	sp, fp, FP_OFFSET	
				@ set sp above fp
	pop	{fp, pc}	@ restore regs
