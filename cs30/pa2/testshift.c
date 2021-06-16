/*
 * Filename: testshift.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function shift().
 * Date: 2.6.2018
 * Sources of Help: Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For shift() function prototype */


/*
 * Unit Test for shift.s
 *
 * void shift( unsigned int lightBank[], const int shiftCnt );
 * 
 * Shifts the current light pattern in the lightBank by shiftCnt places.
 * If shiftCnt is positive, shift left.  If shiftCnt is negative, shift right.
 */
void testshift()
{
  unsigned int lightBank[2];
  int shiftCnt;

  (void) printf( "Testing shift()\n" );


  /* Shift left by 1 bit */ 
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -1;
                                                                    
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x95FD757D && lightBank[1] == 0xBD95F75A );


  /* Shift right by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 1;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x657F5D5F && lightBank[1] == 0x6F657DD6 );
  
  /* Shift left by 3 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -3;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x57F5D5F6 && lightBank[1] == 0xF657DD68 );

  /* Shift right by 3 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 3;
  
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x195FD757 && lightBank[1] == 0xDBD95F75 );

  /* Shift left by 3 bits twice */
  
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -3;

  shift( lightBank, shiftCnt );
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xBFAEAFB7 && lightBank[1] == 0xB2BEEB40 );

  /* Shift right by 3 bits twice */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 3;

  shift( lightBank, shiftCnt );
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x32BFAEA  && lightBank[1] == 0xFB7B2BEE );
  
  /* Shift left by 40 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -40;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xCAFBAD00 && lightBank[1] == 0x0 );
  
  /* Shift right by 40 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 40;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x0 && lightBank[1] == 0xCAFEBA );

  /* Shift left by 268435455 bits */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -268435455;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x80000000 && lightBank[1] == 0x0 );
  
  /* Shift right by 268435455 bits twice */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 268435455;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x0 && lightBank[1] == 0x1 );
  
  /* No shift */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 0;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );


  printf( "Finished running tests on shift()\n" );
}


int main() {
  testshift();

  return 0;
}
