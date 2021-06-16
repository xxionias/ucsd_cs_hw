/* 
 * Filename:	compareKey.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: compareKey takes two const struct Anagram * and compares that
 *		the anagrams that they point to by key. It returns -1 if the 
 *		anagram that p1 points to has a smaller key than the anagram
 *		that p2 points to; returns +1 the when larger; returns 0 
 *		otherwise.
 * Date:	2.21.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	compareKey

	.text

	.equ	OFF_SET, 4	@ (saved regs - 1) * 4
	.equ	LEN, 40		@ max 40 byte per string

/* 
 * Function Name:	compareKey
 * Function Prototype:	int compareKey( const void * p1, const void * p2 )
 * Description:		This function takes two const struct Anagram * and
 *			compares the anagrams that they point to by key.
 * Regs used:		r0 -- passed in p1
 *			r1 -- passed in p2
 *			r2 -- keyOffset
 * Return values:	-1 if the anagram that p1 points to has a smaller
 *			key than the anagram that p2 points to;
 *			+1 if the anagram that p1 points to has a larger
 *			key than the anagram that p2 points to;
 *			0 if the two anagram pointers point to anagrams 
 *			with teh same key.	
 */
compareKey:
	push	{fp, lr}	@ save regs

	add	fp, sp, OFF_SET @ set fp to base of saved regs
	
	ldr	r3, =keyOffset	@ map keyOffset to r3
	ldr	r3, [r3]
	add	r0, r0, r3	@ set p1 ptr to key[0]
	add	r1, r1, r3	@ set p2 ptr to key[0]
	
	mov	r2, LEN		@ map 40 to r2
	bl	strncmp		@ make function call to strncmp
	
	cmp	r0, 0		@ compare return value to 0
	blt	rtn_NEGONE	@ print -1 if return value < 0
	
	cmp	r0, 0
	bgt	rtn_ONE		@ print 1 if return value > 0

	mov	r0, 0		@ print 0 otherwise
	b	rtn		@ branch to return 
	
rtn_NEGONE:
	mov	r0, -1		@ map -1 to r0
	b	rtn		@ branch to return
	
rtn_ONE:
	mov	r0, 1		@ map 1 to r0
	
rtn:	
	sub	sp, fp, OFF_SET	@ set sp above fp

	pop	{fp, pc}	@ restore regs
