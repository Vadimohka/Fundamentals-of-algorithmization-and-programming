#include "mybitset.h"

MyBitset::MyBitset()
{
    _bits.resize(1);
}

MyBitset::MyBitset(int size)
    : _size(size)
{
    _bits.resize((size + 31) / 32);
}

MyBitset::MyBitset(const MyBitset &other)
    : _bits(other._bits)
    , _size(other._size)
{}

void MyBitset::set(size_t pos)
{
    if (pos < 0 || pos >= _size) {
        return;
    }
    size_t index = pos / 32;
    size_t bit = pos % 32;
    _bits[index] |= (1 << bit);
}

bool MyBitset::get(size_t pos)
{
    if (pos < 0 || pos >= _size) {
        return false;
    }
    size_t index = pos / 32;
    size_t bit = pos % 32;
    return (_bits[index] & (1 << bit));
}

bool MyBitset::operator[](size_t pos) const
{
    if (pos < 0 || pos >= _size) {
        return false;
    }
    size_t index = pos / 32;
    size_t bit = pos % 32;
    return (_bits[index] & (1 << bit));
}

void MyBitset::resize(size_t newSize)
{
    _bits.resize((newSize + 31) / 32);
}

bool MyBitset::all()
{
    for (int byte : _bits) {
        if (byte != static_cast<int>(0xFF)) {
            return false;
        }
    }
    return true;
}

bool MyBitset::any()
{
    for (int byte : _bits) {
        if (byte) {
            return true;
        }
    }
    return false;
}

size_t MyBitset::count()
{
    size_t count = 0;
    for (int byte : _bits) {
        for (int i = 0; i < 32; i++) {
            if (byte & (1 << i)) {
                count++;
            }
        }
    }
    return count;
}

void MyBitset::flip()
{
    for (int &byte : _bits) {
        byte = ~byte;
    }
}

bool MyBitset::none()
{
    return !any();
}

void MyBitset::reset()
{
    for (int &bytes : _bits) {
        bytes = 0;
    }
}

void MyBitset::reset(size_t pos)
{
    if (pos >= 0 || pos < _size) {
        size_t index = pos / 32;
        size_t bit = pos % 32;
        _bits[index] &= ~(1 << bit);
    }
}

void MyBitset::set()
{
    for (int &bytes : _bits) {
        size_t bit = 0;
        bytes |= (~bit);
    }
}

size_t MyBitset::size()
{
    return _size;
}

bool MyBitset::test(size_t pos)
{
    return get(pos);
}

QString MyBitset::to_string()
{
    QString str;
    for (size_t i = 0; i < _size; ++i) {
        str.insert(0, get(i) ? '1' : '0');
    }
    return str;
}

unsigned long long MyBitset::to_ullong()
{
    return static_cast<unsigned long long>(count());
}

unsigned long MyBitset::to_ulong()
{
    return static_cast<unsigned long>(count());
}
