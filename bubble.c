#include "bubble.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//
// The code for this sorting function is based off the pseudo code given in asgn5.pdf.

//
// Sorts array with bubble method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *bubble_sort(uint32_t *a, uint32_t e) {
  uint32_t *m_c; // declaration of move and comparison return array
  m_c = (uint32_t *)calloc(2,
      sizeof(
          uint32_t)); // array has size of 2 for moves [0], and comparisons [1]
  uint32_t m = 0; // counter for number of moves
  uint32_t c = 0; // counter for number of comparisons
  for (uint32_t i = 0; i < e; i++) { // from 0 till e - 1
    uint32_t j = e - 1; // j is the last possible index
    while (j > i) { // runs until j is the same value as i
      c++; // comparisons count plus one
      if (a[j] < a[j - 1]) {
        uint32_t temp = a[j]; // temporary index to preserve the value of a[j]
        a[j] = a[j - 1]; // a[j] swaps values with a[j - 1]
        a[j - 1] = temp; // a[j - 1] swaps values with a[j]
        m += 3; // moves count plus three
      }
      j--; // j decreases by 1
    }
  }
  m_c[0] = m; // correct number of moves stored at index 0
  m_c[1] = c; // correct number of comparisons stored at index 1
  return m_c; // returns move and comparison array
}
