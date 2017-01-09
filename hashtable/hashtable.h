#ifndef HASHTABLE_H
#define HASHTABLE_H

// Keys and values can only be ints and strs for now.
struct entry_pair {
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
};

#endif /* HASHTABLE_H */