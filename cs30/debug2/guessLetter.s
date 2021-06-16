/*
 * Filename: guessLetter.s
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines guessLetter for applying a single letter guess to the
 * 		guess buffer.
 * Date: 4/20/30
 * Sources of help: None.
 */
	.cpu	cortex-a53
	.syntax	unified

	/*** XXX: Do NOT change the CASE_*MATCH constants! ***/
	.equ	CASE_MATCH, 0x20
	.equ	CASE_MISMATCH, 0x10

	.equ	UNDERSCORE_CHAR, '_'

	.equ	FP_OFFSET, (10 - 1) * 4
	.equ	CASE_DIFF_OFFSET, 4

	.global	guessLetter
	.type	guessLetter, %function

	.text
	.align	2

/*
 * Function Name: guessLetter()
 * Function Prototype: void guessLetter(char letter, char guessBuf[],
 * 					char answerBuf[], int * count,
 * 					char * caseDiff);
 * Description: Applies a guess `letter` to the guessBuf, based on what letters
 *              are in answerBuf. The count of matched letters is saved into
 *              the address pointed to by `count`. If the guess was almost
 *              right, but off by being uppercase or lowercase, CASE_MISMATCH
 *              is saved into the address pointed to by `caseDiff`. CASE_MATCH
 *              is saved otherwise.
 * Parameters: letter    - the letter that was guessed
 *             guessBuf  - guess of the phrase so far
 *             answerBuf - the actual phrase
 *             count     - address to store number of revealed letters
 *             caseDiff  - set to CASE_MISMATCH if there was a letter in
 *                         answerBuf that did NOT match the case of `letter`,
 *                         set to CASE_MATCH otherwise
 * Side Effects: count and caseDiff are set. guessBuf may be modified.
 * Error Conditions: None.
 * Return Value: None.
 *
 * Registers used:
 * 	r4  - i		-- loop counter
 *	r5  - tmp	-- temporary char for guessBuf[i], answerBuf[i], etc
 * 	r7  - letter	-- for saving param
 * 	r8  - guessBuf	-- for saving param
 * 	r9  - answerBuf	-- for saving param
 * 	r10 - count	-- for saving param
 */
guessLetter:
	push	{r4-r10, fp, ip, lr}
	add	fp, sp, FP_OFFSET

	/* Save r0-r3. */
	mov	r7, r0
	mov	r8, r1
	mov	r9, r2
	mov	r10, r3

	/* Init *count and *caseDiff before looping guess across guessBuf. */
	mov	r5, 0
	str	r5, [r3]			@ *count = 0

	mov	r5, CASE_MATCH
	ldr	r6, [fp, CASE_DIFF_OFFSET]
	strb	r5, [r6]			@ *caseDiff = CASE_MATCH


	/* For loop over guessBuf/answerBuf. */

	mov	r4, 0				@ i = 0

	ldrb	r5, [r8, r4]
	cmp	r5, 0				@ guessBuf[i] == '\0' ?
	beq	endLoop				@ Opposite logic to branch over.

loop:
	
	/* Now check if the letter matches the character in the answer. */
	/* Only count this if the letter has not been revealed yet, AKA:
	 * 	letter == answerBuf[i] && guessBuf[i] == '_' 		*/

	ldrb	r5, [r9, r4]			@ letter == answerBuf[i] ?
	cmp	r7, r5
	bne	letterMatchElse			@ short-circuit to else

	ldrb	r5, [r8, r4]			@ guessBuf[i] == '_' ?
	cmp	r5, UNDERSCORE_CHAR
	bne	letterMatchElse			


letterMatch:

	/* If it does, then set the guessBuf[i] to the letter, */
	/* keeping count of the number of letters changed. */

	strb	r7, [r8, r4]			@ guessBuf[i] = letter
	ldr	r5, [r10]			
	add	r5, r5, 1
	str	r5, [r10]			@ ++*count

	b	letterMatchEnd

letterMatchElse:

	/* Compare uppercased versions in case we want to set caseDiff. */
	/*
	 * Only consider letters that differed from the answerBuf already, AKA:
	 *   letter == toupper(answerBuf[i]) || toupper(letter) == answerBuf[i]
	 */

	ldrb	r0, [r9, r4]
	bl	toupper				@ r0 = toupper(answerBuf[i])
	cmp	r7, r0				@ letter ==
						@ 	toupper(answerBuf[i]) ?
	beq	upperMatch			@ short-circuit to true block

	mov	r0, r7
	bl	toupper				@ r0 = toupper(letter)
	ldrb	r5, [r9, r4]			@ r5 = answerBuf[i]

	cmp	r0, r5				@ toupper(letter) ==
						@ 	answerBuf[i] ?
	bne	upperMatchEnd			@ opposite logic to skip

upperMatch:

	/* Set caseDiff to CASE_MISMATCH if letter only matches if both
	 * cases are the same (e.g. 'a' != 'A' but 'A' == 'A'). */

	mov	r5, CASE_MISMATCH
	ldr	r6, [fp, CASE_DIFF_OFFSET]
	strb	r5, [r6]			@ *caseDiff = CASE_MISMATCH

	b	upperMatchEnd

upperMatchEnd:
letterMatchEnd:

	/* End of loop, increment iterator and check. */
	
	add	r4, r4, 1			@ i++

	ldrb	r5, [r8, r4]
	cmp	r5, 0				@ guessBuf[i] == '\0' ?
	bne	loop				@ Normal logic to branch back.

endLoop:

	sub	sp, fp, FP_OFFSET
	pop	{r4-r10, fp, ip, pc}
