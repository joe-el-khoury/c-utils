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

void delete_vector (vector* _to_del) {
    if (!_to_del) {
        return;
    }
    
    if (!_to_del->data) {
        goto del_just_vec;
    }
    
    for (int i = 0; i < _to_del->size; ++i) {
        void* curr = _to_del->data[i];
        if (curr) {
            free(curr);
        }
    }
    free(_to_del->data);

del_just_vec:
    free(_to_del);
}

void _increase_capacity (vector* _vec) {
    if (!_vec) {
        return;
    }
    if (!_vec->data) {
        return;
    }

    // Double the capacity of the vector.
    int new_capacity = _vec->capacity * 2;
    void** new_data  = (void**)(malloc(sizeof(void*) * new_capacity));

    // Copy the elements over.
    for (int i = 0; i < _vec->size; ++i) {
        new_data[i] = _vec->data[i];
    }

    free(_vec->data);
    _vec->capacity = new_capacity;
}

void push_back (vector* _vec, void* _data) {
    if (!_vec || !_data) {
        return;
    }

    if (_vec->size == _vec->capacity) {
        _increase_capacity(_vec);
    }
    _vec->data[_vec->size] = _data;
}