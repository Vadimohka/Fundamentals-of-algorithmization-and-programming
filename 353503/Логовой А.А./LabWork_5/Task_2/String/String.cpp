#include "String.h"

void String::reallocate(size_t new_capacity) {
    if (new_capacity <= _capacity) {
        return;
    }
    std::unique_ptr<char[]> new_str(new char[new_capacity]);
    std::copy(str.get(), str.get() + len, new_str.get());
    str.swap(new_str);
    _capacity = new_capacity;
}

String::String() : str(new char[1]{'\0'}), len(0) {

}

String::String(const char *s) : len(strlen(s)), _capacity(len + 1) {
    try {
        str.reset(new char[_capacity]);
    } catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed");
    }
    memcpy(str.get(), s, len);
    str[len] = '\0';
}

String::String(const String &s) : len(s.len), _capacity(len + 1) {
    str.reset(new (std::nothrow) char[_capacity]);
    if (!str) {
       throw std::runtime_error("Memory allocation failed");
    }
    memcpy(str.get(), s.str.get(), len);
    str[len] = '\0';
}

String::String(const char *s, size_t len) : str(new char[_capacity]), len(len), _capacity(len + 1) {
    memcpy(str.get(), s, len);
    str[len] = '\0';
}

String &String::operator=(const char *s) {

    len = strlen(s);
    _capacity = len + 1;
    delete[] str.release();
    str.reset(new char[_capacity]);
    memcpy(str.get(), s, len);
    str[len] = '\0';
    return *this;
}

void *String::memcpy(void *s1, const void *s2, size_t n) {
    char* dest = (char*)s1;
    const char* src = (const char*)s2;
    for (size_t i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
    return s1;
}

void *String::memmove(void *s1, const void *s2, size_t n) {
    char* dest = (char*)s1;
    const char* src = (const char*)s2;
    if (dest < src && dest + n > src) {
        for (size_t i = n - 1; i != (size_t)-1; --i) {
            dest[i] = src[i];
        }
    } else {
        memcpy(s1, s2, n);
    }
    return s1;
}

String &String::operator=(const String &s)
{
    if (this != &s) {
        if (len > _capacity) {
            reallocate(len);
        }

        len = s.len;
        std::copy(s.str.get(), s.str.get() + len, str.get());
        str[len] = '\0';
    }
    return *this;
}

bool String::operator<(const String& other) const {
    size_t i = 0;
    while (i < len && i < other.len) {
        if (str[i] < other.str[i]) {
            return true;
        } else if (str[i] > other.str[i]) {
            return false;
        }
        ++i;
    }
    return len < other.len;
}

bool String::operator>(const String& other) const {
    size_t i = 0;
    while (i < len && i < other.len) {
        if (str[i] < other.str[i]) {
            return true;
        } else if (str[i] > other.str[i]) {
            return false;
        }
        ++i;
    }
    return len < other.len;
}

const char &String::operator[](size_t pos) const {
    if (pos >= len) {
        throw std::out_of_range("Index out of range"); // Error if index is out of bounds
    }
    return str[pos];
}

char &String::operator[](size_t pos) {
    if (pos >= len) {
        throw std::out_of_range("Index out of range"); // Error if index is out of bounds
    }
    return str[pos];
}

String::iterator String::begin()
{
    return str.get();
}

String::const_iterator String::begin() const
{
    return str.get();
}

String::iterator String::end() {
    return str.get() + len;
}

String::const_iterator String::end() const
{
    return str.get() + len;
}

void String::reserve(size_t new_capacity) {
    reallocate(std::max(_capacity, new_capacity));
}

void String::push_back(char ch) {
    if (len == _capacity) {
        reserve(_capacity * 2);
    }
    str[len++] = ch;
    str[len] = '\0';
}

void String::pop_back() {
    if (len > 0) {
        --len;
        str[len] = '\0';
    }
}

void String::append(const char *s) {
    size_t additional_len = strlen(s);
    if (len + additional_len >= _capacity) {
        reserve(_capacity + additional_len);
    }
    memcpy(str.get() + len, s, additional_len);
    len += additional_len;
    str[len] = '\0';
}

String &String::operator+=(const char *s) {
    append(s);
    return *this;
}

char *String::strcpy(char *s1, const char *s2) {
    char* dest = s1;
    while (*s2) {
        *dest++ = *s2++;
    }
    *dest = '\0';
    return s1;
}

char *String::strncpy(char *s1, const char *s2, size_t n) {
    char* dest = s1;
    size_t i = 0;
    while (i < n && *s2) {
        *dest++ = *s2++;
        ++i;
    }
    if (i < n) {
        *dest = '\0';
    }
    return s1;
}

char *String::strcat(char *s1, const char *s2) {
    char* dest = s1;
    while (*dest) {
        dest++;
    }
    strcpy(dest, s2);
    return s1;
}

char *String::strncat(char *s1, const char *s2, size_t n) {
    char* dest = s1;
    while (*dest) {
        dest++;
    }
    size_t i = 0;
    while (i < n && *s2) {
        *dest++ = *s2++;
        ++i;
    }
    if (i < n) {
        *dest = '\0';
    }
    return s1;
}

int String::strcmp(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int String::memcmp(const void *s1, const void *s2, size_t n) {
    const char* a = (const char*)s1;
    const char* b = (const char*)s2;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return (unsigned char)a[i] - (unsigned char)b[i];
        }
    }
    return 0;
}

void *String::memset(void *s, int c, size_t n) {
    unsigned char* dest = (unsigned char*)s;
    for (size_t i = 0; i < n; ++i) {
        dest[i] = (unsigned char)c;
    }
    return s;
}

char *String::strerror(int errnum) {
    return "Error message not available";
}

int String::strcoll(const char *s1, const char *s2) {
    int result = 0;
    while (*s1 && *s2) {
        unsigned char c1 = (unsigned char)*s1++;
        unsigned char c2 = (unsigned char)*s2++;

        if (c1 < c2) {
            result = -1;
            break;
        } else if (c1 > c2) {
            result = 1;
            break;
        }
    }

    if (!*s1 && *s2) {
        result = -1;
    } else if (*s1 && !*s2) {
        result = 1;
    }

    return result;
}

size_t String::strxfrm(char *s1, const char *s2, size_t n) {
    size_t i = 0;
    while (i < n && *s2) {
        s1[i] = *s2++;
        i++;
    }

    if (i < n) {
        s1[i] = '\0';
    }

    return i;
}

size_t String::strlen(const char *s)
{
    const char* str = s;
    while (*str)
    {
        ++str;
    }
    return str - s;
}

void String::copy(const char *src, size_t src_pos, size_t count, char *dest) {
    while (count-- > 0) {
        *dest++ = src[src_pos++];
    }
}


size_t String::size() const
{
    return len;
}

size_t String::length() const
{
    return len;
}

bool String::empty() const {
    return len == 0;
}

const char *String::c_str() const
{
    return str.get();
}

char &String::at(size_t pos) {
    if (pos >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[pos];
}

const char &String::at(size_t pos) const {
    if (pos >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[pos];
}

String String::operator+(const String &other) const
{
    String result(*this);
    result += other;
    return result;
}

String &String::operator+=(const String &other)
{
    size_t newLen = len + other.len;
    std::unique_ptr<char[]> newStr(new char[newLen + 1]);
    std::copy(str.get(), str.get() + len, newStr.get());
    std::copy(other.str.get(), other.str.get() + other.len, newStr.get() + len);
    newStr[newLen] = '\0';
    len = newLen;
    str.swap(newStr);
    return *this;
}

void String::memset(int c, size_t n) {
    len = std::min(len, n);
    std::fill_n(str.get(), len, c);
}

size_t String::strlen() const {
    return len;
}

void String::clear() {
    len = 0;
    str.reset(new char[1]{'\0'});
}

size_t String::find(const char *sub, size_t pos) const {
    if (sub == nullptr) {
        throw std::invalid_argument("Subtring cannot be null");
    }

    size_t sub_len = 0;
    while (sub[sub_len] != '\0') {
        sub_len++;
    }

    if (pos > len) {
        return npos;
    }

    try {
        for (size_t i = pos; i <= len - sub_len; ++i) {
            if (str[i] == sub[0]) {
                bool found = true;
                for (size_t j = 1; j < sub_len; ++j) {
                    if (str[i + j] != sub[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return i;
                }
            }
        }


        return npos;
    } catch (const std::exception& e) {

        return npos;
    }
}

void String::insert(size_t pos, const String &other)
{

    if (pos > len) {
        throw std::out_of_range("Index out of range");
    }
    size_t newLen = len + other.len;
    std::unique_ptr<char[]> newStr(new char[newLen + 1]);
    std::copy(str.get(), str.get() + pos, newStr.get());
    std::copy(other.str.get(), other.str.get() + other.len, newStr.get() + pos);
    std::copy(str.get() + pos, str.get() + len, newStr.get() + pos + other.len);
    newStr[newLen] = '\0';
    len = newLen;
    str.swap(newStr);
}

void String::erase(size_t pos, size_t len)
{

    if (pos > this->len) {
        throw std::out_of_range("Index out of range");
    }
    size_t eraseLen = std::min(len, this->len - pos);
    size_t newLen = this->len - eraseLen;
    std::unique_ptr<char[]> newStr(new char[newLen + 1]);
    std::copy(str.get(), str.get() + pos, newStr.get());
    std::copy(str.get() + pos + eraseLen, str.get() + this->len, newStr.get() + pos);
    newStr[newLen] = '\0';
    len = newLen;
    str.swap(newStr);
}

void String::replace(size_t pos, size_t len, const String &other)
{
    erase(pos, len);
    insert(pos, other);
}
