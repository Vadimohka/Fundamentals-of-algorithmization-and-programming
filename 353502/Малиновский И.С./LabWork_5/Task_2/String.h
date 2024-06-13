#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>
#include <cstring>

class String {
public:
    String();
    String(const char* s);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    size_t length() const;
    const char* c_str() const;

    void* memcpy(void* s1, const void* s2, size_t n);
    void* memmove(void* s1, const void* s2, size_t n);
    char* strcpy(char* s1, const char* s2);
    char* strncpy(char* s1, const char* s2, size_t n);
    char* strcat(char* s1, const char* s2);
    char* strncat(char* s1, const char* s2, size_t n);
    int memcmp(const void* s1, const void* s2, size_t n);
    int strcmp(const char* s1, const char* s2);
    int strcoll(const char* s1, const char* s2);
    int strncmp(const char* s1, const char* s2, size_t n);
    size_t strxfrm(char* s1, const char* s2, size_t n);
    char* strtok(char* s1, const char* s2);
    void* memset(void* s, int c, size_t n);
    char* strerror(int errnum);
    size_t strlen(const char* s);

private:
    std::unique_ptr<char[]> data;
    size_t len;
};

String::String() : data(nullptr), len(0) {}

String::String(const char* s) {
    len = std::strlen(s);
    data = std::make_unique<char[]>(len + 1);
    std::strcpy(data.get(), s);
}

String::String(const String& other) : len(other.len) {
    data = std::make_unique<char[]>(len + 1);
    std::strcpy(data.get(), other.data.get());
}

String::String(String&& other) noexcept : data(std::move(other.data)), len(other.len) {
    other.len = 0;
}

String::~String() {}

String& String::operator=(const String& other) {
    if (this == &other)
        return *this;
    len = other.len;
    data = std::make_unique<char[]>(len + 1);
    std::strcpy(data.get(), other.data.get());
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this == &other)
        return *this;
    data = std::move(other.data);
    len = other.len;
    other.len = 0;
    return *this;
}

size_t String::length() const {
    return len;
}

const char* String::c_str() const {
    return data.get();
}

void* String::memcpy(void* s1, const void* s2, size_t n) {
    return std::memcpy(s1, s2, n);
}

void* String::memmove(void* s1, const void* s2, size_t n) {
    return std::memmove(s1, s2, n);
}

char* String::strcpy(char* s1, const char* s2) {
    return std::strcpy(s1, s2);
}

char* String::strncpy(char* s1, const char* s2, size_t n) {
    return std::strncpy(s1, s2, n);
}

char* String::strcat(char* s1, const char* s2) {
    return std::strcat(s1, s2);
}

char* String::strncat(char* s1, const char* s2, size_t n) {
    return std::strncat(s1, s2, n);
}

int String::memcmp(const void* s1, const void* s2, size_t n) {
    return std::memcmp(s1, s2, n);
}

int String::strcmp(const char* s1, const char* s2) {
    return std::strcmp(s1, s2);
}

int String::strcoll(const char* s1, const char* s2) {
    return std::strcoll(s1, s2);
}

int String::strncmp(const char* s1, const char* s2, size_t n) {
    return std::strncmp(s1, s2, n);
}

size_t String::strxfrm(char* s1, const char* s2, size_t n) {
    return std::strxfrm(s1, s2, n);
}

char* String::strtok(char* s1, const char* s2) {
    return std::strtok(s1, s2);
}

void* String::memset(void* s, int c, size_t n) {
    return std::memset(s, c, n);
}

char* String::strerror(int errnum) {
    return std::strerror(errnum);
}

size_t String::strlen(const char* s) {
    return std::strlen(s);
}

#endif // STRING_H
