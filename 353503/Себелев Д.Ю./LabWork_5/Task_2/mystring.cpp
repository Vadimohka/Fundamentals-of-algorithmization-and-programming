#include "mystring.h"

myString::myString() : str(new char[1]), len(0)
{
    str[0] = '\0';
}

myString::myString(const char *s)
{
    len = strlen(s);
    str.reset(new char[len + 1]);
    strcpy(str.get(), s);
}

myString::myString(const myString &s) : str(new char[s.len + 1]), len(s.len)
{
    strcpy(str.get(), s.str.get());
}

myString::myString(myString &&s) : str(std::move(s.str)), len(s.len)
{
    s.len = 0;
    s.str.reset(new char[1]);
    s.str[0] = '\0';
}

myString &myString::operator=(const myString &s)
{
    if (this != &s)
    {
        len = s.len;
        str.reset(new char[len + 1]);
        strcpy(str.get(), s.str.get());
    }

    return *this;
}

char *myString::begin()
{
    return str.get();
}

const char *myString::cbegin() const
{
    return str.get();
}

char *myString::end()
{
    return str.get() + len;
}

const char *myString::cend() const
{
    return str.get() + len;
}

std::reverse_iterator<char *> myString::rbegin()
{
    return std::reverse_iterator<char *>(end());
}

std::reverse_iterator<char *> myString::rend()
{
    return std::reverse_iterator<char *>(begin());
}


myString::~myString() = default;

myString &myString::operator=(myString &&s)
{
    if (this != &s)
    {
        len = s.len;
        str = std::move(s.str);
        s.len = 0;
        s.str.reset(new char[1]);
        s.str[0] = '\0';
    }

    return *this;
}

myString &myString::operator=(const char *s)
{
    len = strlen(s);
    str.reset(new char[len + 1]);
    strcpy(str.get(), s);

    return *this;
}



void *myString::memcpy(void *dest, const void *src, size_t count)
{
    char *d = static_cast<char *>(dest);
    const char *s = static_cast<const char *>(src);

    for (size_t i = 0; i < count; i++)
    {
        d[i] = s[i];
    }

    return dest;
}

void *myString::memmove(void *dest, const void *src, size_t count)
{
    char *d = static_cast<char *>(dest);
    const char *s = static_cast<const char *>(src);

    if (d < s)
    {
        for (size_t i = 0; i < count; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        for (size_t i = count; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

void *myString::memset(void *dest, int ch, size_t count)
{
    char *d = static_cast<char *>(dest);

    for (size_t i = 0; i < count; i++)
    {
        d[i] = ch;
    }

    return dest;
}

char *myString::strcpy(char *dest, const char *src)
{
    size_t i = 0;

    for (; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}

char *myString::strncpy(char *dest, const char *src, size_t count)
{
    size_t i = 0;

    for (; i < count && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    for (; i < count; i++)
    {
        dest[i] = '\0';
    }

    return dest;
}

char *myString::strcat(char *dest, const char *src)
{
    size_t i = 0;
    size_t j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    for (; src[j] != '\0'; j++)
    {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';

    return dest;
}

char *myString::strncat(char *dest, const char *src, size_t count)
{
    size_t i = 0;
    size_t j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    for (; j < count && src[j] != '\0'; j++)
    {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';

    return dest;
}

int myString::memcmp(const void *ptr1, const void *ptr2, size_t count)
{
    const char *p1 = static_cast<const char *>(ptr1);
    const char *p2 = static_cast<const char *>(ptr2);

    for (size_t i = 0; i < count; i++)
    {
        if (p1[i] < p2[i])
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

int myString::strcmp(const char *str1, const char *str2)
{
    size_t i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }

    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    }
    else if (str1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int myString::strcoll(const char *str1, const char *str2)
{
    setlocale(LC_ALL, "");
    return strcmp(str1, str2);
}

int myString::strncmp(const char *str1, const char *str2, size_t count)
{
    size_t i = 0;

    for (; i < count && str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }

    if (i == count)
    {
        return 0;
    }
    else if (str1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

size_t myString::strxfrm(char *dest, const char *src, size_t count)
{
    size_t i = 0;

    for (; i < count && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return i;
}

char *myString::strtok(char *dest, const char *token)
{
    static char* next_token = nullptr;

    if (dest) {
        next_token = dest;
    }

    if (!next_token) {
        return NULL;
    }

    // Skip leading delimiters
    while (*next_token) {
        bool is_delim = false;
        for (const char* d = token; *d != '\0'; ++d) {
            if (*next_token == *d) {
                is_delim = true;
                break;
            }
        }
        if (!is_delim) {
            break;
        }
        next_token++;
    }

    if (!*next_token) {
        return NULL;
    }

    char* token_start = next_token;

    // Find the next delimiter and terminate the current token
    while (*next_token) {
        bool is_delim = false;
        for (const char* d = token; *d != '\0'; ++d) {
            if (*next_token == *d) {
                is_delim = true;
                break;
            }
        }
        if (is_delim) {
            *next_token = '\0';
            next_token++;
            return token_start;
        }
        next_token++;
    }

    next_token = NULL; // End of string reached
    return token_start;
}

char *myString::strerror(int errnum)
{
    char buffer[256];

    switch (errnum)
    {
        case 0:
            strcpy(buffer, "Success");
            break;
        case 1:
            strcpy(buffer, "Operation not permitted");
            break;
        case 2:
            strcpy(buffer, "No such file or directory");
            break;
        case 3:
            strcpy(buffer, "No such process");
            break;
        default:
            strcpy(buffer, "Unknown error");
            break;
    }

    return buffer;
}

size_t myString::strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}
