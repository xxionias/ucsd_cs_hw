#include <stdio.h>
#include "test.h"

void testnumOfDigitsEC() {
  TEST( numOfDigits( 0, 16 ) == 1 );
  TEST( numOfDigits( 2693, 10 ) == 4 );
  TEST( numOfDigits( 0x7A2, 16 ) == 3 );
  TEST( numOfDigits( 8, 2 ) == 4 );
  TEST( numOfDigits( 0, 45 ) == -1 );
}

int main( void ) {
  fprintf( stderr, "Running tests for numofDigitsEC...\n" );
  testnumOfDigitsEC();
  fprintf( stderr, "Done running tests!\n" );
 
  return 0;
}
