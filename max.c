#include "max.h"
#include <assert.h>
#include <stdio.h>

int max(int *numbers, int size) {
  //pre-condition
  assert(numbers && size > 0);
  
  // Sets the record to be the first element in the array
  int largestFound = numbers[0];
  for (int i = 0; i < size; i++) {
    if (numbers[i] > largestFound) {
      // If an element is found that is bigger than the largest found
      // This is the new record
      largestFound = numbers[i];
    }
  }
  return largestFound;
}

#ifndef TEST

int main() {

	return 0;
}
#endif
