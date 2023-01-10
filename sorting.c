#include "binary.h"
#include "bubble.h"
#include "quick.h"
#include "shell.h"
#include <getopt.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
// The function main uses getopt() in order to receive a console command to sort an array filled with random values.
// Optional character argument inputs are: n # (number of elements in array), r # (random seed), p # (how many elements
// to print). There are four sorting methods: Bubble (-b), Shell (-s), Quick (-q), and Binary Insertion (-i) Each method
// has their own respective option, .c and .h files that connect to sorting.c If -A is inputted no sorting method will be
// printed twice. The number of moves and comparisons are tracked in each function and are printed when each sorting methods
// is printed. There are several default variables, and arrays used to keep track of the different data being calculated for
// the four different sorting methods.
//
#define OPTIONS "Absqip:r:n:"

int main(int argc, char **argv) {
  int c = 0; // used for the getopt while loop and switch cases
  uint32_t print = 100; // default value to print up to
  uint32_t seed = 8222022; // default random seed is 8222022
  uint32_t size = 100; // default size of array is 100
  uint32_t moves = 0; // used to keep track of moves in sort
  uint32_t comparisons = 0; // used to keep track of comparisons in sort
  uint32_t
      *array; // array of default values used to reset after sorting method runs
  uint32_t
      *sorted_array; // sorted array that is run through function and printed
  uint32_t *
      move_compare; // array used to store the number of moves and comparisons from each sorting function return
  int print_count = 0; // used to keep track of print spacing
  bool option_A, option_b, option_s, option_q, option_i, option_p, option_r,
      option_n; // booleans used to track options
  option_A = option_b = option_s = option_q = option_i = option_p = option_r
      = option_n = false;
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 'A': // when A is an argument
      option_A = true;
      break;
    case 'b': // when b is an argument
      option_b = true;
      break;
    case 's': // when s is an argument
      option_s = true;
      break;
    case 'q': // when q is an argument
      option_q = true;
      break;
    case 'i': // when i is an argument
      option_i = true;
      break;
    case 'p': // when p is an argument
      option_p = true;
      break;
    case 'r': // when r is an argument
      option_r = true;
      break;
    case 'n': // when n is an argument
      option_n = true;
      break;
    }
  }
  if (option_n) { // sets the size of the array
    for (int k = 0; k < argc; k++) { // from 0 to the number of arguments
      if (strcmp(argv[k], "-n")
          == 0) { // will take argument if string matches -n
        size = (uint32_t)atoi(
            argv[k
                 + 1]); // converts string to integer, size becomes that number
        array = (uint32_t *)calloc(size,
            sizeof(uint32_t)); // memory of inputted size is created for array
        sorted_array = (uint32_t *)calloc(size,
            sizeof(uint32_t)); // memory of inputted size is created for array
      }
    }
  } else {
    array = (uint32_t *)calloc(
        size, sizeof(uint32_t)); // default size of array creation
    sorted_array = (uint32_t *)calloc(
        size, sizeof(uint32_t)); // default size of array creation
  }
  if (option_r) { // sets the random seed
    for (int k = 0; k < argc; k++) { // from 0 to the number of arguments
      if (strcmp(argv[k], "-r")
          == 0) { // will take argument if string matches -r
        seed = (uint32_t)atoi(
            argv[k
                 + 1]); // converts string to integer, seed becomes that number
        srand(seed); // sets the random seed to the argument value.
        for (uint32_t i = 0; i < size;
             i++) { // sets all elements in array to random number
          array[i] = (uint32_t)(
              rand()
              & 0x3FFFFFFF); // the range of random values is restricted from 0 to 2^30 -1 through bit masking
        }
      }
    }
  } else {
    srand(seed); // sets the random seed to the default value.
    for (uint32_t i = 0; i < size;
         i++) { // sets all elements in array to random number
      array[i] = (uint32_t)(
          rand()
          & 0x3FFFFFFF); // the range of random values is restricted from 0 to 2^30 -1 through bit masking
    }
  }
  if (option_p) { // sets the amount of items to be printed
    for (int k = 0; k < argc; k++) { // from 0 to the number of arguments
      if (strcmp(argv[k], "-p")
          == 0) { // will take argument if string matches -p
        print = (uint32_t)atoi(
            argv[k
                 + 1]); // converts string to integer, print becomes that number
      }
    }
  }
  if (option_A) { // employs al sorting algorithms
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = binary_insertion_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Binary Insertion Sort\n%d elements, %d moves, %d compares\n", size,
        moves, comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = quick_sort(sorted_array, 0,
        size - 0); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function*/
    printf("Quick Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 1; i < print + 1;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print
                        + 1) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = shell_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Shell Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = bubble_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Bubble Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
  }
  if (option_i && !option_A) { // enables binary insert sort function
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = binary_insertion_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Binary Insertion Sort\n%d elements, %d moves, %d compares\n", size,
        moves, comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
  }
  if (option_q && !option_A) { // enables quick sort function
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = quick_sort(sorted_array, 0,
        size - 0); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function*/
    printf("Quick Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 1; i < print + 1;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print
                        + 1) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
  }
  if (option_s && !option_A) { // enables shell sort function
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = shell_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Shell Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
  }
  if (option_b && !option_A) { // enables bubble sort function
    for (uint32_t j = 0; j <= size; j++) {
      sorted_array[j] = 0; // resets all elements in sorted_array to 0
    }
    for (uint32_t j = 0; j < size; j++) {
      sorted_array[j]
          = array[j]; // resets all elements in sorted_array to array
    }
    move_compare = bubble_sort(sorted_array,
        size); // sorts the items and returns array of moves and comparisons
    moves = (uint32_t)move_compare[0]; // move count from function
    comparisons = (uint32_t)move_compare[1]; // comparison count from function
    printf("Bubble Sort\n%d elements, %d moves, %d compares\n", size, moves,
        comparisons); // header print
    for (uint32_t i = 0; i < print;
         i++) { // prints all the elements in the sorted array
      printf(
          "%13" PRIu32, sorted_array[i]); // correct format for printing array
      print_count++; // print count is iterated
      if (print_count == 7
          || i + 1
                 == print) { // if the seventh item or last item print new line
        printf("\n");
        print_count = 0; // resets print count
      }
    }
  }
  return 0; // end of program
}
