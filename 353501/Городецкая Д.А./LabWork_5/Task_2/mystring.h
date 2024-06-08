
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <memory>
#include <regex>
#include <string>

class myString {
private:
    std::unique_ptr<char[]> data;
    size_t length;
public:
    myString();
    myString(const char *str);
    myString(const myString &a);
    myString &operator=(const myString &a);
    myString &operator=(const char *str);
    ~myString() = default;
    size_t size() const;
    const char *c_str() const;
    char &operator[](size_t i);
    const char &operator[](int i) const;
    typedef char *iterator;
    typedef const char *const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    myString &operator+=(const myString &other);
    myString &operator+=(const char *str);
    myString operator+(const myString &other) const;
    bool operator==(const myString &other) const;
    bool operator!=(const myString &other) const;
    bool operator<(const myString &other) const;
    bool operator>(const myString &other) const;
    void push_back(const char c);
    static void *myMemcpy(void *s1, const void *s2, size_t n);
    static void *myMemmove(void *s1, const void *s2, size_t n);
    static char *myStrcpy(char *s1, const char *s2);
    static char *myStrncpy(char *s1, const char *s2, size_t n);
    static char *myStrcat(char *s1, const char *s2);
    static char *myStrncat(char *s1, const char *s2, size_t n);
    static int myMemcmp(const void *s1, const void *s2, size_t n);
    static int myStrcmp(const char *s1, const char *s2);
    static int myStrcoll(const char *s1, const char *s2);
    static int myStrncmp(const char *s1, const char *s2, size_t n);
    static size_t myStrxfrm(char *s1, const char *s2, size_t n);
    static char *myStrtok(char *s1, const char *s2);
    static void *myMemset(void *s, int c, size_t n);
    static char *myStrerror(int errnum);
    static size_t myStrlen(const char *s);
    static char *myStrchr(const char *str, int c);
};
#endif // MYSTRING_H
