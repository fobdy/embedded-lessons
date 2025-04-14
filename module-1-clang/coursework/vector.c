#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector *vector_create(size_t element_size, size_t initial_capacity) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (!vec)
        return NULL;

    vec->data = malloc(element_size * initial_capacity);
    if (!vec->data) {
        free(vec);
        return NULL;
    }

    vec->element_size = element_size;
    vec->size = 0;
    vec->capacity = initial_capacity;
    return vec;
}

bool vector_push(Vector *vec, const void *element) {
    if (!vec || !element) {
        return false;
    }

    if (vec->size >= vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        void *new_data = realloc(vec->data, vec->element_size * new_capacity);

        if (!new_data) {
            return false;
        }

        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    void *target = (char *)vec->data + (vec->size * vec->element_size);
    memcpy(target, element, vec->element_size);

    vec->size++;
    return true;
}

void *vector_get(Vector *vec, size_t index) {
    if (!vec || index >= vec->size) {
        return NULL;
    }
    return (char *)vec->data + (index * vec->element_size);
}

void vector_free(Vector *vec) {
    if (vec) {
        free(vec->data);
        free(vec);
        vec = NULL;
    }
}