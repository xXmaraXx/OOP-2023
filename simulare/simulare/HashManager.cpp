#include "Hash.h"
#include "HashManager.h"
#include <cstdio>


Hash*& HashManager::operator[](const char* s) {
    list[count].nume = s;
    return list[count++].hash;

}

void HashManager::print_hashes(const char* s) {
    for (int i = 0; i < count; i++) {
        printf("%s, %d\n", list[i].nume, list[i].hash->calcHash(s));
    }
}

HashManager::HashManager() : count(0) {
}
