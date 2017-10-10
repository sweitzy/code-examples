/* 

sequence.c

Please solve: Take two numbers, second number greater than the first,
as input say 3 and 7 and print the sequence as follows using
recursion: 3 4 5 6 7 6 5 4 3 Recursion involves calling the same
function recursively until some condition is met.

*/

#include <stdio.h>
#include <stdlib.h>

/* sequence: recursive function to print a number sequence */
void sequence(long lower, long upper) {

  if (lower > upper) {
    /* invalid case */
    return;
  } else if (lower == upper) {
    /* we are at peak of sequence */
    printf("%ld ", upper);
  } else {
    printf("%ld ", lower);
    /* recurse toward upper */ 
    sequence(lower + 1, upper);
    printf("%ld ", lower);
  }

} /* sequence */

int main(int argc, char **argv)
{
  if (argc != 3) {
    printf("Wrong number of arguments.\n");
    printf("Usage: %s <lower> <upper>\n", argv[0]);
    return 1;
  }

  long lower = atoi(argv[1]);
  long upper = atoi(argv[2]);

  sequence(lower, upper);
  /* need final newline */
  printf("\n");

  return 0;
} /* main */
