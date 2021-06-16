/* File Name:	parseLong.s
 * Author:	Xinyi Bian
 * Userid: 	cs30xfw
 * Description: parseLong will parse the char * str as a long and set the int 
 *	 	that errorFlag points to if there is an error.	
 * Date:	3/4/2018
 */

	.cpu	cortex-a53
	.syntax	unified

	.section	.rodata
ERR_NOT_INT:	
	.asciz	"Error: %s could not be converted to an integer.\n"
	
	.global	parseLong
	.type	parseLong, %function
	.align	2

	.equ	FP_OFFSET, 20
	.equ	ENDPTR_OFFSET, 24
	.equ	STACK_ALLOC, 8
	.equ	BASE, 0

/* Function Name:	parseLong
 * Function Prototype:	long parseLong( char * str, int * errorFlag )
 * Desciption:		This function will parse the char * str as a long and
 *			set the int that errorFlag points to if there is an 
 *			error. If there is an error while parsing the long, 
 *			print out ERR_NOT_INT to stderr and set the int that
 *			errorFlag points to to 1.
 * Parameters:		r0 - char * str
 *			r1 - int * errorFlag
 * Regs Used:		r4 - errorFlag 
 *			r5 - return value
 *			r6 - str
 * Returns:		The long value that was parsed from str
 */
parseLong:
	push	{r4, r5, r6, r7, fp, lr}
				@ save regs
	add	fp, sp, FP_OFFSET	
				@ set fp to base of saved regs	
	sub	sp, sp, STACK_ALLOC
				@ allocate space for endptr

	mov	r6, r0		@ map str to r6
 	mov 	r4, r1		@ map errorFlag to r4
	bl	__errno_location@ acess memory addr of errno
	mov	r1, 0		@ map 0 to r0
	str	r1, [r0]	@ set errno = 0
	
	mov	r0, r6		@ map str to r0
	sub	r1, fp, ENDPTR_OFFSET
	mov	r2, BASE	@ map BASE to r2
	
	bl	strtol		@ make function call to strtol
	mov	r5, r0		@ map converted long value to r5
	ldr	r2, [fp, -ENDPTR_OFFSET]	
				@ map *endptr to r2
	ldrb	r2, [r2]
	cmp	r2, 0		@ compare *endptr to NULL
	bne	set_errorFlag	@ set errorFlag if it is not NULL

	bl	__errno_location
	ldr	r0, [r0]	@ load errno value to r6
	cmp	r0, 0		@ compare errno to 0
	bne	set_errorFlag	@ set errorFlag if error converting
	b	end

set_errorFlag:
	mov	r0, 1
	str	r0, [r4]	@ set errorFlag to 1	
	ldr	r0, =stderr	@ load addr of stderr
	ldr	r0, [r0]	@ load stderr to r0
	ldr	r1, =ERR_NOT_INT	
				@ map ERR_NOT_INT to r1
	mov	r2, r6		@ map str to r2
	bl	fprintf		@ print error message

end:
	mov	r0, r5		@ map converted long value to r0
	sub	sp, fp, FP_OFFSET	
				@ set sp above fp
	pop	{r4, r5, r6, r7, fp, pc}
				@ restore regs
