#include "stringg.h"

String::String()
{
    array = nullptr;
    reserve(1);
    size_ = 0;
    capacity_ = 0;
}

String::String(size_t n)
{
    reserve(n + 1);
}

String::String(String const &temp)
{
    size_ = temp.size_;
    capacity_ = temp.capacity_;
    array = std::make_unique<char[]>(temp.size_);
    for (int i; i < size_; ++i)
    {
        array[i] = temp.array[i];
    }
}

String::String(std::initializer_list<char> list) : size_(list.size()), capacity_(list.size())
{
    array = std::make_unique<char[]>(size_);
    auto listIt = list.begin();
    size_t i = 0;
    for (i; i < size_; ++i, ++listIt)
    {
        array[i] = *listIt;
    }
    array[i] = '\0';
}

String::~String()
{
    array = std::make_unique<char[]>(0);
    capacity_ = 0;
    size_ = 0;
}

char &String::operator[](size_t i)
{
    return array[i];
}

template<typename... Args>
void String::emplace(String::cIterator pos, Args &&... args)
{
    char temp(args...);
    insert(pos, temp);
}

template<typename... Args>
void String::emplace_back(Args &&... args)
{
    char tmp(args...);
    push_back(tmp);
}

void String::insert(String::cIterator pos_, char const &temp)
{
    size_t pos = (pos_).base() - array.get();
    reserve(size_ + 2);
    for (size_t i = size_; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    array[pos] = temp;
    size_++;
}

void String::insert(String::cIterator pos_, char &&temp)
{
    size_t pos = pos_.base() - array.get();
    reserve(size_ + 2);
    for (size_t i = size_; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    array[pos] = temp;
    size_++;
}

void String::push_back(char temp)
{
    if (size_ + 1 >= capacity_) reserve(2 * size_ + 2);
    array[size_] = temp;
    array[size_ + 1] = '\0';
    size_++;
}

void String::assign(size_t n, char temp)
{
    clear();
    resize(n, temp);
}

void String::assign(String::cIterator beg, String::cIterator end)
{
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++)
    {
        array[i] = *(beg + i);
    }
}

void String::clear()
{
    resize(0);
}

void String::erase(String::iterator temp)
{
    erase(temp, temp + 1);
}

void String::erase(String::iterator beg, String::iterator end)
{
    int i1 = beg.base() - array.get();
    int i2 = end.base() - array.get();
    for (auto i = i1; i <= i2; i++)
    {
        array[i] = array[i + 1];
    }
    size_ = size_ - (i2 - i1);
}

void String::pop_back()
{
    ~(array[size_ - 1]);
    size_--;
}

char &String::front()
{
    return array[0];
}

char &String::back()
{
    return array[size_ - 1];
}

char &String::at(size_t pos_)
{
    if (pos_ > size_) throw;
    try {
        return array[pos_];
    } catch (...) {
        throw;
    }
}

char *String::data()
{
    return array.get();
}

size_t String::capacity() const
{
    return capacity_;
}

size_t String::size() const
{
    return size_;
}

void String::resize(size_t size, char temp)
{
    if (size > capacity_) reserve(size);
    for (size_t i = size_; i < size; i++)
    {
        array[i] = temp;
    }
    for (size_t i = size; i < size_; i++)
    {
        ~(array[i]);
    }
    size_ = size;
}

void String::reserve(size_t size)
{
    if (size <= capacity_)
    {
        return;
    }
    auto temp = std::make_unique<char[]>(size);
    for (int i = 0; i < size_; i++)
    {
        temp[i] = array[i];
    }
    array = std::move(temp);
    capacity_ = size;
}

bool String::empty() const
{
    return size_ == 0;
}

void String::swap(String &toSwap)
{
    std::swap(array, toSwap.array);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}

String::iterator String::begin()
{
    return iterator(array.get());
}

String::iterator String::end()
{
    return iterator(array.get() + size_);
}

String::rIterator String::rbegin()
{
    return rIterator(array.get() + size_);
}

String::rIterator String::rend()
{
    return rIterator(array.get());
}

String::String(const char *c_str)
{
    size_t size = 0;
    while (c_str[size++] != '\0');
    size--;

    reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        array[i] = c_str[i];
    }
    size_ = size;
    array[size_] = '\0';
}

String& String::operator=(const char *c_str)
{
    size_t size = 0;
    while (c_str[size++] != '\0');
    size--;

    reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        array[i] = c_str[i];
    }
    size_ = size;
    array[size_] = '\0';
    return *this;
}

String& String::operator=(String& str)
{
    array = std::make_unique<char[]>(str.capacity_ + 1);
    for (int i = 0; i < str.size_; ++i)
    {
        array[i] = str[i];
    }

    size_ = str.size_;
    capacity_ = str.capacity_;
    array[size_] = '\0';
    return *this;
}

String& String::operator=(String&& str)
{
    array = std::move(str.array);
    size_ = str.size_;
    capacity_ = str.capacity_;
    return *this;
}

String& String::operator+=(String& str)
{
    reserve(size_ + str.size_);
    for (int i = 0; i < str.size_; ++i)
    {
        array[size_ + i] = str[i];
    }
    size_ += str.size_;
    array[size_] = '\0';
    return *this;
}

String& String::operator+=(String&& str)
{
    reserve(size_ + str.size_);
    for (int i = 0; i < str.size_; ++i)
    {
        array[size_ + i] = str[i];
    }
    size_ += str.size_;
    array[size_] = '\0';
    return *this;
}

String String::operator+(String& str)
{
    String res(*this);
    res+=str;
    return res;
}

String String::operator+(String&& str)
{
    String res(*this);
    res+=str;
    return res;
}
