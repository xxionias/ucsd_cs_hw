/*
 * Filename: testcompareAnagram.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function compareAnagram().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"
/*
 * Unit Test for compareAnagram.c
 *
 * void compareAnagram( char const * originalWord, struct Anagram * anagram );
 *
 * Fills the members of the anagram struct based on the originalWord (copies
 * word into anagram->word, and compares anagram->Anagram by calling spawnKey()).
 */
void testcompareAnagram() {
  struct Anagram a, b;
  
  /* Key equal word less */
  strcpy( a.word, "CSE30FUN" );
  strcpy( a.key, "USNFEC30" );
  strcpy( b.word, "USNFEC30" );
  strcpy( b.key, "USNFEC30" );
  TEST( compareAnagram( &a, &b ) == -1 ); 

  /* Key equal word greater */
  strcpy( b.word, "CSE30FUN" );
  strcpy( b.key, "USNFEC30" );
  strcpy( a.word, "USNFEC30" );
  strcpy( a.key, "USNFEC30" );
  TEST( compareAnagram( &a, &b ) == 1 ); 

  /* key equal word equal */
  strcpy( a.word, "CSE30FUN" );
  strcpy( a.key, "USNFEC30" );
  strcpy( b.word, "CSE30FUN" );
  strcpy( b.key, "USNFEC30" );
  TEST( compareAnagram( &a, &b ) == 0 ); 
  
  /* key less than */
  strcpy( a.word, "USNFEC3" );
  strcpy( a.key, "USNFEC3" );
  strcpy( b.word, "CSE30FUN" );
  strcpy( b.key, "USNFEC30" );
  TEST( compareAnagram( &a, &b ) == -1 ); 
  
  /* key greater than */
  strcpy( a.word, "CSE30FUN" );
  strcpy( a.key, "USNFEC30" );
  strcpy( b.word, "USNFEC3" );
  strcpy( b.key, "USNFEC3" );
  TEST( compareAnagram( &a, &b ) == 1 ); 

  /* key less than (symbols) */
  strcpy( a.word, "*" );
  strcpy( a.key, "*" );
  strcpy( b.word, "%" );
  strcpy( b.key, "%" );
  TEST( compareAnagram( &a, &b ) == 1 ); 
  
  /* key greater than (symbols) */
  strcpy( a.word, "%" );
  strcpy( a.key, "%" );
  strcpy( b.word, "*" );
  strcpy( b.key, "*" );
  TEST( compareAnagram( &a, &b ) == -1 ); 

  /* key the same (symbols) */
  strcpy( a.word, "%" );
  strcpy( a.key, "%" );
  strcpy( b.word, "%" );
  strcpy( b.key, "%" );
  TEST( compareAnagram( &a, &b ) == 0 ); 
}

int main() {
  printf("Running tests on compareAnagram()\n");
  testcompareAnagram();
  printf("Finished running tests on compareAnagram()\n");
  return 0;
}
