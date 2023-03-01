#pragma once
#include "movie.h"

class MovieSeries {
    Movie* series[16];
    int count;

    public:
      void init();
      bool add(Movie* s);
      void print();
      void sort();
};