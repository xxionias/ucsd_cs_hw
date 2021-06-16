/* 
 * File name:   testparseRange.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description:
 * Date:        3/5/2018
 */

#include <string.h>
#include "test.h"
#include "pa4.h"

/* Unit Test for parseRange.c
 * 
 * int parseRange( char * rangeStr, char * infile, long * start, long * end )
 * 
 * parseRange will parse the range string that was provided as an argument to 
 * the -r flag. 
 */
void testparseRange() {
  char rangeStr[BUFSIZ];

  /* fully valid range */ 
  strncpy( rangeStr, "5:10", BUFSIZ );
  char * infile = "parseRange.o";
  long start;
  long end;

  int rtn = parseRange( rangeStr, infile, &start, &end );
  
  TEST( rtn == 0 );
  TEST( start == 5 );
  TEST( end == 10 ); 

  /* end too large to convert */
  strncpy( rangeStr, "1:9999999999999999999999999999999999", BUFSIZ );
  rtn = parseRange( rangeStr, infile, &start, &end );

  TEST( rtn == -1 );

  /* negative start */
  strncpy( rangeStr, "-5:10", BUFSIZ );
  rtn = parseRange( rangeStr, infile, &start, &end );

  TEST( rtn == -1 );
  
  /* end < start */
  strncpy( rangeStr, "5:3", BUFSIZ );
  rtn = parseRange( rangeStr, infile, &start, &end );

  TEST( rtn == -1 );

  /* start outside file */
  strncpy( rangeStr, "10000:15000", BUFSIZ );
  rtn = parseRange( rangeStr, infile, &start, &end );

  TEST( rtn == -1 );
  
  /* end outside file */
  strncpy( rangeStr, "1:15000", BUFSIZ );
  rtn = parseRange( rangeStr, infile, &start, &end );

  TEST( rtn == -1 );
} 
 
int main() {
  printf("Running tests on parseRange()\n");
  testparseRange();
  printf("Finished running tests on parseRange()\n");
  return 0;
}
