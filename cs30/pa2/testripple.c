#include "test.h"
#include "pa2.h"

void testripple() {
  unsigned int lightBank[2];

  (void) printf( "Testing ripple()\n" );

  lightBank[0] = 0x80000000;
  lightBank[1] = 0x00000000;

  displayLights(lightBank);
  ripple( lightBank, -4 ); }

int main() {
  testripple();

  return 0; }
