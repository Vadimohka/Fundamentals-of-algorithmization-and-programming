#ifndef BITSET_H
#define BITSET_H

#include <QString>
#include <vector>

template <size_t N>
class Bitset {
private:
    std::vector<bool> bits;

public:
    Bitset() : bits(N, false) {}
    void set(size_t pos);
    bool get(size_t pos) const;
    void set();
    void flip(size_t pos);
    void flip();
    bool all() const;
    bool any() const;
    bool none() const;
    size_t count() const;
    size_t getsize() const;
    QString toString() const;
    unsigned long to_ulong() const;
    unsigned long long to_ullong() const;
    void reset();
    void reset(size_t pos);
    bool test(size_t pos) const;
};
#endif // BITSET_H
