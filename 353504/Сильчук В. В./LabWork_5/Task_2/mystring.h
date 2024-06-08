#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <iterator>
#include <memory>

class MyString
{

public:
    MyString();
    explicit MyString(const char *str);
    MyString(size_t amnt, char c);
    MyString(const MyString &other);
    MyString(MyString &&other) noexcept;
    MyString &operator=(const MyString &other);
    MyString &operator=(MyString &&other) noexcept;
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

    void resize(size_t newSize);
    void reserve(size_t newSize);
    bool empty() const;
    size_t size() const;
    size_t capacity() const;

    char& at(size_t pos);
    const char& at(size_t pos) const;
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    const char *c_str() const;
    const char *data() const;

    char *begin();
    const char *begin() const;
    char *end();
    const char *end() const;
    std::reverse_iterator<char *> rbegin();
    std::reverse_iterator<const char *> rbegin() const;
    std::reverse_iterator<char *> rend();
    std::reverse_iterator<const char *> rend() const;

    void clear();
    void erase(size_t pos, size_t len);
    void push_back(char c);
    void pop_back();
    size_t copy(char* dest, size_t len, size_t pos = 0) const;

    void insert(size_t pos, const char* str);
    void insert(size_t pos, const MyString &str);
    void insert(size_t pos, size_t n, char c);

    void append(const char* str);
    void append(const MyString &str);
    void append(size_t n, char c);

    void replace(size_t pos, size_t len, const char* str);
    void replace(size_t pos, size_t len, const MyString &str);

    size_t find(const MyString &str, size_t pos = 0) const;
    size_t find(const char *str, size_t pos = 0) const;
    size_t rfind(const char *str, size_t pos) const;
    size_t rfind(const char *str) const;
    size_t rfind(const MyString &str, size_t pos) const;
    size_t rfind(const MyString &str) const;

    int compare(const MyString &str) const;

    friend MyString operator+(const MyString &left, const MyString &right);
    friend MyString operator+(const MyString &left, char right);
    friend MyString operator+(char left, const MyString &right);

    friend bool operator==(const MyString &left, const MyString &right);
    friend bool operator!=(const MyString &left, const MyString &right);
    friend bool operator<(const MyString &left, const MyString &right);
    friend bool operator>(const MyString &left, const MyString &right);
    friend bool operator<=(const MyString &left, const MyString &right);
    friend bool operator>=(const MyString &left, const MyString &right);

private:
    std::unique_ptr<char[]> ptr;
    size_t sz;
    size_t cp;
};

#endif // MYSTRING_H
