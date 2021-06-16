/* Filename:  spawnAnagramMain.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            This is the main function that will spawn anagrams. You simply
 *            need to evaluate the flags entered on the command line, spawn 
 *            the array of struct anagrams (and report its size), spawn the
 *            anagram file( and report how many anagrams were written to the 
 *            file), and then free the memory that was allocated for the 
 *            anagrams array. Make sure to set up the default filenames for
 *            the dictionary and anagram files. If the help flag was entered 
 *            just return indicating success right away.
 * Date:      2/23/2018
 * Source of help:
 *           CSE tutor
 */
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"

#define NL "\n"

/* Function Name:       main()     
 * Function Prototype:  int main( int argc, char * argv[] )
 * Description:         This is the main function that will spawn anagrams. 
 *                      You simply need to evaluate the flags entered on the 
 *                      command line, spawn the array of struct anagrams (and 
 *                      report its size), spawn the anagram file( and report 
 *                      how many anagrams were written to the file), and then 
 *                      free the memory that was allocated for the anagrams 
 *                      array. Make sure to set up the default filenames for
 *                      the dictionary and anagram files. If the help flag was 
 *                      entered just return indicating success right away.
 *                      bit unsigned ints; Determine the input source: if a
 *                      filename was entered on the command line or prompt the
 *                      user and execute their commands.
 * Reasons for error:
 *                      Error evaluating the flags;
 *                      Error spawning the anagram array;
 *                      Error spawning the anagram file.
 * Return Value:        Return EXIT_SUCCESS on success;
 *                      Return EXIT_FAILURE on failure.
 */
int main( int argc, char * argv[] ) {
  
  // Set up the default filenames for the dictionary and anagram files.
  char * dictionaryFile = DEFAULT_DICTIONARY_FILE;
  char * anagramFile = DEFAULT_ANAGRAM_FILE;
  
  // Evalute the flags user entered
  int rtn_Flags = evaluateFlags( argc, argv, &dictionaryFile, &anagramFile ); 
                            
  if ( rtn_Flags == -1 ) {
    return EXIT_FAILURE;
  }
  
  // Return 1 when user entered "-h"
  if ( rtn_Flags == 1 ) {
    return EXIT_SUCCESS;
  }
 
  struct Anagram * anagramArray; 
  
  // Spawn the array of struct anagrams and report its size
  int rtn_Array = spawnAnagramArray( dictionaryFile, &anagramArray );

  if ( rtn_Array == -1 ) {
    return EXIT_FAILURE;
  }
  
  fprintf(stdout, STR_SPAWN_ARRAY, rtn_Array); 
  
  // Spawn the anagram file and report how many anagrams were written.
  int rtn_File = spawnAnagramFile( anagramFile, anagramArray, rtn_Array );
  
  if ( rtn_File == -1 ) {
    return EXIT_FAILURE;
  }
  
  fprintf(stdout, STR_SPAWN_FILE, anagramFile, rtn_File);

  // Free the memory that was allocated for the anagrams array.
  free(anagramArray);
  
  return EXIT_SUCCESS;
} 
