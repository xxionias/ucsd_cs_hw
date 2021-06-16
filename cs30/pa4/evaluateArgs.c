/* File Name:   evaluateArgs.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: evaluateArgs will parse the command line arguments. Create an
 *              array of struct option. 
 * Date:        3/4/2018
 */
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include "pa4.h"
#include "pa4Strings.h"

/* Function Name: evaluateArgs
 * Function Prototype:
 * int evaluateArgs( int argc, char * argv[], char ** infile, char ** outfile
 *                   char ** rangeStr, OutType * type, int * convert )
 * Function Description:
 *                This function will parse the command line arguments. Create 
 *                an array of struct option. Check for all errors, in the exact
 *                order. 
 * Reasons for error:
 *                An unknown flag is encountered;
 *                A flag's argument is not supplied;
 *                More than one format flag is supplied;
 *                More than one endian flag is supplied;
 *                Additional arguments are supplied
 * Return Value:
 *                -1 if error;
 *                0 if no error;
 *                1 if help flag was entered
 */

static struct option options[] = {
  { HELP_FLAG_STR,   no_argument,       NULL, HELP_FLAG_CHAR   },
  { HEX_FLAG_STR,    no_argument,       NULL, HEX_FLAG_CHAR    },
  { OCTAL_FLAG_STR,  no_argument,       NULL, OCTAL_FLAG_CHAR  },
  { ASCII_FLAG_STR,  no_argument,       NULL, ASCII_FLAG_CHAR  },
  { STRING_FLAG_STR, no_argument,       NULL, STRING_FLAG_CHAR },
  { BE_FLAG_STR,     no_argument,       NULL, BE_FLAG_CHAR     },
  { LE_FLAG_STR,     no_argument,       NULL, LE_FLAG_CHAR     },
  { RANGE_FLAG_STR,  required_argument, NULL, RANGE_FLAG_CHAR  },
  { UNDUMP_FLAG_STR, required_argument, NULL, UNDUMP_FLAG_CHAR },
  { 0,               0,                 0,    0                }
};

int evaluateArgs( int argc, char * argv[], char ** infile, char ** outfile,
                  char ** rangeStr, OutType * type, int * convert ) {
  int cmd;
  int formatCnt = 0;
  int endianCnt = 0;

  // Parse the command line arguments
  while ((cmd = getopt_long(argc, argv, OPT_STR, options, NULL)) != -1) {
    switch (cmd) {

      // Handle "help" flag
      case HELP_FLAG_CHAR:
        fprintf( stdout, STR_USAGE_LONG, argv[0] );
        return 1; 
      
      // Handle "hex" flag
      case HEX_FLAG_CHAR:        
        *type = HEX;
        formatCnt++;
        break;
      
      // Handle "octal" flag
      case OCTAL_FLAG_CHAR:
        *type = OCTAL;
        formatCnt++;
        break;

      // Handle "ascii" flag
      case ASCII_FLAG_CHAR:
        *type = ASCII;
        formatCnt++;
        break;

      // Handle "string" flag
      case STRING_FLAG_CHAR:
        *type = STRING;
        formatCnt++;
        break;

      // Handle "big endian" flag
      case BE_FLAG_CHAR:
        // Check if there is need to convert
        if ( IS_LITTLE_ENDIAN ) { *convert = 1; }
        endianCnt++;
        break;

      // Handle "little endian" flag
      case LE_FLAG_CHAR:
        // Check if there is need to convert
        if (!IS_LITTLE_ENDIAN) { *convert = 1; }
        endianCnt++;
        break;

      // Handle "range" flag
      case RANGE_FLAG_CHAR:
        *rangeStr = optarg;
        break;

      // Handle "undump" flag
      case UNDUMP_FLAG_CHAR:
        *outfile = optarg;
        break;

      // Handle error case
      case '?':
        fprintf( stderr, STR_USAGE_SHORT, argv[0] );
        return -1;
    }
  }

  
  // Error when multiple format flags
  if ( formatCnt > 1 ) {
    fprintf( stderr, ERR_OUT_FLAGS );
    fprintf( stderr, STR_USAGE_SHORT, argv[0] );
    return -1;
  }


  // Error when multiple endian flags
  if ( endianCnt > 1 ) {
    fprintf( stderr, ERR_END_FLAGS );
    fprintf( stderr, STR_USAGE_SHORT, argv[0] );
    return -1;
  }
 
  // Handle extra arguments
  if (optind != argc - N_POSITIONAL_ARGS) {
    fprintf( stderr, ERR_NUM_ARGS );
    fprintf( stderr, STR_USAGE_SHORT, argv[0] );
    return -1;
  }
  
  // Set infile
  *infile = argv[optind];
  return 0;
}
