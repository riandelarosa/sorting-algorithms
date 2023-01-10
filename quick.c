#include "quick.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//
// The code for this sorting function is based off the pseudo code given in asgn5.pdf.

//
// Partitions arrays into two subarrays by selecting an element from the array and designating it as a pivot.
//
// a : The number of elements in the array
// left : Elements in the array that are less than the pivot goto the left subarray.
// right : Elements in the array that are greater than or equal to the pivot go to the rightsubarray.
//
uint32_t *partition(uint32_t *a, uint32_t left, uint32_t right) {
  uint32_t *m_c_h; // declaration of move and comparison return array
  m_c_h = (uint32_t *)calloc(3,
      sizeof(
          uint32_t)); // array has size of 3 for moves [0], comparisons [1]. hi [2]
  uint32_t m = 0; // counter for number of moves
  uint32_t c = 0; // counter for number of comparisons
  uint32_t pivot = a[left]; // pivot is set to element at index left
  uint32_t lo = left + 1; // lo starts as left plus one
  uint32_t hi = right; // hi starts as right
  while (1) { // while true loop
    c++; // comparisons count plus one
    while (lo <= hi && a[hi] >= pivot) { // if greater than or equal to pivot
      hi--; // hi decrements
      c++; // comparisons count plus one
    }
    c++; // comparisons count plus one
    while (lo <= hi && a[lo] <= pivot) { // if less than or equal to pivot
      lo++; // lo increments
      c++; // comparisons count plus one
    }
    if (lo <= hi) { // if low is less than hi, swap
      uint32_t temp = a[lo]; // temporary index to preserve the value of a[lo]
      a[lo] = a[hi]; // a[lo] swaps values with a[hi]
      a[hi] = temp; // a[hi] swaps values with a[lo]
      m += 3; // moves count plus three
    } else {
      break; // break out of while true loop
    }
  }
  uint32_t temp = a[left]; // temporary index to preserve the value of a[left]
  a[left] = a[hi]; // a[left] swaps values with a[hi]
  a[hi] = temp; // a[hi] swaps values with a[left]
  m += 3; // moves count plus three
  m_c_h[0] = m; // correct number of moves stored at index 0
  m_c_h[1] = c; // correct number of comparisons stored at index 1
  m_c_h[2] = hi; // hi is stored at index 2 for recursive reasons
  return m_c_h; // returns move and comparison array
}

//
// Sorts array with quick method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *quick_sort(uint32_t *a, uint32_t l, uint32_t r) {
  uint32_t *m_c_h; // declaration of move and comparison return array
  m_c_h = (uint32_t *)calloc(3,
      sizeof(
          uint32_t)); // array has size of 3 for moves [0], comparisons [1]. hi [2]
  uint32_t m = 0; // counter for number of moves
  uint32_t c = 0; // counter for number of comparisons
  if (l < r) { // runs if l is correctly less than r
    m_c_h = partition(a, l, r); // partition used to separate into subarrays
    m += (uint32_t)m_c_h[0]; // number of moves from array is added to m
    c += (uint32_t)m_c_h[1]; // number of comparisons from array is added to c
    uint32_t index = m_c_h[2]; // index is set to hi from partition function
    m_c_h = quick_sort(a, l,
        (index - 1)); // quicksort call with l as left and index - 1 as right
    m += (uint32_t)m_c_h[0]; // number of moves from array is added to m
    c += (uint32_t)m_c_h[1]; // number of comparisons from array is added to c
    m_c_h = quick_sort(a, (index + 1),
        r); // quicksort call with index + 1 as left and r as right
    m += (uint32_t)m_c_h[0]; // number of moves from array is added to m
    c += (uint32_t)m_c_h[1]; // number of comparisons from array is added to c
  }
  m_c_h[0] = m; // correct number of moves stored at index 0
  m_c_h[1] = c; // correct number of comparisons stored at index 1
  return m_c_h; // returns move and comparison array
}
