#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <iterator>
#include <memory>

class MyString
{
private:
    std::unique_ptr<char[]> _array;
    size_t _size;
    size_t _capacity;

    using iterator = char *;
    using const_iterator = const char *;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    MyString();
    MyString(const char *str);
    MyString(size_t amnt, char c);
    MyString(const MyString &other);
    MyString(MyString &&other) noexcept;
    MyString &operator=(const MyString &other);
    MyString &operator=(MyString &&other) noexcept;
    ~MyString() = default;

    char &at(size_t pos);
    const char &at(size_t pos) const;
    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;

    char &front();
    const char &front() const;
    char &back();
    const char &back() const;
    const char *c_str() const noexcept;
    const char *data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    void resize(size_t newSize);
    void reserve(size_t newSize);
    void clear() noexcept;
    void push_back(char symbol);
    void pop_back() noexcept;
    bool empty() const noexcept;
    size_t length() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
};

namespace str {
void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
char *strcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t n);
char *strcat(char *s1, const char *s2);
char *strncat(char *s1, const char *s2, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
int strcmp(const char *s1, const char *s2);
int strcoll(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strxfrm(char *s1, const char *s2, size_t n);
size_t strcspn(const char *s1, const char *s2);
char *strtok(char *s1, const char *s2);
void *memset(void *s, int c, size_t n);
size_t strlen(const char *s);
} // namespace str

std::ostream &operator<<(std::ostream &os, const MyString &obj);

#endif // MYSTRING_H
