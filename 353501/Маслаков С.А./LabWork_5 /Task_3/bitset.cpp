#include "bitset.h"
#include <climits>
#include <stdexcept>

int BitSet::get(int index) const
{
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }

    return (bits[index / BLOCK_SIZE] >> (index % BLOCK_SIZE)) & 1;
}

void BitSet::set(int index, int value)
{
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }
    if (value != 0 && value != 1) {
        throw std::invalid_argument("Value must be 0 or 1");
    }
    if (value == 1) {
        bits[index / BLOCK_SIZE] |= (1 << (index % BLOCK_SIZE));
    } else {
        bits[index / BLOCK_SIZE] &= ~(1 << (index % BLOCK_SIZE));
    }
}

bool BitSet::operator[](int index) const
{
    return get(index);
}

bool &BitSet::operator[](int index)
{
    static bool proxy;
    proxy = get(index);
    return proxy;
}

BitSet BitSet::operator~() const
{
    BitSet result;
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        result.bits[i] = ~bits[i];
    }
    return result;
}

BitSet BitSet::operator&(const BitSet &other) const
{
    BitSet result;
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        result.bits[i] = bits[i] & other.bits[i];
    }
    return result;
}

BitSet BitSet::operator|(const BitSet &other) const
{
    BitSet result;
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        result.bits[i] = bits[i] | other.bits[i];
    }
    return result;
}

bool BitSet::operator!=(const BitSet &other) const
{
    return !(*this == other);
}

bool BitSet::operator==(const BitSet &other) const
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        if (bits[i] != other.bits[i]) {
            return false;
        }
    }
    return true;
}

bool BitSet::all() const
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        int value = bits[i];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (!(value & 1)) {
                return false;
            }
            value >>= 1;
        }
    }
    return true;
}

bool BitSet::any() const
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        int value = bits[i];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (value & 1) {
                return true;
            }
            value >>= 1;
        }
    }
    return false;
}

bool BitSet::none() const
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        if (bits[i] != 0) {
            return false;
        }
    }
    return true;
}

int BitSet::count() const
{
    int count = 0;
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        int val = bits[i];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (val & 1) {
                count++;
            }
            val >>= 1;
        }
    }
    return count;
}

void BitSet::fliper()
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        bits[i] = ~bits[i];
    }
}

void BitSet::flip(int index)
{
    index = SIZE - 1 - index;
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }
    bits[index / BLOCK_SIZE] ^= (1 << (index % BLOCK_SIZE));
}

void BitSet::reset()
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        bits[i] = 0;
    }
}

void BitSet::reset(int index)
{
    index = SIZE - 1 - index;
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }
    bits[index / BLOCK_SIZE] &= ~(1 << (index % BLOCK_SIZE));
}

void BitSet::set()
{
    for (int i = 0; i < SIZE / BLOCK_SIZE; i++) {
        bits[i] = ~0;
    }
}

void BitSet::set(int index)
{
    index = SIZE - 1 - index;
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }
    bits[index / BLOCK_SIZE] |= (1 << (index % BLOCK_SIZE));
}

int BitSet::size()
{
    return SIZE;
}

bool BitSet::test(int index) const
{
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Index out of range");
    }
    return (bits[index / BLOCK_SIZE] & (1 << (index % BLOCK_SIZE))) != 0;
}

QString BitSet::to_string() const
{
    QString result;
    for (int i = 0; i < SIZE; i++) {
        result.push_back(test(i) ? '1' : '0');
    }
    return result;
}

ull BitSet::to_ullong() const
{
    if ((ull) SIZE > sizeof(ull) * CHAR_BIT) {
        throw std::overflow_error("BitSet size is too large");
    }
    ull res = 0;
    for (int i = 0; i < SIZE; i++) {
        if (test(SIZE - 1 - i)) {
            res |= 1ULL << i;
        }
    }
    return res;
}

ull BitSet::to_ulong() const
{
    if ((ul) SIZE > sizeof(ul) * CHAR_BIT) {
        throw std::overflow_error("BitSet size is too large");
    }
    ul res = 0;
    for (int i = 0; i < SIZE; i++) {
        if (test(SIZE - 1 - i)) {
            res |= 1UL << i;
        }
    }
    return res;
}
