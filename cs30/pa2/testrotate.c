/*
 * Filename: testrotate.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function rotate().
 * Date: 2.6.2018
 * Sources of Help: Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For rotate() function prototype */


/*
 * Unit Test for rotate.s
 *
 * void rotate( unsigned int lightBank[], const int rotateCnt );
 *
 * rotates the entire lightBank by rotateCnt bits:
 * If rotateCnt is positive, rotate right;
 * If rotateCnt is negative, rotate left.
 */
void testrotate()
{
  unsigned int lightBank[2];
  int rotateCnt;

  (void) printf( "Testing rotate()\n" );


  /* Rotate left by 1 bit */ 
  lightBank[0] = 0x00000001;
  lightBank[1] = 0x00000001;
  rotateCnt = 1;
                                                                    
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0x80000000 && lightBank[1] == 0x80000000 );


  /* rotate right by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 1;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xE57F5D5F && lightBank[1] == 0x6F657DD6 );
  
  /* rotate left by 3 bits */
  lightBank[0] = 0x80000000;
  lightBank[1] = 0x80000000;
  rotateCnt = -1;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0x00000001 && lightBank[1] == 0x00000001 );

  /* rotate right by 3 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 3;
  
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xB95FD757 && lightBank[1] == 0xDBD95F75 );

  /* rotate left by 3 bits twice */
  
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = -3;

  rotate( lightBank, rotateCnt );
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xBFAEAFB7 && lightBank[1] == 0xB2BEEB72 );

  /* rotate right by 3 bits twice*/
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 3;

  rotate( lightBank, rotateCnt );
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xB72BFAEA && lightBank[1] == 0xFB7B2BEE );

  /* rotate left by 40 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = -40;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xCAFBADCA && lightBank[1] == 0xFEBABEDE );

  /* rotate right by 40 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 40;
  
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xBEDECAFB && lightBank[1] == 0xADCAFEBA );
  
  /* rotate left by 268435455 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = -268435455;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xE57F5D5F && lightBank[1] == 0x6F657DD6 );

  /* rotate right by 268435455 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 268435455;
  
  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0x95FD757D && lightBank[1] == 0xBD95F75B );
  
  /* No rotate */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 0;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  printf( "Finished running tests on rotate()\n" );
}


int main() {
  testrotate();

  return 0;
}
