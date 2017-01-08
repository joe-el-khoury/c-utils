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

// Allocation and deallocation.
vector* new_vector ();
void delete_vector (vector*);

// Operations.
void push_back (vector*, void*);

#endif /* VECTOR_H */