#ifndef MYMyString_H
#define MYMyString_H

#include <climits>
#include <iostream>
#include <iterator>
#include <memory>

namespace mycstr
{
void* memcpy(void* s1, const void* s2, size_t n);
void* memmove(void* s1, const void* s2, size_t n);
char* strcpy(char* s1, const char* s2);
char* strncpy(char* s1, const char* s2, size_t n);
char* strcat(char* s1, const char* s2);
char* strncat(char* s1, const char* s2, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);
int strcmp(const char* s1, const char* s2) noexcept;
int strncmp(const char* s1, const char* s2, size_t n) noexcept;
size_t strcspn(const char* s1, const char* s2);
void* memset(void* s, int c, size_t n);
size_t strlen(const char* s);
}  // namespace mycstr

const size_t NO_SUCH_POSITION = ULLONG_MAX;

class MyString
{
    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

private:
    std::unique_ptr<char[]> _data;
    size_t _size;
    size_t _capacity;

public:
    MyString();
    explicit MyString(const char *str);
    MyString(size_t amnt, char c);
    MyString(const MyString &other);
    MyString(MyString &&other) noexcept;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    ~MyString() = default;

    void resize(size_t newSize);
    void reserve(size_t newSize);
    bool empty() const noexcept;
    size_t length() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    void shrink_to_fit();

    char& at(size_t pos);
    const char& at(size_t pos) const;
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
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
    void insert(size_t pos, const MyString& str);
    void insert(size_t pos, size_t n, char c);

    void append(const char* str);
    void append(const MyString& str);
    void append(size_t n, char c);

    void replace(size_t pos, size_t len, const char* str);
    void replace(size_t pos, size_t len, const MyString& str);

    int compare(const MyString& str) const noexcept;

    friend bool operator==(const MyString& lhs, const MyString& rhs) noexcept;
    friend bool operator!=(const MyString& lhs, const MyString& rhs) noexcept;
    friend bool operator<(const MyString& lhs, const MyString& rhs) noexcept;
    friend bool operator>(const MyString& lhs, const MyString& rhs) noexcept;
    friend bool operator<=(const MyString& lhs, const MyString& rhs) noexcept;
    friend bool operator>=(const MyString& lhs, const MyString& rhs) noexcept;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend MyString operator+(const MyString& lhs, char rhs);
    friend MyString operator+(char lhs, const MyString& rhs);

    size_t find(const MyString& str, size_t pos = 0) const noexcept;
    size_t find(const char* str, size_t pos = 0) const noexcept;
    size_t rfind(const char* str, size_t pos) const noexcept;
    size_t rfind(const char* str) const noexcept;
    size_t rfind(const MyString& str, size_t pos) const noexcept;
    size_t rfind(const MyString& str) const noexcept;
};

std::ostream& operator<<(std::ostream& os, const MyString& obj);

#endif // MYMyString_H
