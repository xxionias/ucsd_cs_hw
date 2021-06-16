/*
 * Filename: testprintUsage.c
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: Unit test program to test the function printUsage().
 * Date: 2/20/2018
 * Sources of Help: Tutor
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"
#include "pa3Strings.h"

/*
 * Unit Test for printUsage.s
 *
 * void printUsage( FILE * stream, const char * const usageStr, 
 *                      const char * const progName )
 *
 * This function prints usageStr to the provided file stream, filling
 * usageStr's format specifier with progName.
 *
 * Return Value: None 
 */
void testprintUsage() {
  char file[] = "filename";
  printUsage( stderr, STR_SPAWN_USAGE_LONG, file ); 
}

int main() {
  printf("Running tests on printUsage()\n");
  testprintUsage();
  printf("Finished running tests on printUsage()\n");
  return 0;
}
