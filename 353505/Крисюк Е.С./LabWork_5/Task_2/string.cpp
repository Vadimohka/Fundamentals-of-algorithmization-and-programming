#include "string.h"

String::String() {
    length = 0;
    data = nullptr;
}


String::String(const char *str) : length(0), data(nullptr) {
    if (str) {
        length = Strlen(str);
        data = std::make_unique<char[]>(length + 1);
        Strcpy(data.get(), str);
    }
}

String::String(const String &str) {
    length = str.length;

    if (str.data) {
        data = std::make_unique<char[]>(length + 1);
        Strcpy(data.get(), str.data.get());
    } else {
        data = nullptr;
    }

}
size_t String::Strlen(const char *s) {
    size_t counter = 0;
    while (s[counter] != '\0') {
        counter++;
    }
    return counter;
}

char *String::Strcpy(char *first_string, const char *second_string) {
    if (first_string == nullptr) return first_string;
    size_t i = 0;
    while (second_string[i] != '\0') {
        first_string[i] = second_string[i];
        ++i;
    }
    first_string[i] = '\0';

    return first_string;
}
String &String::operator=(const String &str) {

        length = str.length;
        data = std::make_unique<char[]>(length + 1);
        Strcpy(data.get(), str.data.get());
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

String::iter String::begin() {
    return data.get();
}

String::iter String::end() {
    return data.get() + length;
}

void *String::Memcpy(void *first_string, void *second_string, size_t n) {
    if (first_string == nullptr || second_string == nullptr)
        return nullptr;

    char *ptr = static_cast<char*>(first_string);
    char *ptr1 = static_cast<char*>(second_string);

    for (size_t i = 0; i < n; i++) {
        ptr[i] = ptr1[i];
    }
    return first_string;
}

char *String::Strncpy(char *first_string, const char *second_string, size_t n) {
    if (first_string == nullptr || second_string == nullptr || n == 0) {
        return first_string;
    }
    else{
    size_t i = 0;
    while (i < n && second_string[i] != '\0') {
        first_string[i] = second_string[i];
        ++i;
    }

    while (i < n) {
        first_string[i] = '\0';
        ++i;
    }

    return first_string;
}
}

char *String::Strcat(char *first_string, const char *second_string) {
    size_t i = 0, j = 0;
    while (first_string[i] != '\0') {
        ++i;
    }

    while (second_string[j] != '\0') {
        first_string[i] = second_string[j];
        ++i;
        ++j;
    }

    first_string[i] = '\0';

    return first_string;
}

char *String::Strncat(char *first_string, const char *second_string, size_t n) {
    char *temp = first_string;
    while (*first_string) {
        ++first_string;
    }
    while (n>0 && *second_string) {
        *first_string++ = *second_string++;
        n--;
    }
    *first_string = '\0';
    return temp;

}

int String::Memcmp(const void *first_string, const void *second_string, size_t n) {
    char *str1 = (char *) first_string;
    char *str2 = (char *) second_string;

    while (n> 0) {
        n--;
        if (*str1++ != *str2++){
            if(str1[-1] < str2[-1]) return -1;

            else return 1;
}
    }
    return 0;
}

int String::Strcmp(const char *first_string, const char *second_string) {
    while (*first_string != '\0' && *second_string != '\0' && *first_string == *second_string) {
        ++first_string;
        ++second_string;
    }
    return static_cast<int>(*first_string) - static_cast<int>(*second_string);
}

int String::Strcoll(const char *first_string, const char *second_string) {

    while (*first_string != '\0' && *second_string != '\0') {
        if (*first_string < *second_string) {
            return -1;
        } else if (*first_string > *second_string) {
            return 1;
        }
        first_string++;
        second_string++;
    }
    if (*first_string == '\0' && *second_string == '\0') {
        return 0;
    } else if (*first_string == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int String::Strncmp(const char *first_string, const char *second_string, size_t n) {
    while (n>0 &&*first_string == *second_string) {
            n--;
        if (*first_string == '\0')
            return 1;
        first_string++;
        second_string++;
    }

    return (*first_string - *second_string);

}

size_t String::Strxfrm(char *first_string, const char *second_string, size_t n) {
    size_t i = 0;
    while (*second_string != '\0' && i < n) {
        *first_string = *second_string;
        first_string++;
        second_string++;
        i++;
    }
    *first_string = '\0';
    return i;
}


void *String::Memset(void *s, int c, size_t n) {
    size_t i;
    char *ss = (char *) s;

    for (i = 0; i < n; i++) {
        ss[i] = c;
    }
    return s;
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

