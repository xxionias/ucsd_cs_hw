/*
 * Filename: testset.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function set().
 * Date: 2.6.2018
 * Sources of Help: Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For set() function prototype */


/*
 * Unit Test for set.s
 *
 * void set( unsigned int lightBank[], const unsigned int pattern0, 
 *                                     const unsigned int pattern1 );
 * 
 * Turns on only the bits in lightBank[] specified by pattern0 and pattern1.
 * 1 bits in pattern turn on the bit at the same index in lighBank[];
 * 0 bits in pattern preserve the bit at the same index in lightBank[].
 */
void testset()
{
  // Initialize the parameters to pass in set.s
  unsigned int lightBank[2];
  unsigned int pattern0;
  unsigned int pattern1;

  (void) printf( "Testing set()\n" );


  /* Set by all 1s */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;;
 
  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xFFFFFFFF );

  /* Set by all 0s */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  /* Set by same pattern */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xCAFEBABE;
  pattern1 = 0XDECAFBAD;;

  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  /* Set one light bank */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xFFFFFFFF;
  pattern1 = 0X00000000;

  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xDECAFBAD );

  /* Set alternating bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x55555555;
  pattern1 = 0XAAAAAAAA;

  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xDFFFFFFF && lightBank[1] == 0xFEEAFBAF );

  /* Set half of each bank */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xFFFF0000;
  pattern1 = 0X0000FFFF;

  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xFFFFBABE && lightBank[1] == 0xDECAFFFF );

  printf( "Finished running tests on set()\n" );
}

int main() {
  testset();

  return 0;
}
