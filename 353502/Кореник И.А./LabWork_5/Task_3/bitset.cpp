#include "bitset.h"

BitSet::BitSet(int size) : size(size)
{
    int arrSize = (BITS + size - 1) / BITS;
    data = new unsigned short[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
        data[i] = 0;
    }
}

BitSet::~BitSet()
{
    delete[] data;
}

bool BitSet::operator[](int pos) const
{
    return test(pos);
}

bool &BitSet::operator[](int pos)
{
    static bool b;
    if (pos < 0 || pos >= size)
    {
        return b;
    }
    return (bool&)(data[pos / SIZE] |= (1 << (pos % SIZE)));
}

int BitSet::getSize() const
{
    return size;
}

void BitSet::set(int pos)
{
    if (pos >= 0 && pos < size)
    {
        data[pos / SIZE] |= (1 << (pos % SIZE));
    }
}

void BitSet::set()
{
    for (int i = 0; i < size; ++i)
    {
        data[i / SIZE] |= (1 << (i % SIZE));
    }
}

void BitSet::reset(int pos)
{
    if (pos >= 0 && pos < size)
    {
        data[pos / SIZE] &= ~(1 << (pos % SIZE));
    }
}

void BitSet::reset()
{
    for (int i = 0; i < size; ++i)
    {
        data[i / SIZE] &= ~(1 << (i % SIZE));
    }
}

bool BitSet::test(int pos) const
{
    return (pos >= 0 && pos < size) &&
           (data[pos / SIZE] & (1 << (pos % SIZE)));
}

void BitSet::flip(int pos)
{
    if (pos >= 0 && pos < size)
    {
        data[pos / SIZE] ^= (1 << (pos % SIZE));
    }
}

void BitSet::flip()
{
    for (int i = 0; i < size; ++i)
    {
        data[i / SIZE] ^= (1 << (i % SIZE));
    }
}

bool BitSet::all() const
{
    int fullSizedBlocks = size / BITS;
    int partialSizedBlock = size % BITS;
    for (int i = 0; i < fullSizedBlocks; ++i)
    {
        if (data[i] != (unsigned short)((1 << BITS) - 1))
        {
            return false;
        }
    }
    if (partialSizedBlock > 0)
    {
        unsigned short block = (1 << partialSizedBlock) - 1;
        if (data[fullSizedBlocks] != block)
        {
            return false;
        }
    }
    return true;
}

bool BitSet::any() const
{
    for (int i = 0; i < (BITS + size - 1) / BITS; ++i)
    {
        if (data[i] != 0)
        {
            return true;
        }
    }
    return false;
}

bool BitSet::none() const
{
    return !any();
}

int BitSet::count() const
{
    int n = 0;
    for (int i = 0; i < (BITS + size - 1) / BITS; ++i)
    {
        unsigned short value = data[i];
        while (value)
        {
            n += (value & 1);
            value >>= 1;
        }
    }
    return n;
}

QString BitSet::to_string() const
{
    QString str;
    for (int i = size - 1; i >= 0; --i)
    {
        str += (test(i) ? '1' : '0');
    }
    return str;
}

unsigned long BitSet::to_ulong() const
{
    unsigned long value = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        if (test(i))
        {
            value |= (1UL << i);
        }
    }
    return value;
}

unsigned long long BitSet::to_ullong() const
{
    unsigned long long value = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        if (test(i))
        {
            value |= (1ULL << i);
        }
    }
    return value;
}
