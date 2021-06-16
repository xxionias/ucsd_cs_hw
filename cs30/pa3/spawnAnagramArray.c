/* File Name: spawnAnagramArray.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            spawnAnagramArray will spawn an array of anagrams where each 
 *            element of the array is a struct Anagram spawned from a word 
 *            from the dictionary. Open the dictionaryFile and read in one 
 *            word at a time. For each word in the dictionary, spawn a 
 *            temporary anagram for that word, and then dynamically allocate
 *            memory to make room for this anagram.
 * Date:      2/26/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "pa3.h"
#include "pa3Strings.h"

/* Function Name: 
 *            spawnAnagramArray
 * Function Prototype:
 *            int spawnAnagramArray( char * dictionaryFile, struct Anagram **
 *            anagramArray )
 * Description:
 *            This function will spawn an array of anagrams where each 
 *            element of the array is a struct Anagram spawned from a word 
 *            from the dictionary. Open the dictionaryFile and read in one 
 *            word at a time. For each word in the dictionary, spawn a 
 *            temporary anagram for that word, and then dynamically allocate
 *            memory to make room for this anagram.
 * Reasons for error:
 *            Error opening the dictionary file;
 *            Memory allocation fails
 * Return Value:
 *            Number of anagrams stored in the array on success;
 *            -1 to indicate failure.
 */
int spawnAnagramArray(char * dictionaryFile, struct Anagram ** anagramsArray) {

  errno = 0;
  FILE * inFile = fopen( dictionaryFile, "r" );
  char buf[BUFSIZ] = {0};
  int counter = 0;  


  // Determine if there is permission denied
  if ( errno ==  EACCES ) {
    fprintf( stderr, STR_ERR_DICT_FILE_PERMISSION, dictionaryFile );
    fprintf( stderr, "\n" );
    return -1;
  }

  // Determine if the file is valid
  if ( errno == ENOENT ) {
    fprintf( stderr, STR_ERR_DICT_FILE_INVALID, dictionaryFile );
    fprintf(stderr, "\n");
    return -1;
  }

  // Create a temporary anagram
  struct Anagram tempAnagram;
    
  // Create a temporary array of anagrams
  struct Anagram * tempArray = NULL;
  
  // Open the dictionaryFile and read in one word at a time
  while ( fgets( buf, BUFSIZ, inFile ) ) {
    
    // Null terminate each word    
    size_t len = strlen(buf);
    if( buf[len-1] == '\n' ) {
      buf[--len] = '\0';
    }

    // Spawn a temporary anagram for the word
    spawnAnagram( buf, &tempAnagram );
    counter++;
    
    // Dynamically allocate memory to make room for this anagram
    tempArray = (struct Anagram *) realloc(tempArray, (counter) * 
                                          sizeof(struct Anagram));
    
    // Fail to resize
    if ( !tempArray ) {
      fprintf( stderr, STR_ERR_CREATE_ANAGRAM_FILE, dictionaryFile );
      
      // Free previously allocated memory
      free( tempArray );
      return -1;
    }
    else {
      // Store the anagram at the end of the array
      tempArray[counter - 1] = tempAnagram;
    }     
  }
  
  // Update the anagramsArray double pointer to dynamically allocated array
  *anagramsArray = tempArray;
  
  fclose( inFile );
  tempArray = NULL;
  return counter; 
}
