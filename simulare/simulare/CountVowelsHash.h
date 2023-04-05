#pragma once
#include "Hash.h"

class CountVowelsHash : public Hash {
public:
    int calcHash(const char*) override;
};