/*
 * Filename: testspawnAnagram.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function spawnAnagram().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for spawnAnagram.s
 *
 * void spawnAnagram( char const * originalWord, struct Anagram * anagram );
 *
 * Fills the members of the anagram struct based on the originalWord (copies
 * word into anagram->word, and spawns anagram->key by calling spawnKey()).
 */
void testspawnAnagram() {
  struct Anagram a;

  /* All lowercase short word */
  spawnAnagram("santa", &a);
  TEST(strncmp("santa", a.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", a.key, MAX_WORD_LEN) == 0);

  /* All uppercase short word */
  spawnAnagram("SANTA", &a);
  TEST(strncmp("SANTA", a.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", a.key, MAX_WORD_LEN) == 0);

  /* Mixed word */
  spawnAnagram("SaNTA", &a);
  TEST(strncmp("SaNTA", a.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", a.key, MAX_WORD_LEN) == 0);
  
  /* Very long word */
  spawnAnagram("aaaaabbbbbcccccdddddeeeeefffffggggghhhhhi", &a);
  TEST(strncmp("aaaaabbbbbcccccdddddeeeeefffffggggghhhh", a.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("HHHHGGGGGFFFFFEEEEEDDDDDCCCCCBBBBBAAAAA", a.key, MAX_WORD_LEN) == 0);
}

int main() {
  printf("Running tests on spawnAnagram()\n");
  testspawnAnagram();
  printf("Finished running tests on spawnAnagram()\n");
  return 0;
}
