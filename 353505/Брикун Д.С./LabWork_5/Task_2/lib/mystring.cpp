#include "mystring.h"

myString::myString() : length(0), data(nullptr) {}

myString::myString(const char *str) : length(myStrlen(str)) {
    data = std::make_unique<char[]>(length + 1);
    myStrcpy(data.get(), str);
}

myString::myString(const myString &other) : length(other.length) {
    data = std::make_unique<char[]>(length + 1);
    myStrcpy(data.get(), other.data.get());
}

myString &myString::operator=(const myString &other) {
    if (this != &other) {
        length = other.length;
        data = std::make_unique<char[]>(length + 1);
        myStrcpy(data.get(), other.data.get());
    }
    return *this;
}

myString &myString::operator=(const char *str) {
    size_t newLength = myStrlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    myStrcpy(newData.get(), str);
    data = std::move(newData);
    length = newLength;
    return *this;
}

size_t myString::size() const {
    return length;
}

const char *myString::c_str() const {
    return data.get();
}

char &myString::operator[](size_t index) {
    return data[index];
}

const char &myString::operator[](int index) const {
    return data.get()[index];
}

myString::iterator myString::begin() {
    return data.get();
}

myString::iterator myString::end() {
    return data.get() + length;
}

myString::const_iterator myString::begin() const {
    return data.get();
}

myString::const_iterator myString::end() const {
    return data.get() + length;
}

myString &myString::operator+=(const myString &other) {
    size_t newSize = length + other.size();
    auto newData = std::unique_ptr<char[]>(new char[newSize + 1]);
    myStrcpy(newData.get(), data.get());
    myStrcat(newData.get(), other.data.get());
    data = std::move(newData);
    length = newSize;
    return *this;
}

myString &myString::operator+=(const char *str) {
    size_t newLength = length + myStrlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    myStrcpy(newData.get(), data.get());
    myStrcat(newData.get(), str);
    data = std::move(newData);
    length = newLength;
    return *this;
}

myString myString::operator+(const myString &other) const {
    myString result(*this);
    result += other;
    return result;
}

bool myString::operator==(const myString &other) const {
    return myStrcmp(data.get(), other.data.get()) == 0;
}

bool myString::operator!=(const myString &other) const {
    return !(*this == other);
}

bool myString::operator<(const myString &other) const {
    return myStrcmp(data.get(), other.data.get()) < 0;
}

bool myString::operator>(const myString &other) const {
    return myStrcmp(data.get(), other.data.get()) > 0;
}

void myString::push_back(const char c) {
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(length + 2);
    myStrcpy(newData.get(), data.get());
    newData.get()[length] = c;
    newData.get()[length + 1] = '\0';
    data = std::move(newData);
    ++length;
}

void *myString::myMemcpy(void *s1, const void *s2, size_t n) {
    if (s1 == nullptr) return s1;
    char *ptr = (char *) s1;
    char *ptr1 = (char *) s2;
    for (size_t i = 0; i < n; i++) {
        ptr[i] = ptr1[i];
    }
    return s1;
}

void *myString::myMemmove(void *s1, const void *s2, size_t n) {
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

char *myString::myStrcpy(char *s1, const char *s2) {
    if (s1 == nullptr) return s1;
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        ++i;
    }
    s1[i] = '\0';

    return s1;
}

char *myString::myStrncpy(char *s1, const char *s2, size_t n) {
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

char *myString::myStrcat(char *s1, const char *s2) {
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

char *myString::myStrncat(char *s1, const char *s2, size_t n) {
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

int myString::myMemcmp(const void *s1, const void *s2, size_t n) {
    const char *str1 = (char *) s1;
    const char *str2 = (char *) s2;

    while ((n--) > 0) {
        if (*str1++ != *str2++)
            return str1[-1] < str2[-1] ? -1 : 1;
    }
    return 0;
}

int myString::myStrcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return static_cast<int>(*s1) - static_cast<int>(*s2);
}

int myString::myStrcoll(const char *s1, const char *s2) {
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

int myString::myStrncmp(const char *s1, const char *s2, size_t n) {
    while (--n && *s1 == *s2) {
        if (*s1 == '\0')
            return 1;
        s1++;
        s2++;
    }

    return (*s1 - *s2);

}

size_t myString::myStrxfrm(char *s1, const char *s2, size_t n) {
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

char *myString::myStrtok(char *s1, const char *s2) {
    static char *last = nullptr; // Последнее место, где был найден разделитель
    char *token_start; // Начало следующего токена
    const char *delimiters = s2; // Разделители

    if (s1 != nullptr)
        last = s1;
    if (last == nullptr || *last == '\0')
        return nullptr;

    while (*last != '\0' && myStrchr(delimiters, *last) != nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
        return nullptr;
    }

    token_start = last;

    while (*last != '\0' && myStrchr(delimiters, *last) == nullptr)
        last++;

    if (*last == '\0') {
        last = nullptr;
    } else {
        *last = '\0';
        last++;
    }

    return token_start;
}

void *myString::myMemset(void *s, int c, size_t n) {
    size_t i;
    char *ss = (char *) s;

    for (i = 0; i < n; i++) {
        ss[i] = c;
    }
    return s;
}

char *myString::myStrerror(int errnum) {
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

size_t myString::myStrlen(const char *s) {
    size_t counter = 0;
    while (true) {
        if (s[counter] == '\0') {
            break;
        }
        counter++;
    }
    return counter;
}

char *myString::myStrchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *) str;
        }
        ++str;
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const myString &str) {
    os << str.c_str();
    return os;
}
