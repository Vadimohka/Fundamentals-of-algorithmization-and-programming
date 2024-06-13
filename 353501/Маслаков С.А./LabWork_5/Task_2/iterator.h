#ifndef MYITERATOR_H
#define MYITERATOR_H


class MyIterator
{
private:
    char *ptr;

public:
    MyIterator(char *p)
        : ptr(p){};

    MyIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    MyIterator operator++(int)
    {
        MyIterator temp = *this;
        ++ptr;
        return temp;
    }

    MyIterator &operator--()
    {
        --ptr;
        return *this;
    }

    MyIterator operator--(int)
    {
        MyIterator temp = *this;
        --ptr;
        return temp;
    }

    char &operator*() { return *ptr; }

    bool operator==(const MyIterator &other) const { return ptr == other.ptr; }

    bool operator!=(const MyIterator &other) const { return ptr != other.ptr; }

    bool operator<(const MyIterator &other) const { return ptr < other.ptr; }

    bool operator>(const MyIterator &other) const { return ptr > other.ptr; }

    bool operator<=(const MyIterator &other) const { return ptr <= other.ptr; }

    bool operator>=(const MyIterator &other) const { return ptr >= other.ptr; }

    MyIterator operator+(int n) const { return MyIterator(ptr + n); }

    MyIterator operator-(int n) const { return MyIterator(ptr - n); }

    int operator-(const MyIterator &other) const { return ptr - other.ptr; }

    MyIterator &operator+=(int n)
    {
        ptr += n;
        return *this;
    }

    MyIterator &operator-=(int n)
    {
        ptr -= n;
        return *this;
    }

    char &operator[](int index) const { return ptr[index]; }
};

#endif // MYITERATOR_H
