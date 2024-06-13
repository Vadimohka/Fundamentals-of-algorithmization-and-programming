#include "mystring.h"

// Эта функция копирует n байтов из области памяти, на которую указывает s2, в область памяти, на которую указывает s1.
void *MyString::memcpy(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr) {
        return s1;
    }
    char *dest = static_cast<char *>(s1);
    const char *src = static_cast<const char *>(s2);

    for (size_t i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
    return s1;
}

// Эта функция копирует n байтов из области памяти, на которую указывает s2, в область памяти, на которую указывает s1.
void *MyString::memmove(void *s1, const void *s2, size_t n)
{
    auto aim = static_cast<char *>(s1);
    auto src = static_cast<const char *>(s2);

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

// Эта функция копирует нуль-терминированную строку, на которую указывает s2 (включая нулевой символ), в массив, на который указывает s1.
char *MyString::strcpy(char *s1, const char *s2)
{
    if (s1 == nullptr || s2 == nullptr) {
        return s1;
    }
    size_t i = 0;
    while (s2[i] != '\0') {
        ++i;
    }
    memcpy(s1, s2, i);
    s1[i] = '\0';
    return s1;
}

// Эта функция копирует не более n байтов (включая нулевые символы) из строки, на которую указывает s2, в массив, на который указывает s1.
char *MyString::strncpy(char *s1, const char *s2, size_t n)
{
    if (s1 == nullptr || s2 == nullptr) {
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

// Эта функция добавляет нуль-терминированную строку, на которую указывает s2 (включая нулевой символ), в конец нуль-терминированной строки, на которую указывает s1.
char *MyString::strcat(char *s1, const char *s2)
{
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

// Эта функция выполняет операцию конкатенации (объединения) двух строк, при этом копируя не более n символов из строки s2 в конец строки s1.
char *MyString::strncat(char *s1, const char *s2, size_t n)
{
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

// Эта функция сравнивает первые n байтов памяти, на которые указывают s1 и s2.
int MyString::memcmp(const void *s1, const void *s2, size_t n)
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

// Эта функция сравнивает строки s1 и s2
int MyString::strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

// Эта функция сравнивает первых n символов строк s1 и s2
int MyString::strncmp(const char *s1, const char *s2, size_t n)
{
    while (--n && *s1 == *s2) {
        if (*s1 == '\0') {
            return 1;
        }
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

// Эта функция находит длину первого сегмента строки s1, который состоит только из символов, не входящих в строку s2.
size_t MyString::strcspn(const char *s1, const char *s2)
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

// Эта функция заполняет первые n байтов памяти, на которую указывает s, символом c
void *MyString::memset(void *s, int c, size_t n)
{
    unsigned char *p = static_cast<unsigned char *>(s);
    unsigned char uc = static_cast<unsigned char>(c);

    for (size_t i = 0; i < n; ++i) {
        p[i] = uc;
    }

    return s;
}

// Эта функция вычисляет длину нуль-терминированной строки, на которую указывает s
size_t MyString::strlen(const char *s)
{
    size_t length = 0;

    while (*s != '\0') {
        ++length;
        ++s;
    }

    return length;
}

/////////////////////////////////////////////////////

// Это конструктор по умолчанию, который создает пустую строку, выделяя память для одного символа (включая терминирующий нулевой байт)
MyString::MyString()
    : ptr(std::make_unique<char[]>(1))
    , sz(1)
    , cp(1)
{
    ptr[0] = '\0';
}

// Это конструктор, который создает экземпляр MyString из C-style строки, переданной в качестве аргумента. Он выделяет память для строки,
// копирует ее содержимое и устанавливает размер строки
MyString::MyString(const char *str)
{
    size_t mySize = strlen(str) + 1;
    ptr = std::make_unique<char[]>(mySize);
    sz = mySize;
    cp = mySize;
    memcpy(ptr.get(), str, strlen(str));
}

// Это конструктор, который создает строку заданной длины, заполненную одним символом c. Он выделяет память для строки и заполняет ее указанным символом
// MyString::MyString(size_t amnt, char c)
//     : ptr(std::make_unique<char[]>(amnt + 1))
//     , sz(amnt + 1)
//     , cp(amnt + 1)
// {
//     for (size_t i = 0; i < amnt; ++i) {
//         ptr[i] = c;
//     }
// }

// Это конструктор копирования, который создает новый экземпляр MyString, являющийся копией другого экземпляра MyString. Он выделяет новую память и копирует содержимое
// MyString::MyString(const MyString &other)
//     : ptr(std::make_unique<char[]>(other.sz))
//     , sz(other.sz)
//     , cp(other.sz)
// {
//     strcpy(ptr.get(), other.ptr.get());
// }

// Это конструктор перемещения, который перемещает ресурсы (указатель на память, размер и ёмкость) из другого экземпляра MyString в новый экземпляр
// MyString::MyString(MyString &&other) noexcept
//     : ptr(std::move(other.ptr))
//     , sz(other.sz)
//     , cp(other.sz)
// {
//     other.cp = 0;
//     other.sz = 0;
//     other.resize(0);
// }

MyString &MyString::operator=(const MyString &other)
{
    if (&other != this) {
        ptr = std::make_unique<char[]>(other.sz);
        sz = other.sz;
        cp = other.cp;
        strcpy(ptr.get(), other.ptr.get());
    }

    return *this;
}

// MyString &MyString::operator=(MyString &&other) noexcept
// {
//     ptr = std::move(other.ptr);
//     sz = other.sz;
//     cp = other.cp;

//     other.cp = 0;
//     other.sz = 0;
//     other.resize(0);

//     return *this;
// }

// void MyString::resize(size_t newSize)
// {
//     ++newSize;
//     if (newSize <= sz) {
//         sz = newSize;
//         ptr[sz - 1] = '\0';
//     } else {
//         reserve(newSize);
//         for (size_t i = sz; i < newSize; ++i) {
//             ptr[i] = '\0';
//         }
//         sz = newSize;
//     }
// }

// void MyString::reserve(size_t newSize)
// {
//     ++newSize;
//     if (newSize <= cp) {
//         return;
//     }

//     std::unique_ptr<char[]> newData = std::make_unique<char[]>(newSize);
//     if (sz > 1) {
//         memcpy(newData.get(), ptr.get(), sz);
//     }
//     ptr = std::move(newData);
//     cp = newSize;
// }

bool MyString::empty() const
{
    return sz <= 1;
}

size_t MyString::size() const
{
    if (sz == 0) {
        return 0;
    }
    return sz - 1;
}

size_t MyString::capacity() const
{
    return cp;
}

const char *MyString::c_str() const
{
    return ptr.get();
}

// void MyString::clear()
// {
//     resize(0);
// }

void MyString::erase(size_t pos, size_t len)
{
    len = std::min(len, sz - pos);
    memmove(ptr.get() + pos, ptr.get() + pos + len, sz - pos - len + 1);
    sz -= len;
}

// void MyString::push_back(char c)
// {
//     if (sz + 1 >= cp) {
//         reserve(cp == 0 ? 2 : cp * 2);
//     }

//     ptr[sz - 1] = c;
//     ptr[sz] = '\0';
//     ++sz;
// }

// size_t MyString::copy(char *dest, size_t len, size_t pos) const
// {
//     if (pos > size()) {
//         throw std::out_of_range("Position out of range");
//     }

//     size_t count = std::min(std::min(len, size() - pos), strlen(dest));
//     memcpy(dest, ptr.get() + pos, count);
//     return count;
// }
