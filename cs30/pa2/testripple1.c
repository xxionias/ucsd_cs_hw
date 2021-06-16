#include "test.h"
#include "pa2.h"

void testripple1() {
  unsigned int lightBank[2];

  (void) printf( "Testing ripple()\n" );

  lightBank[0] = 0x80000000;
  lightBank[1] = 0x00000000;

  ripple1( lightBank, 4 ); }

int main() {
  testripple1();

  return 0; }
