#include "mystring.h"
#include <ostream>

String::String() : length(0), data(nullptr) {}

String::String(const char *str) : length(Strlen(str)) {
    data = std::make_unique<char[]>(length + 1);
    Strcpy(data.get(), str);
}

String::String(const String &other) : length(other.length) {
    data = std::make_unique<char[]>(length + 1);
    Strcpy(data.get(), other.data.get());
}

String &String::operator=(const String &other) {
    if (this != &other) {
        length = other.length;
        data = std::make_unique<char[]>(length + 1);
        Strcpy(data.get(), other.data.get());
    }
    return *this;
}

String &String::operator=(const char *str) {
    size_t newLength = Strlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    Strcpy(newData.get(), str);
    data = std::move(newData);
    length = newLength;
    return *this;
}

size_t String::size() const {
    return length;
}

const char *String::c_str() const {
    return data.get();
}

char &String::operator[](size_t index) {
    return data[index];
}

const char &String::operator[](int index) const {
    return data.get()[index];
}

String::iterator String::begin() {
    return data.get();
}

String::iterator String::end() {
    return data.get() + length;
}

String::const_iterator String::begin() const {
    return data.get();
}

String::const_iterator String::end() const {
    return data.get() + length;
}

String &String::operator+=(const String &other) {
    size_t newSize = length + other.size();
    auto newData = std::unique_ptr<char[]>(new char[newSize + 1]);
    Strcpy(newData.get(), data.get());
    Strcat(newData.get(), other.data.get());
    data = std::move(newData);
    length = newSize;
    return *this;
}

String &String::operator+=(const char *str) {
    size_t newLength = length + Strlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    Strcpy(newData.get(), data.get());
    Strcat(newData.get(), str);
    data = std::move(newData);
    length = newLength;
    return *this;
}

String String::operator+(const String &other) const {
    String result(*this);
    result += other;
    return result;
}

bool String::operator==(const String &other) const {
    return Strcmp(data.get(), other.data.get()) == 0;
}

bool String::operator!=(const String &other) const {
    return !(*this == other);
}

bool String::operator<(const String &other) const {
    return Strcmp(data.get(), other.data.get()) < 0;
}

bool String::operator>(const String &other) const {
    return Strcmp(data.get(), other.data.get()) > 0;
}

void String::push_back(const char c) {
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(length + 2);
    Strcpy(newData.get(), data.get());
    newData.get()[length] = c;
    newData.get()[length + 1] = '\0';
    data = std::move(newData);
    ++length;
}

void *String::Memcpy(void *s1, const void *s2, size_t n) {
    if (s1 == nullptr) return s1;
    char *ptr = (char *) s1;
    char *ptr1 = (char *) s2;
    for (size_t i = 0; i < n; i++) {
        ptr[i] = ptr1[i];
    }
    return s1;
}

void *String::Memmove(void *s1, const void *s2, size_t n) {
    char *d = (char *) s1;
    const char *s = (char *) s2;
    if (d < s)
        while (n--)
            *d++ = *s++;
    else {
        char *lasts = (char *) s + (n - 1);
        char *lastd = d + (n - 1);
        while (n--)
            *lastd-- = *lasts--;
    }
    return s1;
}

char *String::Strcpy(char *s1, const char *s2) {
    if (s1 == nullptr) return s1;
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        ++i;
    }
    s1[i] = '\0';

    return s1;
}

char *String::Strncpy(char *s1, const char *s2, size_t n) {
    if (s1 == nullptr || s2 == nullptr || n == 0) {
        return s1;
    }

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

char *String::Strcat(char *s1, const char *s2) {
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

char *String::Strncat(char *s1, const char *s2, size_t n) {
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

int String::Memcmp(const void *s1, const void *s2, size_t n) {
    const char *str1 = (char *) s1;
    const char *str2 = (char *) s2;

    while ((n--) > 0) {
        if (*str1++ != *str2++)
            return str1[-1] < str2[-1] ? -1 : 1;
    }
    return 0;
}

int String::Strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return static_cast<int>(*s1) - static_cast<int>(*s2);
}

int String::Strcoll(const char *s1, const char *s2) {
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

int String::Strncmp(const char *s1, const char *s2, size_t n) {
    while (--n && *s1 == *s2) {
        if (*s1 == '\0')
            return 1;
        s1++;
        s2++;
    }

    return (*s1 - *s2);

}

size_t String::Strxfrm(char *s1, const char *s2, size_t n) {
    size_t i = 0;
    while (*s2 != '\0' && i < n) {
        *s1 = *s2;
        s1++;
        s2++;
        i++;
    }
    *s1 = '\0';
    return i;
}

char *String::Strtok(char *s1, const char *s2) {
    static char *last = nullptr; // Последнее место, где был найден разделитель
    char *token_start; // Начало следующего токена
    const char *delimiters = s2; // Разделители

    if (s1 != nullptr)
        last = s1;
    if (last == nullptr || *last == '\0')
        return nullptr;

    while (*last != '\0' && Strchr(delimiters, *last) != nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
        return nullptr;
    }

    token_start = last;

    while (*last != '\0' && Strchr(delimiters, *last) == nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
    } else {
        *last = '\0';
        last++;
    }

    return token_start;
}

void *String::Memset(void *s, int c, size_t n) {
    size_t i;
    char *ss = (char *) s;

    for (i = 0; i < n; i++) {
        ss[i] = c;
    }
    return s;
}

char *String::Strerror(int errnum) {
    static char *errors[] = {
        "No error",                             // 0
        "Operation not permitted",              // 1
        "No such file or directory",            // 2
        "No such process",                      // 3
        "Interrupted system call",              // 4
        "Input/output error",                   // 5
    };

    // Проверяем, является ли код ошибки известным
    if (errnum >= 0 && errnum < sizeof(errors) / sizeof(errors[0]))
        return errors[errnum];
    else
        return "Unknown error"; // Возвращаем "Неизвестная ошибка" для неизвестных кодов ошибок
}

size_t String::Strlen(const char *s) {
    size_t counter = 0;
    while (true) {
        if (s[counter] == '\0') {
            break;
        }
        counter++;
    }
    return counter;
}

char *String::Strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *) str;
        }
        ++str;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const String &str) {
    os << str.c_str();
    return os;
}
