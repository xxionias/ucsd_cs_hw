/*
 * Filename: findEnd.s
 * Description: Assembly function that traverses a string and returns the
 *              length of the string and stores a pointer to the last char.
 */ 
	.cpu	cortex-a53
	.syntax unified

	.global	findEnd
	.type	findEnd, %function

	.text
	.align	2

	.equ	FP_OFFSET, 20	@ (# of saved regs - 1) * 4

/*
 * Function name: findEnd()
 * Function prototype: int findEnd(char* str, char** endPtr)
 * Description: Takes in a string and a char**.  Traverses string until it
 *              finds the null character.  Stores pointer to the last char
 *              of the string in the endPtr parameter. Returns strLength.
 * Parameters: r0 - string to find length of
 *             r1 - char** endPtr, to store ptr to last char, for use in
 *                   calling function
 *             r4 - strLength: calculate length of string
 *             r5 - endChar: last char in str
 *             r6 - currChar: used to find endChar (in loop)
 * Side Effects: Stores ptr to last char of str in char** endPtr
 * Return Value: length of string
 */

findEnd:

	push	{r4-r7, fp, lr}		@ Prologue
	add	fp, sp, FP_OFFSET	@ Set fp to bottom of the saved regs

	mov	r4, 0		@ strLength (counter) init to 0
	mov	r5, r0		@ endChar = str

	ldrb	r6, [r0]	@ Get 1st char of str

	cmp	r6, 0		@ if *str == '\0', this is empty string
	beq	emptyStr	@ so skip loop

checkChar:

	add	r0, r0, 1	@ increment str to look at next char
	add	r4, r4, 1	@ increment strLength

	add	r5, r0, -1	@ adjust str to point back to last char
	ldrb	r6, [r0]	@ Get next char of str

	cmp	r6, 0		@ if *str == '\0', end loop
	bne	checkChar	@ otherwise, positive logic branch back


emptyStr:

	str	r5, [r1]	@ store ptr to last char
	mov	r0, r4		@ return strLength

	sub	sp, fp, FP_OFFSET	@ Epilogue - Deallocate local vars
	pop	{r4-r7, fp, pc}		@ Return from function

