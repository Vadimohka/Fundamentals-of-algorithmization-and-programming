#include "mystring.h"

namespace str {

void *memcpy(void *s1, const void *s2, size_t n)
{
    char *dest = static_cast<char *>(s1);
    const char *src = static_cast<const char *>(s2);
    while (n--) {
        *dest++ = *src++;
    }
    return s1;
}

void *memmove(void *s1, const void *s2, size_t n)
{
    char *dest = static_cast<char *>(s1);
    const char *src = static_cast<const char *>(s2);
    if (dest <= src || dest >= (src + n)) {
        while (n--) {
            *dest++ = *src++;
        }
    } else {
        dest += n;
        src += n;
        while (n--) {
            *--dest = *--src;
        }
    }
    return s1;
}

char *strcpy(char *s1, const char *s2)
{
    char *dest = s1;
    while ((*dest++ = *s2++)) {
    }
    return s1;
}

char *strncpy(char *s1, const char *s2, size_t n)
{
    char *dest = s1;
    const char *src = s2;
    while (n-- && *src) {
        *dest++ = *src++;
    }

    if (n) {
        *dest = '\0';
    }
    return s1;
}

char *strcat(char *s1, const char *s2)
{
    char *dest = s1;
    // Перемещаем указатель dest до конца строки s1
    while (*dest) {
        ++dest;
    }
    // Копируем символы из s2 в конец s1
    while (*s2) {
        *dest++ = *s2++;
    }

    *dest = '\0';
    return s1;
}

char *strncat(char *s1, const char *s2, size_t n)
{
    char *dest = s1;
    // Перемещаем указатель dest до конца строки s1
    while (*dest) {
        ++dest;
    }
    // Копируем символы из s2 в конец s1, но не более n символов
    while (n-- && *s2) {
        *dest++ = *s2++;
    }

    *dest = '\0';
    return s1;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1 = static_cast<const unsigned char *>(s1);
    const unsigned char *p2 = static_cast<const unsigned char *>(s2);
    while (n--) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        ++p1;
        ++p2;
    }
    return 0;
}

int strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
    }
    return *reinterpret_cast<const unsigned char *>(s1)
           - *reinterpret_cast<const unsigned char *>(s2);
}

int strcoll(const char *s1, const char *s2)
{
    setlocale(LC_ALL, "");
    return str::strcmp(s1, s2);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n--) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        } else if (*s1 == '\0') {
            return 0;
        }
        ++s1;
        ++s2;
    }
    return 0;
}

size_t strxfrm(char *s1, const char *s2, size_t n)
{
    setlocale(LC_ALL, "");
    size_t len = strlen(s2);
    if (len >= n) {
        strncpy(s1, s2, n);
    }
    return len;
}

char *strtok(char *s1, const char *s2)
{
    static char *next_token = nullptr;
    if (s1 != nullptr) {
        next_token = s1;
    }
    if (next_token == nullptr) {
        return nullptr;
    }
    char *token_start = next_token;
    while (*next_token != '\0') {
        const char *s2_ptr = s2;
        while (*s2_ptr != '\0') {
            if (*next_token == *s2_ptr) {
                *next_token = '\0';
                ++next_token;
                return token_start;
            }
            ++s2_ptr;
        }
        ++next_token;
    }
    next_token = nullptr;
    return token_start;
}

void *memset(void *s, int c, size_t n)
{
    char *dest = static_cast<char *>(s);
    while (n--) {
        *dest++ = static_cast<char>(c);
    }
    return s;
}

size_t strlen(const char *s)
{
    const char *dest = s;
    while (*dest) {
        ++dest;
    }
    return dest - s;
}
}

std::ostream &operator<<(std::ostream &os, const MyString &string)
{
    return os << string.c_str();
}

const char *MyString::c_str() const noexcept
{
    return _array.get();
}

char &MyString::operator[](size_t pos)
{
    return _array[pos];
}

const char &MyString::operator[](size_t pos) const
{
    return _array[pos];
}

MyString::MyString()
    : _array(std::make_unique<char[]>(1))
    , _size(1)
    , _capacity(1)
{
    _array[0] = '\0';
}

MyString::MyString(size_t amount, char c)
    : _array(std::make_unique<char[]>(amount + 1))
    , _size(amount + 1)
    , _capacity(amount + 1)
{
    for (size_t i = 0; i < amount; ++i) {
        _array[i] = c;
    }
}

MyString::MyString(const char *str)
{
    size_t mySize = str::strlen(str) + 1;
    _array = std::make_unique<char[]>(mySize);
    _size = mySize;
    _capacity = mySize;
    str::memcpy(_array.get(), str, str::strlen(str));
}

MyString::MyString(MyString &&other) noexcept
    : _array(std::move(other._array))
    , _size(other._size)
    , _capacity(other._size)
{
    other._capacity = 0;
    other._size = 0;
    other.resize(0);
}

MyString &MyString::operator=(const MyString &other)
{
    if (&other != this) {
        _array = std::make_unique<char[]>(other._size);
        _size = other._size;
        _capacity = other._capacity;
        str::strncpy(_array.get(), other._array.get(), other._size);
    }
    return *this;
}

MyString &MyString::operator=(MyString &&other) noexcept
{
    _array = std::move(other._array);
    _size = other._size;
    _capacity = other._capacity;

    other._capacity = 0;
    other._size = 0;
    other.resize(0);

    return *this;
}

char &MyString::at(size_t pos)
{
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _array[pos];
}

const char &MyString::at(size_t pos) const
{
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _array[pos];
}

void MyString::resize(size_t newSize)
{
    ++newSize;
    if (newSize <= _size) {
        _size = newSize;
        _array[_size - 1] = '\0';
    } else {
        reserve(newSize);
        for (size_t i = _size; i < newSize; ++i) {
            _array[i] = '\0';
        }
        _size = newSize;
    }
}

void MyString::reserve(size_t newSize)
{
    ++newSize;
    if (newSize <= _capacity) {
        return;
    }

    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newSize);
    if (_size > 1) {
        str::memcpy(newData.get(), _array.get(), _size);
    }

    _array = std::move(newData);
    _capacity = newSize;
}

void MyString::push_back(char c)
{
    if (_size + 1 >= _capacity) {
        reserve(_capacity == 0 ? 2 : _capacity * 2);
    }

    _array[_size - 1] = c;
    _array[_size] = '\0';
    ++_size;
}

void MyString::pop_back() noexcept
{
    if (_size > 1) {
        back() = '\0';
        --_size;
        return;
    }

    if (_capacity != 0) {
        front() = '\0';
    }
}

bool MyString::empty() const noexcept
{
    return _size <= 1;
}

size_t MyString::length() const noexcept
{
    if (_size == 0) {
        return 0;
    }
    return _size - 1;
}

size_t MyString::size() const noexcept
{
    if (_size == 0) {
        return 0;
    }
    return _size - 1;
}

size_t MyString::capacity() const noexcept
{
    return _capacity;
}

void MyString::clear() noexcept
{
    resize(0);
}

MyString::iterator MyString::begin() noexcept
{
    return _array.get();
}

MyString::const_iterator MyString::begin() const noexcept
{
    return _array.get();
}

MyString::iterator MyString::end() noexcept
{
    return _array.get() + _size - 1;
}

MyString::const_iterator MyString::end() const noexcept
{
    return _array.get() + _size - 1;
}

MyString::reverse_iterator MyString::rbegin() noexcept
{
    return reverse_iterator(end());
}

MyString::const_reverse_iterator MyString::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}

MyString::reverse_iterator MyString::rend() noexcept
{
    return reverse_iterator(begin() - 1);
}

MyString::const_reverse_iterator MyString::rend() const noexcept
{
    return const_reverse_iterator(begin() - 1);
}

char &MyString::front()
{
    return _array[0];
}

const char &MyString::front() const
{
    return _array[0];
}

char &MyString::back()
{
    return _array[_size - 2];
}

const char &MyString::back() const
{
    return _array[_size - 2];
}
