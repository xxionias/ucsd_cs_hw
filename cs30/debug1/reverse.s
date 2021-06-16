/*
 * Filename: reverse.s
 * Description: Assembly function that reverses the characters of a string
 *              and determines whether the string was a palindrome.
 */ 
	.cpu	cortex-a53
	.syntax unified

	.section	.rodata
palStr:
	.asciz	"PALINDROME!\n"

	.global	reverse
	.type	reverse, %function
	.align	2
	.equ	FP_OFFSET, (6 - 1) * 4	@ (# of saved regs - 1) * 4
	.equ	ENDPTR_OFFSET, 24
	.equ	STACK_ALLOC, 8

/*
 * Function name: reverse()
 * Function prototype: int reverse(char* str)
 * Description: Takes in a char*, finds the end of the string, and traverses
 *              the string, swapping characters. At the end, if all swapped
 *              characters matched, returns 1 to indicate it was a palindrome.
 * Parameters: r0 - string to reverse
 * Side Effects: Prints message if the string is a palindrome
 * Return Value: 0 indicating string not a palindrome
 *               1 indicating string is a palindrome
 * Registers Used: r3 - strLength
 *                 r4 - swapChars return value
 *                 r5 - startPtr
 *                 r6 - endPtr
 */
reverse:

	push	{r4-r7, fp, lr}		@ Prologue
	add	fp, sp, FP_OFFSET
	sub	sp, sp, STACK_ALLOC	@ allocate space for local var endPtr

	mov	r5, r0		@ save startPtr before call
	/* Find length of str and ptr to last char */
	@ ptr to string as first arg to findEnd -- already in r0
	ldr	r1, [fp, -ENDPTR_OFFSET]	@ pass in address of endPtr
	bl	findEnd				@ as 2nd arg

	mov	r7, r0				@ strLength (counter) init to 0
	ldr	r6, [fp, -ENDPTR_OFFSET]	@ grab pointer addr from endPtr
	ldr	r6, [r6]
	cmp	r5, r6		@ while startPtr <= endPtr, swap chars
	bgt	endSwapLoop

swapLoop:

	mov	r0, r5		@ startPtr as first arg to swapChars
	mov	r1, r6		@ endPtr as second arg to swapChars, then swap!
	bl	swapChars	@ swap 'em!

	mov	r4, r0		@ number of chars that were the same
	sub	r7, r7, r4	@ subtract number of same chars from strLength

	add	r5, r5, 1	@ increment startPtr
	add	r6, r6, -1	@ decrement endPtr

	cmp	r5, r6		@ while startPtr <= endPtr, swap chars
	ble	swapLoop

endSwapLoop:

	cmp	r7, 0		@ if strLength == 0,
	bne	notPalindrome	@ then all chars were matched

	ldr	r0, =palStr	@ We found a palindrome!
	bl	printf		@ Print out our wonderful find

	mov	r0, 1		@ Since palindrome found, return 1
	b	end

notPalindrome:

	mov	r0, 0		@ not palindrome, return 0

end:

	sub	sp, fp, FP_OFFSET	@ Epilogue - deallocate local vars
	pop	{r4-r7, fp, pc}		@ Return from function

