#define _CRT_SECURE_NO_WARNINGS
#include "movie.h"
#include <cstring>


void Movie::set_name(const char* name) {
    strcpy(this->name, name);
}

void Movie::set_year(int year) {
    this->year = year;
}

void Movie::set_score(double score) {
    this->score = score;
}

void Movie::set_length(int length) {
    this->length = length;
}

const char* Movie::get_name() const {
    return name;
}

int Movie::get_year() const{
    return year;
}

double Movie::get_score() const {
    return score;
}

int Movie::get_length() const {
    return length;
}

int Movie::get_passed_years() const {
    return 2023-year;
}


