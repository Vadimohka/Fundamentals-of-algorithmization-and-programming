#ifndef CONSTMYITERATOR_H
#define CONSTMYITERATOR_H

class ConstMyIterator
{
private:
    const char *ptr;

public:
    ConstMyIterator(const char *p)
        : ptr(p)
    {}

    ConstMyIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    ConstMyIterator operator++(int)
    {
        ConstMyIterator temp = *this;
        ++ptr;
        return temp;
    }

    ConstMyIterator &operator--()
    {
        --ptr;
        return *this;
    }

    ConstMyIterator operator--(int)
    {
        ConstMyIterator temp = *this;
        --ptr;
        return temp;
    }

    const char &operator*() const { return *ptr; }

    bool operator==(const ConstMyIterator &other) const { return ptr == other.ptr; }

    bool operator!=(const ConstMyIterator &other) const { return ptr != other.ptr; }

    bool operator<(const ConstMyIterator &other) const { return ptr < other.ptr; }

    bool operator>(const ConstMyIterator &other) const { return ptr > other.ptr; }

    bool operator<=(const ConstMyIterator &other) const { return ptr <= other.ptr; }

    bool operator>=(const ConstMyIterator &other) const { return ptr >= other.ptr; }

    ConstMyIterator operator+(int n) const { return ConstMyIterator(ptr + n); }

    ConstMyIterator operator-(int n) const { return ConstMyIterator(ptr - n); }

    int operator-(const ConstMyIterator &other) const { return ptr - other.ptr; }

    ConstMyIterator &operator+=(int n)
    {
        ptr += n;
        return *this;
    }

    ConstMyIterator &operator-=(int n)
    {
        ptr -= n;
        return *this;
    }

    const char &operator[](int index) const { return ptr[index]; }
};

#endif // CONSTMYITERATOR_H
