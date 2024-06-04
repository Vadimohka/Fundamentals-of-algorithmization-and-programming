#include "mystring.h"

MyString::MyString()
{
    data_ = nullptr;
    capacity_ = 0;
    size_ = 0;
    reserve(1);
}

MyString::MyString(const MyString &other)
{
    if(other.size_ > capacity_)
        reserve(other.size_);
    for(int i = 0; i < other.size_; i++)
        data_[i] = other.data_[i];
    size_ = other.size_;
}

MyString::MyString(std::initializer_list<char> list): size_(list.size()), capacity_(list.size())
{
    data_ = std::make_unique<char[]>(size_);
    auto listIt = list.begin();

    int i = 0;
    for (; i < size_; ++i, ++listIt)
    {
        data_[i] = *listIt;
    }
    data_[i] = '\0';
}

MyString::MyString(const char *other)
{
    int size = 0;
    while(other[size++] != '\0');
    size = 0;
    reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        data_[i] = other[i];
    }
    size_ = size;

    data_[size_] = '\0';
}

MyString::~MyString()
{
    data_ = std::make_unique<char[]>(0);
    size_ = capacity_ = 0;
}

char &MyString::operator[](int i)
{
    return data_[i];
}

MyString &MyString::operator=(const char * other)
{
    int size = 0;
    while (other[size++] != '\0');
    size--;

    reserve(size);

    for (int i = 0; i < size; i++)
    {
        data_[i] = other[i];
    }
    size_ = size;
    data_[size_] = '\0';
    return *this;
}

void MyString::reserve(int size)
{
    if(size < capacity_)
        return;

    auto tmp = std::make_unique<char[]>(size);

    for(int i = 0; i < this->size_; i++)
        tmp[i] = data_[i];

    capacity_ = size;
    data_ = std::move(tmp);
}

bool MyString::empty()
{
    return size_ == 0;
}

void MyString::resize(int size, char tmp)
{
    if (size > capacity_) reserve(size);

    for (int i = size_; i < size; i++)
    {
        data_[i] = tmp;
    }
    size_ = size;
}

void MyString::clear()
{
    resize(0);
}

int MyString::size() const
{
    return size_;
}

int MyString::capacity() const
{
    return capacity_;
}

char &MyString::front()
{
    return data_[0];
}

char &MyString::back()
{
    return data_[size_-1];
}

char &MyString::at(int i)
{
    if(i <= size_)
    {
        try
        {
            return data_[i];
        }
        catch (...)
        {
            throw;
        }
    }
    else throw;
}

char *MyString::data()
{
    return data_.get();
}

MyString::iterator MyString::begin()
{
    return iterator(data_.get());
}

MyString::rIterator MyString::rbegin()
{
    return rIterator(data_.get()+size_);
}

MyString::iterator MyString::end()
{
    return iterator(data_.get()+size_);
}

MyString::rIterator MyString::rend()
{
    return rIterator(data_.get());
}

void MyString::swap(MyString &b)
{
    std::swap(b.size_,size_);
    std::swap(b.capacity_,capacity_);
    std::swap(b.data_,data_);
}

void MyString::push_back(char a)
{
    reserve(size_ + 2);
    size_++;

    data_[size_-1] = a;
    data_[size_] = 0;
}

void MyString::insert(cIterator pos, const char & tmp)
{
    int ind = pos.base() - data_.get();

    reserve(size_ + 2);

    for (size_t i = size_; i > ind; i--)
    {
        data_[i] = data_[i - 1];
    }

    data_[ind] = tmp;
    size_++;
}

void MyString::insert(cIterator pos, char && tmp)
{
    int ind = pos.base() - data_.get();

    reserve(size_ + 2);

    for (size_t i = size_; i > ind; i--)
    {
        data_[i] = data_[i - 1];
    }

    data_[ind] = tmp;
    size_++;
}

void MyString::erase(iterator pos)
{
    erase(pos,end());
}

void MyString::erase(iterator f , iterator s)
{
    int i = f.base() - data_.get();
    int j = s.base() - data_.get();

    for (auto it = i; it <= j; it++)
    {
        data_[it] = data_[it + 1];
    }

    size_ = size_ - (j - i);
}

void MyString::assign(int n, char c)
{
    clear();
    resize(n, c);
}

void MyString::assign(cIterator f, cIterator s)
{
    clear();
    int size = f.base() - s.base();
    resize(size);
    for (auto it = 0; it < size; it++)
    {
        data_[it] = *(f + it);
    }
}

void MyString::pop_back()
{
    ~(data_[size_ - 1]);
    size_--;
}

void *MyString::memcpy(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr)
    {
        return s1;
    }

    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;

    for(int i = 0; i < n; ++i)
    {
        cs1[i] = cs2[i];
    }

    return s1;
}

void *MyString::memmove(void *s1, const void *s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    char* tmp = new char[n];
    for(int i = 0; i < n; ++i)
    {
        tmp[i] = cs2[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cs1[i] = tmp[i];
    }
    delete [] tmp;
    return s1;
}

char *MyString::strcpy(char *s1, const char *s2)
{
    int i = 0;

    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }

    s1[i] = 0;

    return s1;
}

char *MyString::strncpy(char *s1, const char *s2, size_t n)
{
    int n1 = n;
    int i = 0;
    while(n1-- && s2[i] != 0)
    {
        s1[i] = s2[i];
        i++;
    }
    while(n1 >= 0)
    {
        s1[i] = 0;
        i++;
        n1--;
    }

    s1[i] = 0;

    return s1;
}

char *MyString::strcat(char *s1, const char *s2)
{
    size_t size1 = MyString::strlen(s1);
    size_t i = 0;
    while (s2[i])
    {
        s1[size1+i] = s2[i];
        ++i;
    }
    s1[size1 + i] = '\0';
    return s1;
}

char *MyString::strncat(char *s1, const char *s2, size_t n)
{
    int size1 = MyString::strlen(s1);
    int i = 0, n1 = n;
    while (s2[i] && n1--)
    {
        s1[size1+i] = s2[i];
        ++i;
    }
    s1[size1 + i] = '\0';
    return s1;
}

int MyString::memcmp(const void *s1, const void *s2, size_t n)
{
    const auto *it1 = (const char*)s1;
    const auto *it2 = (const char*)s2;

    while(n-- && *it1 == *it2)
    {
        it1++;
        it2++;
    }

    if(*it1 == *it2)
        return 0;

    if(*it1 > *it2)
        return 1;

    return -1;
}

int MyString::strcmp(const char *s1, const char *s2)
{
    while(*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }

    if (*s1 > *s2)
    {
        return 1;
    }

    if (*s1 < *s2)
    {
        return -1;
    }

    return 0;

}

int MyString::strcoll(const char *s1, const char *s2)
{
    while(*s1 != '\0' || *s2 != '\0')
    {

        if(*s1 == '\0')
            return -1;

        if(*s2 == '\0')
            return 1;

        if(*s1 > *s2)
            return 1;

        if(*s2 > *s1)
            return -1;


        s1++;
        s2++;

    }

    return 0;
}

int MyString::strncmp(const char *s1, const char *s2, size_t n)
{
    while(*s1 == *s2 && *s1 != '\0' && n--)
    {
        s1++;
        s2++;
    }

    if (*s1 > *s2)
    {
        return 1;
    }

    if (*s1 < *s2)
    {
        return -1;
    }

    return 0;

}

size_t MyString::strxfrm(char *s1, const char *s2, size_t n)
{
    int ind = 0;

    while(*s2 != '\0' && n--)
    {
        *s1 = *s2;
        ind++;
    }

    *s1 = '\0';
    return ind;
}

char *MyString::strtok(char *s1, const char *s2)
{

}

void *MyString::memset(void *s, int c, size_t n)
{
    char * cs = (char *)s;
    for(int i = 0; i < n; i++)
        cs[i] = i;
    return s;
}

char *MyString::strerror(int errnum)
{

}

size_t MyString::strlen(const char *s)
{
    int i = 0;
    while(s[i++] != '\0');
    i--;
    return i;

}

template<typename... Args>
void MyString::emplace(cIterator pos, Args &&... args)
{
    char tmp(args...);
    insert(pos, tmp);
}

template<typename... Args>
void MyString::emplace_back(Args &&... args)
{
    char tmp(args...);
    push_back(tmp);
}
