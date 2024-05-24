#include "stringfunctions.h"

size_t stringFunctions::strlen(const char* s)
{
    size_t i = 0;
    while (true)
    {
        if (s[i] == '\0')
        {
            break;
        }
        ++i;
    }
    return i;
}

void* stringFunctions::memcpy(void* s1, const void* s2, size_t n)
{
    if (s1 == nullptr)
    {
        return s1;
    }
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    for(int i = 0; i < n; ++i)
    {
        cs1[i] = cs2[i];
    }
    return s1;
}

void* stringFunctions::memmove(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    char* t = new char[n];
    for(int i = 0; i < n; ++i)
    {
        t[i] = cs2[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cs1[i] = t[i];
    }
    delete [] t;
    return s1;
}

char* stringFunctions::strcpy(char* s1, const char* s2)
{
    size_t i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        ++i;
    }
    s1[i] = '\0';
    return s1;
}

char* stringFunctions::strncpy(char* s1, const char* s2, size_t n)
{
    size_t i = 0;
    while (i < n && s2[i] != '\0')
    {
        s1[i] = s2[i];
        ++i;
    }
    while (i < n)
    {
        s1[i] = '\0';
        ++i;
    }
    s1[n] = '\0';
    return s1;
}

char* stringFunctions::strcat(char* s1, const char* s2)
{
    size_t size1 = stringFunctions::strlen(s1);
    size_t i = 0;
    while (s2[i])
    {
        s1[size1+i] = s2[i];
        ++i;
    }
    s1[size1 + i] = '\0';
    return s1;
}

char* stringFunctions::strncat(char* s1, const char* s2, size_t n)
{
    for(int i = 0; i < n; ++i)
    {
        s1[i] = s2[i];
    }
    s1[n] = '\0';
    return s1;
}

int stringFunctions::memcmp(const void* s1, const void* s2, size_t n)
{
    auto *lv = static_cast<const char *>(s1);
    const auto *rv = static_cast<const char *>(s2);
    while (*lv == *rv && --n)
    {
        ++lv;
        ++rv;
    }
    if (*lv > *rv)
    {
        return 1;
    }
    if (*lv < *rv)
    {
        return -1;
    }
    return 0;
}

int stringFunctions::strcmp(const char* s1, const char* s2)
{
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
        ++s1;
        ++s2;
    }

    if (*s1 > *s2)
    {
        return 1;
    }
    if (*s1 < *s2)
    {
        return -1;
    }
    return 0;
}

int stringFunctions::strncmp(const char* s1, const char* s2, size_t n)
{
    int i = 0;
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n)
    {
        ++i;
        ++s1;
        ++s2;
    }

    if (*s1 > *s2)
    {
        return 1;
    }
    if (*s1 < *s2)
    {
        return -1;
    }
    return 0;
}

char* stringFunctions::strtok(char* s1, const char* s2)
{
    bool (*isDelim)(char, const char*) = [](char ch, const char* s2)
    {
        int i = 0;
        while(s2[i])
        {
            if(s2[i] == ch)
            {
                return true;
            }
            ++i;
        }
        return false;
    };
    static char *backup;
    if(!s1)
    {
        s1 = backup;
    }
    if(!s1)
    {
        return nullptr;
    }

    while (true)
    {
        if(isDelim(*s1, s2))
        {
            s1++;
            continue;
        }
        if(*s1 == '\0')
        {
            return nullptr;
        }
        break;
    }
    char* ret = s1;
    while (true)
    {
        if(isDelim(*s1, s2))
        {
            *s1 = '\0';
            s1++;
            backup = s1;
            return ret;
        }
        if(*s1 == '\0')
        {
            backup = s1;
            return ret;
        }
        s1++;
    }
}

void* stringFunctions::memset(void* ptr, int value, size_t n)
{
    size_t i;
    char *ss = (char *) ptr;

    for (i = 0; i < n; i++)
    {
        ss[i] = value;
    }
    return ptr;
}

int stringFunctions::strcoll(const char* s1, const char* s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 < *s2)
        {
            return -1;
        }
        else if (*s1 > *s2)
        {
            return 1;
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0')
    {
        return 0;
    }
    else if (*s1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

char* stringFunctions::strerror(int errnum)
{
    static char *errors[] =
    {
        "No error",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "Input/output error",
    };

    if (errnum >= 0 && errnum < sizeof(errors) / sizeof(errors[0]))
    {
        return errors[errnum];
    }
    else
    {
        return "Unknown error";
    }
}

size_t mystrxfrm(char* s1, const char* s2, size_t n)
{
    size_t i = 0;
    while (*s2 != '\0' && i < n)
    {
        *s1 = *s2;
        ++s1;
        ++s2;
        ++i;
    }
    *s1 = '\0';
    return i;
}
