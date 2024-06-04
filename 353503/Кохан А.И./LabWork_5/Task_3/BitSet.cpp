#include "BitSet.h"

constexpr short BITS = sizeof(ushort) * 8;
constexpr short MAX_SIZE_IN_BYTE = sizeof(ushort) * BITS;

BitSet::BitSet(size_t newSize, ushort initValue = 0)
    : _size(newSize)
{
    size_t arrSize = (BITS + _size - 1) / BITS;
    _data = new ushort[arrSize];
    for (size_t i = 0; i < arrSize; ++i) {
        _data[i] = initValue;
    }
}

BitSet::~BitSet()
{
    delete[] _data;
}

bool BitSet::operator[](size_t pos) const
{
    return test(pos);
}

bool &BitSet::operator[](size_t pos)
{
    static bool b;
    if (pos < 0 || pos >= _size) {
        return b;
    }
    return (bool &) (_data[pos / MAX_SIZE_IN_BYTE] |= (1 << (pos % MAX_SIZE_IN_BYTE)));
}

size_t BitSet::getSize() const
{
    return _size;
}

void BitSet::set(size_t pos)
{
    if (pos >= 0 && pos < _size) {
        _data[pos / MAX_SIZE_IN_BYTE] |= (1 << (pos % MAX_SIZE_IN_BYTE));
    }
}

void BitSet::set()
{
    for (size_t i = 0; i < _size; ++i) {
        _data[i / MAX_SIZE_IN_BYTE] |= (1 << (i % MAX_SIZE_IN_BYTE));
    }
}

void BitSet::reset(size_t pos)
{
    if (pos >= 0 && pos < _size) {
        _data[pos / MAX_SIZE_IN_BYTE] &= ~(1 << (pos % MAX_SIZE_IN_BYTE));
    }
}

void BitSet::reset()
{
    for (size_t i = 0; i < _size; ++i) {
        _data[i / MAX_SIZE_IN_BYTE] &= ~(1 << (i % MAX_SIZE_IN_BYTE));
    }
}

bool BitSet::test(size_t pos) const
{
    return (pos >= 0 && pos < _size)
           && (_data[pos / MAX_SIZE_IN_BYTE] & (1 << (pos % MAX_SIZE_IN_BYTE)));
}

void BitSet::flip(size_t pos)
{
    if (pos >= 0 && pos < _size) {
        _data[pos / MAX_SIZE_IN_BYTE] ^= (1 << (pos % MAX_SIZE_IN_BYTE));
    }
}

void BitSet::flip()
{
    for (size_t i = 0; i < _size; ++i) {
        _data[i / MAX_SIZE_IN_BYTE] ^= (1 << (i % MAX_SIZE_IN_BYTE));
    }
}

bool BitSet::all() const
{
    size_t fullSizedBlocks = _size / BITS;
    size_t partialSizedBlock = _size % BITS;
    for (size_t i = 0; i < fullSizedBlocks; ++i) {
        if (_data[i] != static_cast<ushort>((1 << BITS) - 1)) {
            return false;
        }
    }
    if (partialSizedBlock > 0) {
        ushort block = (1 << partialSizedBlock) - 1;
        if (_data[fullSizedBlocks] != block) {
            return false;
        }
    }
    return true;
}

bool BitSet::any() const
{
    for (size_t i = 0; i < (BITS + _size - 1) / BITS; ++i) {
        if (_data[i] != 0) {
            return true;
        }
    }
    return false;
}

bool BitSet::none() const
{
    return !any();
}

size_t BitSet::count() const
{
    size_t n = 0;
    for (size_t i = 0; i < (BITS + _size - 1) / BITS; ++i) {
        ushort value = _data[i];
        while (value) {
            n += (value & 1);
            value >>= 1;
        }
    }
    return n;
}

QString BitSet::to_string() const
{
    QString str;
    for (int i = _size - 1; i >= 0; --i) {
        str += (test(i) ? '1' : '0');
    }
    return str;
}

unsigned long BitSet::to_ulong() const
{
    unsigned long value = 0;
    for (int i = _size - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1UL << i);
        }
    }
    return value;
}

unsigned long long BitSet::to_ullong() const
{
    size_t value = 0;
    for (int i = _size - 1; i >= 0; --i) {
        if (test(i)) {
            value |= (1ULL << i);
        }
    }
    return value;
}
