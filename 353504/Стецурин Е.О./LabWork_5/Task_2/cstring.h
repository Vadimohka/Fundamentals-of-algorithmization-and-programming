#ifndef CSTRING_H
#define CSTRING_H

#include <stddef.h>
#include <stdbool.h>

class CString
{
public:
    CString();
    void* memcpy(void* dest, const void* src, size_t n);
    void* memmove(void* dest, const void* src, size_t n);
    char* strcpy(char* dest, const char* src);
    char* strncpy(char* dest, const char* src, size_t n);
    char* strcat(char* dest, const char* src);
    char* strncat(char* dest, const char* src, size_t n);
    int memcmp(const void* ptr1, const void* ptr2, size_t n);
    int strcmp(const char* str1, const char* str2);
    int strcoll(const char* s1, const char* s2);
    int strncmp(const char* str1, const char* str2, size_t n);
    size_t strxfrm(char* dest, const char* src, size_t n);
    char* strtok(char* s1, const char* s2);
    void* memset(void* dest, int value, size_t n);
    const char* strerror(int errnum);
    size_t strlen(const char* str);
};

#endif // CSTRING_H
