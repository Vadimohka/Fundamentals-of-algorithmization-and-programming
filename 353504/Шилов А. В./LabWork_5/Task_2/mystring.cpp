#include "mystring.h"

MyString::MyString() {

}

MyString::MyString(char *c)
{
    if (c == nullptr) {
        len = 0;
        str = std::make_unique<char[]>(1); // для '\0'
        str[0] = '\0';
    } else {
        len = strlen(c);
        str = std::make_unique<char[]>(len + 1);
        strcpy(str.get(), c);
    }
}

void* MyString::memcpy(void* dest, const void* src, int n)
{
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    for(int i = 0; i < n; ++i)
    {
        cdest[i] = csrc[i];
    }
    return dest;
}

void* MyString::memmove(void* dest, const void* src, int n)
{
    char* csrc = (char*)src;
    char* cdest = (char*)dest;
    std::unique_ptr<char[]> temp = std::make_unique<char[]>(n);
    memcpy(temp.get(), csrc, n);
    memcpy(cdest, temp.get(), n);
    return dest;
}

char* MyString::strcpy(char* dest, const char* src)
{
    return static_cast<char*>(memcpy(dest, src, strlen(src) + 1));
}

int MyString::strlen(const char* str)
{
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

char *MyString::strncpy(char *s1, const char *s2, int n)
{
    int i;
    for (i = 0; i < n && s2[i] != '\0'; i++)
        s1[i] = s2[i];
    for ( ; i < n; i++)
        s1[i] = '\0';
    return s1;
}

char *MyString::strcat(char *s1, const char *s2)
{
    char* dest = s1;
    while (*dest) dest++;
    while (*s2 != '\0')
    {
        *dest = *s2;
        dest++;
        s2++;
    }
    *dest = '\0';
    return s1;
}

char *MyString::strncat(char *s1, const char *s2, int n)
{
    char* dest = s1;
    while (*dest) dest++;
    int i = 0;
    while (i != n)
    {
        *dest = *s2;
        dest++;
        s2++;
        i++;
    }
    *dest = '\0';
    return s1;
}

int MyString::memcmp(const void *s1, const void *s2, int n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    for (int i = 0; i < n; ++i)
    {
        if (cs1[i] > cs2[i]) return 1;
        if (cs2[i] > cs1[i]) return -1;
    }
    return 0;
}

int MyString::strcmp(const char *s1, const char *s2)
{
    for (int i = 0; i < strlen(s1) - 1 || i < strlen(s2) - 1; ++i)
    {
        if (s1[i] > s2[i]) return 1;
        if (s2[i] > s1[i]) return -1;
        if (s2[i + 1] == '\0' && s1[i + 1 != '\0']) return 1;
        if (s1[i + 1] == '\0' && s2[i + 1 != '\0']) return -1;
    }
    return 0;
}

int MyString::strcoll(const char *s1, const char *s2)
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

int MyString::strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (s1[i] > s2[i]) return 1;
        if (s2[i] > s1[i]) return -1;
        if (s1[i] == '\0' && s2[i] == '\0') return 0;
    }
    return 0;
}

int MyString::strxfrm(char *s1, const char *s2, int n)
{
    int srcLen = strlen(s2);

    if (srcLen + 1 <= n)
    {
        strcpy(s1, s2);
        return srcLen;
    }
    else
    {
        return srcLen + 1;
    }
}

char *MyString::strtok(char *s1, const char *s2)
{
    static char* input = NULL;
    if (s1 != NULL) {
        input = s1;
    }
    if (input == NULL) {
        return NULL;
    }

    char* result = new char[strlen(input) + 1];
    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (strchr(s2, input[i]) == NULL) {
            result[i] = input[i];
        } else {
            result[i] = '\0';
            input = input + i + 1;
            return result;
        }
    }

    result[i] = '\0';
    input = NULL;
    return result;
}

void *MyString::memset(void *s, int c, int n)
{
    char* s1 = static_cast<char*>(s);
    for (int i = 0; i < n; ++i)
    {
        s1[i] = static_cast<char>(c);
    }
    return s;
}

char *MyString::strerror(int errnum)
{
    switch(errnum) {
    case 1:
        return "Error 1: Accessing invalid memory";
    case 2:
        return "Error 2: Accessing a NULL value";
    default:
        return "Unknown error";
    }
}
