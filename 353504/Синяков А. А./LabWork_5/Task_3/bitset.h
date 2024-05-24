#ifndef BITSET_H
#define BITSET_H

#include <QString>

class BitSet {
private:
    static const int BITS_PER_BLOCK = 16;
    static const int BLOCK_SIZE = sizeof(unsigned short) * BITS_PER_BLOCK;

    unsigned short* data;
    int size;

public:
    explicit BitSet(int size);
    ~BitSet();

    [[nodiscard]] int getSize() const;

    void set(int pos);
    void set();

    void reset(int pos);
    void reset();

    [[nodiscard]] bool test(int pos) const;

    void flip(int pos);
    void flip();

    [[nodiscard]] bool all() const;
    [[nodiscard]] bool any() const;
    [[nodiscard]] int count() const;
    [[nodiscard]] bool none() const;
    [[nodiscard]] QString to_string() const;
    [[nodiscard]] unsigned long long to_ullong() const;
    [[nodiscard]] unsigned long to_ulong() const;

    bool operator[](int pos) const;
    bool& operator[](int pos);
};

#endif // BITSET_H
