/* 
 * Filename: 	displayLights.s
 * Author:	Xinyi Bian
 * Userid: 	cs30xfw
 * Description:	This function displays the lights based on what bits are set in
 *		the lightBank array.
 * Date:	2/11/2018
 */
 	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified
	
	.global	displayLights

	.equ	INT, 4			@ 4 byte per int
	.equ	OFF_SET, 36		@ (saved regs - 1) * 4
	.equ	NL, '\n'		@ new line character
	.equ	right_extract, 0x1	@ Extract the right most bit
	.equ	left_extract, 0x80000000@ Extract the left most bit
	.equ	asterisk, 0x2A		@ ascii # of asterisk
	.equ	hyphen, 0x2D		@ ascii # of hyphen
	.equ	space, 0x20		@ ascii # of space
	.equ	LEN, 32			@ 32 bits per lightBank element
/* Function name:	displayLights
 * Function prototype:	void displayLights( const unsigned int lightBank[] )
 * Description:		Print out the char "*" if bit is on and char "-" if bit
 *			is off.
 * Parameter:		lightBank array
 * Registers used:	r0 -- &lightBank[0]
 *			r4 -- loop counter
 *			r5 -- bit extractor
 *			r6 -- determine the bit is 0 or 1 
 *			r7 -- store lightBank[0]
 *			r8 -- store lightBank[1]
 *			r9 -- counter for displaying space
 */
displayLights:
 	push 	{r4, r5, r6, r7, r8, r9, fp, lr}
					@ save regs
	
	add	fp, sp, OFF_SET		@ set fp to base of saved regs

	ldr	r7, [r0]		@ load from memory addr in r0 to r7
	ldr	r8, [r0, INT]		@ load form memory addr in r0 + 4 to r8
        
	mov	r5, left_extract	@ mao 0x80000000 to r5
	mov	r9, 1			@ map 1 to r9
	mov	r4, 1			@ map 1 to r4
	cmp	r4, LEN			@ compare r4 to 32, end first loop when
	bgt	end_first_loop		@ r4 > 32

first_loop:
	and 	r6, r5, r7		@ store the bit of lightBank[0]
	cmp	r6, 0			@ determine if the bit is 0 or 1
	beq	p_f_hyphen		@ print hyphen if bit is 0

p_f_asterisk:
	mov	r0, asterisk		@ map asterisk char to r0
	bl	printChar		@ make function call to printChar
	b	end_p_f_hyphen		@ branch to end_p_f_hyphen

p_f_hyphen:				
	mov	r0, hyphen		@ map hyphen char to r0
	bl	printChar		@ make function call to printChar

end_p_f_hyphen:
	cmp	r9, INT			@ determine if 4 bits have already 
					@ displayed
	bne	end_p_f_space

p_f_space:
	mov	r0, space		@ map space char to r0
	bl	printChar		@ make function call to printChar
	mov	r9, 1			@ reset r9 to 1
	b	not_add_f_one		@ avoid adding 1 to r9

end_p_f_space:
	add	r9, r9, 1		@ counter for displaying space++

not_add_f_one:
	lsr	r5, r5, 1		@ shift the bit to extract 
	add	r4, r4, 1		@ counter++
	cmp	r4, LEN			@ first_loop when r4 <= 32
	ble	first_loop		
	
end_first_loop:
	mov	r9, 1			@ reset counter for displaying space
	mov	r5, left_extract	@ reset bit extractor
	mov	r4, 1			@ reset counter
	cmp	r4, LEN			@ compare r4 to 32, end second loop
	bgt	end_second_loop		@ when r4 > 32

second_loop:
	and 	r6, r5, r8		@ store the bit of lightBank[1]
	cmp	r6, 0			@ determine if the bit is 0 or 1
	beq	p_s_hyphen		@ print hyphen if bit is 0

p_s_asterisk:
	mov	r0, asterisk		@ map asterisk to r8
	bl	printChar		@ make function call to printChar
	b	end_p_s_hyphen		@ branch to end_p_s_hyphen

p_s_hyphen:
	mov	r0, hyphen		@ map hyphen char to r0
	bl	printChar		@ make function call to printChar

end_p_s_hyphen:
	cmp	r9, INT			@ determine if 4 bits have already
	bne	end_p_s_space		@ displayed

p_s_space:
	mov	r0, space		@ map space char to r0
	bl	printChar		@ make function call to printChar
	mov	r9, 1			@ reset r9 to 1
	b	not_add_s_one		@ avoid adding 1 to r9

end_p_s_space:
	add	r9, r9, 1		@ counter for displaying space++

not_add_s_one:	
	lsr	r5, r5, 1		@ shift the bit to extract
	add	r4, r4, 1		@ counter++
	cmp	r4, LEN			@ second_loop when r4 <= 32
	ble	second_loop

end_second_loop:
	mov	r0, NL			@ print new line after two loops
	bl	printChar		@ make function call to printChar

	sub	sp, fp, OFF_SET		@ set sp above fp
	pop	{r4, r5, r6, r7, r8, r9, fp, pc}
					@ restore regs
