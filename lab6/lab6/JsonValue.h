#pragma once
#include <ostream>

class JsonValue {
public:
    virtual ~JsonValue() = 0;
  virtual void print(std::ostream& out, int indentation) const = 0;
};

inline JsonValue::~JsonValue() {
}