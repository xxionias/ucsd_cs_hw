/* 
 * Filename:	shift.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: Shifts the entire lightBank by shiftCnt bits.
 * Date:	2.6.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	shift

	.text

	.equ	OFF_SET, 12		@ (saved regs - 1) * 4
	.equ	INT, 4			@ 4 byte per int
	.equ	right_extract, 0x1	@ Extract the right most bit
	.equ	left_extract, 0x80000000@ Extract the left most bit
	.equ	shift_index, 31		@ 32 bits - 1
	.equ	lower_byte, 0x3f	@ Extract the lower 6 bits

/* 
 * Function Name:	shift
 * Function Prototype:	void shift( unsigned int lightBank[], const
 *				int shiftCnt );
 * Description:		if shiftCnt is positive, shift right;
 *			if shiftCnt is negative, shift left.
 * Regs Used:		r0 -- &lightBank[0]
 *			r1 -- shiftCnt
 *			r2 -- store lightBank[0]
 *			r3 -- store lightBank[1]
 *			r4 -- extract bit
 *			r5 -- loop counter
 */
shift:	
	push	{r4, r5, fp, lr}	@ save regs

	add	fp, sp, OFF_SET 	@ set fp to base of savad regs

	ldr	r2, [r0]		@ load from memory addr in r0 to r2
	ldr	r3, [r0, INT]		@ load from memory addr in r0 + 4 to r3
	
	cmp	r1, 0			@ branch if shiftCnt is positive
	ble	else

	and	r1, r1, lower_byte	@ only consider the lower 6 bits 
	mov	r5, 0			@ counter set to 0
	cmp	r5, r1			@ end loop if counter >= shiftCnt
	bge 	end_pos_loop

pos_loop:
	lsr	r3, r3, 1		@ first shift lightBank[1] right 1 bit
	and	r4, r2, right_extract	@ extract the right most bit from 
					@ lightBank[0]
	lsl	r4, r4, shift_index	@ shift the extracted bit to the most 
					@ left
	lsr	r2, r2, 1		@ shift lightBank[0] right 1 bit
	add	r3, r3, r4		@ add extracted bit to lightBank[1]

	add	r5, r5, 1		@ counter++
	cmp	r5, r1			@ loop if counter < shiftCnt 
	blt	pos_loop

end_pos_loop:
	b	end_if			@ Go to the end

else:	
	mvn	r1, r1			@ Invert r1
	add	r1, r1, 1		@ 2's comp
	and 	r1, r1, lower_byte	@ only consider the lower 6 bits
	mov	r5, 0			@ counter set to 0
	cmp	r5, r1			@ end loop if counter >= shiftCnt
	bge	end_neg_loop

neg_loop:
	lsl	r2, r2, 1		@ first shift lightBank[0] left 1 bit
	and	r4, r3, left_extract	@ extract the left most bit from 
					@ lightBank[1]
	lsr	r4, r4, shift_index	@ shift the extracted bit to the most 
					@ right
	lsl	r3, r3, 1		@ shift lightBank[1] left 1 bit
	add	r2, r2, r4		@ add extracted bit to lightBank[0]

	add	r5, r5, 1		@ counter++
	cmp	r5, r1			@ loop if counter < shiftCnt
	blt	neg_loop

end_neg_loop:

end_if:
	
	str	r2, [r0]		@ store from memory addr in r2 to r0

	str 	r3, [r0, INT]		@ store from memory addr in r3 to r0 + 4

	sub	sp, fp, OFF_SET		@ set sp above fp
	pop	{r4, r5, fp, pc}	@ retore regs
