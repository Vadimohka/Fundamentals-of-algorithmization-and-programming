#ifndef BITSET_H
#define BITSET_H

#include <QString>

class BitSet
{
private:
    static const int BITS = 16;
    static const int SIZE = sizeof(unsigned short) * BITS;

    unsigned short* data;
    int size;
public:
    explicit BitSet(int);
    ~BitSet();

    bool operator[](int) const;
    bool &operator[](int);

    int getSize() const;
    void set(int);
    void set();
    void reset(int);
    void reset();
    bool test(int) const;
    void flip(int);
    void flip();

    bool all() const;
    bool any() const;
    bool none() const;
    int count() const;
    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;
};

#endif // BITSET_H
