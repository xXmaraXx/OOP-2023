#pragma once
#include "Hash.h"

class CountConsonantHash : public Hash {
public:
    int calcHash(const char*) override;
};