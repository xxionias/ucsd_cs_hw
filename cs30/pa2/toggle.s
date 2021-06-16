/* 
 * Filename:	toggle.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: Toggles the bits specified by pattern0 and pattern1.
 * Date:	2.6.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	toggle

	.text
	
	.equ	OFF_SET, 12	@ (saved regs - 1) * 4
	.equ	INT, 4		@ 4 byte per int

/* 
 * Function Name:	toggle
 * Function Prototype:	void toggle( unsigned int lightBank[], const
 * 			unsigned int pattern0, const unsigned int pattern1 )
 * Description:		1 toggles the bit in lightBank;
 *			0 preserves the bit in lightBank.
 * Regs Used:		r0 -- &lightBank[0]
 *			r1 -- pattern0
 *			r2 -- pattern1
 *			r3 -- store lightBank[0]
 *			r4 -- store lightBank[1]
 */
toggle:	
	push	{r4, fp, ip, lr}@ save regs
	
	add	fp, sp, OFF_SET	@ set fp to base of saved regs

	ldr	r3, [r0]	@ load from memory addr in r0 to r3
	eor	r3, r1, r3	@ exclusive or r1 and r3, map to r3
	str	r3, [r0]	@ store from r3 to memory addr in r0

	ldr	r4, [r0, INT]	@ load from memory addr in r0 + 4 to r4
	eor	r4, r2, r4	@ exclusive or r2 and r4, map to r4
	str	r4, [r0, INT]	@ store from r4 to memory addr in r0 + 4

	sub	sp, fp, OFF_SET	@ set so above fp

	pop	{r4, fp, ip, pc}@ restore regs
