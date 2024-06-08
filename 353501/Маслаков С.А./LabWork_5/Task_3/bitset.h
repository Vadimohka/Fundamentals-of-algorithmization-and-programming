#ifndef BITSET_H
#define BITSET_H

#include <QString>
#include <cstdint>
typedef unsigned long long ull;
typedef unsigned long ul;

class BitSet
{
private:
    int SIZE;
    static const int BLOCK_SIZE = 16;
    uint16_t *bits;

public:
    BitSet()
        : SIZE(1024)
    {
        bits = new uint16_t[SIZE / BLOCK_SIZE];
        std::fill_n(bits, SIZE / BLOCK_SIZE, 0);
    };

    BitSet(int bitCount)
        : SIZE(bitCount)
    {
        bits = new uint16_t[SIZE / BLOCK_SIZE];
        std::fill_n(bits, SIZE / BLOCK_SIZE, 0);
    }

    ~BitSet() {}

    int get(int index) const;

    void set(int index, int value);

    bool operator[](int index) const;
    bool &operator[](int index);

    BitSet operator~() const;
    BitSet operator&(const BitSet &other) const;
    BitSet operator|(const BitSet &other) const;
    BitSet operator^(const BitSet &other) const;
    bool operator!=(const BitSet &other) const;
    bool operator==(const BitSet &other) const;

    bool all() const;
    bool any() const;
    bool none() const;

    int count() const;
    void fliper();
    void flip(int index);
    void reset();
    void reset(int index);
    void set();
    void set(int index);
    int size();

    bool test(int index) const;
    QString to_string() const;

    ull to_ullong() const;
    ull to_ulong() const;
};

#endif // BITSET_H
