#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <QString>

using iterator = char*;
using const_iterator = const char*;
using reverse_iterator = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;

class MyString
{
public:
    //Constructors
    MyString() : _str(new char[1]), _len(0)
    {
        _str[0] = '\0';
    }

    MyString(const MyString& s) : _str(new char[s._len + 1]), _len(s._len)
    {
        memcpy(_str.get(), s._str.get(), _len + 1);
    }

    MyString(MyString&& s) noexcept : _str(std::move(s._str)), _len(s._len)
    {
        s._len = 0;
    }

    MyString(const char* str) noexcept
    {
        _len = strlen(str);
        _str.reset(new char[_len + 1]);
        memcpy(_str.get(), str, _len + 1);
    }

    MyString(const QString& str)
    {
        std::string std = str.toStdString();
        _len = str.size();
        _str.reset(new char[_len + 1]);
        std::strcpy(_str.get(), std.c_str());
    }

    size_t length() const
    {
        return _len;
    }

    MyString& operator=(const MyString& s)
    {
        if (this != &s) {
            _str.reset(new char[s._len + 1]);
            _len = s._len;
            memcpy(_str.get(), s._str.get(), _len + 1);
        }
        return *this;
    }

    MyString& operator=(MyString&& s) noexcept
    {
        if (this != &s)
        {
            _str = std::move(s._str);
            _len = s._len;
            s._len = 0;
        }
        return *this;
    }

    MyString& operator=(const char* str)
    {
        _len = strlen(str);
        _str.reset(new char[_len + 1]);
        memcpy(_str.get(), str, _len + 1);
        return *this;
    }

    MyString& operator = (QString& str)
    {
        std::string stdstr = str.toStdString();
        _len = stdstr.length();
        _str.reset(new char[_len + 1]);
        memcpy(_str.get(), stdstr.c_str(), _len + 1);
        return *this;
    }

    iterator begin() noexcept
    {
        return _str.get();
    }

    const_iterator begin() const noexcept
    {
        return _str.get();
    }

    iterator end() noexcept
    {
        return _str.get() + _len;
    }

    const_iterator end() const noexcept
    {
        return _str.get() + _len;
    }

    reverse_iterator rbegin() noexcept
    {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const noexcept
    {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() noexcept
    {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const noexcept
    {
        return const_reverse_iterator(begin());
    }

    const char* c_str() const noexcept
    {
        return _str.get();
    }

    static void* memcpy(void* dest, const void* src, size_t count)
    {
        auto aim = static_cast<unsigned char*>(dest);
        auto source = static_cast<const unsigned char*>(src);

        for (size_t i = 0; i < count; ++i)
        {
            aim[i] = source[i];
        }

        return dest;
    }

    static void* memmove(void* dest, const void* src, size_t count)
    {
        auto aim = static_cast<unsigned char*>(dest);
        auto source = static_cast<const unsigned char*>(src);

        if (aim < source)
        {
            for (size_t i = 0; i < count; ++i)
            {
                aim[i] = source[i];
            }
        }
        else
        {
            for (size_t i = count; i > 0; --i)
            {
                aim[i - 1] = source[i - 1];
            }
        }

        return dest;
    }

    static void* memset(void* dest, int ch, size_t count)
    {
        auto aim = static_cast<unsigned char*>(dest);

        for (size_t i = 0; i < count; ++i)
        {
            aim[i] = ch;
        }

        return dest;
    }

    static char* strcpy(char* dest, const char* src)
    {
        size_t i = 0;
        for (; src[i] != '\0'; ++i)
        {
            dest[i] = src[i];
        }
        dest[i] = '\0';

        return dest;
    }

    static char* strncpy(char* dest, const char* src, size_t count)
    {
        size_t i = 0;
        for (; i < count && src[i] != '\0'; ++i)
        {
            dest[i] = src[i];
        }
        for (; i < count; ++i)
        {
            dest[i] = '\0';
        }

        return dest;
    }

    static char* strcat(char* dest, const char* src)
    {
        size_t i = 0;
        // find the end of the dest string
        for (; dest[i] != '\0'; ++i);

        // start appending src to dest from where dest ended
        size_t j = 0;
        for (; src[j] != '\0'; ++j)
        {
            dest[i + j] = src[j];
        }

        // append null character at the end
        dest[i + j] = '\0';

        return dest;
    }

    static char* strncat(char* dest, const char* src, size_t count)
    {
        size_t i = 0;
        // find the end of the dest string
        for (; dest[i] != '\0'; ++i);

        // start appending src to dest from where dest ended
        size_t j = 0;
        for (; j < count && src[j] != '\0'; ++j)
        {
            dest[i + j] = src[j];
        }

        // append null character at the end
        dest[i + j] = '\0';

        return dest;
    }

    static int memcmp(const void* s1, const void* s2, size_t n)
    {
        auto str1 = static_cast<const unsigned char*>(s1);
        auto str2 = static_cast<const unsigned char*>(s2);

        for (size_t i = 0; i < n; ++i)
        {
            if (str1[i] < str2[i])
            {
                return -1;
            }
            else if (str1[i] > str2[i])
            {
                return 1;
            }
        }

        return 0;
    }

    static int strcmp(const char* s1, const char* s2)
    {
        size_t i = 0;
        for (; s1[i] != '\0' && s2[i] != '\0'; ++i)
        {
            if (s1[i] < s2[i])
            {
                return -1;
            }
            else if (s1[i] > s2[i])
            {
                return 1;
            }
        }

        if (s1[i] == '\0' && s2[i] == '\0')
        {
            return 0;
        }
        else if (s1[i] == '\0')
        {
            return -1;
        }
        else
        {
            return 1;
        }

    }

    static int strncmp(const char* s1, const char* s2, size_t n)
    {
        size_t i = 0;
        for (; i < n && s1[i] != '\0' && s2[i] != '\0'; ++i)
        {
            if (s1[i] < s2[i])
            {
                return -1;
            }
            else if (s1[i] > s2[i])
            {
                return 1;
            }
        }

        if (i == n)
        {
            return 0;
        }
        else if (s1[i] == '\0')
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    static size_t strxfrm(char* s1, const char* s2, size_t n)
    {
        size_t i = 0;
        for (; i < n && s2[i] != '\0'; ++i)
        {
            s1[i] = s2[i];
        }

        if (i < n)
        {
            s1[i] = '\0';  // Null-terminate s1
        }
        else
        {
            s1[n - 1] = '\0';  // Null-terminate s1
        }

        return i;
    }

    static int strcoll(const char* s1, const char* s2)
    {
        setlocale (LC_ALL, "");
        return strcmp(s1, s2);
    }

    static char* strtok(char* str, const char* delim)
    {
        static char* buffer;

        if (str != nullptr)
            buffer = str;

        buffer += std::strspn(buffer, delim);

        if (*buffer == '\0')
            return nullptr;

        char* const tokenBegin = buffer;

        buffer += std::strcspn(buffer, delim);

        if (*buffer != '\0')
            *buffer++ = '\0';

        return tokenBegin;
    }

    static char* strerror(int errnum)
    {
        static char buffer[256];

        switch(errnum)
        {
        case 0:
            std::strcpy(buffer, "No error");
            break;
        case EINVAL:
            std::strcpy(buffer, "Invalid argument");
            break;
        case EACCES:
            std::strcpy(buffer, "Permission denied");
            break;
        case ENOENT:
            std::strcpy(buffer, "No such file or directory");
            break;
        default:
            std::strcpy(buffer, "Unknown error");
        }

        return buffer;
    }

    static size_t strlen(const char* s)
    {
        size_t len = 0;
        for (; s[len] != '\0'; ++len);
        return len;
    }

    ~MyString() = default;

private:
    std::unique_ptr<char[]> _str;
    size_t _len;
};



#endif // MYSTRING_H
