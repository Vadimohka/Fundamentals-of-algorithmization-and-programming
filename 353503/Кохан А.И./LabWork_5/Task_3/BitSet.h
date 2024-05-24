#ifndef BITSET_H
#define BITSET_H

#include <QString>

class BitSet
{
private:
    ushort *_data;
    size_t _size;

public:
    explicit BitSet(size_t newSize, ushort initValue);
    ~BitSet();

    bool &operator[](size_t index);
    bool operator[](size_t index) const;

    size_t getSize() const;
    void set(size_t);
    void set();
    void reset(size_t);
    void reset();
    bool test(size_t) const;
    void flip(size_t);
    void flip();
    bool all() const;
    bool any() const;
    bool none() const;
    size_t count() const;
    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;
};

#endif // BITSET_H
