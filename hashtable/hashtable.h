#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <stdlib.h>

// Keys and values can only be ints and strs for now.
struct entry_pairs {
    union {
        struct {
            int key;
            int val;
        } _int_int;

        struct {
            int   key;
            char* val;
        } _int_str;

        struct {
            char* key;
            char* val;
        } _str_str;

        struct {
            char* key;
            int   val;
        } _str_int;
    };
} typedef entry_pair;

// Allocation and deallocation of pairs.
entry_pair* _new_int_int_pair (int, int);
entry_pair* _new_int_str_pair (int, const char*);
entry_pair* _new_str_str_pair (const char*, const char*);
entry_pair* _new_str_int_pair (const char*, int);
void _free_int_int_pair (entry_pair*);
void _free_int_str_pair (entry_pair*);
void _free_str_str_pair (entry_pair*);
void _free_str_int_pair (entry_pair*);

#endif /* HASHTABLE_H */