#include "mystring.h"

typedef unsigned char uc;

MyString::MyString()
    : len(0)
    , data(new char[1])
{
    data[0] = '\0';
}

char *MyString::getData() const
{
    return data.get();
}

MyString::MyString(const char *str)
{
    len = strlen(str);
    data.reset(new char[len + 1]);
    for (size_t i = 0; i < len; i++) {
        data.get()[i] = str[i];
    }
    data.get()[len] = '\0';
}

MyString::MyString(const MyString &other)
{
    len = other.len;
    data.reset(new char[other.len + 1]);
    for (size_t i = 0; i < len; i++) {
        data.get()[i] = other.data.get()[i];
    }
    data.get()[len] = '\0';
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other) {
        len = other.len;
        data.reset(new char[len + 1]);
        for (size_t i = 0; i < len; i++) {
            data.get()[i] = other.data.get()[i];
        }
        data.get()[len] = '\0';
    }
    return *this;
}

void *MyString::memcpy(void *s1, const void *s2, size_t n)
{
    char *dest = static_cast<char *>(s1);
    const char *src = static_cast<const char *>(s2);
    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return s1;
}

void *MyString::memmove(void *s1, const void *s2, size_t n)
{
    char *dest = static_cast<char *>(s1);
    const char *src = static_cast<const char *>(s2);
    if (dest <= src) {
        for (size_t i = 0; i < n; i++) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = n; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    return s1;
}

char *MyString::strcpy(char *s1, const char *s2)
{
    char *dest = s1;
    while ((*dest++ = *s2++) != '\0')
        ;
    return s1;
}

char *MyString::strncpy(char *s1, const char *s2, size_t n)
{
    char *dest = s1;
    size_t i = 0;
    for (; i < n && s2[i] != '\0'; i++) {
        dest[i] = s2[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return s1;
}

char *MyString::strcat(char *s1, const char *s2)
{
    size_t size1 = strlen(s1);
    size_t i = 0;
    while (s2[i]) {
        s1[size1 + i] = s2[i];
        ++i;
    }
    s1[size1 + i] = '\0';
    return s1;
}

char *MyString::strncat(char *s1, const char *s2, size_t n)
{
    char *dest = s1;
    while (*dest != '\0') {
        dest++;
    }

    size_t i = 0;
    while (i < n && *s2 != '\0') {
        dest[i] = *s2;
        ++i;
        ++s2;
    }

    dest[i] = '\0';
    return s1;
}

int MyString::memcmp(const void *s1, const void *s2, size_t n)
{
    const uc *us1 = static_cast<const uc *>(s1);
    const uc *us2 = static_cast<const uc *>(s2);
    while (n-- > -0) {
        if (*us1 != *us2) {
            return (*us1 < *us2) ? -1 : 1;
        }
        ++us1;
        ++us2;
    }
    return 0;
}

int MyString::strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        ++s1;
        ++s2;
    }

    if (*s1 > *s2) {
        return 1;
    }
    if (*s1 < *s2) {
        return -1;
    }
    return 0;
}

int MyString::strcoll(const char *s1, const char *s2)
{
    return strcmp(s1, s2);
}

int MyString::strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            return ((uc) s1[i] - (uc) s2[i]);
        }
    }
    return 0;
}

size_t MyString::strxfrm(char *s1, const char *s2, size_t n)
{
    strncpy(s1, s2, n);
    return strlen(s1);
}

char *MyString::strtok(char *s1, const char *s2)
{
    static char *next_token = nullptr;
    if (s1 != nullptr) {
        next_token = s1;
    }

    if (next_token == nullptr) {
        return nullptr;
    }

    char *token_start = next_token;

    while (*next_token != '\0') {
        const char *s = s2;
        while (*s != '\0') {
            if (*next_token == *s++) {
                *next_token = '\0';
                ++next_token;
                return token_start;
            }
        }
        ++next_token;
    }

    //если больше нет разделителей то весь текст - последний токен
    next_token = nullptr;
    return token_start;
}

void *MyString::memset(void *s, int c, size_t n)
{
    uc *p = static_cast<uc *>(s);
    while (n--) {
        *p++ = (uc) c;
    }
    return s;
}

char *MyString::strerror(int errnum)
{
    switch (errnum) {
    case 0:
        return "No error";
    case 1:
        return "Operation not permitted";
    case 2:
        return "No such file or directory";

    default:
        return "Unknown error";
    }
}

size_t MyString::strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}
