#include "MovieSeries.h"
#include <cstring>
#include <cstdio>
#include <algorithm>

void MovieSeries::init() {
    count = 0;
}

bool MovieSeries::add(Movie* s) {

    if (count > 16)
        return false;
    else {
        series[count] = s;
        count++;
        return true;
    }

}

void MovieSeries::print() {
    for (int i = 0; i < count; i++) {
        printf(
              "%s,%d,%1.f,%d,%d\n",
              series[i]->get_name(),
              series[i]->get_year(),
              series[i]->get_score(),
              series[i]->get_length(),
              series[i]->get_passed_years());
    }

}

void MovieSeries::sort() {

    for (int i = 0; i < count-1; i++) 
        for (int j = i + 1; j < count; j++) {
            if (series[i]->get_passed_years() < series[j]->get_passed_years()) {
                std::swap(series[i], series[j]);
            }
        }
}

