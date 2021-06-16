/*
 * Filename: testspawnKey.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function spawnKey().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for spawnKey.c
 *
 * void spawnKey( char * key, const char * const word, int keyLen );
 *
 * spawnKey will fill the character array key with the reverse-sorted, all
 * uppercase version of the string word.
 */
void testspawnKey() {
  char key[MAX_WORD_LEN];
  
  /* simple word, all caps, no sort */
  char word[BUFSIZ] = "FEDCBA"; 
  spawnKey( key, word, MAX_WORD_LEN );
  TEST( strncmp( key, "FEDCBA", MAX_WORD_LEN ) == 0 );
  
  /* simple word, all caps, sort */
  strcpy(word, "ABCDEF");
  spawnKey( key, word, MAX_WORD_LEN );
  TEST( strncmp( key, "FEDCBA", MAX_WORD_LEN ) == 0 );

  /* simple word, no caps, sort */
  strcpy(word, "abcdef");
  spawnKey( key, word, MAX_WORD_LEN );
  TEST( strncmp( key, "FEDCBA", MAX_WORD_LEN ) == 0 );
  
  /* simple word, mixed caps, sort */
  strcpy(word, "AbcDeF");
  spawnKey( key, word, MAX_WORD_LEN );
  TEST( strncmp( key, "FEDCBA", MAX_WORD_LEN ) == 0 );
  
  /* simple word, small keyLen */
  strcpy(word, "CSE30FUN");
  spawnKey( key, word, 7 );
  TEST( strncmp( key, "SFEC30", MAX_WORD_LEN ) == 0 );
}

int main() {
  printf("Running tests on spawnKey()\n");
  testspawnKey();
  printf("Finished running tests on spawnKey()\n");
  return 0;
}
