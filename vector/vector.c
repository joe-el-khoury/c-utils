#include "vector.h"

#define INITIAL_ALLOC 8

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      ALLOC/DEALLOC FUNCTIONS   /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

vector* new_vector_with_sz (size_t _sz) {
    vector* ret = (vector*)(malloc(sizeof(vector)));

    ret->data = (void**)(malloc(sizeof(void*) * _sz));
    // Size is the number of elements, capacity is how much the vector can hold.
    ret->size = 0;
    ret->capacity = _sz;

    return ret;
}

vector* new_vector () {
    return new_vector_with_sz(INITIAL_ALLOC);
}

// Only free the vector, but don't free its elements.
void delete_vector (vector* _vec) {
    if (!_vec) {
        return;
    }
    
    if (!_vec->data) {
        goto del_just_vec;
    }

    free(_vec->data);
del_just_vec:
    free(_vec);
}

// Free all the elements as well.
void delete_vector_free (vector* _vec) {
    if (!_vec) {
        return;
    }
    
    if (!_vec->data) {
        goto del_just_vec;
    }
    
    for (size_t i = 0; i < _vec->size; ++i) {
        void* curr = _vec->data[i];
        if (curr) {
            free(curr);
        }
    }
    
    free(_vec->data);
del_just_vec:
    free(_vec);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////    DONE ALLOC/DEALLOC FUNCTIONS   //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    _vec->data = new_data;
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

void push_back_int (vector* _vec, int _int) {
    int* data = (int*)(malloc(sizeof(int)));
    *data = _int;
    push_back(_vec, (void*)(data));
}

void push_back_str (vector* _vec, char* _str) {
    size_t len = strlen(_str);
    if (len <= 0) {
        return;
    }

    char* data = (char*)(malloc(sizeof(char) * len));
    push_back(_vec, (void*)(data));
}

// Insert an element at an arbitrary position in the vector.
// Should've used a linked list, though.
void insert (vector* _vec, void* _data, int _at) {
    if (!_vec || !_data) {
        return;
    }

    if (_vec->size == _vec->capacity) {
        _increase_capacity(_vec);
    }

    // Keep increasing capacity until we can make space for the element.
    while (_at >= _vec->capacity) {
        _increase_capacity(_vec);
    }

    // Inserting an element after the last element - no need to rearrange elements.
    if (_at >= _vec->size) {
        _vec->data[_at] = _data;
        _vec->size = _at+1;
        return;
    }

    // Inserting somewhere in the middle.- move all elements to the right of where we're inserting one slot forward.
    for (int i = _vec->size-1; i >= _at; ++i) {
        _vec->data[i+1] = _vec->data[i];
    }
    _vec->data[_at] = _data;
    _vec->size++;
}

// Get an element at a specific index, return NULL if element doesn't exist.
void** get (vector* _vec, int _idx) {
    if (!_vec || _idx < 0 || _idx >= _vec->size) {
        return NULL;
    }

    return &(_vec->data[_idx]);
}

void set (vector* _vec, int _idx, void* _data) {
    void** got = get(_vec, _idx);
    if (!got) {
        return;
    }

    *got = _data;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      SEARCH FUNCTIONS    ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

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

bool _cmp_int (void* _a, void* _b) {
    return *((int*)(_a)) == *((int*)(_b));
}

bool search_int (vector* _vec, int _int) {
    return search(_vec, (void*)(&_int), _cmp_int);
}

bool _cmp_str (void* _a, void* _b) {
    // Cast the void pointers.
    char* str_a = (char*)(_a);
    char* str_b = (char*)(_b);

    int i = 0;
    while (str_a[i] && str_b[i]) {
        if (str_a[i] != str_a[i]) {
            return false;
        }

        i++;
    }

    // We should've reached the null character in both strings if they are equal.
    return !str_a[i] && !str_b[i];
}

bool search_str (vector* _vec, char* _str) {
    return search(_vec, (void*)(_str), _cmp_str);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      END SEARCH FUNCTIONS    ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////