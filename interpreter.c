#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// A struct that contains a dynamic array of integers
// The struct owns the array and is responsible for freeing it
typedef struct {
  int *buffer;
  size_t size;
  size_t capacity;
} array_of_int;
array_of_int read_int_array_from_file(const char *filename) {
  assert(filename != NULL);
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Could not open file '%s'\n", filename);
    exit(1);
  }
  const size_t initial_capacity = 256;
  size_t capacity = initial_capacity;
  int *array = malloc(capacity * sizeof(int)); // Start with a smaller initial capacity
  size_t size = 0;
  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  while (true) {
    int value = 0;
    int status = fscanf(file, "%d", &value);
    if (status == EOF) {
      break;
    }
    if (size >= capacity) {
      // Double the capacity and reallocate memory
      capacity *= 2;
      int *new_array = realloc(array, capacity * sizeof(int));
      if (new_array == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(array);
        exit(1);
      }
      array = new_array;
    }
    array[size] = value; // Insert the value into the array
    size++;
  }
  fclose(file);
  return (array_of_int){.buffer = array, .size = size, .capacity = capacity};
}

void main( int argc, char** argv) {
    int registers[10] = {0};
    unsigned long long RAM[1000] = {0};





    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    array_of_int array = read_int_array_from_file(argv[1]);
    for (size_t i = 0; i < array.size; i++) {
        printf("%d\n", array.buffer[i]);
    }
    free(array.buffer);
    return 0;
}