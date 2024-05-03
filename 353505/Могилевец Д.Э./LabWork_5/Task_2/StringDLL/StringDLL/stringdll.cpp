#include "stringdll.h"

String::String(const char *str)
{
    length = strlen(str);
    data = std::make_unique<char[]>(length + 1);
    strcpy(data.get(), str);
}

String::String(const String &other) : length(other.length) {
    data = std::make_unique<char[]>(length + 1);
    strcpy(data.get(), other.data.get());
}

String &String::operator=(const String &other)
{
    if (this != &other) {
        length = other.length;
        data = std::make_unique<char[]>(length + 1);
        String::strcpy(data.get(), other.data.get());
    }
    return *this;
}

String &String::operator=(const char* other)
{
    size_t newLength = String::strlen(other);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    String::strcpy(newData.get(), other);
    data = std::move(newData);
    length = newLength;
    return *this;
}

size_t String::size() const
{
    return length;
}

char &String::operator[](size_t index)
{
    return data[index];
}

String::iterator String::begin() const
{
    return data.get();
}

String::iterator String::end() const
{
    return data.get() + length;
}

String &String::operator+=(const String &other)
{
    size_t newSize = length + other.size();
    auto newData = std::unique_ptr<char[]>(new char[newSize + 1]);
    String::strcpy(newData.get(), data.get());
    String::strcat(newData.get(), other.data.get());
    data = std::move(newData);
    length = newSize;
    return *this;
}

bool String::operator==(const String &other) const
{
    return strcmp(data.get(), other.data.get()) == 0;
}

bool String::operator!=(const String &other) const
{
    return strcmp(data.get(), other.data.get()) != 0;
}

bool String::operator<(const String &other) const
{
    return strcmp(data.get(), other.data.get()) < 0;
}

bool String::operator>(const String &other) const
{
    return strcmp(data.get(), other.data.get()) > 0;
}

void String::push_back(const char c)
{
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(length + 2);
    strcpy(newData.get(), data.get());
    newData.get()[length] = c;
    newData.get()[length + 1] = '\0';
    data = std::move(newData);
    ++length;
}

String &String::operator+=(const char* other)
{
    size_t newLength = length + strlen(other);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    strcpy(newData.get(), data.get());
    strcat(newData.get(), other);
    data = std::move(newData);
    length = newLength;
    return *this;
}


void *String::memcpy(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr) return s1;
    char *dest = static_cast<char*>(s1);
    const char *src = static_cast<const char*>(s2);

    for (size_t i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
    return s1;
}

void *String::memmove(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr) return s1;
    char *dest = static_cast<char*>(s1);
    const char *src = static_cast<const char*>(s2);
    if (dest <= src || dest >= src + n) {
        for (size_t i = 0; i < n; ++i) {
            dest[i] = src[i];
        }
    } else {
        for (size_t i = n; i > 0; --i) {
            dest[i - 1] = src[i - 1];
        }
    }
    return s1;
}

char *String::strcpy(char *s1, const char *s2)
{
    if (s1 == nullptr || s2 == nullptr) return s1;
    size_t i = 0;
    while (s2[i] != '\0')
        ++i;
    memcpy(s1, s2, i);
    s1[i] = '\0';
    return s1;
}

char *String::strncpy(char *s1, const char *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr) return s1;

    size_t i = 0;
    while (i < n && s2[i] != '\0') {
        s1[i] = s2[i];
        ++i;
    }
    while (i < n) {
        s1[i] = '\0';
        ++i;
    }

    return s1;
}

char *String::strcat(char *s1, const char *s2)
{
    size_t i = 0, j = 0;
    while (s1[i] != '\0') {
        ++i;
    }
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        ++i;
        ++j;
    }
    s1[i] = '\0';
    return s1;
}

char *String::strncat(char *s1, const char *s2)
{

}

char *String::srncat(char *s1, const char *s2, size_t n)
{
    char *temp = s1;
    while (*s1) {
        ++s1;
    }
    while (n-- && *s2) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return temp;
}

int String::memcmp(const void *s1, const void *s2, size_t n)
{
    const char *str1 = (char *) s1;
    const char *str2 = (char *) s2;
    while ((n--) > 0) {
        if (*str1++ != *str2++)
            return str1[-1] < str2[-1] ? -1 : 1;
    }
    return 0;
}

int String::strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

int String::strcoll(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2) {
            return -1;
        } else if (*s1 > *s2) {
            return 1;
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    } else if (*s1 == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int String::strncmp(const char *s1, const char *s2, size_t n)
{
    while (--n && *s1 == *s2) {
        if (*s1 == '\0')
            return 1;
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

char* String::strxfrm(char *s1, const char *s2, size_t n)
{
    return String::strncpy(s1, s2, n);
}

char *String::strtok(char *s1, const char *s2)
{
    static char *last = nullptr;
    char *token_start;
    const char *delimiters = s2;
    if (s1 != nullptr)
        last = s1;
    if (last == nullptr || *last == '\0')
        return nullptr;

    while (*last != '\0' && String::strchr(delimiters, *last) != nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
        return nullptr;
    }

    token_start = last;

    while (*last != '\0' && String::strchr(delimiters, *last) == nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
    } else {
        *last = '\0';
        last++;
    }

    return token_start;
}

void *String::memset(void *s, int c, size_t n)
{
    size_t i;
    char *ss = (char *) s;
    for (i = 0; i < n; i++) {
        ss[i] = (char)c;
    }
    return s;
}

char *String::strerror(int errnum)
{
    static const char *errorMessages[] = {
        "No error",
        "Permission denied",
        "File not found",
        "Invalid argument"
    };

    static const int numErrors = sizeof(errorMessages) / sizeof(errorMessages[0]);
    if (errnum >= 0 && errnum < numErrors) {
        return const_cast<char*>(errorMessages[errnum]);
    } else {
        return const_cast<char*>("Unknown error");
    }
}

size_t String::strlen(const char *s)
{
    int i = 0;
    while (*s != '\0') {
        ++s;
        ++i;
    }
    return i;
}

char *String::strchr(const char *str, int c)
{
    while (*str != '\0') {
        if (*str == c)
            return (char *) str;
        ++str;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const String &str) {

    os << str.begin();
    return os;
}
