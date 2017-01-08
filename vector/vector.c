#include "vector.h"

vector* new_vector () {
    vector* ret = (vector*)(malloc(sizeof(vector)));

    // We can assume no memory errors occur.

    ret->data = (void**)(malloc(sizeof(void*) * 8));
    // Size is the number of elements, capacity is how much the vector can hold.
    ret->size = 0;
    ret->capacity = 8;

    return ret;
}

void delete_vector () {}