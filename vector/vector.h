#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/**
 * C++-style vectors, with the tedious programming in C.
 */

struct vectors {
    size_t size;
    size_t capacity;
    void** data;
} typedef vector;

vector* new_vector ();
void delete_vector (vector*);

#endif /* VECTOR_H */