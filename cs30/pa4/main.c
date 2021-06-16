/*
 * Filename: main.c
 * Author: 	 Xinyi Bian
 * Userid:	 cs30xfw
 * Description:
 *           main.c will be the main entry point of the program. It will be 
 *           responsible for parsing command line arguments, openining all
 *           required files, and then calling the appropriate functions.	
 * Date: 	   3/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function name: main
 * Function Prototype:
 * int main( int argc, char * argv[] )
 * Description:   main is the main entry point of the program. It will be 
 *                responsible for parsing command line arguments, opening
 *                all required files, and then calling the appropriate 
 *                functions.
 * Reasons of error:
 *                Error in evaluateArgs;
 *                Error in parseRange;
 *                Error opening file.
 * Return Type:   EXIT_SUCCESS during normal execution;
 *                EXIT_FAILURE in case of error.
 * Side Effect:   None.
 */ 
int main( int argc, char * argv[] ) {
  
  char * infile;
  char * outfile = NULL;
  char * rangeStr = NULL;
  OutType type = HEX;
  int convert;

  // Parse the arguments by calling evaluateArgs()
  int rtn_eval = evaluateArgs( argc, argv, &infile, &outfile, &rangeStr, &type,
                                                                   &convert ); 
  // If the help flag was entered, return EXIT_SUCCESS
  if ( rtn_eval == 1 ) { return EXIT_SUCCESS; }

  // Error in evaluateArgs
  if ( rtn_eval == -1 ) { return EXIT_FAILURE; }
  
  // Open the infile for reading
  FILE * infile_fp; 
  
  // Error opening file
  if ((infile_fp = fopen( infile, "rb" )) == NULL) {
    perror( infile );
    return EXIT_FAILURE;
  }

  // Get the size of the file
  struct stat st;
  stat( infile, &st );
  long size = st.st_size;  

  // Locate the starting and ending location if range option not selected
  long start = 0;
  long end = size;
  
  // Call parseRange() if range option was entered
  if ( rangeStr ) { 
    
    int rtn_range = parseRange( rangeStr, infile, &start, &end );
    
    // Error parsing range
    if ( rtn_range == -1 ) {
      fprintf( stderr, STR_USAGE_SHORT, argv[0] );
      return EXIT_FAILURE;
    }    
 
    // Move the file pointer to the starting value the user entered
    fseek( infile_fp, start, SEEK_SET );  
  }
  

  if ( outfile ) {  
    // Open the outfile for writing and call undump() if undump option
    FILE * outfile_fp = fopen( outfile, "wb" );
    undump( infile_fp, outfile_fp, convert );
    fclose( outfile_fp );
  }

  // Call printStrings() if type is string option
  else if ( type == STRING ) {
    printStrings( infile_fp, end );
  }
  
  // Call printBytes() option
  else {
    printBytes( infile_fp, type, end, convert );
  }

  // Close all opened files
  fclose( infile_fp );
}
