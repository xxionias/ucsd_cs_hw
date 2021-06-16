/*
 * Filename: testcompareChar.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function compareChar().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for compareChar.s
 *
 * int compareChar( const void * p1, const void * p2 );
 *
 * This function takes two const char * and compares the char that each
 * points to in reverse alphabetical order. 
 *
 * Return Value:
 * -1 if the char that p1 points to should be ordered ealier than the 
 * char that p2 points to;
 * +1 if the char that p1 points to should be ordered later than the 
 * char that p2 points to;
 * 0 if the two char pointers point to the same char.
 */
void testcompareChar() {
  
  /* Less than */
  TEST(compareChar("a", "b") == 1);
  
  /* Greater than */
  TEST(compareChar("b", "a") == -1);

  /* Equal to */
  TEST(compareChar("b", "b") == 0);

  /* Less than (symbols) */
  TEST(compareChar("$", "#") == -1);
}

int main() {
  printf("Running tests on compareChar()\n");
  testcompareChar();
  printf("Finished running tests on compareChar()\n");
  return 0;
}
