#include "string.h"

String::String() : data(nullptr), len(0) {}

String::String(const char* s) {
    len = strlen(s);
    data = std::make_unique<char[]>(len + 1);
    strcpy(data.get(), s);
}

String::String(const String& other) : len(other.len) {
    data = std::make_unique<char[]>(len + 1);
    strcpy(data.get(), other.data.get());
}

String::String(String&& other) noexcept : data(move(other.data)), len(other.len) {
    other.len = 0;
}

String::~String() {}

String& String::operator=(const String& other) {
    if (this == &other)
        return *this;
    len = other.len;
    data = std::make_unique<char[]>(len + 1);
    strcpy(data.get(), other.data.get());
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
    return memcpy(s1, s2, n);
}

void* String::memmove(void* s1, const void* s2, size_t n) {
    return memmove(s1, s2, n);
}

char* String::strcpy(char* s1, const char* s2) {
    return strcpy(s1, s2);
}

char* String::strncpy(char* s1, const char* s2, size_t n) {
    return strncpy(s1, s2, n);
}

char* String::strcat(char* s1, const char* s2) {
    return strcat(s1, s2);
}

char* String::strncat(char* s1, const char* s2, size_t n) {
    return strncat(s1, s2, n);
}

int String::memcmp(const void* s1, const void* s2, size_t n) {
    return memcmp(s1, s2, n);
}

int String::strcmp(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

int String::strcoll(const char* s1, const char* s2) {
    return strcoll(s1, s2);
}

int String::strncmp(const char* s1, const char* s2, size_t n) {
    return strncmp(s1, s2, n);
}

size_t String::strxfrm(char* s1, const char* s2, size_t n) {
    return strxfrm(s1, s2, n);
}

char* String::strtok(char* s1, const char* s2) {
    return strtok(s1, s2);
}

void* String::memset(void* s, int c, size_t n) {
    return memset(s, c, n);
}

char* String::strerror(int errnum) {
    return strerror(errnum);
}

size_t String::strlen(const char* s) {
    return strlen(s);
}
