#include "binary.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//
// The code for this sorting function is based off the pseudo code given in asgn5.pdf.

//
// Sorts array with binary insertion method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *binary_insertion_sort(uint32_t *a, uint32_t e) {
  uint32_t *m_c; // declaration of move and comparison return array
  m_c = (uint32_t *)calloc(2,
      sizeof(
          uint32_t)); // array has size of 2 for moves [0], and comparisons [1]
  uint32_t m = 0; // counter for number of moves
  uint32_t c = 0; // counter for number of comparisons
  for (uint32_t i = 1; i < e; i++) { // from 0 till e - 1
    uint32_t value = a[i]; // value becomes element at index i
    uint32_t left = 0; // left is set to first index
    uint32_t right = i; // right is set to current index
    while (left < right) {
      uint32_t mid
          = left + ((right - left) / 2); // mid becomes calculation of middle
      c++; // comparisons count plus one
      if (value
          >= a[mid]) { // if value is greater or equal to the element at index mid
        left = mid + 1; // left becomes mid plus one
      } else {
        right = mid; // right becomes mid
      }
    }
    for (uint32_t j = i; j > left;
         j--) { // runs while j is greater than left most value
      uint32_t temp = a[j]; // temporary index to preserve the value of a[j]
      a[j] = a[j - 1]; // a[j] swaps values with a[j - 1]
      a[j - 1] = temp; // a[j - 1] swaps values with a[j]
      m += 3; // moves count plus three
    }
  }
  m_c[0] = m; // correct number of moves stored at index 0
  m_c[1] = c; // correct number of comparisons stored at index 1
  return m_c; // returns move and comparison array
}
