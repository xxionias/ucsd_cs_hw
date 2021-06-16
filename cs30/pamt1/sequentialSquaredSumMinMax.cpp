/* Filename: sequentialSquaredSumMinMax.cpp
 * Author:   Xinyi Bian
 * Userid:   cs30xfw
 * Date:     2/23/2018
 * Description:
 *  	     sequentialSquaredSumMinMax() takes a regerence to the array
 *  	     allocated in main(), and low and high indexes. It should then
 *  	     iterate through each element, from lo to hi and calculate the
 *  	     squared sum and determine the minimum and maximum values in
 *  	     this partition.
 */
#include <stdlib.h>
#include <stdio.h>
#include "pamt1.h"

/* 
 * Function Name: sequentialSquaredSumMinMax
 * Function Prototype:
 * struct result sequentialSquaredSumMinMax( signed char a[], int lo, int hi )
 * Description:
 *  	     sequentialSquaredSumMinMax() takes a regerence to the array
 *  	     allocated in main(), and low and high indexes. It should then
 *  	     iterate through each element, from lo to hi and calculate the
 *  	     squared sum and determine the minimum and maximum values in
 *  	     this partition.
 * Return Value:
 * The results will be saved in a struct result and returned to the caller
 */
struct result sequentialSquaredSumMinMax( signed char a[], int lo, int hi ) {
  // Initialize teh struct result
  struct result result1;
  result1.sum = result1.min = result1.max = 0;

  // Sum the squared element
  for(int ii = lo; ii < hi; ii++) {
    result1.sum += (long long)(a[ii] * a[ii]);
        
    // Comparing the element to store the min/max
    if(result1.min > (int)a[ii]){
      result1.min = (int)a[ii];
    }

    if(result1.max < (int)a[ii]) {
      result1.max = (int)a[ii];
    }
  }

  // Return the struct result
  return result1;
}
