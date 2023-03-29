#pragma warning(disable : 4996)
#include "EveryClass.h"
#include <ostream>
#include <string.h>
#include <string>

ArrayValue::ArrayValue() {
    count = 0;
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < count; i++)
        delete[] array[i];
}

void ArrayValue::print(std::ostream& out, int indentation) const {
    out << "[";
    for (int i = 0; i < count-1; i++) {
        array[i]->print(out, indentation + 2);
        out << ", ";
    }
    array[count - 1]->print(out, indentation + 2);
    out << "]";
}

void ArrayValue::add(JsonValue* value) {
    array[count++] = value;
}

NullValue::NullValue() {
}

void NullValue::print(std::ostream& out, int indentation) const {
    out << "null";
}

NumberValue::NumberValue(int x) {
    this->number = x;
}


void NumberValue::print(std::ostream& out, int indentation) const {
    out << this->number;
}

const char* StringValue::getString() {
    return this->string;
}

StringValue::StringValue(const char* c) {
    strcpy(this->string, c);
}

StringValue::~StringValue() {
    delete[] string;
}

void StringValue::print(std::ostream& out, int indentation) const {
    out << "\"" << this->string << "\"";
}

BoolValue::BoolValue(bool x) {
    this->b = x;
}

void BoolValue::print(std::ostream& out, int indentation) const {
    if (b)
        out << "true";
    else
        out << "false";
}

ObjectValue::ObjectValue() {
    this->count = 0;
}

ObjectValue::~ObjectValue() {
    for (int i = 0; i < count; i++)
        delete[] objects[i];
    delete[] objects;
}

ObjectValue::operator unsigned() {
    return count;
}

void ObjectValue::print(std::ostream& out, int indentation = 0) const {
    out << "{";
    if (count > 0) {
        out << "\n";
        for (int i = 0; i < count - 1; i++) {
            out << std::string(indentation + 4, ' ');
            objects[i][0]->print(out, indentation + 4);
            out << ": ";
            objects[i][1]->print(out, indentation + 4);
            out << ",\n";
        }
        out << std::string(indentation + 4, ' ');
        objects[count - 1][0]->print(out, indentation + 4);
        out << ": ";
        objects[count - 1][1]->print(out, indentation + 4);
        out << "\n";
    }
    out << std::string(indentation, ' ') << "}";
}

void ObjectValue::add(const char* name, JsonValue* value) {
    JsonValue* stringValue = new StringValue(name);
    objects[count][0] = stringValue;
    objects[count++][1] = value;
}



