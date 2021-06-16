/*
 * File name:   printStrings
 * Author: 	    Xinyi Bian
 * Userid:	    cs30xfw
 * Description:	printStrings will print out all valid sequences of characters 
 *              in the file. 
 * Date: 	3/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function name: printStrings
 * Function Prototype:
 * void printStrings( FILE * fp, long endAddr )
 * Description:   This function will print out all valid sequences of 
 *                characters in the file. It also only read from the
 *                file until it reaches endAddr bytes into the file.
 * Reasons for error:
 *                Memory allocation failed.
 * Return Type:   None
 * Side Effect:   Print out all valid sequences of characters in file
 */ 
void printStrings( FILE * fp, long endAddr ) {
  // Read from the file
  long startAddr = ftell(fp);
  long size = endAddr - startAddr;
  char * string = NULL;
  long numSumBuf = 0;
  long str_len = 0;
  long pre_len = 0;
  
  // Loop through the bytes in the buffer
  while ( startAddr < endAddr ) {
    char buf[STR_BUFFER_SIZE];
    int buf_ptr = -1;
    fread( buf, sizeof(*buf), STR_BUFFER_SIZE, fp );
    startAddr += STR_BUFFER_SIZE;
    numSumBuf += STR_BUFFER_SIZE;
    long printCnt = STR_BUFFER_SIZE;
    if ( numSumBuf > size ) {
      printCnt = printCnt - (numSumBuf - size);
    }
    for ( int i = 0; i < printCnt; i++ ) {
      // First determine if it is a printable character
      if ( isprint( buf[i] ) ) {
        // No string built yet
        if ( buf_ptr == -1 ) {
          // Save the index if the current byte is a printable character
          buf_ptr = i;
        }

        // Reach end of buffer, but still not at end of possible string
        if ( i == printCnt - 1 ) {
          // Dynamically allocate space if no string yet
          if ( !string ) {
            str_len= i - buf_ptr + 1;
            pre_len = str_len;
            string = calloc(str_len, sizeof(*buf));
            if( !string ) {
              perror(string);
              free( string );
              return;
            } 
            strncpy( string, buf + buf_ptr, str_len );
          }

          // Realloc memory for string
          else {
            str_len = i - buf_ptr + 1;
            string = realloc( string, strlen(string) + str_len );
            
            // Check if memory allocated
            if ( !string ) {
              perror( string );
              free( string );
              string = NULL;
              return;
            }
            strncpy( string + pre_len, buf, str_len );
            pre_len += str_len;
          }
          // Reset buffer pointer
          buf_ptr = -1;
        }
      } 
    
      else {
        // Null-char detected
        if ( buf[i] == '\0' ) {
        
          // Do nothing if there is no string created and no pointer valid
          if ( buf_ptr == -1 && !string ) {}
        
          // Print string if string exists and '\0' is the first in buffer
          else if ( i == 0 && string ) {
            string = realloc(string, pre_len + 1);
            
            // Check if memory allocated
            if ( !string ) {
              perror(string);
              free( string );
              string = NULL;
            }

            // Print the string
            strncpy( string + pre_len, buf, 1 );
            fprintf( stdout, "%s", string );
            fprintf( stdout, NL );
            free( string );
            string = NULL;
          }

          // No string available yet
          else if ( !string ) {
            str_len = i - buf_ptr + 1;
            string = calloc(str_len, sizeof(*buf));
            
            // Print error message if memory allocation fails
            if( !string ) {
              perror(string);
              free( string );
              return;
            }

            // Print the string 
            strncpy( string, buf + buf_ptr, str_len ); 
            fprintf( stdout, "%s", string );
            fprintf( stdout, NL );
            free( string );
            string = NULL;     
          }
          else {
            // Realloc memory space for the string
            str_len = i - buf_ptr + 1;
            string = realloc(string, pre_len + str_len);      
            // Check if memory allocation succeeds
            if( !string ) {
              perror(string);
              free( string );
              return;
            }
            
            // Print the string 
            strncpy( string + pre_len, buf + buf_ptr, str_len ); 
            fprintf( stdout, "%s", string );
            fprintf( stdout, NL );
            free( string );
            string = NULL;
          }
        }
        else {
          // Throw away potential string, if one exists
          if ( string ) {
            free(string);
            string = NULL;
          }
        }
        buf_ptr = -1;
      }
    }
  }

  // After looping all the char
  // Throw away string, if one exists
  if ( string ) {
    free( string );
    string = NULL;
  }
       
}
