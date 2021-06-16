/* 
 * Filename:	compareChar.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: compareChar takes two const char * and compares the char that
 *		tach points to in reverse alphabetical order.
 * Date:	2.21.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	compareChar

	.text

	.equ	OFF_SET, 4	@ (saved regs - 1) * 4

/* 
 * Function Name:	compareChar
 * Function Prototype:	int compareChar( const void * p1, const void * p2 )
 * Description:		This function takes two const char * and compares the
 *			vhar that each points to in reverse alphabetical order.
 * Regs used:		r0 -- passed in p1
 *			r1 -- passed in p2
 *			r2 -- char p1 pointed to
 *			r3 -- char p2 pointed to
 * Returns:		-1 if the char that p1 points to should be ordered
 *			earlier than the char that p2 points to;
 *			+1 if the char that p1 points to should be ordered
 *			later than the char that p2 points to;
 *			0 if the two char pointers point to the same char.
 */
compareChar:
	push	{fp, lr}	@ save regs

	add	fp, sp, OFF_SET @ set fp to base of saved regs

	ldrb	r2, [r0]	@ map the char p1 pointed to r2
	ldrb	r3, [r1]	@ map the char p2 pointed to r3
	
	cmp	r2, r3		@ compare two chars
	blt	print_ONE	@ print 1 if p1 char is before p2 char
	
	cmp 	r2, r3
	bgt	print_NEGONE	@ print -1 if p2 char is before p1 char

	b	print_ZERO	@ print 0 if two char is the same

print_ONE:
	mov	r0, 1		@ map 1 to r0
	b	end_print	@ branch to end_print

print_NEGONE:
	mov	r0, -1		@ map -1 to r0
	b	end_print	@ branch to end_print

print_ZERO:
	mov	r0, 0		@ map 0 to r0
		
end_print:
			
	sub	sp, fp, OFF_SET	@ set sp above fp

	pop	{fp, pc}	@ restore regs
