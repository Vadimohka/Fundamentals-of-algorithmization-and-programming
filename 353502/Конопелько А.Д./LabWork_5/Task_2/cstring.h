#ifndef CSTRING_H
#define CSTRING_H

#include <stddef.h>
#include <stdbool.h>

class CString
{
public:
    CString();
    void* memcpy(void* destination, const void* source, size_t num); // copy block of memory
    void* memmove(void* destination, const void* source, size_t num); // move block of memory
    char* strcpy(char* destination, const char* source); // copy string
    char* strncpy(char* destination, const char* source, size_t num); // copy characters from string
    char* strcat(char* destination, const char* source); // concatenate strings
    char* strncat(char* destination, const char* source, size_t num); // append characters from string
    int memcmp(const void* ptr1, const void* ptr2, size_t num); // compare two blocks of memory
    int strcmp(const char* str1, const char* str2); // compare two strings
    int strcoll(const char* s1, const char* s2); // compare two strings using locale
    int strncmp(const char* str1, const char* str2, size_t num); // compare characters of two strings
    size_t strxfrm(char* destination, const char* source, size_t num); // transform string using locale
    char* strtok(char* s1, const char* s2); // split string into tokens
    void* memset(void* destination, int value, size_t num); // fill block of memory
    size_t strlen(const char* str); // get string length
};

#endif // CSTRING_H
