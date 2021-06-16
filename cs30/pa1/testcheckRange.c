/*
 * Filename: testcheckRange.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function checkRange.
 * Date: 1.22.2018
 * Sources of Help: course website
 */ 

#include <stdio.h>
#include "pa1.h"
#include "test.h"

/*
 * Function Name:  testcheckRange()
 * Function Prototype:  long checkRange( long value, long minRange, 
 *                                                     long maxRange );
 * Description:  Checks to see if value is within the range of minRange 
 *                                              to maxRange, inclusive.
 * Parameters:  value is to be checked within minRange and maxRange
 * Side Effect:  None
 * Error Conditions:  None
 * Return Value:  Returns -1 if minRange > maxRange; Returns 1 if value is 
 *        between minRange and maxRange (inclusive); Returns 0 otherwise.
 */
void testcheckRange( ) {

  /* Test around 0 */
  TEST( checkRange( 0, 0, 1 ) == 1 );
  TEST( checkRange( 0, 0, 0 ) == 1 );
  
  /* Test error cases */
  TEST( checkRange( 0, 0, -1 ) == -1 );
  
  /* Test edge cases */
  TEST( checkRange( 2, 0, 1 ) == 0 );
  TEST( checkRange( 100, -100, -99 ) == 0 );
}

/* 
 * Function Name:  main()
 * Function Prototype:  int main( void )
 * Description:  Main Driver for testcheckRange.c.
 * Parameters:  None
 * Side Effects:  Show if the test fails or succeeds.
 * Error Conditions:  None
 * Return value:  Rrturns 0 after executing.
 */
int main( void ) {
  
  // format print out messages
  fprintf(stderr, "Running tests for checkRange...\n");
  testcheckRange();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
