/* File Name: parseRange.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            parseRange parses the range string that was provided as an 
 *            argument to the -r flag. A valid rangeStr is formatted as 
 *            "start:end". Convert teh values to longs and store them in the 
 *            appropriate output parameters. 
 * Date:      3/4/2018
 */
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "pa4.h"
#include "pa4Strings.h"

/* Function Name: parseRange.c
 * Function Prototype:
 * int parseRange( char * rangeStr, char * infile, long * start, long * end )
 * Description:
 *            parseRange parses the range string that was provided as an 
 *            argument to the -r flag. A valid rangeStr is formatted as 
 *            "start:end". Convert teh values to longs and store them in the 
 *            appropriate output parameters. 
 * Reasons for error:
 *            Range string is not formatted correctly
 *            start is not valid
 *            end is not valid
 * Return Value:
 *            0 if success;
 *            -1 if error.
 *  
 */
int parseRange( char * rangeStr, char * infile, long * start, long * end ) {
  
  char range[BUFSIZ];
  strncpy( range, rangeStr, BUFSIZ );
  // Seperate the first number string from the string
  char * numptr = strtok( range, SEPARATORS );
  
  // Check if the there is ":" in the string
  if ( !numptr ) {
    fprintf( stderr, ERR_RANGE_FMT );
    return -1;  
  }
  
  int errorFlag = 0;
  * start = parseLong( numptr, &errorFlag );
  
  // Check if start is successfully converted and start < 0
  if ( errorFlag == 1 || * start < 0 ) {
    fprintf( stderr, ERR_RANGE_INV );
    return -1;
  }

  numptr = strtok( NULL, SEPARATORS );
  
  // Check if there is "\0" in the string
  if ( !numptr ) {
    fprintf( stderr, ERR_RANGE_FMT );
    return -1;
  } 

  // Convert the values to longs
  // Store the values in the ouput parameters
  errorFlag = 0;
  * end = parseLong( numptr, &errorFlag );
  
  // Check if end is successfully converted and > 0
  if ( errorFlag == 1 || * end < 0 ) {
    fprintf( stderr, ERR_RANGE_INV );
    return -1;
  }
   
  // Check extra format of ":"
  numptr = strtok( NULL, SEPARATORS );
  if ( numptr ) {
    fprintf( stderr, ERR_RANGE_FMT );
    return -1;
  }

  // Check if start <= end
  if ( * start >= * end ) {
    fprintf( stderr, ERR_RANGE_INV );
    return -1;
  }

  // Determine the file size
  struct stat st;
  stat( infile, &st);
  int size = st.st_size;
  
  // Check if start and end is within file size
  if ( * start > size || * end > size ) {
    fprintf( stderr, ERR_RANGE_INV );
    return -1;
  }
  
  return 0;
 
}
