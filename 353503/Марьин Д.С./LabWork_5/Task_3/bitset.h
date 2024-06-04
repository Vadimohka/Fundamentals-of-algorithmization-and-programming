#ifndef BITSET_H
#define BITSET_H
#include <cstddef>
#include <string>

template<size_t N>
class BitSet
{
private:
    size_t* _data;

    struct BitReference;

    constexpr size_t  capacity() const noexcept;

public:
    // Constructors and destructor
    BitSet();
    BitSet(const BitSet& other);
    BitSet(BitSet&& other) noexcept;
    ~BitSet();

    // Operators
    BitSet& operator=(const BitSet& other);
    BitSet& operator=(BitSet&& other) noexcept;
    BitSet& operator&=(const BitSet& other);
    BitSet& operator|=(const BitSet& other);
    BitSet& operator^=(const BitSet& other);
    BitSet& operator<<=(size_t shift);
    BitSet& operator>>=(size_t shift);
    BitSet operator~() const;
    BitSet operator&(const BitSet& other) const;
    BitSet operator|(const BitSet& other) const;
    BitSet operator^(const BitSet& other) const;
    BitSet operator<<(size_t shift) const;
    BitSet operator>>(size_t shift) const;
    bool operator==(const BitSet& other) const;
    bool operator!=(const BitSet& other) const;
    BitReference operator[](size_t index);
    bool operator[](size_t index) const;

    // Methods
    void set(size_t index, bool value);
    void set();
    size_t size() const noexcept;
    bool test(size_t index) const;
    bool get(size_t index) const;
    void reset();
    void flip();
    bool any() const;
    bool none() const;
    bool all() const;
    std::string to_string() const;
    size_t count() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;
private:
    struct BitReference
    {
        size_t* _byte;
        size_t _bit;

        BitReference(size_t* byte, size_t bit) : _byte(byte), _bit(bit) {}

        operator bool() const
        {
            return *_byte & (1 << _bit);
        }

        BitReference& operator=(bool value)
        {
            if (value)
                *_byte |= (1 << _bit);
            else
                *_byte &= ~(1 << _bit);
            return *this;
        }

        BitReference& operator=(const BitReference& other)
        {
            return *this = (bool) other;
        }
    };
};

template<size_t N>
constexpr size_t BitSet<N>::capacity() const noexcept
{
    return N / (sizeof(size_t) * 8) + (N % (sizeof(size_t) * 8) != 0);
}

template<size_t N>
BitSet<N>::BitSet() : _data(new size_t[capacity()])
{
    reset();
}

template<size_t N>
BitSet<N>::BitSet(const BitSet& other) : _data(new size_t[capacity()])
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] = other._data[i];
}

template<size_t N>
BitSet<N>::BitSet(BitSet&& other) noexcept : _data(other._data)
{
    other._data = nullptr;
}

template<size_t N>
BitSet<N>::~BitSet()
{
    delete[] _data;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator=(const BitSet& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < capacity(); ++i)
            _data[i] = other._data[i];
    }
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator=(BitSet&& other) noexcept
{
    if (this != &other)
    {
        delete[] _data;
        _data = other._data;
        other._data = nullptr;
    }
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator&=(const BitSet& other)
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] &= other._data[i];
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator|=(const BitSet& other)
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] |= other._data[i];
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator^=(const BitSet& other)
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] ^= other._data[i];
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator<<=(size_t shift)
{
    if (shift >= N)
        return *this = BitSet<N>();
    size_t shiftBytes = shift / (sizeof(size_t) * 8);
    size_t shiftBits = shift % (sizeof(size_t) * 8);
    for (size_t i = 0; i < capacity(); ++i)
    {
        _data[i] = i + shiftBytes < capacity() ? _data[i + shiftBytes] << shiftBits : 0;
        if (shiftBits != 0 && i + shiftBytes + 1 < capacity())
            _data[i] |= _data[i + shiftBytes + 1] >> (sizeof(size_t) * 8 - shiftBits);
    }
    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator>>=(size_t shift)
{
    if (shift >= N)
        return *this = BitSet<N>();
    size_t shiftBytes = shift / (sizeof(size_t) * 8);
    size_t shiftBits = shift % (sizeof(size_t) * 8);
    for (size_t i = 0; i < capacity(); ++i)
    {
        _data[i] = i >= shiftBytes ? _data[i - shiftBytes] >> shiftBits : 0;
        if (shiftBits != 0 && i >= shiftBytes + 1)
            _data[i] |= _data[i - shiftBytes - 1] << (sizeof(size_t) * 8 - shiftBits);
    }
    return *this;
}

template<size_t N>
BitSet<N> BitSet<N>::operator~() const
{
    BitSet<N> result(*this);
    result.flip();
    return result;
}

template<size_t N>
BitSet<N> BitSet<N>::operator&(const BitSet& other) const
{
    BitSet<N> result(*this);
    result &= other;
    return result;
}

template<size_t N>
BitSet<N> BitSet<N>::operator|(const BitSet& other) const
{
    BitSet<N> result(*this);
    result |= other;
    return result;
}

template<size_t N>
BitSet<N> BitSet<N>::operator^(const BitSet& other) const
{
    BitSet<N> result(*this);
    result ^= other;
    return result;
}

template<size_t N>
BitSet<N> BitSet<N>::operator<<(size_t shift) const
{
    BitSet<N> result(*this);
    result <<= shift;
    return result;
}

template<size_t N>
BitSet<N> BitSet<N>::operator>>(size_t shift) const
{
    BitSet<N> result(*this);
    result >>= shift;
    return result;
}

template<size_t N>
bool BitSet<N>::operator==(const BitSet& other) const
{
    for (size_t i = 0; i < capacity(); ++i)
        if (_data[i] != other._data[i])
            return false;
    return true;
}

template<size_t N>
bool BitSet<N>::operator!=(const BitSet& other) const
{
    return !(*this == other);
}
template<size_t N>
typename BitSet<N>::BitReference BitSet<N>::operator[](size_t index)
{
    return BitReference(_data + index / (sizeof(size_t) * 8), index % (sizeof(size_t) * 8));
}
template<size_t N>
bool BitSet<N>::operator[](size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("BitSet index out of range");
    }
    size_t byteIndex = index / (sizeof(size_t) * 8);
    size_t bitIndex = index % (sizeof(size_t) * 8);
    return (_data[byteIndex] & (1 << bitIndex)) != 0;
}
template<size_t N>
void BitSet<N>::set(size_t index, bool value)
{
    (*this)[index] = value;
}
template<size_t N>
void BitSet<N>::set()
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] = ~0;
}
template<size_t N>
size_t BitSet<N>::size() const noexcept
{
    return N;
}
template<size_t N>
bool BitSet<N>::test(size_t index) const
{
    return (bool)get(index);
}
template<size_t N>
bool BitSet<N>::get(size_t index) const
{
    if (index >= N)
    {
        throw std::out_of_range("BitSet index out of range");
    }
    return (*this)[index];
}
template<size_t N>
void BitSet<N>::reset()
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] = 0;
}
template<size_t N>
void BitSet<N>::flip()
{
    for (size_t i = 0; i < capacity(); ++i)
        _data[i] = ~_data[i];
}
template<size_t N>
bool BitSet<N>::any() const
{
    for (size_t i = 0; i < capacity(); ++i)
        if (_data[i] != 0)
            return true;
    return false;
}
template<size_t N>
bool BitSet<N>::none() const
{
    return !any();
}
template<size_t N>
bool BitSet<N>::all() const
{
    for (size_t i = 0; i < capacity(); ++i)
        if (_data[i] != ~0)
            return false;
    return true;
}
template<size_t N>
std::string BitSet<N>::to_string() const
{
    std::string result;
    for (size_t i = N; i > 0; --i)
        result += (*this)[i - 1] ? '1' : '0';
    return result;
}
template<size_t N>
size_t BitSet<N>::count() const
{
    size_t result = 0;
    for (size_t i = 0; i < capacity(); ++i)
        result += __builtin_popcount(_data[i]);
    return result;
}
template<size_t N>
unsigned long long BitSet<N>::to_ullong() const
{
    unsigned long long result = 0;
    for (size_t i = 0; i < capacity(); ++i)
        result |= (unsigned long long)_data[i] << (i * sizeof(size_t) * 8);
    return result;
}
template<size_t N>
unsigned long BitSet<N>::to_ulong() const
{
    return (unsigned long)to_ullong();
}
#endif // BITSET_H
