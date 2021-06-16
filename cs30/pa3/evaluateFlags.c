/* Filename:  evaluateFlags.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Date:      2/23/2018
 * Description:
 *            evaluateFlags.c uses getopt() to evaluate the flags described in
 *            the long usage statement for spawning angrams.
 * Date:      2/23/2018
 */
#include "pa3.h"
#include "pa3Strings.h"
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
/* Function Name:       evaluateFlags.c
 * Function Prototype:  int evaluateFlags( int argc, char * argv[]. char **
 *                      dictionaryFile, char ** anagramFile )
 * Description:         Uses getopt() to evaluate the flags described in the 
 *                      long usage statement for spawninf anagrams. By passing
 *                      in pointers to a char pointers( that were declared in 
 *                      main ) for the filenames, the original char pointers
 *                      can be changed. 
 * Reasons for error:   getopt() detects an invalid flag or missing flag argu-
 *                      ment: getopt() will automatically print an error 
 *                      message.
 *                      Extra args after getopt() completes.
 * Return Value:        0 to indicate success;
 *                      -1 to indicate failure.
 */
int evaluateFlags( int argc, char * argv[], 
char ** dictionaryFile, char ** anagramFile ) {
  int option;
  
  // Determine flags
  while ((option = getopt( argc, argv, ARG_STR )) != -1) {
    switch (option) {
      
      // '-h' entered
      case FLAG_HELP:
        printUsage( stderr, STR_SPAWN_USAGE_LONG, argv[0] );
        return 1;
      
      // '-d' entered
      case FLAG_DICTIONARY_FILE:
        *dictionaryFile = optarg;
        break;

      // '-a' entered
      case FLAG_ANAGRAM_FILE:
        *anagramFile = optarg;
        break;
  
      // Error entered
      case '?':
        printUsage( stderr, STR_SPAWN_USAGE_SHORT, argv[0] );
        return -1; 
    } 
  }

  // Handle extra argumentes
  if ( optind < argc ) {
    printUsage( stderr, STR_ERR_EXTRA_ARGS, argv[optind] );
    return -1;
  }
  
  return 0;
}  
