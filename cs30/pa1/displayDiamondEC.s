/*
 * Filename:		displayDiamond.s
 * Author:		Xinyi Bian
 * Userid:		cs30xfw
 * Description:		This assembly module will perform the actual
 *			outputting of individual characters, such 
 *			that the diamond pattern is displayed with 
 *			the user-supplied values.
 * Date:		1.30.2018
 * Source of help:	course website
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.section	.rodata

fmt:	.asciz		"%d"

	.global		displayDiamond
	.type		displayDiamond, %function

	.text
	.align		2
	.equ		FP_OFFSET, 32
	.equ		NL, '\n'
	.equ		ZERO, 0
	.equ		ONE, 1
	.equ		ROW_STEP, 2
	.equ		VERT_MARGIN, 2
	.equ		HALF_DIVISOR, 2

/* Function Name:	displayDiamond()
 * Function Prototype:	void displayDiamond( long width, long height,
 * 					char border, char diamond )
 * Description:		Print diamond according to the parameters.
 * Error Condition:	None.
 * Return Value: 	None.
 * Registers used:
 * 			r0 - arg 1 -- width
 *			r1 - arg 2 -- height
 *			r2 - arg 3 -- border
 *			r3 - arg 4 -- diamond
 */
displayDiamond:
	
	@ Save registers
	push	{r4, r5, r6, r7, r8, r9, r10, fp, lr} 
	
	@ Set fp to base of saved registers
	add	fp, sp, FP_OFFSET		 
	mov 	r4, r0		@ Pass width to r4
	mov 	r5, r1		@ Pass height to r5
	mov 	r6, r2		@ Pass border to r6
	mov 	r7, r3		@ Pass diamond to r7

@ Print the top border
	mov	r0, r4
	mov	r1, 10
	bl	numOfDigits	@ Calculate the number of digits
	mov	r10, r0

	mov	r9, ONE
	cmp	r9, r10		@ conditions to stop loop
	bgt	end_top_row_loop

top_row_loop:
	mov	r8, ONE		@ col = 1
	cmp	r8, r4		@ col <= width
	bgt	end_top_border_loop

@ Print top border of the diamond
top_border_loop:
	mov	r0, r6		@ printChar( border )
	bl	printChar	
	
	add	r8, r8, ONE	@ i++

	cmp	r8, r4		@ loop
	ble	top_border_loop
end_top_border_loop:

	add 	r9, r9, ONE

	mov 	r0, NL
	bl 	printChar	@ print new line

	cmp	r9, r10
	ble	top_row_loop
end_top_row_loop:


@ Print top half of the diamond
	mov	r8, ONE		@ row = 1
	sub	r9, r5, VERT_MARGIN
	cmp	r8, r9		@ row <= height - VERT_MARGIN
	bgt	end_top_half_diamond_loop

top_half_diamond_loop:
	mov	r9, HALF_DIVISOR
	sub	r10, r4, r8
	sdiv	r10, r10, r9	@ outer = ( width - row ) / HALF_DIVISOR
	cmp	r10, ONE	@ outer >= 1
	blt	end_top_left_border_loop

@ Print the left border chars for this row
top_left_border_loop:
	mov	r0, r6
	bl	printChar	@ printChar( border )

	sub	r10, r10, ONE	@ outer--

	cmp	r10, ONE
	bge	top_left_border_loop

end_top_left_border_loop:
	mov 	r10, ONE
	cmp	r10, r8		@ conditions to stop loop
	bgt	end_top_diamond_loop

@ Print the diamond chars for this row
top_diamond_loop:
	mov	r0, r7
	bl	printChar	@ print( diamond )  

	add 	r10, r10, ONE   @ inner++

	cmp	r10, r8
	ble	top_diamond_loop

end_top_diamond_loop:
	mov	r9, HALF_DIVISOR	
	sub	r10, r4, r8
	sdiv	r10, r10, r9	@ conditions to stop loop
	cmp	r10, ONE
	blt	end_top_right_border_loop

@ Print the right border chars for this row
top_right_border_loop:
	mov	r0, r6
	bl	printChar	@ print( border )

	sub	r10, r10, ONE   @ outer--

	cmp	r10, ONE
	bge	top_right_border_loop

end_top_right_border_loop:
	mov	r0, NL
	bl	printChar	@ print new line

	add	r8, r8, ROW_STEP
	
	sub	r9, r5, VERT_MARGIN
	cmp	r8, r9
	ble	top_half_diamond_loop

end_top_half_diamond_loop:
	mov	r8, r5
	cmp	r8, ZERO	@ conditions to stop loop
	blt	end_bottom_half_diamond_loop

@ Print bottom half of the diamond
bottom_half_diamond_loop:
	mov	r9, HALF_DIVISOR
	sub	r10, r4, r8
	sdiv	r10, r10, r9	@ conditions to stop loop
	cmp	r10, ZERO
	blt	end_bottom_left_border_loop

bottom_left_border:
	mov	r0, r6
	bl	printChar	@ printChar( border )

	sub	r10, r10, ONE	@ outer--
	
	cmp	r10, ONE
	bge	bottom_left_border
	
end_bottom_left_border_loop:
	mov	r10, ONE
	cmp	r10, r8		@ conditions to stop loop
	bgt	end_bottom_diamond_loop

@ Print the diamond chars for this row
bottom_diamond_loop:
	mov	r0, r7
	bl	printChar	@ printChar( diamond )

	add	r10, r10, ONE	@ inner++

	cmp	r10, r8
	ble	bottom_diamond_loop

end_bottom_diamond_loop:
	mov	r9, HALF_DIVISOR
	sub	r10, r4, r8
	sdiv	r10, r10, r9	@ conditions to stop loop
	cmp	r10, ONE
	blt	end_bottom_right_border_loop

@ Print the right border chars for this row
bottom_right_border_loop:
	mov	r0, r6
	bl	printChar	@ printChar( border )

	sub	r10, r10, ONE	@ outer--

	cmp	r10, ONE
	bge	bottom_right_border_loop

end_bottom_right_border_loop:
	mov	r0, NL
	bl	printChar	@ print new line

	sub	r8, r8, ROW_STEP

	cmp	r8, ZERO

	bge	bottom_half_diamond_loop

end_bottom_half_diamond_loop:
	mov	r8, ONE
	cmp	r8, r4
	bgt	end_bottom_border_loop

@ Print the bottom border
	mov 	r0, r4
	mov	r1, 10
	bl	numOfDigits
	mov	r10, r0

	mov	r9, ONE
	cmp	r9, r10
	bgt	end_bottom_row_loop

bottom_row_loop:
	mov	r8, ONE
	cmp	r8, r4
	bgt	end_bottom_border_loop

@ Print bottom half of the diamond
bottom_border_loop:
	mov	r0, r6
	bl	printChar	@ printChar( border )
	
	add	r8, r8, ONE
	cmp	r8, r4
	ble	bottom_border_loop

end_bottom_border_loop:
	add 	r9, r9, ONE

	mov	r0, NL
	bl	printChar

	cmp	r9, r10
	ble	bottom_row_loop

end_bottom_row_loop:
	sub	fp, sp, FP_OFFSET	@ Set sp to one of saved registers
	pop	{r4, r5, r6, r7, r8, r9, r10, fp, lr}	@ Restore fp, lr into pc
