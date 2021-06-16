/* File Name: spawnAnagramFile.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            spawnAnagramFile will use fopen() and fwrite() to write out an
 *            anagram File with a ".ao" extension. Create a temporary array
 *            of characters to build the name of the anagram file with the 
 *            ".ao" extension appended.
 * Date:      2/26/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "pa3.h"
#include "pa3Strings.h"

/* Function Name: 
 *            spawnAnagramFile
 * Function Prototype:
 *            int spawnAnagramFile( char * anagramFile, struct Anagram *
 *            anagramArray, int numAnagrams )
 * Description:
 *            spawnAnagramFile will use fopen() and fwrite() to write out an
 *            anagram File with a ".ao" extension. Create a temporary array
 *            of characters to build the name of the anagram file with the 
 *            ".ao" extension appended.
 * Reasons for error:
 *            Error when calling fopen().
 * Return Value:
 *            Number of anagrams written to file on success;
 *            -1 to indicate failure.
 */
int spawnAnagramFile(char * anagramFile, 
struct Anagram * anagramArray, int numAnagrams) {
    errno = 0;
    FILE * inFile = fopen( anagramFile, "w" );
    
    // Print Error messages if there is error calling fopen().
    if ( errno ) {
      fprintf( stderr, STR_ERR_CREATE_ANAGRAM_FILE, anagramFile );
    }
    
    // Create a temporary array of characters to build the name of the anagaram
    // file with the ".ao" extension appended
    char tempName[BUFSIZ]; 
    strncpy(tempName, anagramFile, BUFSIZ); 
    strncat(tempName, ANAGRAM_FILE_EXT, BUFSIZ);
   
    // Null terminate
    // dictionaryFile[strlen(dictionaryFile)] = '\0';
    inFile = fopen( tempName, "w" );

    // Create the anagram file and write the entire array
    int rtn_File = fwrite( anagramArray, sizeof(struct Anagram), 
                                              numAnagrams, inFile); 
    
    // Return the number of anagrams written to file on success
    fclose( inFile );
    
    return rtn_File; 
}
