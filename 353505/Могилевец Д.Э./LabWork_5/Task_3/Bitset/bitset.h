#ifndef BITSET_H
#define BITSET_H


#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>

template <size_t len> class Bitset
{
private:
    static_assert(len > 1, "Bitset must have at least one bit");
    static const size_t amOfBlocks = 1 + len / 64;
    std::vector<uint64_t> blocks = std::vector<uint64_t>(amOfBlocks, 0);
public:
    Bitset<len>() {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = 0;
    }

    Bitset<len>(uint64_t init) {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = 0;
        blocks[0] = init;
    }

    Bitset<len>(const Bitset<len> &other) {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = other.blocks[i];
    }

    Bitset<len> &operator=(const Bitset<len> &other) {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = other.blocks[i];
        return *this;
    }

    size_t size() const { return len; }

private:
    class Bit {
        uint64_t* block;
        uint8_t pos;

    public:
        Bit(uint64_t* block_, int pos_) : block(block_), pos(pos_ % 64) {}

        bool test() const { return (*block << pos) & 0x8000; }
        operator bool() const { return test(); }
        Bit operator=(bool val) {
            if (val)
                *block |= static_cast<uint64_t>(val << pos);
            else
                *block |= static_cast<uint64_t>(~(val << pos));
            return *this;
        }

        void set() { *block |= 1 << pos; }
        void flip() { *block ^= 1 << pos; }
        void reset() { *block &= ~(1 << pos); }
    };

public:

    Bit at(size_t pos) const { return Bit(&blocks[pos / 64], pos); }
    Bit operator[](size_t pos) { return this->at(pos); }

    void set(size_t pos) { at(pos).set(); }
    void reset(size_t pos) { at(pos).reset(); }
    void flip(size_t pos) { at(pos).flip(); }

    bool test(size_t pos) const { return at(pos).test(); }

    bool operator[](size_t pos) const { return test(pos); }

    std::string to_string() const {
        std::string res(len, '0');
        for (int i = 0; i < len; i++) if (test(i)) res[i] = '1';
        return res;
    }

    unsigned long long to_ullong() const {
        return blocks[0];
    }

    unsigned long to_ulong() const {
        return blocks[0];
    }

    size_t count() const {
        size_t bits = 0;
        for (int i = 0; i < len - 1; i++) {
            bits += __builtin_popcountll(blocks[i]);
        }
        bits += __builtin_popcountll(blocks[len - 1] >> (64 - len % 64));
        return bits;
    }

    bool all() const { return count() == size(); }
    bool any() const { return count() != 0; }
    bool none() const { return count() == 0; }

    void set() {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = ~0;
    }
    void reset() {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = 0;
    }

    void flip() {
        for (int i = 0; i < amOfBlocks; i++)
            blocks[i] = ~blocks[i];
    }

    Bitset<len> operator~() const {
        Bitset<len> res;
        for (int i = 0; i < amOfBlocks; i++)
            res.blocks[i] = ~blocks[i];
        return res;
    }

    Bitset<len> operator& (const Bitset<len> &other) const {
        Bitset<len> res;
        for (int i = 0; i < amOfBlocks; i++)
            res.blocks[i] = blocks[i] & other.blocks[i];
        return res;
    }

    Bitset<len> operator| (const Bitset<len> &other) const {
        Bitset<len> res;
        for (int i = 0; i < amOfBlocks; i++)
            res.blocks[i] = blocks[i] | other.blocks[i];
        return res;
    }

    Bitset<len> operator^ (const Bitset<len> &other) const {
        Bitset<len> res;
        for (int i = 0; i < amOfBlocks; i++)
            res.blocks[i] = blocks[i] ^ other.blocks[i];
        return res;
    }
};

#endif // BITSET_H
