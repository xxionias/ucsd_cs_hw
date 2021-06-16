/*
 * File name: undump.c
 * Author: 	  Xinyi Bian
 * Userid:	  cs30xfw
 * Description:
 *            undump is responsible for taking a previously created hex dump 
 *            from our program and converting it back into the original	file
 *            format. 
 * Date: 	3/11/2018
 */

#include <stdio.h>
#include "pa4.h"
#include "pa4Strings.h"

/*
 * Function name: undump
 * Function Prototype:
 * void undump( FILE * infile, FILE * outfile, int convertFlag )
 * Description:   This function is responsible for taking a previously created
 *                hex dump from our program and converting it back into the 
 *                original file format. 
 * Return Type:   None
 * Side Effect:   Convert the endianness of the bytes of the entire file
 */ 
void undump( FILE * infile, FILE * outfile, int convertFlag ) {
  
  // Get rid of the offset
  while (fscanf( infile, STR_SCANF_OFF ) != EOF) {
    
    for( int j = 0; j < BYTES_PER_LINE / BYTE_BUFFER_SIZE; j++ ) {
    
      unsigned char buf[BYTE_BUFFER_SIZE];
      // Read in two byte at a time
      if (fscanf( infile, STR_SCANF, buf, buf+1 ) != EOF ) {
        fscanf( infile, STR_SCANF, buf+2, buf+3 );
      }
    
      else { break; }
   
      // Change the endianness of the bytes if convertFlag is set    
      if ( convertFlag ) {
        convertOrder( buf );
      } 
 
      // Write the buffer to the outfile
      fwrite( buf, sizeof(*buf), sizeof(buf), outfile );
    }
  }
}
