/*
 * Filename: testclear.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function clear().
 * Date: 2.6.2018
 * Sources of Help: Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For clear() function prototype */


/*
 * Unit Test for clear.s
 *
 * void clear( unsigned int lightBank[], const unsigned int pattern0, 
 *                                     const unsigned int pattern1 );
 * 
 * Turns on only the bits in lightBank[] specified by pattern0 and pattern1.
 * 1 bits in pattern turn on the bit at the same index in lighBank[];
 * 0 bits in pattern preserve the bit at the same index in lightBank[].
 */
void testclear()
{
  // Initialize the parameters to pass in clear.s
  unsigned int lightBank[2];
  unsigned int pattern0;
  unsigned int pattern1;

  (void) printf( "Testing clear()\n" );


  /* Clear entire lightBank */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;;
 
  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );

  /* Clear none */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  /* Clear by same pattern */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xCAFEBABE;
  pattern1 = 0XDECAFBAD;;

  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );

  /* Clear alternating bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x55555555;
  pattern1 = 0XAAAAAAAA;

  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x8AAAAAAA && lightBank[1] == 0x54405105 );
 
  printf( "Finished running tests on clear()\n" );
}

int main() {
  testclear();
  
  return 0;
}      
