#ifndef PAMT_H   /* Macro Guard */
#define PAMT_H

#include <thread>

/*
 * Local function prototypes for PAMT1
 */

struct result sequentialSquaredSumMinMax( signed char a[], int lo, int hi );
void initData( signed char a[], int size );
void usage( char* filename );

/*
 * The data structure to encapsulate the results of the calculations.
 */

struct result {
  long long sum;
  int min;
  int max;
};

#endif
