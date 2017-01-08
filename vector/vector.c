#include "vector.h"

#define INITIAL_ALLOC 8

vector* new_vector () {
    vector* ret = (vector*)(malloc(sizeof(vector)));

    // We can assume no memory errors occur.

    ret->data = (void**)(malloc(sizeof(void*) * INITIAL_ALLOC));
    // Size is the number of elements, capacity is how much the vector can hold.
    ret->size = 0;
    ret->capacity = INITIAL_ALLOC;

    return ret;
}

void delete_vector (vector* _to_del) {}