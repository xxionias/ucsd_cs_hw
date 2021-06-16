#include "test.h"
#include  "pa2.h"

void testdisplayLights() {
  unsigned int lightBank[2];
  lightBank[0] = 0x0000000F;
  lightBank[1] = 0x0000000F;
  displayLights( lightBank ); }

int main() {
  testdisplayLights();

  return 0; }
