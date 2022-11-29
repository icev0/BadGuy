#ifndef OBFUSCATE
#define OBFUSCATE

#include <malloc.h>

#define OBFUSCATE(x) OBFUSCATE_KEY(x, '0')

size_t strlen(const char *_Str) {
    size_t count;
    while (*_Str)
        _Str++, count++;
    return count;
}

char *OBFUSCATE_KEY(char *str, char key) {
    size_t count = strlen(str);
    char *ret = (char*)malloc(count);
    size_t i = 0;
    while (i < count)
        *(ret + i) = *(str + i) ^ key, i++;
    *(ret + i) = 0;
    return ret;
}

#endif