#include <stdlib.h>
#include "cvector.h"


struct vector_t {
    int *source;
    size_t size;
    size_t capacity;
};

VectorError vector_init (vector_t **v, size_t capacity) {
  if (!v) return VECTOR_NULL_POINTER;
  if (*v) return VECTOR_EXISTS_ERROR;
  
  *v = (vector_t*) malloc (sizeof (vector_t));
  if (!*v) return VECTOR_MEMORY_ERROR;
  
  (*v)->source = malloc (capacity * sizeof (int));
  if  (!(*v)->source) {
    free(*v);
    *v = NULL;
    return VECTOR_MEMORY_ERROR;
  }

  (*v)->size = 0;
  (*v)->capacity = capacity;
  return VECTOR_SUCCESS;
}

VectorError vector_push (vector_t *v, int value) {
  if (!v) return VECTOR_NULL_POINTER;
  if (v->size >= v->capacity) {
    int *tmp;
    size_t new_capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
    tmp = realloc (v->source, new_capacity * sizeof (int));
    if (!tmp) return VECTOR_MEMORY_ERROR;
    v->source = tmp;
    v->capacity = new_capacity;
  }
  v->source[v->size++] = value;
  return VECTOR_SUCCESS;
}

VectorError vector_free (vector_t **v) {
  if (v && *v) {
    free ((*v)->source);
    (*v)->source = NULL;
    (*v)->size = 0;
    (*v)->capacity = 0;
    free(*v);
    *v = NULL;
  }
  return VECTOR_SUCCESS;
}

VectorError vector_get (const vector_t *v, size_t index, int *element) {
  if (!v) return VECTOR_NULL_POINTER;
  if (index >= v->size) return VECTOR_BOUNDS_ERROR;
  *element = v->source[index];
  return VECTOR_SUCCESS;
}

VectorError vector_get_size (const vector_t *v, size_t* size) {
  if (!v) return VECTOR_NULL_POINTER;
  *size = v->size;
  return VECTOR_SUCCESS;
}

VectorError vector_get_capacity (const vector_t *v, size_t* capacity) {
  if (!v) return VECTOR_NULL_POINTER;
  *capacity = v->capacity;
  return VECTOR_SUCCESS;
}

const char* vector_status_string (VectorError status) {
  switch (status) {
    case VECTOR_SUCCESS:      return "Success";
    case VECTOR_NULL_POINTER: return "Null pointer";
    case VECTOR_MEMORY_ERROR: return "Memory error";
    case VECTOR_BOUNDS_ERROR: return "Out of bounds error";
    case VECTOR_EXISTS_ERROR: return "You cannot erase vector";
    default:                  return "Unknown error";
  }
}

