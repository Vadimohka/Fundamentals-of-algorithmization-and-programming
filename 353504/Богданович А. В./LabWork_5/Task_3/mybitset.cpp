#include "mybitset.h"

MyBitSet::MyBitSet(int size): totalBits(size)
{
    int arrSize = (cnt_bits + size - 1) / cnt_bits;
    blockData = new unsigned short[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        blockData[i] = 0;
    }
}

MyBitSet::~MyBitSet()
{
    delete[] blockData;
}

bool MyBitSet::test(int pos) const {
    return (pos >= 0 && pos < totalBits) && (blockData[pos / cnt_bits] & (1 << (pos % cnt_bits)));
}

int MyBitSet::size() const
{
    return totalBits;
}

void MyBitSet::set(int position) {
    if (position >= 0 && position < totalBits) {
        int blockIndex = position / cnt_bits;
        int bitOffset = position % cnt_bits;
        unsigned short mask = (1 << bitOffset);
        blockData[blockIndex] |= mask;
    }
}

void MyBitSet::set() {
    for (int i = 0; i < totalBits; ++i) {
        int blockIndex = i / cnt_bits;
        int bitOffset = i % cnt_bits;
        unsigned short mask = (1 << bitOffset);
        blockData[blockIndex] |= mask;
    }
}

void MyBitSet::reset(int pos) {
    if (pos >= 0 && pos < totalBits) {
        int blockIndex = pos / cnt_bits;
        int bitOffset = pos % cnt_bits;
        unsigned short mask = ~(1 << bitOffset);
        blockData[blockIndex] &= mask;
    }
}

void MyBitSet::reset() {
    for (int i = 0; i < totalBits; ++i) {
        int blockIndex = i / cnt_bits;
        int bitOffset = i % cnt_bits;
        unsigned short mask = ~(1 << bitOffset);
        blockData[blockIndex] &= mask;
    }
}

void MyBitSet::flip(int pos) {
    if (pos >= 0 && pos < totalBits) {
        int blockIndex = pos / cnt_bits;
        int bitOffset = pos % cnt_bits;
        unsigned short mask = (1 << bitOffset);
        blockData[blockIndex] ^= mask;
    }
}

void MyBitSet::flip() {
    for (int i = 0; i < totalBits; ++i) {
        int blockIndex = i / cnt_bits;
        int bitOffset = i % cnt_bits;
        unsigned short mask = (1 << bitOffset);
        blockData[blockIndex] ^= mask;
    }
}

bool MyBitSet::all() const {
    int fullSizedBlocks = totalBits / cnt_bits;
    int partialSizedBlock = totalBits % cnt_bits;
    unsigned short fullBlockMask = (1 << cnt_bits) - 1;
    unsigned short partialBlockMask = (1 << partialSizedBlock) - 1;

    for (int i = 0; i < fullSizedBlocks; ++i) {
        if (blockData[i] != fullBlockMask) {
            return false;
        }
    }

    if (partialSizedBlock > 0 && blockData[fullSizedBlocks] != partialBlockMask) {
        return false;
    }

    return true;
}

bool MyBitSet::any() const {
    int totalBlocks = (totalBits + cnt_bits - 1) / cnt_bits;
    for (int i = 0; i < totalBlocks; ++i) {
        if (blockData[i] != 0) {
            return true;
        }
    }
    return false;
}

bool MyBitSet::none() const
{
    return !any();
}

int MyBitSet::count() const {
    int count = 0;
    int totalBlocks = (totalBits + cnt_bits - 1) / cnt_bits;
    for (int i = 0; i < totalBlocks; ++i) {
        unsigned short value = blockData[i];
        while (value) {
            count += (value & 1);
            value >>= 1;
        }
    }
    return count;
}

QString MyBitSet::to_string() const {
    QString str;
    for (int i = totalBits - 1; i >= 0; --i) {
        if (test(i)) {
            str += '1';
        } else {
            str += '0';
        }
    }
    return str;
}

unsigned long MyBitSet::to_ulong() const {
    unsigned long value = 0;
    for (int i = totalBits - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1UL << i);
        }
    }
    return value;
}

unsigned long long MyBitSet::to_ullong() const {
    unsigned long long value = 0;
    for (int i = totalBits - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1ULL << i);
        }
    }
    return value;
}

bool MyBitSet::operator[](int pos) const
{
    return test(pos);
}

bool& MyBitSet::operator[](int pos) {
    static bool dummy;
    if (pos < 0 || pos >= totalBits) {
        return dummy;
    }
    return reinterpret_cast<bool&>(blockData[pos / cnt_bits] |= (1 << (pos % cnt_bits)));
}

MyBitSet MyBitSet::operator~() const {
    MyBitSet result(totalBits);
    int blockCount = (totalBits + cnt_bits - 1) / cnt_bits;
    for (int i = 0; i < blockCount; ++i) {
        result.blockData[i] = ~blockData[i];
    }
    return result;
}

MyBitSet MyBitSet::operator&(const MyBitSet& other) const {
    MyBitSet result(totalBits);
    int blockCount = (totalBits + cnt_bits - 1) / cnt_bits;
    for (int i = 0; i < blockCount; ++i) {
        result.blockData[i] = blockData[i] & other.blockData[i];
    }
    return result;
}

MyBitSet MyBitSet::operator|(const MyBitSet& other) const {
    MyBitSet result(totalBits);
    int blockCount = (totalBits + cnt_bits - 1) / cnt_bits;
    for (int i = 0; i < blockCount; ++i) {
        result.blockData[i] = blockData[i] | other.blockData[i];
    }
    return result;
}
