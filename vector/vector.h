#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

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
void delete_vector_free (vector*);

// Operations.
void push_back (vector*, void*);
void push_back_int (vector*, int);
void push_back_str (vector*, char*);
void insert (vector*, void*, int);
void** get (vector*, int);
void   set (vector*, int, void*);

// Search.
bool search (vector*, void*, bool (*)(void*, void*));
bool search_int (vector*, int);
bool search_str (vector*, char*);

#endif /* VECTOR_H */