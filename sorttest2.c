#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define MAX_INT 1000000

/* Program which reads two arguments from the command line, one is an integer: a count of how 
 * many integers to process, and the other is either 1 or 2, specifing which sorting function to use
 * Allocates an array capable of holding that many random integers and then sorts them.
 * 
 *
 * Usage:
 *         ./sorttest2 some_number 1_or_2
 * Example:
 *         ./sorttest2 2014
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./sorttest2 some_number 1_or_2\n");
    return 1;
  }

  int which_function = atoi(argv[2]);
  if (!((which_function == 1) || (which_function == 2))) {
    printf("Must enter either '1' for sort_descending or '2' for alt_sort_descending\n");
    return 1;
  }

  int i; // array index 
  int count = atoi(argv[1]);
  int *array = malloc(sizeof(int) * count);

  // Generate random integers
  struct timeval tv;
  gettimeofday(&tv, NULL);
  srandom(tv.tv_usec);
  for (i = 0; i < count; i++) {
    array[i] = random() % MAX_INT;
  }

  // Sort the array using timesort()
  timesort(array, count, which_function);

  free(array);
  return 0;
}