/* 
 * File Name: readAnagramFile.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            readAnagramFile will open and read the anagramFile in order
 *            to create and populate the anagramsArray in memory. Open the 
 *            file for reading as a binary file. Next, determine if the 
 *            anagram file is well formed: the size of the file must be a 
 *            multiple of the size of a struct Anagram. Dynamically allocate
 *            memory for the array and report how many anagrams to read. Read
 *            the entire array of anagrams from the file at once and store in 
 *            the block of memory just allocated.
 * Date:      2/27/2018
 */

#include "pa3.h"
#include "pa3Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

/* Function Name: readAnagramFile
 * Function Prototype:
 * int readAnagramFile( char * anagramFile, struct AnagramsArray )
 * Description:
 *            readAnagramFile will open and read the anagramFile in order
 *            to create and populate the anagramsArray in memory. Open the 
 *            file for reading as a binary file. Next, determine if the 
 *            anagram file is well formed: the size of the file must be a 
 *            multiple of the size of a struct Anagram. Dynamically allocate
 *            memory for the array and report how many anagrams to read. Read
 *            the entire array of anagrams from the file at once and store in 
 *            the block of memory just allocated.
 * Reasons for error:
 *            Error opening anagramFile;
 *            Anagram file is an invalid size
 *            Memory allocation error
 *            Number of anagrams read from teh file is not the same as expected
 * Return Values:
 *            Returns -1 if error;
 *            Returns number of anagrams in the array
 */
int readAnagramFile( char * anagramFile, struct Anagram ** anagramsArray ) {
  errno = 0;
  
  // Open and read the anagramFile as a binary file 
  FILE * inFile = fopen( anagramFile, "rb" );
  
  // No permission
  if ( errno == EACCES) {
    fprintf( stderr, STR_ERR_ANAGRAM_FILE_PERMISSION, anagramFile );
    fprintf( stderr, "\n" );
    return -1;
  }
  
  // Invalid file
  if ( errno == ENOENT) {  
    fprintf( stderr, STR_ERR_ANAGRAM_FILE_INVALID, anagramFile );
    fprintf( stderr, "\n" );
    return -1;
  }
   
  // Determine if the anagram file is well formed
  // The size of the file must be a multiple of the size of struct Anagram
  struct stat st;
  stat( anagramFile, &st );
  int size = st.st_size;
  if ( size % sizeof(struct Anagram) != 0 ) {
    fprintf( stderr, STR_ERR_ANAGRAM_FILE_CORRUPT, anagramFile );
    fprintf( stderr, "\n" );
    return -1;
  }
  
  // Report how many anagrams you are going to read 
  int numExpected = size / sizeof(struct Anagram);
  
  fprintf( stderr, STR_HUNT_FILE, anagramFile, numExpected );
  
  // Dynamically allocate memory for the array
  struct Anagram * tempArray = 
  (struct Anagram *) malloc( numExpected * sizeof(struct Anagram));
   
  // Read the entire array of anagrams from the file
  // Store in the block of memory just allocated
  // Report how many anagrams were read from the file
  int numActual = fread(tempArray, sizeof(struct Anagram), numExpected, inFile);
  
  fprintf( stderr, STR_HUNT_ARRAY, numActual ); 
  // Return -1 if number of anagrams read from file is not the same as expected     
  if ( numExpected != numActual ) {return -1;}
  
  // Update the anagramsArray pointer
  *anagramsArray = tempArray;

  // Return number of anagrams in the array
  return numActual;
}
