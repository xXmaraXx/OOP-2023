#include "CountAsciiHash.h"

int CountAsciiHash::calcHash(const char* s) {
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++)
        nr += (int)s[i];
    return nr;
}
