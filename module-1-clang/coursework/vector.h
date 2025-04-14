#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * Vector
 */

typedef struct Vector {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
} Vector;

Vector *vector_create(size_t element_size, size_t initial_capacity);
bool vector_push(Vector *vec, const void *element);
void *vector_get(Vector *vec, size_t index);
void vector_free(Vector *vec);

#endif