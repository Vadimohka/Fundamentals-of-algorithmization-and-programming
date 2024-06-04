#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <memory>

namespace stringFunctions
{
    void* memcpy(void*, const void*, size_t);
    void* memmove(void*, const void*, size_t);
    char* strcpy(char*, const char*);
    char* strncpy(char*, const char*, size_t);
    char* strcat(char*, const char*);
    char* strncat(char*, const char*, size_t);
    int memcmp(const void*, const void*, size_t);
    int strcmp(const char*, const char*);
    int strncmp(const char*, const char*, size_t);
    int strcoll(const char*, const char*);
    char* strtok(char*, const char*);
    void* memset(void*, int, size_t);
    char* strerror(int);
    size_t strlen(const char*);
    size_t strxfrm(char* s1, const char* s2, size_t n);
};

#endif // STRINGFUNCTIONS_H
