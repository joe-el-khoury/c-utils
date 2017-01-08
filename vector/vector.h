#ifndef VECTOR_H
#define VECTOR_H

/**
 * C++-style vectors, with the tedious programming in C.
 */

struct vectors {
    size_t size;
    size_t capacity;
    void** data;
} typedef vector;

#endif /* VECTOR_H */