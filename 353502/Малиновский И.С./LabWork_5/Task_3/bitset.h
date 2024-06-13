#ifndef BITSET_H
#define BITSET_H

#include <bitset>
#include <string>

class BitSet {
public:
    BitSet(size_t size);

    bool all() const;
    bool any() const;
    size_t count() const;
    void flip(size_t pos);
    void flip();
    bool none() const;
    void reset(size_t pos);
    void reset();
    void set(size_t pos);
    void set();
    size_t size() const;
    bool test(size_t pos) const;
    std::string to_string() const;
    unsigned long to_ulong() const;
    unsigned long long to_ullong() const;

    bool operator[](size_t pos) const;
    bool operator[](size_t pos);

private:
    std::bitset<64> bits; // Максимальный размер 64 бита, можно изменить при необходимости
};

#endif // BITSET_H
