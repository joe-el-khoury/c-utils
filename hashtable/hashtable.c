#include "hashtable.h"

char* _dup_str (char* _str) {
    if (!_str) {
        return NULL;
    }

    size_t len = strlen(_str);
    char* ret = (char*)(malloc(sizeof(char) * len));
    for (int i = 0; i < len; ++i) {
        ret[i] = _str[i];
    }
    return ret;
}

// Allocates a pair.
entry_pair* _new_pair () {
    return (entry_pair*)(malloc(sizeof(entry_pair)));
}

entry_pair* _new_int_int_pair (int _key, int _val) {
    entry_pair* ep = _new_pair();
    ep->_int_int.key = _key;
    ep->_int_int.val = _val;
    return ep;
}

entry_pair* _new_int_str_pair (int _key, char* _val) {
    entry_pair* ep = _new_pair();
    ep->_int_str.key = _key;
    ep->_int_str.val = _dup_str(_val);
    return ep;
}

entry_pair* _new_str_str_pair (char* _key, char* _val) {
    entry_pair* ep = _new_pair();
    ep->_str_str.key = _dup_str(_key);
    ep->_str_str.val = _dup_str(_val);
    return ep;
}

entry_pair* _new_str_int_pair (char* _key, int _val) {
    entry_pair* ep = _new_pair();
    ep->_str_int.key = _dup_str(_key);
    ep->_str_int.val = _int;
    return ep;
}