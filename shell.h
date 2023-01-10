// shell.h - Contains the function declarations for the Shell sorting method.

#ifndef __SHELL_H__
#define __SHELL_H__

#include <inttypes.h>
#include <stdbool.h>

//
// Sorts array with shell method.
//
// a : The array that is going to be sorted.
// e : The number of elements in the array
//
uint32_t *shell_sort(uint32_t *a, uint32_t e);

#endif
