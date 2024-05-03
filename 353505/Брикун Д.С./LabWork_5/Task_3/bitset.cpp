#include "bitset.h"

#include "bitset.h"
#include "qdebug.h"

BitSet::BitSet(int size) : size(size) {
    int arraySize = (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK;
    data = new unsigned short[arraySize];
    for (int i = 0; i < arraySize; ++i)
        data[i] = 0;
}

BitSet::~BitSet() {
    delete[] data;
}

int BitSet::getSize() const {
    return size;
}

void BitSet::set(int pos) {
    if (pos >= 0 && pos < size)
        data[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE));
}

void BitSet::set() {
    for (int i = 0; i < size; ++i)
        data[i / BLOCK_SIZE] |= (1 << (i % BLOCK_SIZE));
}

void BitSet::reset(int pos) {
    if (pos >= 0 && pos < size)
        data[pos / BLOCK_SIZE] &= ~(1 << (pos % BLOCK_SIZE));
}

void BitSet::reset() {
    for (int i = 0; i < size; ++i)
        data[i / BLOCK_SIZE] &= ~(1 << (i % BLOCK_SIZE));
}

bool BitSet::test(int pos) const {
    return (pos >= 0 && pos < size) && (data[pos / BLOCK_SIZE] & (1 << (pos % BLOCK_SIZE)));
}

void BitSet::flip(int pos) {
    if (pos >= 0 && pos < size)
        data[pos / BLOCK_SIZE] ^= (1 << (pos % BLOCK_SIZE));
}

void BitSet::flip() {
    for (int i = 0; i < size; ++i) {
        data[i / BLOCK_SIZE] ^= (1 << (i % BLOCK_SIZE));
    }
}

bool BitSet::all() const {
    int fullBlocks = size / BITS_PER_BLOCK;
    int partialBlockSize = size % BITS_PER_BLOCK;
    for (int i = 0; i < fullBlocks; ++i) {
        if (data[i] != (unsigned short)((1 << BITS_PER_BLOCK) - 1))
            return false;
    }
    if (partialBlockSize > 0) {
        unsigned short mask = (1 << partialBlockSize) - 1; // Маска для последних неполных битов
        if (data[fullBlocks] != mask)
            return false;
    }

    return true;
}

bool BitSet::any() const {
    for (int i = 0; i < (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK; ++i) {
        if (data[i] != 0)
            return true;
    }
    return false;
}

int BitSet::count() const {
    int count = 0;
    for (int i = 0; i < (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK; ++i) {
        unsigned short val = data[i];
        while (val) {
            count += (val & 1);
            val >>= 1;
        }
    }
    return count;
}

bool BitSet::none() const {
    return !any();
}

QString BitSet::to_string() const {
    QString str;
    for (int i = size - 1; i >= 0; --i) {
        str += test(i) ? '1' : '0';
    }
    return str;
}

unsigned long long BitSet::to_ullong() const {
    unsigned long long val = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (test(i))
            val |= (1ULL << i);
    }
    return val;
}

unsigned long BitSet::to_ulong() const {
    unsigned long val = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (test(i))
            val |= (1ULL << i);
    }
    return val;
}

bool BitSet::operator[](int pos) const {
    return test(pos);
}

bool& BitSet::operator[](int pos) {
    static bool ex;
    if (pos < 0 || pos >= size)
        return ex;
    return reinterpret_cast<bool&>(data[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE)));
}
