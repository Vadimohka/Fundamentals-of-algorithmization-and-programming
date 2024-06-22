#include "cstring.h"

CString::CString() {}

void *CString::memcpy(void *destination, const void *source, size_t num)
{
    unsigned char* dst = static_cast<unsigned char*>(destination);
    const unsigned char* sourceNew = static_cast<const unsigned char*>(source);
    for (size_t i = 0; i < num; ++i) {
        dst[i] = sourceNew[i];
    }
    return destination;
}

void *CString::memmove(void *destination, const void *source, size_t num)
{
    unsigned char* dst = static_cast<unsigned char*>(destination);
    const unsigned char* sourceNew = static_cast<const unsigned char*>(source);
    unsigned char* tmp = new unsigned char[num];
    if (tmp == nullptr) {
        return nullptr;
    }
    memcpy(tmp, sourceNew, num);
    memcpy(dst, tmp, num);
    delete[] tmp;

    return destination;
}

char *CString::strcpy(char *destination, const char *source)
{
    char* dst = destination;
    const char* sourceNew = source;
    while (*sourceNew != '\0') {
        *dst = *sourceNew;
        ++dst;
        ++sourceNew;
    }
    *dst = '\0';

    return destination;
}

char *CString::strncpy(char *destination, const char *source, size_t num)
{
    char* dst = destination;
    const char* sourceNew = source;
    size_t i = 0;
    while (*sourceNew != '\0' && i < num) {
        *dst = *sourceNew;
        ++dst;
        ++sourceNew;
        ++i;
    }
    while (i < num) {
        *dst = '\0';
        ++dst;
        ++i;
    }

    return destination;
}

char *CString::strcat(char *destination, const char *source)
{
    char* dst_end = destination + strlen(destination);
    const char* sourceNew = source;
    char* dst_current = dst_end;
    while (*sourceNew != '\0') {
        *dst_current = *sourceNew;
        ++dst_current;
        ++sourceNew;
    }
    *dst_current = '\0';

    return destination;
}

char *CString::strncat(char *destination, const char *source, size_t num)
{
    char* dst_end = destination + strlen(destination);
    const char* sourceNew = source;
    char* dst_current = dst_end;
    size_t i = 0;
    while (*sourceNew != '\0' && i < num) {
        *dst_current = *sourceNew;
        ++dst_current;
        ++sourceNew;
        ++i;
    }
    *dst_current = '\0';

    return destination;
}

int CString::memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char* s1 = static_cast<const unsigned char*>(ptr1);
    const unsigned char* s2 = static_cast<const unsigned char*>(ptr2);

    for (size_t i = 0; i < num; ++i) {
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

int CString::strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        ++str1;
        ++str2;
    }
    if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    } else {
        return 0;// =
    }
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

int CString::strncmp(const char *str1, const char *str2, size_t num)
{
    while (num > 0 && *str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        ++str1;
        ++str2;
        --num;
    }

    if (num == 0) {
        return 0;
    } else if (*str1 == '\0' && *str2 != '\0') {
        return -1;
    } else if (*str1 != '\0' && *str2 == '\0') {
        return 1;
    } else {
        return 0;
    }
}

size_t CString::strxfrm(char *destination, const char *source, size_t num)
{
    size_t sourceLen = CString::strlen(source);
    if (sourceLen + 1 <= num) {
        CString::strcpy(destination, source);
        return sourceLen;
    } else {
        return sourceLen + 1;
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
    if (*token_start == '\0') {
        carry = nullptr;
        return nullptr;
    }
    char* token_end = token_start;
    while (*token_end != '\0') {
        bool delim_found = false;
        for (const char* delim_ptr = s2; *delim_ptr != '\0'; delim_ptr++) {
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

void *CString::memset(void *destination, int value, size_t num)
{
    unsigned char val = static_cast<unsigned char>(value);
    unsigned char* i = static_cast<unsigned char*>(destination);
    unsigned char* end = i + num;
    while (i != end) {
        *i = val;
        ++i;
    }
    return destination;
}

size_t CString::strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}
