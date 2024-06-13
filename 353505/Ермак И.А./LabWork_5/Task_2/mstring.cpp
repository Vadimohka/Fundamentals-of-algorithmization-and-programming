#include "mstring.h"

MString::MString()
{
    array = nullptr;
    reserve(1);
    size_ = 0;
    capacity_ = 0;
}

MString::MString(size_t n)
{
    reserve(n + 1);
}

MString::MString(MString const &temp)
{
    size_ = temp.size_;
    capacity_ = temp.capacity_;
    array = std::make_unique<char[]>(temp.size_);
    for (int i; i < size_; ++i)
    {
        array[i] = temp.array[i];
    }
}

MString::MString(std::initializer_list<char> list) : size_(list.size()), capacity_(list.size())
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

MString::~MString()
{
    array = std::make_unique<char[]>(0);
    capacity_ = 0;
    size_ = 0;
}

char &MString::operator[](size_t i)
{
    return array[i];
}

template<typename... Args>
void MString::emplace(MString::cIterator pos, Args &&... args)
{
    char temp(args...);
    insert(pos, temp);
}

template<typename... Args>
void MString::emplace_back(Args &&... args)
{
    char tmp(args...);
    push_back(tmp);
}

void MString::insert(MString::cIterator pos_, char const &temp)
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

void MString::insert(MString::cIterator pos_, char &&temp)
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

void MString::push_back(char temp)
{
    if (size_ + 1 >= capacity_) reserve(2 * size_ + 2);
    array[size_] = temp;
    array[size_ + 1] = '\0';
    size_++;
}

void MString::assign(size_t n, char temp)
{
    clear();
    resize(n, temp);
}

void MString::assign(MString::cIterator beg, MString::cIterator end)
{
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++)
    {
        array[i] = *(beg + i);
    }
}

void MString::clear()
{
    resize(0);
}

void MString::erase(MString::iterator temp)
{
    erase(temp, temp + 1);
}

void MString::erase(MString::iterator beg, MString::iterator end)
{
    int i1 = beg.base() - array.get();
    int i2 = end.base() - array.get();
    for (auto i = i1; i <= i2; i++)
    {
        array[i] = array[i + 1];
    }
    size_ = size_ - (i2 - i1);
}

void MString::pop_back()
{
    ~(array[size_ - 1]);
    size_--;
}

char &MString::front()
{
    return array[0];
}

char &MString::back()
{
    return array[size_ - 1];
}

char &MString::at(size_t pos_)
{
    if (pos_ > size_) throw;
    try {
        return array[pos_];
    } catch (...) {
        throw;
    }
}

char *MString::data()
{
    return array.get();
}

size_t MString::capacity() const
{
    return capacity_;
}

size_t MString::size() const
{
    return size_;
}

void MString::resize(size_t size, char temp)
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

void MString::reserve(size_t size)
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

bool MString::empty() const
{
    return size_ == 0;
}

void MString::swap(MString &toSwap)
{
    std::swap(array, toSwap.array);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}

MString::iterator MString::begin()
{
    return iterator(array.get());
}

MString::iterator MString::end()
{
    return iterator(array.get() + size_);
}

MString::rIterator MString::rbegin()
{
    return rIterator(array.get() + size_);
}

MString::rIterator MString::rend()
{
    return rIterator(array.get());
}

MString::MString(const char *c_str)
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

MString& MString::operator=(const char *c_str)
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

MString& MString::operator=(MString& str)
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

MString& MString::operator=(MString&& str)
{
    array = std::move(str.array);
    size_ = str.size_;
    capacity_ = str.capacity_;
    return *this;
}

MString& MString::operator+=(MString& str)
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

MString& MString::operator+=(MString&& str)
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

MString MString::operator+(MString& str)
{
    MString res(*this);
    res+=str;
    return res;
}

MString MString::operator+(MString&& str)
{
    MString res(*this);
    res+=str;
    return res;
}
