/* 
 * Filename:	clear.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: Turns off the bits specified by pattern0 and pattern1.
 * Date:	2.6.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	clear

	.text

	.equ	OFF_SET, 12	@ (saved regs - 1) * 4
	.equ	INT, 4		@ 4 byte per int

/* 
 * Function Name:	clear
 * Function Prototype:	void clear( unsigned int lightBank[], const unsigned
 *			int pattern0, const unsigned pattern1 )
 * Description:		1 clears the bit in lightBank;
 *			0 preserves the bit in lightBank.
 * Regs used:		r0 -- &lightBank[0]
 *			r1 -- pattern0
 *			r2 -- pattern1
 *			r3 -- store lightBank[0]
 *			r4 -- store lightBank[1]
 */
clear:
	push	{r4, fp, ip, lr}@ save regs

	add	fp, sp, OFF_SET @ set fp to base of saved regs

	mvn 	r1, r1		@ not r1, map to r1
	ldr	r3, [r0]	@ load from memory addr in r0 to r3
	and	r3, r1, r3	@ and r1 and r3, map to r3
	str	r3, [r0]	@ store from r3 to memory addr in r0
		
	mvn	r2, r2		@ not r2, map to r2
	ldr	r4, [r0, INT]	@ load from memory addr in r0 + 4 to r4
	and	r4, r2, r4	@ and r2 and r4, map to r4
	str	r4, [r0, INT]	@ store from r4 to memory addr in r0 + 4

	sub	sp, fp, OFF_SET	@ set sp above fp

	pop	{r4, fp, ip, pc}@ restore regs
