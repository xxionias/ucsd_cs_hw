/* Filename: numOfFactors.cpp
 * Author: Xinyi Bian
 * Userid: cs30xfw
 * Description: numOfFactors() takes the number n which we are calculating
 * 		how many evenly-divisible factors there are, lo is the low
 * 		(inclusive) range of possible factors to check, and hi is 
 * 		the high (exclusive) range of possible factors to check. 
 * Date: 3/7/2018
 */

/*
 * Function name: numOfFactors()
 *
 * Function prototype: long long numOfFactors( long long n,
 *                                             long long lo,
 *                                             long long hi );
 *
 * Params: n is the value we are checking to determine how many factors
 *           evenly divide into it.
 *         lo is the low (inclusive) range of possible factors to check.
 *         hi is the high (exclusive) range of possible factors to check.
 *
 * Algorithm:
 *   if n <= 1 return 0 (we won't deal with values less than 2). By definition,
 *       prime numbers are greater than 1.
 *
 *   if lo <= 1, set lo to 2 (we won't deal with factors less than 2).
 *
 *   loop thru the range [lo, hi) as factors incrementing by 1 each time
 *       thru the loop checking if n is evenly divisible by each factor.
 *       If it is evenly divisible, increment the number of
 *       evenly-divisible factors for this range.
 *   
 *   There may be other more efficient algorithms, but this will do.
 *   We want to see how multi-threading in C++11 with async()/get()
 *   might improve overall performance.
 *
 * Side Effects: None.
 *
 * Error Conditions: None.
 *
 * Return value: long long int indicating the number of evenly-divisible
 *               factors in n.
 */

long long numOfFactors( long long n, long long lo, long long hi ) {
  long long counter = 0;
  if ( n <= 1 ) { return 0; }
  if ( lo <= 1 ) { lo = 2; }
  for( long long i = lo; i < hi; ++i ) {
    if( n%i == 0 ) { ++counter; }
  }
  return counter;
}

