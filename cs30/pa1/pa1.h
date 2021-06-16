/*
 * File: pa1.h
 * Description: Header file that contains function prototypes and
 *              constants.
 *
 * XXX Only add constants to this file.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */

#ifndef PA1_H    /* Macro Guard */
#define PA1_H

/* Base to use with strtol */
#define BASE 10

/* Range limits for command line arguments */
#define WIDTH_MIN 3
#define WIDTH_MAX 21
#define HEIGHT_MIN 1
#define HEIGHT_MAX 19
#define ASCII_MIN 33
#define ASCII_MAX 126

/* Assembly function prototypes */
long checkRange( long value, long minRange, long maxRange );
void displayDiamond( long width, long height, char border, char diamond );
long isOdd( long value );
void printChar( char ch );
long rem( long dividend, long divisor );

/* EC Assembly function prototypes */
long numOfDigits( long num, long base );


#endif /* PA1_H */
