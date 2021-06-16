/* 
 * Filename:	compareAnagram.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: compareAnagram takes two const struct Anagram * and compares
 *		the anagrams that they point to. First compare the two anagram'
 *		keys. If the two keys are different, return the appropriate 
 *		result. 
 *		Returns -1 if the anagram that p1 points to either has
 *		a smaller key than does the anagram that p2 points to, or
 *		has the same key but has a smaller word than does the anagram
 *		that p2 points to
 *		Returns +1 if the anagram that p1 points to either has
 *		a larger key than does the anagram that p2 points to, or
 *		has the same key but has a larger word than does the anagram
 *		that p2 points to
 *		0 if the two anagram pointers point to equal anagrams.
 * Date:	2.21.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	compareAnagram

	.text

	.equ	OFF_SET, 12 	@ (saved regs - 1) * 4
	.equ	LEN, 40		@ 4 byte per int

/* 
 * Function Name:	compareAnagram
 * Function Prototype:	int compareAnagram( const void * p1, const void * p2 )
 * Description:		compareAnagram takes two const struct Anagram * and
 *			compares the anagrams that they point to. First compare
 *			the two anagrams' keys. If the two keys are different,
 *			return the appropriate result.
 * Regs used:		r0 -- passed in p1
 *			r1 -- passed in p2
 *			r3 -- wordOffset
 *			r4 -- p1
 *			r5 -- p2
 * Return values:	Returns -1 if the anagram that p1 points to either has
 *			a smaller key than does the anagram that p2 points to,
 *			or has the same key but has a smaller word than does 
 *			the anagram that p2 points to
 *			Returns +1 if the anagram that p1 points to either has
 *			a larger key than does the anagram that p2 points to, or
 *			has the same key but has a larger word than does the 
 *			anagram that p2 points to
 */
compareAnagram:
	push	{r4, r5, fp, lr}	@ save regs

	add	fp, sp, OFF_SET 	@ set fp to base of saved regs

	mov	r4, r0			@ map p1 to r4
	mov	r5, r1			@ map p2 to r5
		
	bl	compareKey		@ make function call to compareKey
	
	bne	end_print		@ return if key are different
	
	mov	r0, r4			@ otherwise map p1 to r0
	mov	r1, r5			@ map p2 to r1

	ldr	r3, =wordOffset		@ map wordOffset to r3
	ldr	r3, [r3]
	
	add	r0, r0, r3		@ set p1 ptr to word[0]
	add	r1, r1, r3		@ set p2 ptr to word[0]
	
	mov	r2, LEN			@ map 40 to r2		
	bl	strncmp			@ make function call to strncmp
	
	cmp	r0, 0			@ compare return value to 0
	blt	print_NEGONE		@ print -1 if rtn_val < 0
	
	cmp 	r0, 0			
	bgt	print_ONE		@ print 1 if rtn_val > 0

	b	print_ZERO		@ print 0 otherwise

print_ONE:
	mov	r0, 1			@ map 1 to r0
	b	end_print		@ branch to return

print_NEGONE:
	mov	r0, -1			@ map -1 to r0
	b	end_print		@ branch to return

print_ZERO:
	mov	r0, 0			@ map 0 to r0
	
end_print:
	sub	sp, fp, OFF_SET		@ set sp above fp

	pop	{r4, r5, fp, pc}	@ restore regs
