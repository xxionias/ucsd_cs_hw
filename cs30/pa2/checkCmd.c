/* 
 * Filename:    checkCmd.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: checkCmd checks if the passed in cmdString is in the commands[]
 *              array or not. It returns the index of the cmdString in the 
 *              array if found and return -1 if not found. 
 * Date:        2/11/2018
 * Source of help:
 *              CSE tutor
 */
#include  <stdio.h>
#include  <string.h>
#include  "pa2.h"
#include  "pa2Strings.h"

/* 
 * Function Name:       checkCmd()
 * Function Prototype:  int checkCmd( const char * const cmdString, const char
 *                                                             commands[] ) 
 * Description:         It checks if the passed in cmdString is in the passed
 *                      in array commands[].
 * Return Value:        Return the index of cmdString in the commands[] if 
 *                      successfully found;
 *                      Return -1 if not found.
 */
int checkCmd( const char * const cmdString, const char * const commands[] ) {
  
  // initialize the counter as the index of array commands[]
  int i;
  
  // Loop when reaching each element in the array
  while ( commands[i] ) {
    
    // Return the index of the element in the array if found 
    if( !strncmp( cmdString,commands[i], BUFSIZ ) ) { return i; }
    
    i++; 
  }
  
  // Return -1 if element not found
  return -1; 
}
