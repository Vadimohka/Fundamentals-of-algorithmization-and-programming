#ifndef MYSTRING_H
#define MYSTRING_H

#include <memory>

class MyString
{
public:
    MyString();
    explicit MyString(const char *str);
    MyString &operator=(const MyString &other);
    ~MyString() = default;

    static void *memcpy(void *s1, const void *s2, size_t n);
    static void *memmove(void *s1, const void *s2, size_t n);
    static char *strcpy(char *s1, const char *s2);
    static char *strncpy(char *s1, const char *s2, size_t n);
    static char *strcat(char *s1, const char *s2);
    static char *strncat(char *s1, const char *s2, size_t n);
    static int memcmp(const void *s1, const void *s2, size_t n);
    static int strcmp(const char *s1, const char *s2);
    static int strncmp(const char *s1, const char *s2, size_t n);
    static size_t strcspn(const char *s1, const char *s2);
    static void *memset(void *s, int c, size_t n);
    static size_t strlen(const char *s);

    const char *c_str() const;
    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void erase(size_t pos, size_t len);

private:
    std::unique_ptr<char[]> ptr;
    size_t sz;
    size_t cp;
};

#endif // MYSTRING_H
