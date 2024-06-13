#include "mystring.h"

namespace my
{
    void* memcpy(void* s1, const void* s2, size_t n)
    {
        auto aim = static_cast<unsigned char*>(s1);
        auto src = static_cast<const unsigned char*>(s2);
        for (size_t i = 0; i < n; ++i)
        {
            aim[i] = src[i];
        }

        return s1;
    }


    void* memmove(void* s1, const void* s2, size_t n)
    {
        auto aim = static_cast<unsigned char*>(s1);
        auto src = static_cast<const unsigned char*>(s2);

        if (aim < src)
        {
            for (size_t i = 0; i < n; ++i)
            {
                aim[i] = src[i];
            }
        }
        else if (aim > src)
        {
            for (size_t i = n; i > 0; --i)
            {
                aim[i - 1] = src[i - 1];
            }
        }

        return s1;
    }


    char* strcpy(char* s1, const char* s2)
    {
        char* origin = s1;
        while ((*s1++ = *s2++) != '\0') {}
        return origin;
    }


    char* strncpy(char* s1, const char* s2, size_t n)
    {
        while (n > 0 && *s2 != '\0')
        {
            *s1++ = *s2++;
            --n;
        }
        while (n > 0)
        {
            *s1++ = '\0';
            --n;
        }
        return s1 - n;
    }


    char* strcat(char* s1, const char* s2)
    {
        char* origin = s1;
        while (*s1 != '\0')
        {
            ++s1;
        }
        while ((*s1++ = *s2++) != '\0') {}
        return origin;
    }


    char* strncat(char* s1, const char* s2, size_t n)
    {
        char* origin = s1;
        while (*s1 != '\0')
        {
            ++s1;
        }
        while (n > 0 && (*s1++ = *s2++) != '\0')
        {
            --n;
        }

        *s1 = '\0';

        return origin;
    }


    int memcmp(const void* s1, const void* s2, size_t n)
    {
        auto p1 = static_cast<const unsigned char*>(s1);
        auto p2 = static_cast<const unsigned char*>(s2);

        for (size_t i = 0; i < n; ++i)
        {
            if (p1[i] < p2[i])
            {
                return -1;
            }

            if (p1[i] > p2[i])
            {
                return 1;
            }
        }

        return 0;
    }


    int strcmp(const char* s1, const char* s2) noexcept
    {
        try
        {
            while (*s1 != '\0' && *s2 != '\0')
            {
                if (*s1 < *s2)
                {
                    return -1;
                }

                if (*s1 > *s2)
                {
                    return 1;
                }

                ++s2;
                ++s1;
            }

            if (*s1 == '\0' && *s2 != '\0')
            {
                return -1;
            }

            if (*s1 != '\0' && *s2 == '\0')
            {
                return 1;
            }
        }
        catch (...)
        {
            throw 1;
        }

        return 0;
    }


    int strncmp(const char* s1, const char* s2, size_t n) noexcept
    {
        if (n == 0) { return 0; }
        try
        {
            while (n > 0 && *s1 != '\0' && *s2 != '\0')
            {
                if (*s1 < *s2)
                {
                    return -1;
                }
                if (*s1 > *s2)
                {
                    return 1;
                }

                --n;
                ++s1;
                ++s2;

            }
            if (*s1 == '\0' && *s2 != '\0')
            {
                return -1;
            }

            if (*s1 != '\0' && *s2 == '\0')
            {
                return 1;
            }
        }
        catch(...)
        {
            throw 1;
        }

        return 0;
    }


    size_t strcspn(const char* s1, const char* s2)
    {
        size_t count = 0;
        while (*s1 != '\0')
        {
            const char* p = s2;
            while (*p != '\0')
            {
                if (*s1 == *p)
                {
                    return count;
                }

                ++p;
            }

            ++count;
            ++s1;
        }

        return count;
    }


    void* memset(void* s, int c, size_t n)
    {
        unsigned char* p = static_cast<unsigned char*>(s);
        unsigned char uc = static_cast<unsigned char>(c);

        for (size_t i = 0; i < n; ++i)
        {
            p[i] = uc;
        }

        return s;
    }


    size_t strlen(const char* s)
    {
        size_t length = 0;

        while (*s != '\0')
        {
            ++length;
            ++s;
        }

        return length;
    }
}


QString String::toQString()
{
    QString ans = "";

    for (int i = 0; i < _size - 1; ++i)
    {
        ans.push_back(_data[i]);
    }

    return ans;
}

String::String() : _data(std::make_unique<char[]>(1)), _size(1), _capacity(1)
{
    _data[0] = '\0';
}


String::String(const char *str)
{
    size_t mySize = my::strlen(str) + 1;
    _data = std::make_unique<char[]>(mySize);
    _size = mySize;
    _capacity = mySize;
    my::memcpy(_data.get(), str, my::strlen(str));
}


String::String(size_t amnt, char c) : _data(std::make_unique<char[]>(amnt + 1)), _size(amnt + 1), _capacity(amnt + 1)
{
    for (size_t i = 0; i < amnt; ++i)
    {
        _data[i] = c;
    }
}


String::String(const String &other): _data(std::make_unique<char[]>(other._size)), _size(other._size), _capacity(other._size)
{
    my::strcpy(_data.get(), other._data.get());
}


String::String(String &&other) noexcept: _data(std::move(other._data)), _size(other._size), _capacity(other._size)
{
    other._capacity = 0;
    other._size = 0;
    other.resize(0);
}


String& String::operator=(const String& other)
{
    if (&other != this)
    {
        _data = std::make_unique<char[]>(other._size);
        _size = other._size;
        _capacity = other._capacity;
        my::strcpy(_data.get(), other._data.get());
    }

    return *this;
}


String& String::operator=(String&& other) noexcept
{
    _data = std::move(other._data);
    _size = other._size;
    _capacity = other._capacity;

    other._capacity = 0;
    other._size = 0;
    other.resize(0);

    return *this;
}


void String::resize(size_t newSize)
{
    ++newSize;
    if (newSize <= _size)
    {
        _size = newSize;
        _data[_size - 1] = '\0';
    }
    else
    {
        reserve(newSize);
        for (size_t i = _size; i < newSize; ++i) {
            _data[i] = '\0';
        }
        _size = newSize;
    }
}


void String::reserve(size_t newSize)
{
    ++newSize;
    if (newSize <= _capacity)
    {
        return;
    }

    std::unique_ptr<char[]> newData = std::make_unique<char[]>(newSize);
    if (_size > 1)
    {
        my::memcpy(newData.get(), _data.get(), _size);
    }

    _data = std::move(newData);
    _capacity = newSize;
}


bool String::empty() const noexcept
{
    return _size <= 1;
}


size_t String::size() const noexcept
{
    if (_size == 0)
    {
        return 0;
    }

    return _size - 1;
}


char& String::operator[](size_t pos)
{
    return _data[pos];
}


const char& String::operator[](size_t pos) const
{
    return _data[pos];
}


char& String::front()
{
    return _data[0];
}


char& String::back()
{
    return _data[_size - 2];
}


const char* String::c_str() const noexcept
{
    return _data.get();
}


const char* String::data() const noexcept
{
    return _data.get();
}


String::iterator String::begin() noexcept
{
    return _data.get();
}


String::const_iterator String::begin() const noexcept
{
    return _data.get();
}


String::iterator String::end() noexcept
{
    return _data.get() + _size - 1;
}


String::const_iterator String::end() const noexcept
{
    return _data.get() + _size - 1;
}


String::reverse_iterator String::rbegin() noexcept
{
    return reverse_iterator(end());
}


String::const_reverse_iterator String::rbegin() const noexcept
{
    return const_reverse_iterator(end());
}


String::reverse_iterator String::rend() noexcept
{
    return reverse_iterator(begin() - 1);
}


String::const_reverse_iterator String::rend() const noexcept
{
    return const_reverse_iterator(begin() - 1);
}


void String::clear() noexcept
{
    resize(0);
}


void String::erase(size_t pos, size_t len)
{
    len = std::min(len, _size - pos);
    my::memmove(_data.get() + pos, _data.get() + pos + len, _size - pos - len + 1);
    _size -= len;
}


void String::push_back(char c)
{
    if (_size + 1 >= _capacity)
    {
        reserve(_capacity == 0 ? 2 : _capacity * 2);
    }

    _data[_size - 1] = c;
    _data[_size] = '\0';
    ++_size;
}


void String::pop_back() noexcept
{
    if (_size > 1)
    {
        back() = '\0';
        --_size;
        return;
    }

    if (_capacity != 0)
    {
        front() = '\0';
    }
}


size_t String::copy(char* dest, size_t len, size_t pos) const
{
    if (pos > size())
    {
        throw std::out_of_range("Position out of range");
    }

    size_t count = std::min(std::min(len, size() - pos), my::strlen(dest));
    my::memcpy(dest, _data.get() + pos, count);
    return count;
}


void String::insert(size_t pos, const char* str)
{
    reserve(my::strlen(str) + size());

    my::memmove(_data.get() + pos + my::strlen(str), _data.get() + pos, _size - pos);
    my::memcpy(_data.get() + pos, str, my::strlen(str));
    _size += my::strlen(str);
}


void String::append(const String& str)
{
    append(str.data());
}


int String::compare(const String &str) const noexcept
{
    return my::strcmp(_data.get(), str._data.get());
}

/*******************************ПЕРЕГРУЗКА*ОПЕРАТОРОВ*******************************/


String operator+(const String& lhs, const String& rhs)
{
    String result(lhs);
    result.append(rhs);
    return result;
}


bool operator<(const String& str1, const String& str2) noexcept
{
    return str1.compare(str2) < 0;
}


bool operator>(const String& str1, const String& str2) noexcept
{
    return str1 < str2;
}


bool operator==(const String& str1, const String& str2) noexcept
{
    return str1.compare(str2) == 0;
}


bool operator!=(const String& str1, const String& str2) noexcept
{
    return !(str1 == str2);
}


bool operator<=(const String& str1, const String& str2) noexcept
{
    return !(str2 < str1);
}


bool operator>=(const String& str1, const String& str2) noexcept
{
    return !(str1 < str2);
}

