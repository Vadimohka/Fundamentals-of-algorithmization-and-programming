#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <QString>

class myString
{
public:
    myString();

    myString(const char* s);

    myString(const myString& s);

    myString(myString&& s);

    ~myString();

    myString& operator=(const myString& s);

    myString& operator=(myString &&s);

    myString& operator=(const char* s);

    char* begin();
    const char* cbegin() const;
    char* end();
    const char* cend() const;
    std::reverse_iterator<char*> rbegin();
    std::reverse_iterator<char*> rend();

    static void* memcpy(void* dest, const void* src, size_t count);
    static void* memmove(void* dest, const void* src, size_t count);
    static void* memset(void* dest, int ch, size_t count);
    static char* strcpy(char* dest, const char* src);
    static char* strncpy(char* dest, const char* src, size_t count);
    static char* strcat(char* dest, const char* src);
    static char* strncat(char* dest, const char* src, size_t count);
    static int memcmp(const void* ptr1, const void* ptr2, size_t count);
    static int strcmp(const char* str1, const char* str2);
    static int strcoll(const char* str1, const char* str2);
    static int strncmp(const char* str1, const char* str2, size_t count);
    static size_t strxfrm(char* dest, const char* src, size_t count);
    static char* strtok(char* dest, const char* src);
    static char* strerror(int errnum);
    static size_t strlen(const char* s);

private:
    std::unique_ptr<char[]> str;
    size_t len;
};

#endif // MYSTRING_H
