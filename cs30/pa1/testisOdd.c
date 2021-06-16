/*
 * Filename: testisOdd.c
 * Author:   Xinyi Bian
 * Userid:   cs30xfw
 * Description:
 *           Unit test program to test the function isOdd.
 * Date:     1.30.2018
 * Sources of help:
 *           Course website
 */

#include <stdio.h>
#include "pa1.h"
#include "test.h"

/*
 * Function Name: testisOdd()
 * Function Prototype:  void testisOdd()
 * Description:  Unit Test for isOdd.s
 * Parameters:  None
 * Side Effects: Call isOdd()
 * Error Conditions:  None
 * Return Value:  Returns 1 if odd; Returns 0 if even.
 */
void testisOdd() {
  
  // Test odd numbers
  TEST( isOdd( 3 ) == 1 );
  TEST( isOdd( 999 ) == 1 );

  // Test even numbers
  TEST( isOdd( 0 ) == 0 );
  TEST( isOdd( 100 ) == 0 );
}

/* 
 * Function Name: main()
 * Function Prototype:  int main( void )
 * Description:  Main driver for testisOdd.c
 * Parameters:  None
 * Side Effects:  None
 * Error Conditions:  None
 * Return Value:  Returns 0 after executing.
 */
int main (void) {
  
  // format print out messages
  fprintf(stderr, "Running tests for isOdd...\n");
  testisOdd();
  fprintf(stderr, "Done running tests!\n");
  
  return 0;
}
