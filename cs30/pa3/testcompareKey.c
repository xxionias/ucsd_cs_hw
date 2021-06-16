/*
 * Filename: testcompareKey.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function compareKey().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"
/*
 * Unit Test for compareKey.c
 *
 * void compareKey( char const * originalWord, struct Anagram * anagram );
 *
 * Fills the members of the anagram struct based on the originalWord (copies
 * word into anagram->word, and compares anagram->key by calling spawnKey()).
 */
void testcompareKey() {
  struct Anagram a, b;
  
  /* key greater than */
  strcpy( a.key, "CSEFUN" );
  strcpy( b.key, "USNFEC" );
  TEST( compareKey( &a, &b ) == -1 ); 

  /* key less than */
  strcpy( b.key, "CSEFUN" );
  strcpy( a.key, "USNFEC" );
  TEST( compareKey( &a, &b ) == 1 ); 

  /* key equal */
  strcpy( a.key, "CSEFUN" );
  strcpy( b.key, "CSEFUN" );
  TEST( compareKey( &a, &b ) == 0 ); 

  /* key greater than( symbols ) */
  strcpy( a.key, "" );
  strcpy( b.key, "CSEFUN" );
  TEST( compareKey( &a, &b ) == -1 ); 
  
  /* key less( symbols ) */
  strcpy( b.key, "" );
  strcpy( a.key, "CSEFUN" );
  TEST( compareKey( &a, &b ) == 1 ); 
  
  /* key the same( symbols ) */
  strcpy( a.key, "" );
  strcpy( b.key, "" );
  TEST( compareKey( &a, &b ) == 0 ); 
}
int main() {
  printf("Running tests on compareKey()\n");
  testcompareKey();
  printf("Finished running tests on compareKey()\n");
  return 0;
}
