/*
 * File name:  printBytes
 * Author: 	   Xinyi Bian
 * Userid:	   cs30xfw
 * Description:
 *             printBytes will be responsible for reading data from the file
 *             pointer up to (but not including) endAddr bytes into the file,
 *             and will output the bytes from the file according to the 
 *             specified OutType. If convertFlag is set (value is non-zero)
 *             then this function will change the endianness of the input 4 
 *             bytes at a time before printing out the bytes. 
 * Date: 	3/11/2018
 */

#include <stdio.h>
#include <ctype.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function name: printBytes
 * Function Prototype:
 * void printBytes( FILE * fp, OutType type, long endAddr, int convertFlag )
 * Description:
 *             printBytes will be responsible for reading data from the file
 *             pointer up to (but not including) endAddr bytes into the file,
 *             and will output the bytes from the file according to the 
 *             specified OutType. If convertFlag is set (value is non-zero)
 *             then this function will change the endianness of the input 4 
 *             bytes at a time before printing out the bytes. 
 * Return Type:
 *             None
 * Side Effect:
 *             Output bytes from the file according to the specified OutType. 
 */ 
void printBytes( FILE * fp, OutType type, long endAddr, int convertFlag ) {
  // Determine how many total bytes to read from the file
  long startAddr = ftell( fp );  
  long size = endAddr - startAddr;
  
  long i = 0;
  long numSumBuf = 0;
  // Loop through the file until read in total # of bytes just calculated
  while ( startAddr < endAddr ) {
    
    // Print out the addr in the file at the beginning
    if ( i == 0 ) {
      if ( type == OCTAL ) {
        fprintf( stdout, STR_OFFSET_OCT, startAddr );
      }
      else { 
        fprintf( stdout, STR_OFFSET_HEX, startAddr );
      }
    }

    // Print out the addr when offset
    else if ( i % BYTES_PER_LINE == 0 ) {
      if ( type == OCTAL ) {
        fprintf( stdout, NL );
        fprintf( stdout, STR_OFFSET_OCT, startAddr );
      }
      else { 
        fprintf( stdout, NL );
        fprintf( stdout, STR_OFFSET_HEX, startAddr );
      }
    }
    
    // Print out one byte at a time    
    unsigned char buf[BYTE_BUFFER_SIZE];
    numSumBuf += BYTE_BUFFER_SIZE;
    fread( buf, sizeof(*buf), BYTE_BUFFER_SIZE, fp );
    int printCnt = BYTE_BUFFER_SIZE;
    
    // Check if the read size is within the range
    if ( numSumBuf > size ) { 
      printCnt = BYTE_BUFFER_SIZE - (numSumBuf - size);
      
      if ( convertFlag == 1 ) {
        // Pad the buffer with zeros
        for ( int j = BYTE_BUFFER_SIZE - 1; j >= printCnt; j-- ) {
          buf[j] = 0;
        }
      } 
    }

    // Convert order when necesary
    if ( convertFlag == 1 ) {
      convertOrder( &buf[0] );
      printCnt = BYTE_BUFFER_SIZE;
    }

    // Loop through buf within valid range to output
    for ( int k = 0; k < printCnt; k++ ) {
      if ( type == OCTAL ) {
        fprintf( stdout, STR_OCTAL_FMT, buf[k] );
      }
      
      // If type is ASCII, check if the character is printable.   
      if ( type == ASCII ) {
        
        // Print out the byte in hex if the character is not printable
        if ( !isprint( buf[k] ) ) {
          fprintf( stdout, STR_HEX_FMT, buf[k] );
        }
        else {
          fprintf( stdout, STR_ASCII_FMT, buf[k] );
        } 
      }

      if ( type == HEX ) {
        fprintf( stdout, STR_HEX_FMT, buf[k] );
      }
      
      if ( k % GROUP_SIZE == 1 ) {
        fprintf( stdout, STR_SPACE );
      }

      startAddr++;
      i++;
    }
  }  

  // Print out final newline for formatting reasons
  fprintf( stdout, NL );
}   
