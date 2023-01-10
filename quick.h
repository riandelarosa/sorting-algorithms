// quick.h - Contains the function declarations for the Quick sorting method.

#ifndef __QUICK_H__
#define __QUICK_H__

#include <inttypes.h>
#include <stdbool.h>

//
// Partitions arrays into two subarrays by selecting an element from the array and designating it as a pivot.
//
// a : The number of elements in the array
// left : Elements in the array that are less than the pivot goto the left subarray.
// right : Elements in the array that are greater than or equal to the pivot go to the rightsubarray.
//
uint32_t *partition(uint32_t *a, uint32_t left, uint32_t right);

//
// Sorts array with quick method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *quick_sort(uint32_t *a, uint32_t l, uint32_t r);

#endif
