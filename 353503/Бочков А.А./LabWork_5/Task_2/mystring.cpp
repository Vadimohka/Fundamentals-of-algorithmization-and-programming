#include "mystring.h"
#include <stdexcept>

void *memcpy(void *s1, const void *s2, size_t n)
{
    auto aim = static_cast<unsigned char *>(s1);
    auto src = static_cast<const unsigned char *>(s2);

    for (size_t i = 0; i < n; ++i) {
        aim[i] = src[i];
    }

    return s1;
}

void *memmove(void *s1, const void *s2, size_t n)
{
    auto aim = static_cast<unsigned char *>(s1);
    auto src = static_cast<const unsigned char *>(s2);

    if (aim < src) {
        for (size_t i = 0; i < n; ++i) {
            aim[i] = src[i];
        }
    } else if (aim > src) {
        for (size_t i = n; i > 0; --i) {
            aim[i - 1] = src[i - 1];
        }
    }

    return s1;
}

char *strcpy(char *s1, const char *s2)
{
    char *origin = s1;

    while ((*s1++ = *s2++) != '\0') {
    }

    return origin;
}

char *strncpy(char *s1, const char *s2, size_t n)
{
    while (n > 0 && *s2 != '\0') {
        *s1++ = *s2++;
        --n;
    }

    while (n > 0) {
        *s1++ = '\0';
        --n;
    }

    return s1 - n;
}

char *strcat(char *s1, const char *s2)
{
    char *origin = s1;

    while (*s1 != '\0') {
        ++s1;
    }
    while ((*s1++ = *s2++) != '\0') {
    }

    return origin;
}

char *strncat(char *s1, const char *s2, size_t n)
{
    char *origin = s1;

    while (*s1 != '\0') {
        ++s1;
    }

    while (n > 0 && (*s1++ = *s2++) != '\0') {
        --n;
    }
    *s1 = '\0';

    return origin;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    auto p1 = static_cast<const unsigned char *>(s1);
    auto p2 = static_cast<const unsigned char *>(s2);

    for (size_t i = 0; i < n; ++i) {
        if (p1[i] < p2[i]) {
            return -1;
        }
        if (p1[i] > p2[i]) {
            return 1;
        }
    }

    return 0;
}

int strcmp(const char *s1, const char *s2) noexcept
{
    try {
        while (*s1 != '\0' && *s2 != '\0') {
            if (*s1 < *s2) {
                return -1;
            }
            if (*s1 > *s2) {
                return 1;
            }
            ++s1;
            ++s2;
        }

        if (*s1 == '\0' && *s2 != '\0') {
            return -1;
        }
        if (*s1 != '\0' && *s2 == '\0') {
            return 1;
        }
    } catch (...) {
    }
    return 0;
}

// strcoll

int strncmp(const char *s1, const char *s2, size_t n) noexcept
{
    if (n == 0) {
        return 0;
    }

    try {
        while (n > 0 && *s1 != '\0' && *s2 != '\0') {
            if (*s1 < *s2) {
                return -1;
            }
            if (*s1 > *s2) {
                return 1;
            }
            ++s1;
            ++s2;
            --n;
        }

        if (*s1 == '\0' && *s2 != '\0') {
            return -1;
        }
        if (*s1 != '\0' && *s2 == '\0') {
            return 1;
        }
    } catch (...) {
    }
    return 0;
}

//strxfrm

size_t strcspn(const char *s1, const char *s2)
{
    size_t count = 0;

    while (*s1 != '\0') {
        const char *p = s2;
        while (*p != '\0') {
            if (*s1 == *p) {
                return count;
            }
            ++p;
        }
        ++count;
        ++s1;
    }

    return count;
}

//strtok

void *memset(void *s, int c, size_t n)
{
    unsigned char *p = static_cast<unsigned char *>(s);
    unsigned char uc = static_cast<unsigned char>(c);

    for (size_t i = 0; i < n; ++i) {
        p[i] = uc;
    }

    return s;
}

//my_strerror

size_t strlen(const char *s)
{
    size_t length = 0;

    while (*s != '\0') {
        ++length;
        ++s;
    }

    return length;
}

MyString::MyString()
    : _data(std::make_unique<char[]>(1))
    , _size(1)
    , _capacity(1)
{
    _data[0] = '\0';
}

MyString::MyString(const char *str)
{
    size_t mySize = strlen(str) + 1;
    _data = std::make_unique<char[]>(mySize);
    _size = mySize;
    _capacity = mySize;
    memcpy(_data.get(), str, strlen(str));
}

MyString::MyString(size_t amnt, char c)
    : _data(std::make_unique<char[]>(amnt + 1))
    , _size(amnt + 1)
    , _capacity(amnt + 1)
{
    for (size_t i = 0; i < amnt; ++i) {
        _data[i] = c;
    }
}

MyString::MyString(const MyString &other)
    : _data(std::make_unique<char[]>(other._size))
    , _size(other._size)
    , _capacity(other._size)
{
    strcpy(_data.get(), other._data.get());
}

MyString::MyString(MyString &&other) noexcept
    : _data(std::move(other._data))
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
        _data = std::make_unique<char[]>(other._size);
        _size = other._size;
        _capacity = other._capacity;
        strcpy(_data.get(), other._data.get());
    }

    return *this;
}

MyString &MyString::operator=(MyString &&other) noexcept
{
    _data = std::move(other._data);
    _size = other._size;
    _capacity = other._capacity;

    other._capacity = 0;
    other._size = 0;
    other.resize(0);

    return *this;
}

void MyString::resize(size_t newSize)
{
    ++newSize;
    if (newSize <= _size) {
        _size = newSize;
        _data[_size - 1] = '\0';
    } else {
        reserve(newSize);
        for (size_t i = _size; i < newSize; ++i) {
            _data[i] = '\0';
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
        memcpy(newData.get(), _data.get(), _size);
    }
    _data = std::move(newData);
    _capacity = newSize;
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

void MyString::shrink_to_fit()
{
    if (_size == _capacity) {
        return;
    }

    std::unique_ptr<char[]> newData = std::make_unique<char[]>(_size);
    memcpy(newData.get(), _data.get(), _size);
    newData.get()[_size] = '\0';
    _data = std::move(newData);
    _capacity = _size;
}

char &MyString::at(size_t pos)
{
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _data[pos];
}

const char &MyString::at(size_t pos) const
{
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _data[pos];
}

char &MyString::operator[](size_t pos)
{
    return _data[pos];
}

const char &MyString::operator[](size_t pos) const
{
    return _data[pos];
}

char &MyString::front()
{
    return _data[0];
}

const char &MyString::front() const
{
    return _data[0];
}

char &MyString::back()
{
    return _data[_size - 2];
}

const char &MyString::back() const
{
    return _data[_size - 2];
}

const char *MyString::c_str() const noexcept
{
    return _data.get();
}

const char *MyString::data() const noexcept
{
    return _data.get();
}

MyString::iterator MyString::begin() noexcept
{
    return _data.get();
}

MyString::const_iterator MyString::begin() const noexcept
{
    return _data.get();
}

MyString::iterator MyString::end() noexcept
{
    return _data.get() + _size - 1;
}

MyString::const_iterator MyString::end() const noexcept
{
    return _data.get() + _size - 1;
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

void MyString::clear() noexcept
{
    resize(0);
}

void MyString::erase(size_t pos, size_t len)
{
    len = std::min(len, _size - pos);
    memmove(_data.get() + pos, _data.get() + pos + len, _size - pos - len + 1);
    _size -= len;
}

void MyString::push_back(char c)
{
    if (_size + 1 >= _capacity) {
        reserve(_capacity == 0 ? 2 : _capacity * 2);
    }

    _data[_size - 1] = c;
    _data[_size] = '\0';
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

size_t MyString::copy(char *dest, size_t len, size_t pos) const
{
    if (pos > size()) {
        throw std::out_of_range("Position out of range");
    }

    size_t count = std::min(std::min(len, size() - pos), strlen(dest));
    memcpy(dest, _data.get() + pos, count);
    return count;
}

void MyString::insert(size_t pos, const char *str)
{
    reserve(strlen(str) + size());

    memmove(_data.get() + pos + strlen(str), _data.get() + pos, _size - pos);
    memcpy(_data.get() + pos, str, strlen(str));
    _size += strlen(str);
}

void MyString::insert(size_t pos, const MyString &str)
{
    insert(pos, str.data());
}

void MyString::insert(size_t pos, size_t n, char c)
{
    if (pos > _size) {
        throw std::out_of_range("Position out of range");
    }

    size_t newSize = _size + n;
    reserve(newSize);
    memmove(_data.get() + pos + n, _data.get() + pos, _size - pos + 1);
    memset(_data.get() + pos, c, n);
    _size = newSize;
}

void MyString::append(const char *str)
{
    insert(_size - 1, str);
}

void MyString::append(const MyString &str)
{
    append(str.data());
}

void MyString::append(size_t n, char c)
{
    insert(_size - 1, n, c);
}

void MyString::replace(size_t pos, size_t len, const char *str)
{
    erase(pos, len);
    insert(pos, str);
}

void MyString::replace(size_t pos, size_t len, const MyString &str)
{
    replace(pos, len, str.data());
}

size_t MyString::find(const MyString &str, size_t pos) const noexcept
{
    return find(str.c_str(), pos);
}

size_t MyString::find(const char *str, size_t pos) const noexcept
{
    size_t len = strlen(str);
    if (len == 0) {
        return pos <= _size ? pos : NO_POS;
    }
    if (pos >= _size || size() == 0) {
        return NO_POS;
    }

    for (size_t i = pos; i + len <= _size; ++i) {
        bool found = true;
        for (size_t j = 0; j < len; ++j) {
            if (_data[i + j] != str[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return NO_POS;
}

size_t MyString::rfind(const char *str, size_t pos) const noexcept
{
    size_t len = strlen(str);
    if (len == 0) {
        return pos <= _size ? pos : NO_POS;
    }
    if (pos >= _size) {
        pos = _size - 1;
    }
    if (size() == 0) {
        return NO_POS;
    }

    for (size_t i = pos; i != NO_POS; --i) {
        bool found = true;
        for (size_t j = 0; j < len; ++j) {
            if (i + j >= _size || _data[i + j] != str[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return NO_POS;
}

size_t MyString::rfind(const char *str) const noexcept
{
    return rfind(str, _size - 1);
}

size_t MyString::rfind(const MyString &str, size_t pos) const noexcept
{
    return rfind(str.c_str(), pos);
}

size_t MyString::rfind(const MyString &str) const noexcept
{
    return rfind(str.c_str());
}

int MyString::compare(const MyString &str) const noexcept
{
    return strcmp(_data.get(), str._data.get());
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    MyString result(lhs);
    result.append(rhs);
    return result;
}

MyString operator+(const MyString &lhs, char rhs)
{
    MyString result(lhs);
    result.push_back(rhs);
    return result;
}

MyString operator+(char lhs, const MyString &rhs)
{
    MyString result(1, lhs);
    result.append(rhs);
    return result;
}

bool operator==(const MyString &lhs, const MyString &rhs) noexcept
{
    return lhs.compare(rhs) == 0;
}

bool operator!=(const MyString &lhs, const MyString &rhs) noexcept
{
    return !(lhs == rhs);
}

bool operator<(const MyString &lhs, const MyString &rhs) noexcept
{
    return lhs.compare(rhs) < 0;
}

bool operator>(const MyString &lhs, const MyString &rhs) noexcept
{
    return rhs < lhs;
}

bool operator<=(const MyString &lhs, const MyString &rhs) noexcept
{
    return !(rhs < lhs);
}

bool operator>=(const MyString &lhs, const MyString &rhs) noexcept
{
    return !(lhs < rhs);
}

std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
    return os << obj.c_str();
}
