/* 
 * Filename:    spawnKey.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: spawnKey takes three parameters and will fill the character 
 *              array key with the reverse-sorted, all uppercase version of
 *              the string word.
 * Date:        2/21/2018
 * Source of help:
 *              CSE tutor
 */
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <ctype.h>
#include  "pa3.h"

/* 
 * Function Name:       spawnKey()
 * Function Prototype:  void spawnKey( char * key, const char * const word, 
 *                                      int keyLen );
 * Description:         This function will fill the character array key with 
 *                      the reverse-sorted, all uppercase version of the 
 *                      string word.
 * Return Value:        None
 */
void spawnKey( char * key, const char * const word, int keyLen ) {
 
  
  // Copy string to key buffer
  key = strncpy( key, word, keyLen );

  // Key is null terminated
  key[keyLen - 1] = '\0';

  // Convert to uppercase
  for( int i = 0; i < keyLen && key[i] != '\0'; i++ ) {
    key[i] = toupper( key[i] );
  }

  // Sort in reverse alphabetical order 
  qsort( key, strlen( key ), sizeof(char), compareChar );
}
