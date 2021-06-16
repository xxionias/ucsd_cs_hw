/* 
 * Filename:  testrem.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            Unit test program to test the function rem.
 * Date:      1.30.2018
 * Sources of help: course website
 */

#include <stdio.h>
#include "pa1.h"
#include "test.h"

/*
 * Function Name:  testrem()
 * Function Prototype:  void testrem()
 * Description:  Unit test for rem.s
 * Parameters:  None
 * Side Effects:  None
 * Error Conditions:  None
 * Return Value:  Returns remainder of dividend / divisor.
 */
void testrem() {

  // Test simple cases
  TEST( rem( 3, 2 ) == 1 );
  TEST( rem( 10, 2 ) == 0 );
  TEST( rem( 100, 51 ) == 49 );
  TEST( rem( 34, 5 ) == 4 );
  
  // Test negative numbers cases
  TEST( rem( -5, -3 ) == -2 );
}

/* 
 * Function Name: main()
 * Function Prototype: int main( void )
 * Description: Main driver for testrem.c.
 * Parameters:  None
 * Side Effects:  None
 * Error Conditions:  None
 * Return value:  Returns 0 after executing.
 */
int main( void ) {

  // format print out messages
  fprintf(stderr, "Runnning tests for rem...\n");
  testrem();
  fprintf(stderr, "Done running tests!\n");

  return 0;

}
