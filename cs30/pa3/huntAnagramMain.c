/* File Name: huntAnagramMain.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            huntAnagramMain controls the hunt for anagrams.First,check that
 *            only a single filename was passed in as a command line argument.
 *            Next, read the anagram file to load teh array of anagrams into
 *            memory. Sort the anagrams array using qsort() with 
 *            compareAnagram() as the comparsion function. Once the anagrams 
 *            is sorted, hunt for anagrams! Once the hunt is over, free the 
 *            dynamically allocated memory that was used to hold the anagrams
 *            array.
 * Date:      2/28/2018
 */ 

#include "pa3.h"
#include "pa3Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Function Name: main
 * Function Prototype:
 *                int main( int argc, char * argv[] )
 * Description:
 *            huntAnagramMain controls the hunt for anagrams.First,check that
 *            only a single filename was passed in as a command line argument.
 *            Next, read the anagram file to load the array of anagrams into
 *            memory. Sort the anagrams array using qsort() with 
 *            compareAnagram() as the comparsion function. Once the anagrams 
 *            is sorted, hunt for anagrams! Once the hunt is over, free the 
 *            dynamically allocated memory that was used to hold the anagrams
 *            array.
 * Reasons for Error:
 *            Wrong number of arguments;
 *            Anagram filename doesn't end with .ao;
 *            Error reading the anagram file.
 * Return Value:
 *            Return EXIT_FAILURE indicating error;
 *            Return EXIT_SUCCESS otherwise.
 */
int main( int argc, char * argv[] ){
  errno = 0;

  // Check only a single filename was passed in
  if ( argc != 2 ) {
    printUsage( stderr, STR_HUNT_USAGE, argv[0] );
    return EXIT_FAILURE;
  }
  
  // Check if anagramfile name ends with .ao
  char * dot = strrchr( argv[1], '.' );
  
  // Error if there is no "." 
  if ( !dot ) {
    fprintf( stderr, STR_ERR_ANAGRAM_FILE_EXT, argv[1], ANAGRAM_FILE_EXT );
    return EXIT_FAILURE;
  }
  
  // Error if there is no ".ao"
  if ( dot && strcmp( dot, ANAGRAM_FILE_EXT ) != 0 ) {
    fprintf( stderr, STR_ERR_ANAGRAM_FILE_EXT, argv[1], ANAGRAM_FILE_EXT );
    return EXIT_FAILURE;
  }

  struct Anagram * tempArray;
  struct Anagram ** anagramArray = & tempArray;
  int rtn_Val = readAnagramFile( argv[1], anagramArray );
  if ( rtn_Val == -1 ) { return EXIT_FAILURE; } 

  // Sort the anagrams array
  qsort( *anagramArray, rtn_Val, sizeof(struct Anagram), compareAnagram );
  
  // Hunt for anagrams
  huntForAnagrams( *anagramArray, rtn_Val );
  
  // Free the dynamically allocated memory that was used to store array
  free( tempArray );
  
}

