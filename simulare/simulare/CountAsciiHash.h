#pragma once
#include "Hash.h"

class CountAsciiHash : public Hash {
public:
    int calcHash(const char*) override;
};