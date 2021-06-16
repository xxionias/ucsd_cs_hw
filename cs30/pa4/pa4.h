/*
 * File: pa4.h
 * Description: Header file that contains function prototypes and
 *              constants.
 *
 * XXX Only add constants to this file at the bottom.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */

#ifndef _PA4_H /* Header Guard. */
#define _PA4_H

/* Determines what types to print out. */
typedef enum {
  ASCII,
  OCTAL,
  HEX,
  STRING
} OutType;

/* ===== Endianness checks. ===== */
#define IS_LITTLE_ENDIAN (*((char *) &(int){1}))

/* ===== Functions. ===== */
/* Assembly. */
void convertOrder( unsigned char * toConvert );
long parseLong( char * str, int * errorFlag );
/* C. */
void printBytes( FILE * fp, OutType type, long endAddr, int convertFlag );
void printStrings( FILE * fp, long endAddr );
void undump( FILE * infile, FILE * outfile, int convertFlag );
int evaluateArgs( int argc, char * argv[], char ** infile, char ** outfile,
    char ** rangeStr, OutType * type, int * convert );
int parseRange( char * rangeStr, char * infile, long * start, long * end );


/* ===== Helpful constants. ===== */
#define HELP_FLAG_CHAR    'h'
#define HELP_FLAG_STR     "help"
/* Byte mode. Can be any one of hex, octal, ascii. */
#define HEX_FLAG_CHAR     'x'
#define HEX_FLAG_STR      "hex"
#define OCTAL_FLAG_CHAR   'o'
#define OCTAL_FLAG_STR    "octal"
#define ASCII_FLAG_CHAR   'c'
#define ASCII_FLAG_STR    "ascii"
/* String Mode. Prints as strings. */
#define STRING_FLAG_CHAR  's'
#define STRING_FLAG_STR   "string"
/* Treat values as big endian. */
#define BE_FLAG_CHAR      'b'
#define BE_FLAG_STR       "big-endian"
/* Treat values as little endian. */
#define LE_FLAG_CHAR      'l'
#define LE_FLAG_STR       "little-endian"
/* Range of addresses. */
#define RANGE_FLAG_CHAR   'r'
#define RANGE_FLAG_STR    "range"
/* Undump. */
#define UNDUMP_FLAG_CHAR  'u'
#define UNDUMP_FLAG_STR   "undump"

#define OPT_STR           "xocsblhr:u:"

#define N_POSITIONAL_ARGS 1
#define BYTE_BUFFER_SIZE  4
#define STR_BUFFER_SIZE   20
#define GROUP_SIZE        2
#define BYTES_PER_LINE    16

#include <stdio.h>
#define SEPARATORS        ":\0"
#define NL                "\n"
#endif /* pa4.h */
