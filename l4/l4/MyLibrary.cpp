#pragma warning(disable : 4996)
#pragma warning(disable : 6386)
#include "MyLibrary.h"
#include <cstdarg>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cstring>


MyLibrary::MyLibrary(const MyLibrary& other) : output_stream(other.output_stream) {
    this->books_count = other.books_count;
    this->books = new int[books_count];
    for (unsigned i = 0; i < this->books_count; i++) {
        this->books[i] = other.books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream){
    this->books = nullptr;
    this->books_count = -1;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++) {
        this->books[i] = min + std::rand() % (max - min + 1);
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    this->books_count = 1;
    char* clone = new char[strlen(books_values) + 1];
    for (unsigned i = 0; i < strlen(books_values); i++)
        if (books_values[i] == ';')
            this->books_count++;
    this->books = new int[books_count];
    clone = strcpy(clone, books_values);
    char* current_id = new char;
    current_id = strtok(clone, ";");
    unsigned i = 0;
    while (current_id) {
        this->books[i++] = (int) std::atoi(current_id);
        current_id = strtok(nullptr, ";");
    }
    delete[] clone;
    delete current_id;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream){
    this->books_count = books_count;
    this->books = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (unsigned i = 0; i < books_count; i++) {
        this->books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : MyLibrary(std::cout, v.size(), v.begin()) {
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const {
    if (books_count == -1) {
        output_stream << "Found -1 books" << "\n";
        return;
    } else
        output_stream << "Found " << books_count<<" books"<< "\n";
    for (unsigned i = 0; i < books_count; ++i) {
        output_stream << books[i] << " ";
    }
    output_stream << "\n";
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index >= books_count) {
        return;
    }else books[book_index] = book_id;
}

unsigned MyLibrary::get_books_count() const {
    return this->books_count;
}

int MyLibrary::get_book_id_by_index(unsigned index) const {
    if (index >= books_count) {
        return -1;
    }
    return books[index];
}




