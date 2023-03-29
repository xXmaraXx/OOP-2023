#pragma once
#include "JsonValue.h"
#include <vector>

class ArrayValue : public JsonValue {

    JsonValue* array[16]{};
    int count;
  public:
    ArrayValue();
    ~ArrayValue();
    void print(std::ostream& out, int indentation) const override;
    void add(JsonValue* value);

};

class NumberValue : public JsonValue {
    int number;

  public:
    NumberValue(int x);
    void print(std::ostream& out, int indentation) const override;
};

class NullValue : public JsonValue {
  public:
    NullValue();
    void print(std::ostream& out, int indentation) const override;
};

class BoolValue : public JsonValue {
    bool b;
  public:
    BoolValue(bool x);
    void print(std::ostream& out, int indentation) const override;

};

class StringValue : public JsonValue {
    char string[256];

  public:
    const char* getString();
    StringValue(const char* c);
    ~StringValue();
    void print(std::ostream& out, int indentation) const override;
};

class ObjectValue : public JsonValue {
    JsonValue* objects[16][2]{};
    int count;

    public:
      ObjectValue();
      ~ObjectValue();
      operator unsigned();
      void print(std::ostream& out, int indentation) const override;
      void add(const char* name, JsonValue* value);
};

