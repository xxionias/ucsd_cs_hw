/*
 * Filename: testtoggle.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function toggle().
 * Date: 2.6.2018
 * Sources of Help: Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For toggle() function prototype */


/*
 * Unit Test for toggle.s
 *
 * void toggle( unsigned int lightBank[], const unsigned int pattern0, 
 *                                     const unsigned int pattern1 );
 * 
 * Turns on only the bits in lightBank[] specified by pattern0 and pattern1.
 * 1 bits in pattern turn on the bit at the same index in lighBank[];
 * 0 bits in pattern preserve the bit at the same index in lightBank[].
 */
void testtoggle()
{
  // Initialize the parameters to pass in toggle.s
  unsigned int lightBank[2];
  unsigned int pattern0;
  unsigned int pattern1;

  (void) printf( "Testing toggle()\n" );


  /* Toggle both banks */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x35014541 && lightBank[1] == 0x21350452 );

  /* Don't toggle */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  /* Toggle by same pattern */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0xCAFEBABE;
  pattern1 = 0XDECAFBAD;;

  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );
  
  /* Toggle alternating bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  pattern0 = 0x55555555;
  pattern1 = 0XAAAAAAAA;

  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x9FABEFEB && lightBank[1] == 0x74605107 );
  
  printf( "Finished running tests on toggle()\n" );
}


int main() {
  testtoggle();

  return 0;
}
