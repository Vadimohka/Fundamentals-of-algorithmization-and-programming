#ifndef MYBITSET_H
#define MYBITSET_H

#include <QString>

class MyBitSet
{
public:
    //constructors
    explicit MyBitSet(int);
    ~MyBitSet();
    //functions
    bool test(int) const;
    int size() const;
    void set(int position);
    void set();
    void reset(int position);
    void reset();
    void flip(int position);
    void flip();
    bool all() const;
    bool any() const;
    bool none() const;
    int count() const;
    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;
    //operators
    bool operator[](int) const;
    bool &operator[](int);
    MyBitSet operator~() const;
    MyBitSet operator&(const MyBitSet& other) const;
    MyBitSet operator|(const MyBitSet& other) const;
private:
    static const int cnt_bits = 16;
    static const int size_of_block = sizeof(unsigned short) * cnt_bits;

    unsigned short* blockData;
    int totalBits;
};

#endif // MYBITSET_H
