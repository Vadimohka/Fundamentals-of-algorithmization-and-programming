#include "somestring.h"

SomeString::SomeString() {
    length = 0;
    data = nullptr;
}

SomeString::SomeString(const char *str) : length(0), data(nullptr) {
    if (str) {
        length = SomeStrlen(str);
        data = std::make_unique<char[]>(length + 1);
        SomeStrcpy(data.get(), str);
    }
}
SomeString::SomeString(const SomeString &other) {
    length = other.length;

    if (other.data) {
        data = std::make_unique<char[]>(length + 1);
        SomeStrcpy(data.get(), other.data.get());
    } else {
        data = nullptr;
    }

}
size_t SomeString::SomeStrlen(const char *s) {
    size_t counter = 0;
    while (s[counter] != '\0') {
        counter++;
    }
    return counter;
}

char *SomeString::SomeStrcpy(char *s1, const char *s2) {
    if (s1 == nullptr) return s1;
    size_t i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        ++i;
    }
    s1[i] = '\0';

    return s1;
}
SomeString &SomeString::operator=(const SomeString &other) {

        length = other.length;
        data = std::make_unique<char[]>(length + 1);
        SomeStrcpy(data.get(), other.data.get());
    return *this;
}

SomeString &SomeString::operator=(const char *str) {
    size_t newLength = SomeStrlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newLength + 1);
    SomeStrcpy(newData.get(), str);
    data = std::move(newData);
    length = newLength;
    return *this;
}
size_t SomeString::size() const {
    return length;
}

const char *SomeString::c_str() const {
    return data.get();
}

char &SomeString::operator[](size_t index) {
    return data[index];
}

const char &SomeString::operator[](int index) const {
    return data.get()[index];
}

SomeString::iter SomeString::begin() {
    return data.get();
}

SomeString::iter SomeString::end() {
    return data.get() + length;
}

void *SomeString::SomeMemcpy(void *s1, void *s2, size_t n) {
    if (s1 == nullptr || s2 == nullptr)
        return nullptr;

    char *ptr = static_cast<char*>(s1);
    char *ptr1 = static_cast<char*>(s2);

    for (size_t i = 0; i < n; i++) {
        ptr[i] = ptr1[i];
    }
    return s1;
}

char *SomeString::SomeStrncpy(char *s1, const char *s2, size_t n) {
    if (s1 == nullptr || s2 == nullptr || n == 0) {
        return s1;
    }
    else{
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
}

char *SomeString::SomeStrcat(char *s1, const char *s2) {
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

char *SomeString::SomeStrncat(char *s1, const char *s2, size_t n) {
    char *temp = s1;
    while (*s1) {
        ++s1;
    }
    while (n>0 && *s2) {
        *s1++ = *s2++;
        n--;
    }
    *s1 = '\0';
    return temp;

}

int SomeString::SomeMemcmp(const void *s1, const void *s2, size_t n) {
    char *str1 = (char *) s1;
    char *str2 = (char *) s2;

    while (n> 0) {
        n--;
        if (*str1++ != *str2++){
            if(str1[-1] < str2[-1]) return -1;

            else return 1;
}
    }
    return 0;
}

int SomeString::SomeStrcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return static_cast<int>(*s1) - static_cast<int>(*s2);
}

int SomeString::SomeStrcoll(const char *s1, const char *s2) {
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

int SomeString::SomeStrncmp(const char *s1, const char *s2, size_t n) {
    while (n>0 &&*s1 == *s2) {
            n--;
        if (*s1 == '\0')
            return 1;
        s1++;
        s2++;
    }

    return (*s1 - *s2);

}

size_t SomeString::SomeStrxfrm(char *s1, const char *s2, size_t n) {
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


void *SomeString::SomeMemset(void *s, int c, size_t n) {
    size_t i;
    char *ss = (char *) s;

    for (i = 0; i < n; i++) {
        ss[i] = c;
    }
    return s;
}

char *SomeString::SomeStrchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char *) str;
        }
        ++str;
    }
    return nullptr;
}

