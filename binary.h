// binary.h - Contains the function declarations for the Binary Insertion sorting method.

#ifndef __BINARY_H__
#define __BINARY_H__

#include <inttypes.h>
#include <stdbool.h>

//
// Sorts array with binary insertion method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *binary_insertion_sort(uint32_t *a, uint32_t e);

#endif
