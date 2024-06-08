#include "mystring.h"

myString::myString() {
    length = 0;
    data = nullptr;
}

myString::myString(const char *str){
    length = myStrlen(str);
    data = std::make_unique<char[]>(length + 1);
    myStrcpy(data.get(), str);
}

myString::myString(const myString &a) {
    length = a.length;
    data = std::make_unique<char[]>(length + 1);
    myStrcpy(data.get(), a.data.get());
}

myString &myString::operator=(const myString &a) {
    if (this != &a) {
        length = a.length;
        data = std::make_unique<char[]>(length + 1);
        myStrcpy(data.get(), a.data.get());
    }
    return *this;
}

myString &myString::operator=(const char *str) {
    size_t nlength = myStrlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(nlength + 1);
    myStrcpy(newData.get(), str);
    data = std::move(newData);
    length = nlength;
    return *this;
}

size_t myString::size() const {
    return length;
}

const char *myString::c_str() const {
    return data.get();
}

char &myString::operator[](size_t i) {
    return data[i];
}

const char &myString::operator[](int i) const {
    return data.get()[i];
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

myString &myString::operator+=(const myString &a) {
    size_t nsize = length + a.size();
    auto newData = std::unique_ptr<char[]>(new char[nsize + 1]);
    myStrcpy(newData.get(), data.get());
    myStrcat(newData.get(), a.data.get());
    data = std::move(newData);
    length = nsize;
    return *this;
}

myString &myString::operator+=(const char *str) {
    size_t nlength = length + myStrlen(str);
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(nlength + 1);
    myStrcpy(newData.get(), data.get());
    myStrcat(newData.get(), str);
    data = std::move(newData);
    length = nlength;
    return *this;
}

myString myString::operator+(const myString &a) const {
    myString result(*this);
    result += a;
    return result;
}

bool myString::operator==(const myString &a) const {
    return myStrcmp(data.get(), a.data.get()) == 0;
}

bool myString::operator!=(const myString &a) const {
    return !(*this == a);
}

bool myString::operator<(const myString &a) const {
    return myStrcmp(data.get(), a.data.get()) < 0;
}

bool myString::operator>(const myString &a) const {
    return myStrcmp(data.get(), a.data.get()) > 0;
}

void myString::push_back(const char a) {
    std::unique_ptr<char[]> newData = std::make_unique<char[]>(length + 2);
    myStrcpy(newData.get(), data.get());
    newData.get()[length] = a;
    newData.get()[++length] = '\0';
    data = std::move(newData);

}

void *myString::myMemcpy(void *s1, const void *s2, size_t n) {
    if (s1 == nullptr) return s1;
    char *ch = (char*) s1, *ch1 = (char*) s2;
    for (size_t i = 0; i < n; i++) ch[i] = ch1[i];
    return s1;
}

void *myString::myMemmove(void *s1, const void *s2, size_t n) {
    char *ch = (char*) s1;
    const char *ch1 = (char*) s2;
    if (ch < ch1) while (n--) *ch++ = *ch1++;
    else {
        char *l = (char*)ch1 + (n - 1), *l1 = ch + (n - 1);
        while (n--) *l1-- = *l--;
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
    char *t = s1;
    while (*s1) {
        ++s1;
    }
    while (n-- && *s2) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return t;

}

int myString::myMemcmp(const void *s1, const void *s2, size_t n) {
    const char *ch = (char *) s1;
    const char *ch1 = (char *) s2;
    while ((n--) > 0) {
        if (*ch++ != *ch1++) return ch[-1] < ch1[-1] ? -1 : 1;
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
        if (*s1 < *s2) return -1;
        else if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') return 0;
    else if (*s1 == '\0') return -1;
    else return 1;
}

int myString::myStrncmp(const char *s1, const char *s2, size_t n) {
    while (--n && *s1 == *s2) {
        if (*s1 == '\0') return 1;
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
    static char *l = nullptr;
    char *ch;
    const char *ch2 = s2;
    if (s1 != nullptr) l = s1;
    if (l == nullptr || *l == '\0') return nullptr;
    while (*l != '\0' && myStrchr(ch2, *l) != nullptr){
        l++;
    }
    if (*l == '\0') {
        l = nullptr;
        return nullptr;
    }
    ch = l;
    while (*l != '\0' && myStrchr(ch2, *l) == nullptr){
        l++;
    }
    if (*l == '\0') l = nullptr;
    else {
        *l = '\0';
        l++;
    }
    return ch;
}

void *myString::myMemset(void *s, int c, size_t n) {
    size_t i;
    char *ch = (char *) s;
    for (i = 0; i < n; i++) ch[i] = c;
    return s;
}

char *myString::myStrerror(int errnum) {
    static char *errors[] = {"No error","Operation not permitted","No such file or directory","No such process","Interrupted system call","Input/output error"};
    if (errnum >= 0 && errnum < sizeof(errors) / sizeof(errors[0])) return errors[errnum];
    else return "Unknown error";
}

size_t myString::myStrlen(const char *s) {
    size_t counter = 0;
    while (true) {
        if (s[counter] == '\0') break;
        counter++;
    }
    return counter;
}

char *myString::myStrchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c) return (char *) str;
        ++str;
    }
    return nullptr;
}
