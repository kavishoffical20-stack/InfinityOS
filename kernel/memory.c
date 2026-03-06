#include "include/kernel.h"

void* kmemset(void* dst, int value, size_t size) {
    unsigned char* d = (unsigned char*)dst;
    for (size_t i = 0; i < size; ++i) {
        d[i] = (unsigned char)value;
    }
    return dst;
}

void* kmemcpy(void* dst, const void* src, size_t size) {
    unsigned char* d = (unsigned char*)dst;
    const unsigned char* s = (const unsigned char*)src;
    for (size_t i = 0; i < size; ++i) {
        d[i] = s[i];
    }
    return dst;
}

size_t kstrlen(const char* s) {
    size_t i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}
