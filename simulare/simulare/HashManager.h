#pragma once
#include "Hash.h"

class HashManager {
    struct hash_elem {
        Hash* hash;
        char const* nume;
    } list[4];

    int count;
public:
    Hash*& operator[](const char*);
    void print_hashes(const char*);
    HashManager();
};