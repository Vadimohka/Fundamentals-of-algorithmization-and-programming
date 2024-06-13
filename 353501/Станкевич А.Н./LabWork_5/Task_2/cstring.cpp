#include "cstring.h"
#include <cstdlib>

CString::CString() {

}

void *CString::memcpy(void *dest, const void *src, size_t n)
{
    unsigned char* dst = static_cast<unsigned char*>(dest);
    const unsigned char* source = static_cast<const unsigned char*>(src);
    for (size_t i = 0; i < n; ++i) {
        dst[i] = source[i];
    }
    return dest;
}

char *CString::strncpy(char *dest, const char *src, size_t n)
{
    char* dst = dest;
    const char* source = src;

    while (*source != '\0' && n > 0) {
        *dst++ = *source++;
        --n;
    }

    while (n > 0) {
        *dst++ = '\0';
        --n;
    }

    return dest;
}

void *CString::memmove(void *dest, const void *src, size_t n)
{
    void* tmp = nullptr;

    if (static_cast<const unsigned char*>(src) >= static_cast<unsigned char*>(dest) &&
        static_cast<const unsigned char*>(src) < static_cast<unsigned char*>(dest) + n)
    {
        tmp = malloc(n);
        if (!tmp) {
            return nullptr;
        }
        memcpy(tmp, src, n);
        memcpy(dest, tmp, n);

        free(tmp);
    }
    else
    {
        memcpy(dest, src, n);
    }

    return dest;
}

char *CString::strcpy(char *dest, const char *src)
{
    char* dst = dest;
    const char* source = src;
    while (*source != '\0') {
        *dst = *source;
        ++dst;
        ++source;
    }
    *dst = '\0';

    return dest;
}



char *CString::strcat(char *dest, const char *src)
{
    char* dst = dest;

    while (*dst != '\0') {
        ++dst;
    }

    while (*src != '\0') {
        *dst++ = *src++;
    }

    *dst = '\0';

    return dest;
}


char *CString::strncat(char *dest, const char *src, size_t n)
{
    char* dst_end = dest + strlen(dest);
    const char* source = src;
    char* dst_current = dst_end;
    size_t i = 0;
    while (*source != '\0' && i < n) {
        *dst_current = *source;
        ++dst_current;
        ++source;
        ++i;
    }
    *dst_current = '\0';

    return dest;
}

int CString::memcmp(const void *ptr1, const void *ptr2, size_t n)
{
    const unsigned char* s1 = static_cast<const unsigned char*>(ptr1);
    const unsigned char* s2 = static_cast<const unsigned char*>(ptr2);

    for (size_t i = 0; i < n; ++i) {
        if (*s1 > *s2) {
            return 1;
        } else if (*s1 < *s2) {
            return -1;
        }
        ++s1;
        ++s2;
    }

    return 0;
}

int CString::strcoll(const char *s1, const char *s2)
{
    while (true) {
        int result = strncmp(s1, s2, 1);
        if (result != 0 || *s1 == '\0' || *s2 == '\0') {
            return result;
        }
        ++s1;
        ++s2;
    }
}

int CString::strncmp(const char *str1, const char *str2, size_t n)
{
    while (n > 0)
    {
        if (*str1 != *str2)
            return static_cast<int>(static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2));
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
        n--;
    }
    return 0;
}

int CString::strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        ++str2;
        ++str1;

    }
    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    } else {
        return 0;// =
    }
}
size_t CString::strxfrm(char *dest, const char *src, size_t n)
{
    size_t srcLen = CString::strlen(src);

    if (srcLen + 1 <= n) {
        CString::strcpy(dest, src);
        return srcLen;
    } else {
        return srcLen + 1;
    }
}

char *CString::strtok(char *s1, const char *s2)
{
    static char* carry = nullptr;
    char* token_start = nullptr;
    if (s1 != nullptr) {
        token_start = s1;
    } else if (carry == nullptr) {
        return nullptr;
    } else {
        token_start = carry;
    }
    while (*token_start != '\0') {
        bool delim_found = false;
        for (const char* delim_ptr = s2; *delim_ptr != '\0'; ++delim_ptr) {
            if (*token_start == *delim_ptr) {
                delim_found = true;
                break;
            }
        }
        if (!delim_found) {
            break;
        }
        ++token_start;
    }
        char* token_end = token_start;
    if (*token_start == '\0') {
        carry = nullptr;
        return nullptr;
    }

    while (*token_end != '\0') {
        bool delim_found = false;
        for (const char* delim_ptr = s2; *delim_ptr != '\0'; ++delim_ptr) {
            if (*token_end == *delim_ptr) {
                delim_found = true;
                break;
            }
        }
        if (delim_found) {
            break;
        }
        ++token_end;
    }
    if (*token_end == '\0') {
        carry = nullptr;
    } else {
        *token_end = '\0';
        carry = token_end + 1;
    }

    return token_start;
}

void *CString::memset(void *dest, int value, size_t n)
{
    unsigned char val = static_cast<unsigned char>(value);
    unsigned char* i = static_cast<unsigned char*>(dest);
    unsigned char* end = i + n;
    while (i != end) {
        *i = val;
        ++i;
    }
    return dest;
}

size_t CString::strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

const char *CString::strerror(int errnum)
{
    switch (errnum) {
    case 1:
        return "Недопустимый доступ к памяти";
    case 2:
        return "Файл не найден";
    case 3:
        return "Недопустимый аргумент";
    default:
        return "ошибка";
    }
}
