#include "bitset.h"

Bitset::Bitset(int size) : size(size) {
    int arraySize = (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK;
    arr = new unsigned short[arraySize];
    for (int i = 0; i < arraySize; ++i)
        arr[i] = 0;
}


Bitset::~Bitset() {
    delete[] arr;
}

int Bitset::getSize() const {
    return size;
}

void Bitset::set(int pos) {
    if (pos >= 0 && pos < size)
        arr[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE));
}

void Bitset::set() {
    for (int i = 0; i < size; ++i)
        arr[i / BLOCK_SIZE] |= (1 << (i % BLOCK_SIZE));
}

void Bitset::reset(int pos) {
    if (pos >= 0 && pos < size)
        arr[pos / BLOCK_SIZE] &= ~(1 << (pos % BLOCK_SIZE));
}

void Bitset::reset() {
    for (int i = 0; i < size; ++i)
        arr[i / BLOCK_SIZE] &= ~(1 << (i % BLOCK_SIZE));
}

bool Bitset::test(int pos) const {
    return (pos >= 0 && pos < size) && (arr[pos / BLOCK_SIZE] & (1 << (pos % BLOCK_SIZE)));
}

void Bitset::flip(int pos) {
    if (pos >= 0 && pos < size)
        arr[pos / BLOCK_SIZE] ^= (1 << (pos % BLOCK_SIZE));
}

void Bitset::flip() {
    for (int i = 0; i < size; ++i) {
        arr[i / BLOCK_SIZE] ^= (1 << (i % BLOCK_SIZE));
    }
}

bool Bitset::all() const {
    int fullBlocks = size / BITS_PER_BLOCK;
    int partialBlockSize = size % BITS_PER_BLOCK;
    for (int i = 0; i < fullBlocks; ++i) {
        if (arr[i] != (unsigned short)((1 << BITS_PER_BLOCK) - 1))
            return false;
    }
    if (partialBlockSize > 0) {
        unsigned short mask = (1 << partialBlockSize) - 1; // Маска для последних неполных битов
        if (arr[fullBlocks] != mask)
            return false;
    }

    return true;
}

bool Bitset::any() const {
    for (int i = 0; i < (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK; ++i) {
        if (arr[i] != 0)
            return true;
    }
    return false;
}

int Bitset::count() const {
    int count = 0;
    for (int i = 0; i < (size + BITS_PER_BLOCK - 1) / BITS_PER_BLOCK; ++i) {
        unsigned short val = arr[i];
        while (val) {
            count += (val & 1);
            val >>= 1;
        }
    }
    return count;
}

bool Bitset::none() const {
    return !any();
}

QString Bitset::to_string() const {
    QString str;
    for (int i = size - 1; i >= 0; --i) {
        str += test(i) ? '1' : '0';
    }
    return str;
}

unsigned long long Bitset::to_ullong() const {
    unsigned long long val = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (test(i))
            val |= (1ULL << i);
    }
    return val;
}

unsigned long Bitset::to_ulong() const {
    unsigned long val = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (test(i))
            val |= (1ULL << i);
    }
    return val;
}

bool Bitset::operator[](int pos) const {
    return test(pos);
}

bool& Bitset::operator[](int pos) {
    static bool ex;
    if (pos < 0 || pos >= size)
        return ex;
    return reinterpret_cast<bool&>(arr[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE)));
}
