Emre Sunar
esunar

To compile:

1 Open the terminal
2 Type "make" to compile the C files
3 Type "make docs" to ensure that doxygen copies the html files into the proper directory
4 Execute the programs by using the commands indicated below

sort.c:

Function 1 - print_int_array

/** Prints an array of integers, one per line.
 * @param nums Array to print
 * @param count Number of elements to print
 */

Function 2 - sort_descending

/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to print
 * @param count Number of elements to print
 */

Function 3 - alt_sort_descending

/** Sorts an array of integers into descending order using pointers
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to print
 * @param count Number of elements to print
 */

 Function 4 - print_timeval

 /** Prints the contents of a timeval struct.
 * @param t Struct to print.
 */

 Function 5 - timediff

 /** Calculates difference between two timestamps. 
 * Note that this takes structs as parameters and returns a struct;
 * it does not use pointers.
 * @param time1 A time stamp
 * @param time2 another timestamp (assumed same as or later than time 1)
 * @return A timeval struct representing time2 - time1
 */

 timesort.c:

Function 1 - timesort

 /** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

 sorttest.c:

 Function 1 - Main

 /* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest some_number another_number ...
 * Example:
 *         ./sorttest 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

 sorttest2.c:

 Function 1 - Main

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

 Timing Results: 

 Test 1: 

 1. Using sort_descending
 
 ./sorttest2 900 1 

 Result:

Timestamp before sorting: Seconds: 1676174915, Microseconds: 673036
Timestamp after sorting: Seconds: 1676174915, Microseconds: 675750
Time spent sorting: Seconds: 0, Microseconds: 2714


 2. Using alt_sort_descending
 
 ./sorttest2 900 2

 Result:

Timestamp before sorting: Seconds: 1676174951, Microseconds: 722753
Timestamp after sorting: Seconds: 1676174951, Microseconds: 725316
Time spent sorting: Seconds: 0, Microseconds: 2563

Test 2: 

 1. Using sort_descending

 ./sorttest2 9900 1 

Timestamp before sorting: Seconds: 1676175271, Microseconds: 272625
Timestamp after sorting: Seconds: 1676175271, Microseconds: 423861
Time spent sorting: Seconds: 0, Microseconds: 151236


 2. Using alt_sort_descending

 ./sorttest2 9900 2

Timestamp before sorting: Seconds: 1676175297, Microseconds: 427944
Timestamp after sorting: Seconds: 1676175297, Microseconds: 539648
Time spent sorting: Seconds: 0, Microseconds: 111704

 Test 3: 

 1. Using sort_descending

 ./sorttest2 50000 1 

Timestamp before sorting: Seconds: 1676230491, Microseconds: 58416
Timestamp after sorting: Seconds: 1676230496, Microseconds: 815769
Time spent sorting: Seconds: 5, Microseconds: 757353

 2. Using alt_sort_descending

 ./sorttest2 50000 2

Timestamp before sorting: Seconds: 1676230541, Microseconds: 31438
Timestamp after sorting: Seconds: 1676230545, Microseconds: 295931
Time spent sorting: Seconds: 4, Microseconds: 264493

Is using incrementing pointers actually faster than using array indexing? If so, 
approximately how much faster?

From the testing shown above it is clear that incrementing pointers is actually considerably
faster than array indexing by a reasonable margin. 
Doing some quick math to calculate approximately how much faster:

Test 1: Microseconds: 2714 - Microseconds: 2563 = Faster by 151 Microseconds

Percent faster = 5.56%

Test 2: Microseconds: 151236 - Microseconds: 111704 = 39532 Microseconds

Percent faster = 26.14%

Test 3: Seconds: 5, Microseconds: 757353 - Seconds: 4, Microseconds: 264493 = 1.49286 Seconds

Percent faster = 25.94%