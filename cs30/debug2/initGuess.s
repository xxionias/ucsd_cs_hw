/*
 * Filename: initGuess.s
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines initGuess for initializing the guess buffer.
 * Date: 4/20/30
 * Sources of help: None.
 */
	.cpu	cortex-a53
	.syntax	unified

	.equ	NUL_CHAR, 0
	.equ	UNDERSCORE_CHAR, '_'

	.equ	FP_OFFSET, (10 - 1) * 4

	.global	initGuess
	.type	initGuess, %function

	.text
	.align	2

/*
 * Function Name: initGuess()
 * Function Prototype: void initGuess(char guessBuf[], const char answerBuf[],
 * 				      size_t len);
 * Description: Takes the string in answerBuf, replaces alphabetical characters
 * 		with underscores, and places the modified string in guessBuf.
 * Parameters: guessBuf  - guess of the phrase so far
 *             answerBuf - the actual phrase
 *             len       - length of guessBuf
 * Side Effects: guessBuf is modified.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers used:
 * 	r4 - i		-- loop counter
 * 	r5 - tmp	-- temporary
 * 	r7 - guessBuf	-- for saving param
 * 	r8 - answerBuf	-- for saving param
 * 	r9 - len	-- for saving param
 */
initGuess:
	push	{r4-r10, fp, ip, lr}	@ prologue
	add	fp, sp, FP_OFFSET

	/* Save r0-r2. */
	mov	r7, r0
	mov	r8, r1
	mov	r9, r2

	/* Copy the answer into the guess buffer. */
	/* Args are already in the right place, just copy with strncpy. */
	bl	strncpy
	sub	r5, r9, 1		@ r5 = len - 1
	mov	r0, NUL_CHAR
	strb	r0, [r7, r5]		@ nul-terminate guessBuf

	/* Loop across guessBuf, replacing alpha chars with underscores. */

	mov	r4, 0			@ i = 0
	cmp	r4, r9			@ i < len ?
	bge	endLoop			@ opposite logic to skip loop

loop:

	/* Check if guessBuf[i] is an alphabet character. */
	ldrb	r0, [r7, r4]
	bl	isalpha
	cmp	r0, 0			@ isalpha(guessBuf[i]) ?
	beq	alphaEnd		@ opposite logic to skip if

alpha:

	/* If alpha, set char to underscore. */
	mov	r0, UNDERSCORE_CHAR
	strb	r0, [r7, r4]

alphaEnd:

	add	r4, r4, 1		@ i++
	cmp	r4, r9
	blt	loop			@ forward logic to branch back

endLoop:

	sub	sp, fp, FP_OFFSET
	pop	{r4-r10, fp, ip, pc}	@ epilogue

