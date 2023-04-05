#include "EasyHash.h"

int EasyHash::calcHash(const char* s)
{
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='a' && s[i]<='z')) { 
            if (s[i] == 'a' || s[i] == 'A' ||
                s[i] == 'e' || s[i] == 'E' ||
                s[i] == 'i' || s[i] == 'I' ||
                s[i] == 'o' || s[i] == 'O' ||
                s[i] == 'u' || s[i] == 'U') {
                nr += ((int)s[i] * 10);
            }
            else if (s[i] != 'a' && s[i] != 'A' &&
                s[i] != 'e' && s[i] != 'E' &&
                s[i] != 'i' && s[i] != 'I' &&
                s[i] != 'o' && s[i] != 'O' &&
                s[i] != 'u' && s[i] != 'U') {
                nr+=((int)s[i]*11);
            } 
        }
        else {
            nr += ((int)s[i] * 12);
        }
    }
    return nr;
}
