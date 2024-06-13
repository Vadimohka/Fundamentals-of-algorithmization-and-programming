#include "stddef.h"
#include "stdbool.h"

extern "C" {
    void *memcpy(void *s1, const void *s2, size_t n);
    void *memmove(void *s1, const void *s2, size_t n);
    char *strcpy(char *s1, const char *s2);
    char *strncpy(char *s1, const char *s2, size_t n);
    char *strcat(char *s1, const char *s2);
    char *strncat(char *s1, const char *s2, size_t n);
    int memcmp(const void *s1, const void *s2, size_t n);
    int strcmp(const char *s1, const char *s2);
    int strncmp(const char *s1, const char *s2, size_t n);
    size_t strxfrm(char *s1, const char *s2, size_t n);
    char *strtok(char *s1, const char *s2);
    void *memset(void *s, int c, size_t n);
   
    size_t strlen(const char *s);
}