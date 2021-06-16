/* 
 * Filename: 	displayLightsEC.s
 * Author:	Xinyi Bian
 * Userid: 	cs30xfw
 * Description:	This function displays the lights based on what bits are set in
 *		the lightBank array.
 * Date:	2/13/2018
 */
 	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified
	
	.global	displayLightsEC

	.equ	INT, 4			@ 4 byte per int
	.equ	OFF_SET, 36		@ (saved regs - 1) * 4
	.equ	NL, '\n'		@ new line character
	.equ	right_extract, 0x1	@ Extract the right most bit
	.equ	left_extract, 0x80000000@ Extract the left most bit
	.equ	LEN, 32			@ 32 bits per lightBank element

/* Function name:	displayLightsEC
 * Function prototype:	void displayLightsEC( const unsigned int lightBank[], 
 *					char onChar, char offChar )
 * Description:		Print out the onChar if bit is on and offChar if bit
 *			is off.
 * Parameter:		lightBank[]
 * Registers used:	r0 -- &lightBank[0
 *			r1 -- on_char
 *			r2 -- off_char
 *			r4 -- counter
 *			r5 -- bit extractor
 *			r6 -- determine the bit is 0 or 1			
 *			r7 -- lightBank[0]
 *		 	r8 -- lightBank[1]
 *			r9 -- on_char
 *			r10- -off_char
 */
displayLightsEC:
 	push 	{r4, r5, r6, r7, r8, r9, r10, fp, ip, lr}
					@ save regs	
	add	fp, sp, OFF_SET		@ set fp to base of saved regs
	
	mov	r9, r1			@ map on_char to r9
	mov	r10, r2			@ map off_char to r10
	ldr	r7, [r0]		@ load from memory addr in r0 to r7
	ldr	r8, [r0, INT]		@ load from memory addr in r0 + 4 to r8
        
	mov	r5, left_extract	@ map 0x80000000 to r5
	mov	r4, 1			@ map 1 to r4
	cmp	r4, LEN			@ compare r4 to 32, end first loop when
	bgt	end_first_loop		@ r4 > 32

first_loop:
	and 	r6, r5, r7		@ store the bit of lightBank[0]
	cmp	r6, 0			@ determine if the bit is 0 or 1
	beq	p_f_off			@ print off_char if bit is 0

p_f_on:
	mov	r0, r9			@ map on_char to r0
	bl	printChar		@ make function call to printChar
	b	end_p_f_off		@ branch to end_p_f_off

p_f_off:
	mov	r0, r10			@ map off_char to r0
	bl	printChar		@ make function call to printChar

end_p_f_off:
	lsr	r5, r5, 1		@ shift the bit to extract
	add	r4, r4, 1		@ counter++
	cmp	r4, LEN			@ first_loop when r4 <= 32			
	ble	first_loop
	
end_first_loop:
	mov	r5, left_extract	@ reset bit extractor
	mov	r4, 1			@ reset counter for displaying space
	cmp	r4, LEN			@ compare r4 to 32, end second loop
	bgt	end_second_loop		@ when r4 > 32

second_loop:	
	and 	r6, r5, r8		@ store the bit of lightBank[1]
	cmp	r6, 0			@ determine if the bit is 0 or 1
	beq	p_s_off			@ print off_char if bit is 0

p_s_on:
	mov	r0, r9			@ map on_char to r0
	bl	printChar		@ make funcion call to printChar
	b	end_p_s_off		@ branch to end_p_s_off

p_s_off:
	mov	r0, r10			@ map off_char to r0
	bl	printChar		@ make function call to printChar

end_p_s_off:
	lsr	r5, r5, 1		@ shift the bit to extract
	add	r4, r4, 1		@ counter++
	cmp	r4, LEN			@ second_loop when r4 <= 32
	ble	second_loop

end_second_loop:
	mov	r0, NL			@ print new line after two loops
	bl	printChar		@ make function call to printChar

	sub	sp, fp, OFF_SET		@ set sp above fp
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, ip, pc}
					@ restore regs
