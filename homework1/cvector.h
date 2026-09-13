#ifndef CVECTOR_H
#define CVECTOR_H

typedef enum {
  VECTOR_SUCCESS      = 0,
  VECTOR_NULL_POINTER = 1,
  VECTOR_MEMORY_ERROR = 2,
  VECTOR_BOUNDS_ERROR = 3,
  VECTOR_EXISTS_ERROR = 4
} VectorError;

typedef struct vector_t vector_t;

VectorError vector_init (vector_t **v, size_t initial_capacity);
VectorError vector_push (vector_t *v, int value);
VectorError vector_free (vector_t **v);

VectorError vector_get (const vector_t *v, size_t index, int *element);
VectorError vector_get_size (const vector_t *v, size_t* size);
VectorError vector_get_capacity (const vector_t *v, size_t* capacity);

const char* vector_status_string (VectorError status);

#endif

