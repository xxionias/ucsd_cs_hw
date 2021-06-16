/* 
 * Filename:	ripple.s
 * Author:	Xinyi Bian
 * Userid: 	cs30xfw
 * Description: Rotate the entire lightBank by rippleCnt bits displaying the 
 *		light banks after each single bit rotate.
 * Date:	2/11/2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	ripple

	.text

	.equ	OFF_SET, 20		@ (saved regs - 1) * 4
	.equ	INT, 4			@ 4 byte per int
	.equ	right_extract, 0x00000001
	.equ	left_extract, 0x80000000
	.equ	shift_index, 31

/* 
 * Function Name:	ripple
 * Function Prototype:  void ripple( unsigned int lightBank[], 
 *					const int rippleCnt );
 * Description:		if rippleCnt is positive, rotate right;
 *			if rippleCnt is negative, rotate left.
 * Regs Used:		r0 -- &lightBank[0]
 *			r1 -- rippleCnt
 *			r4 -- store &lightBank[0]
 *			r5 -- store rippleCnt
 *			r6 -- counter
 */
ripple:	
	push	{r4, r5, r6, fp, ip, lr}
					@ save regs

	add	fp, sp, OFF_SET		@ set fp to base of saved regs
	

	mov 	r4, r0			@ map &lightBank[0] to r4
	mov	r5, r1			@ map rippleCnt to r5
	cmp	r5, 0			@ branch if rotateCnt is positive
	blt	else	
		
	cmp	r5, 0
	bne	not_p

p:
	bl	displayLights	
			
not_p:
	mov	r6, 1			@ counter set to 1
	cmp	r6, r5			@ end loop if counter > rippleCnt
	bgt 	end_pos_loop

pos_loop:
	mov	r1, 1			@ set rotateCnt to 1
	mov	r0, r4			@ initialize lightBank for rotate
	bl 	rotate			@ make function call to rotate
	
	mov	r4, r0			@ map the changed lightBank to r4
	
	bl	displayLights		@ make function call to displayLights

	add	r6, r6, 1		@ counter++
	cmp	r6, r5			@ loop if counter <=  rippleCnt
	ble	pos_loop

end_pos_loop:
	b	end_if			@ Go to the end

else:
	mov	r6, -1			@ counter set to -1
	cmp	r6, r5			@ end loop if 	
	blt	end_neg_loop

neg_loop:
	mov	r1, -1			@ set rotateCnt to -1
	mov	r0, r4			@ initialize lightBank for rotate
	bl	rotate			@ make function call to rotate
	
	mov	r4, r0			@ map the changed lightBank to r4
	
	bl	displayLights		@ make function call to displayLights
	
	sub	r6, r6, 1		@ counter--
	cmp	r6, r5			@ loop if counter >= rippleCnt
	bge	neg_loop

end_neg_loop:

end_if:
	
	sub	sp, fp, OFF_SET		@ set sp above fp
	pop	{r4, r5, r6, fp, ip, pc}
					@ restore regs
