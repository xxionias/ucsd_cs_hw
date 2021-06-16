/* Filename:	summain.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: summain is responsible for setting up the local variables,
 *		calling sum7(), then setting up and executing the call to
 *		printf() to output the result of the sum.
 * Date:	2/14/2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.data

	.equ	OFF_SET, 4	@ (saved reg - 1) * 4
	.equ	TWO, 2
	.equ	THR, 3
	.equ	FOU, 4
	.equ	FIV, 5
	.equ	SIX, 6
	.equ	SEV, 7
	.equ	SXT, 16
	.equ	FE, 48
	.equ	NE, -8
	.equ	NT, -12
 	.equ	NS, -16
	.equ	NTY, -20
	.equ	NTF, -24
	.equ	NTE, -28
	.equ	NTT, -32
	.equ	NTS, -36
	.equ	NF, -40
	.equ	NFF, -44
	.equ	NFE, -48
	.equ	NFT, -52
	
fmt:	.asciz	"Sum of %d %d %d %d %d %d %d = %d\n"
	
	.global	main
	.type	main, %function

	.text
	.align	2

/* Function Name:	main
 * Function Prototype:  int main( void )
 * Description:		main sets up local variables as parameters to pass in
 *			for sum7.s
 * Return Value:	sum of the numbers
 * Regs used:		r0 -- store extra variables other than 1-4 
 */
main:
	push	{fp, lr}	@ save regs
	add	fp, sp, OFF_SET @ set fp to case of saved regs

	sub	sp, sp, FE	@ allocate memory 
	
	mov	r0, FIV		@ map 5 to r0
	str	r0, [fp, NTF]	@ store 5 in fp  - 24
	str	r0, [fp, NFT]	@ store 5 in fp  - 52
	
	mov	r0, SIX		@ map 6 to r0
	str	r0, [fp, NTE]	@ store 6 in fp - 28
	str	r0, [fp, NFE]	@ store 6 in fp - 48
	
	mov	r0, SEV		@ map 7 to r0
	str	r0, [fp, NTT]	@ store 7 in fp - 32
	str	r0, [fp, NFF]	@ store 7 in fp - 44
	
	mov	r0, 1		@ map 1 to r0
	str	r0, [fp, NE]	@ store 1 in fp - 8

	mov	r1, TWO		@ map 2 to r1
	str	r1, [fp, NT] 	@ store 2 in fp - 12

	mov	r2, THR		@ map 3 to r2
	str	r2, [fp, NS]	@ store 3 in fp - 16

	mov	r3, FOU		@ map 4 to r3
	str	r3, [fp, NTY]	@ store 4 in fp - 20
	bl	sum7		@ make function call to sum7
	
	str	r0, [fp, NTS]	@ store sum in fp - 36

	add	sp, sp, SXT	@ deallocate memory
	sub	sp, sp, SXT	@ allocate memory

	mov	r0, FOU		@ map 4 to r0
	str	r0, [fp, NFT]	@ store 4 in fp - 50

	mov	r0, FIV		@ map 5 to r0
	str	r0, [fp, NFE]	@ store 5 in fp - 48

	mov	r0, SIX		@ map 6 to r0
	str	r0, [fp, NFF]	@ store 6 in fp - 44

	mov	r0, SEV		@ map 7 to r0
	str	r0, [fp, NF]	@ store 7 in fp - 40
 
	mov	r1, 1		@ map 1 to r1
	mov	r2, TWO		@ map 2 to r2
	mov	r3, THR		@ map 3 to r3
	ldr	r0, =fmt	@ call printf
	bl	printf
	
	mov	r0, 0		@ return 0

	sub	sp, fp, OFF_SET	@ set sp above fp

	pop	{fp, pc}	@ restore regs
