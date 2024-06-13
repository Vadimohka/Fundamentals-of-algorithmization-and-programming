#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <iterator>
#include <memory>
#include <QDebug>

namespace my
{
    void* memmove(void* s1, const void* s2, size_t n);

    char* strcpy(char* s1, const char* s2);

    void* memcpy(void* s1, const void* s2, size_t n);

    char* strncat(char* s1, const char* s2, size_t n);

    int memcmp(const void* s1, const void* s2, size_t n);

    int strcmp(const char* s1, const char* s2) noexcept;

    int strncmp(const char* s1, const char* s2, size_t n) noexcept;

    char* strncpy(char* s1, const char* s2, size_t n);

    char* strcat(char* s1, const char* s2);

    void* memset(void* s, int c, size_t n);

    size_t strlen(const char* s);

    size_t strcspn(const char* s1, const char* s2);
}

const size_t NO_POS = -1;

class String
{
private:
    std::unique_ptr<char[]> _data;
    size_t _size;
    size_t _capacity;

    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    QString toQString();

    String();
    String(const char *str);
    String(size_t amnt, char c);
    String(const String &other);
    String(String &&other) noexcept;
    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    ~String() = default;

    void resize(size_t newSize);
    void reserve(size_t newSize);
    bool empty() const noexcept;
    size_t size() const noexcept;

    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& front();
    char& back();
    const char* c_str() const noexcept;
    const char* data() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    void clear() noexcept;
    void erase(size_t pos, size_t len);
    void push_back(char c);
    void pop_back() noexcept;
    size_t copy(char* dest, size_t len, size_t pos = 0) const;

    void insert(size_t pos, const char* str);
    void append(const String& str);
    int compare(const String& str) const noexcept;

    friend String operator+(const String& lhs, const String& rhs);
    friend bool operator==(const String& lhs, const String& rhs) noexcept;
    friend bool operator!=(const String& lhs, const String& rhs) noexcept;
    friend bool operator<(const String& lhs, const String& rhs) noexcept;
    friend bool operator>(const String& lhs, const String& rhs) noexcept;
    friend bool operator<=(const String& lhs, const String& rhs) noexcept;
    friend bool operator>=(const String& lhs, const String& rhs) noexcept;
};

std::ostream& operator<<(std::ostream& os, const String& obj);

#endif // MYSTRING_H
