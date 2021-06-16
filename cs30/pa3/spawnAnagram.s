/* 
 * Filename:	spawnAnagram.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: spawnAnagram spawns an anagram by filling out its fields based
 *		on the originalWord.
 * Date:	2.21.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	spawnAnagram

	.text

	.equ	OFF_SET, 20	@ (saved regs - 1) * 4
	.equ	LEN, 40		@ max 40 byte per string

/* 
 * Function Name:	spawnAnagram
 * Function Prototype:	void spawnAnagram( char const * original Word, struct
 *					Anagram * anagram );
 * Description:		This function spawns an anagram by filling out its 
 *			field based on the originalWord. This function should
 *			copy originalWord into the anagram's word field, and 
 *			also spawn a key that correspondes to originalWord 
 *			which will populate the key field of the anagram.
 * Regs used:		r0 -- passed in originalWord
 *			r1 -- passed in anagram
 *			r4 -- originalWord
 *			r5 -- anagram
 *			r6 -- keyOffset
 *			r7 -- wordOffset
 */
spawnAnagram:
	push	{r4, r5, r6, r7, fp, lr}@ save regs

	add	fp, sp, OFF_SET 	@ set fp to base of saved regs
	
	ldr 	r6, =keyOffset		@ load keyOffset to r6 
	ldr	r6, [r6]
	
	ldr	r7, =wordOffset		@ load wordOffset to r7
	ldr	r7, [r7]
	
	mov	r4, r0			@ map originalWord to r4
	mov	r5, r1			@ map anagram to r5
	add	r1, r1, r7		@ set ptr to word[0]
	mov	r0, r1			@ map ptr to r0
	mov	r1, r4			@ map originalWord to r1
	mov	r2, LEN			@ map 40 to r2
	bl	strncpy			@ make function call to strncpy
	
	mov	r0, r5			@ map anagram to r0
	add	r0, r0, r6		@ set ptr to key[0]
	sub	r0, r0, 1  		@ set ptr to word[39]
	mov	r1, 0			@ map null character to r1
	strb	r1, [r0]		@ null terminate word[39]
	
	mov	r0, r5			@ map anagram to r0
	add	r0, r0, r6		@ set ptr to key[0]
	mov	r1, r4			@ map orignalWord to r1
	mov	r2, LEN			@ map 40 to r2		
	bl 	spawnKey		@ make function call to spawnKey
	
	sub	sp, fp, OFF_SET		@ set sp above fp

	pop	{r4, r5, r6, r7, fp, pc}@ restore regs
