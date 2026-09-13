#include <stdio.h>
#include "cvector.h"


int main (int argc, char *argv[]) {
  size_t initial_size, desired_size;
  VectorError status;
  vector_t* v = NULL;
  size_t size, capacity;
  
  if (argc < 3 || sscanf(argv[1], "%lu", &initial_size) != 1 || sscanf(argv[2], "%lu", &desired_size) != 1) {
    printf("Usage: %s initial_size desired_size\n", argv[0]);
    return 0;
  }

  status = vector_init (&v, initial_size);
  if (status != VECTOR_SUCCESS) {
    printf("%s", vector_status_string(status));
    return status;
  }

  for (size_t i = 0; i < desired_size && status == VECTOR_SUCCESS; i++) {
    status = vector_push(v, i);
    if (status == VECTOR_SUCCESS) {
      vector_get_size(v, &size);
      vector_get_capacity(v, &capacity);
      
      printf("size: %lu\n", size);
      printf("capacity: %lu\n\n", capacity);
    }
  }
  if (status != VECTOR_SUCCESS) {
    printf("%s", vector_status_string(status));
    vector_free(v);
    return status;
  }
  
  vector_get_size(v, &size);
  for (size_t i = 0; i < size; i++) {
    int tmp;
    vector_get(v, i, &tmp);
    printf("%d ", tmp);
  }
  printf("\n");

  vector_free(&v);
  return 0;
}

