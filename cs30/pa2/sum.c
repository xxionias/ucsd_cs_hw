#include <stdio.h>

int main( void ) {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  int f = 6;
  int g = 7;
  
  int sum;

  sum = sum7( a, b, c, d, e, f, g );

  printf( "Sum of %d %d %d %d %d %d %d = %d\n", a, b, c, d, e, f, g, sum );

  return 0;

}
