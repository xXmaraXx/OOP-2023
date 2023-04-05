#pragma once
#include "Hash.h"

class EasyHash : public Hash {
public:
    int calcHash(const char*) override;
};