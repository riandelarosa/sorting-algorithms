#include "shell.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//
// The code for this sorting function is based off the pseudo code given in asgn5.pdf.

//
// Sorts array with shell method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *shell_sort(uint32_t *a, uint32_t e) {
  uint32_t *m_c; // declaration of move and comparison return array
  m_c = (uint32_t *)calloc(2,
      sizeof(
          uint32_t)); // array has size of 2 for moves [0], and comparisons [1]
  uint32_t m = 0; // counter for number of moves
  uint32_t c = 0; // counter for number of comparisons
  uint32_t n = e; // n is set to number of elements
  uint32_t count = 0; // count is set to the number of gaps
  while (n > 1) { // used to calculate number of gaps
    if (n <= 2) { // if n is 1 or lower, last gap
      n = 1; // last gap is set
      count++; // count plus one
    } else {
      n = 5 * n / 11; // next gap is set
      count++; // count plus one
    }
  }
  uint32_t step = e; // step starts as the number of elements in the array
  while (
      count
      > 0) { // will count down count until 0 to make sure there is correct number of gaps
    if (step <= 2) { // if step is 1 or lower, last gap
      step = 1; // last gap is set
    } else {
      step = 5 * step / 11; // next gap is set
    }
    for (uint32_t i = step; i < e;
         i++) { // goes from the gap until the last index
      for (uint32_t j = i; j > step - 1; j -= step) {
        c++; // comparisons count plus one
        if (a[j] < a[j - step]) { // swap if less than
          uint32_t temp = a[j]; // temporary index to preserve the value of a[j]
          a[j] = a[j - step]; // a[j] swaps values with a[j - step]
          a[j - step] = temp; // a[j - step] swaps values with a[j]
          m += 3; // moves count plus three
        }
      }
    }
    count--; // decrements count
  }
  m_c[0] = m; // correct number of moves stored at index 0
  m_c[1] = c; // correct number of comparisons stored at index 1
  return m_c; // returns move and comparison array
}
