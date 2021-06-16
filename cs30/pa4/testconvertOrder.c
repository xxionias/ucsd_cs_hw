/* 
 * Filename:    testconvertOrder.c
 * Author:      Xinyi Bian
 * Userid:      cs30xfw
 * Description: Test program to test convertOrder.s
 * Date:        3/4/2018
 */
#include <string.h>
#include "test.h"
#include "pa4.h"

/* 
 * Unit test for convertOrder.s
 * 
 * void convertOrder( unsigned char * toConvert )
 * 
 * convertOrder will convert the endianness of the byte sequence 
 * pointed to by the argument. 
 */
void testconvertOrder() {
  /* Convert chars (numbers) */
  int toConvert = 1234;
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == -771489792 );
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == 1234 );
  
  /* Convert chars (letters) */
  toConvert = (int) "l";
  convertOrder( (unsigned char *) &toConvert );
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == (int) "l" );

  /* Convert upper char */
  toConvert = (int) "Z";
  convertOrder( (unsigned char *) &toConvert );
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == (int) "Z" );
  
  /* Convert w/ zeros */
  toConvert = (int) "0Z";
  convertOrder( (unsigned char *) &toConvert );
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == (int) "0Z" );

  /* Convert hex bytes */
  toConvert = (int) 0xFE34;
  convertOrder( (unsigned char *) &toConvert );
  convertOrder( (unsigned char *) &toConvert );
  TEST( toConvert == (int) 0xFE34 );

}

int main() {
  printf("Running tests on convertOrder()\n");
  testconvertOrder();
  printf("Finished running tests on convertOrder()\n");
  return 0;
} 
