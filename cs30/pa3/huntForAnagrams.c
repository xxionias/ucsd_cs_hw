/* File Name: huntForAnagrams.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            huntForAnagram will interactively ask the user for a word, hunt
 *            for anagrams of said word in the anagramsArray, and then report
 *            the results of the hunt.
 * Date:      2/28/2018
 */

#include "pa3.h"
#include "pa3Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Function Name: huntForAnagrams
 * Function Prototype:
 * void hunrForAnagrams( struct Anagram * anagramsArray, int numAnagrams )
 * Description:
 *                First prompt the user, then read user input using fgets() 
 *                until the user inputs EOF. After each word is read from 
 *                the user, there will be a newline in the buffer after the 
 *                input word. Remove the newline character by overwriting it 
 *                with a null character.
 * Return Value:  None
 */
void huntForAnagrams( struct Anagram * anagramsArray, int numAnagrams ) {
  char buf[BUFSIZ] = {0};
  FILE * inFile = stdin;
  
  // First prompt the user, read user input until EOF
  for( DISPLAY_PROMPT; fgets( buf, BUFSIZ, inFile ) != NULL; DISPLAY_PROMPT ) {
    // Null terminate
    char * replace = strrchr(buf, '\n');
    * replace = '\0';
    
    // Spawn a temporary anagram with the input word
    struct Anagram tempAnagram;
    spawnAnagram( buf, &tempAnagram );
    
    // Search for this struct Anagram in the anagramArray
    struct Anagram * matchAnagram = (struct Anagram *) bsearch(&tempAnagram, 
             anagramsArray, numAnagrams, sizeof(struct Anagram), compareKey);
    
    // Reprompt user if no matches are found
    if (!matchAnagram) {
      fprintf( stdout, STR_NO_ANAGRAMS ); 
      continue;
    }
    
    // A match is found
    // Manually scan backwards through the array to determine first match
    // Check if the previous anagram in the array has the same key
    int counter = 0;
    while ( matchAnagram >= &anagramsArray[0] && compareKey(matchAnagram, 
                                                   &tempAnagram) == 0 ) {
      matchAnagram--;
    }

    matchAnagram++;

    // Build one buffer with all the anagrams of the user's input word
    char buffer[BUFSIZ] = {0};
    while (compareKey(matchAnagram, &tempAnagram) == 0) {
      if (strncasecmp(matchAnagram->word, tempAnagram.word, BUFSIZ)!= 0) {
        strncat( buffer, STR_SPACE_CHAR, BUFSIZ );
        strncat( buffer, matchAnagram->word, BUFSIZ );
        counter++;
      } 
      matchAnagram++;
    } 
        
    if ( counter == 0 ) {
      fprintf( stdout, STR_NO_ANAGRAMS ); 
      continue;
    }
        
    // Print the buffer once the last match has been found
    fprintf( stdout, STR_FOUND_ANAGRAMS );
    fprintf( stdout, buffer );
    fprintf( stdout, "\n" );

    // Repeat the loop
    continue;  
  }
    
  printf("\n");
}
      
