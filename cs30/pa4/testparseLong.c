/* 
 * Filename:    testparseLong.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: Test program to test parseLong.s
 * Date:        3/4/2018
 */
#include <string.h>
#include <limits.h>
#include "test.h"
#include "pa4.h"

/* 
 * Unit test for parseLong.s
 * 
 * void parseLong( char * str, int * errorFlag )
 * 
 * parseLong will parse the char * str as a long and set the int that
 * errorFlag points to if there is an error. 
 */
void testparseLong() {
  char str[BUFSIZ];

  /* Numerical */
  strncpy( str, "5", BUFSIZ );
  int errorFlag = 0;
  long rtn = parseLong( str, &errorFlag ); 
  TEST( rtn == 5 );
  TEST( errorFlag == 0 );

  /* Negative numerical */
  strncpy( str, "-5", BUFSIZ );
  errorFlag = 0;
  rtn = parseLong( str, &errorFlag ); 
  TEST( rtn == -5 );
  TEST( errorFlag == 0 );

  /* Zero */
  strncpy( str, "0", BUFSIZ );
  errorFlag = 0;
  rtn = parseLong( str, &errorFlag ); 
  TEST( rtn == 0 );
  TEST( errorFlag == 0 );

  /* Invalid conversion */
  strncpy( str, "?", BUFSIZ );
  errorFlag = 0;
  rtn = parseLong( str, &errorFlag );
  TEST( rtn == 0 );
  TEST( errorFlag == 1 );
  
  /* Value out of positive range */
  strncpy( str, "9999999999999999999999999999", BUFSIZ );
  errorFlag = 0;
  rtn = parseLong( str, &errorFlag );
  TEST( rtn == LONG_MAX );
  TEST( errorFlag == 1 );

  /* Value out of negative range */
  strncpy( str, "-9999999999999999999999999999", BUFSIZ );
  errorFlag = 0;
  rtn = parseLong( str, &errorFlag );
  TEST( rtn == LONG_MIN );
  TEST( errorFlag == 1 );
}

int main() {
  printf("Running tests on parseLong()\n");
  testparseLong();
  printf("Finished running tests on parseLong()\n");
  return 0;
} 
