/* 
 * Filename:	printUsage.s
 * Author:	Xinyi Bian
 * Userid:	cs30xfw
 * Description: printUsage prints usageStr to the provided file stream, filling
 *		usageStr's format specifier with progName.
 * Date:	2.25.2018
 */
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.global	printUsage

	.text

	.equ	OFF_SET, 4	@ (saved regs - 1) * 4

/* 
 * Function Name:	printUsage
 * Function Prototype:	void printUsage( FILE * stream, const char * const 
 *				usageStr, const char * const progName )
 * Description:		This function prints usageStr to the provided file 
 *			stream, filling usageStr's format specifier with
 *			progName.
 * Regs used:		r0 -- FILE * stream
 *			r1 -- const char * const usageStr
 *			r2 -- const char * const progName
 * Returns:		None
 */
printUsage:
	push	{fp, lr}	@ save regs

	add	fp, sp, OFF_SET @ set fp to base of saved regs
	
	bl	fprintf

	sub	sp, fp, OFF_SET	@ set sp above fp

	pop	{fp, pc}	@ restore regs
