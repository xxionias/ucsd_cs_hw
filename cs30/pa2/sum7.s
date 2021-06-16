/* Filename:	sum7 
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: sum7 sums up the 7 parameters.
 * Date:	2/14/2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	sum7
	.type	sum7 %function

	.equ	OFF_SET, 4 	@ (saved reg - 1) * 4

/* Function Name:	sum7
 * Function Prototype:	int sum7( int a, int b, int c, int d, int e
 *					int f, int g )
 * Description:		sums up the 7 parameters
 * Return Value:	sum
 * Regs Used:		r0 -- sum
 *			r1 -- load e, f, g
 */
sum7:
	push	{fp, lr}	@ save regs
	add	fp, sp, OFF_SET @ set fp to case of saved regs
	
	add	r0, r0, r1	@ sum = a + b
	add	r0, r0, r2	@ sum = sum + c
	add	r0, r0, r3	@ sum = sum + d
	
	ldr	r1, [fp, 4]	@ map e to r1 
	add	r0, r0, r1	@ sum = sum + e
	ldr	r1, [fp, 8]	@ map f to r1
	add	r0, r0, r1	@ sum = sum + f
	ldr	r1, [fp, 12]	@ map g to r1
	add	r0, r0, r1	@ sum = sum + g

	sub	sp, fp, OFF_SET @ set sp above fp
	pop	{fp, pc}	@ restore regs

