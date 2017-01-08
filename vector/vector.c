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
    
    for (size_t i = 0; i < _to_del->size; ++i) {
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
    size_t new_capacity = _vec->capacity * 2;
    void** new_data  = (void**)(malloc(sizeof(void*) * new_capacity));

    // Copy the elements over.
    for (size_t i = 0; i < _vec->size; ++i) {
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
    _vec->size++;
}

// Search for an element, given a comparison function.
bool search (vector* _vec, void* _data, bool (*_cmp)(void* _a, void* _b)) {
    if (!_vec || !_data || !_cmp) {
        return false;
    }

    for (int i = 0; i < _vec->size; ++i) {
        bool are_eq = _cmp(_vec->data[i], _data);
        if (are_eq) {
            return true;
        }
    }

    return false;
}

bool cmp_int (void* _a, void* _b) {
    return *((int*)(_a)) == *((int*)(_b));
}

bool search_int (vector* _vec, int _int) {
}

bool search_str (vector* _vec, char* _str) {}