#ifndef MYSTRING_H
#define MYSTRING_H

#include <QDebug>
#include <bits/unique_ptr.h>

class MyString
{
public:
    MyString();
    MyString(char* c);
    void *memcpy(void *dest, const void *src, int n);
    void *memmove(void *dest, const void *src, int n);
    char *strcpy(char *dest, const char *src);
    int strlen(const char *str);
    char* strncpy(char* s1, const char* s2, int n);
    char* strcat(char* s1, const char* s2);
    char* strncat(char* s1, const char* s2, int n);
    int memcmp(const void* s1, const void* s2, int n);
    int strcmp(const char* s1, const char* s2);
    int strcoll(const char* s1, const char* s2);
    int strncmp(const char* s1, const char* s2, int n);
    int strxfrm(char* s1, const char* s2, int n);
    char* strtok(char* s1, const char* s2);
    void* memset(void* s, int c, int n);
    char* strerror(int errnum);
private:
    std::unique_ptr<char[]> str;
    int len;
};

#endif // MYSTRING_H
