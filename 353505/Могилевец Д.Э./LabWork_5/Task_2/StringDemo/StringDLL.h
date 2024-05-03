#ifndef STRINGDLL_H
#define STRINGDLL_H

#include <iostream>
#include <memory>

class String
{
public:
    String() : data(nullptr), length(0) {}
    explicit String(const char *str);

    String(const String &other);

    String &operator=(const String &other);

    String &operator=(const char *str);

    ~String() = default;

    size_t size() const;

    char &operator[](size_t index);

    const char &operator[](int index) const;

    typedef char *iterator;
    typedef const char *const_iterator;

    iterator begin() const;

    iterator end() const;

    String &operator+=(const String &other);

    String &operator+=(const char *str);

    bool operator==(const String &other) const;

    bool operator!=(const String &other) const;

    bool operator<(const String &other) const;

    bool operator>(const String &other) const;

    void push_back(const char c);

    static void *memcpy(void *s1, const void *s2, size_t n);

    static void *memmove(void *s1, const void *s2, size_t n);

    static char *strcpy(char *s1, const char *s2);

    static char *strncpy(char *s1, const char *s2, size_t n);

    static char *strcat(char *s1, const char *s2);

    static char *srncat(char *s1, const char *s2, size_t n);

    static int memcmp(const void *s1, const void *s2, size_t n);

    static int strcmp(const char *s1, const char *s2);

    static int strcoll(const char *s1, const char *s2);

    static int strncmp(const char *s1, const char *s2, size_t n);

    static char* strxfrm(char *s1, const char *s2, size_t n);

    static char *strtok(char *s1, const char *s2);

    static void *memset(void *s, int c, size_t n);

    static char *strerror(int errnum);

    static size_t strlen(const char *s);

    static char *strchr(const char *str, int c);

    friend std::ostream &operator<<(std::ostream &os, const String &str);

private:
    std::unique_ptr<char[]> data;
    size_t length;
};
#endif // STRINGDLL_H
