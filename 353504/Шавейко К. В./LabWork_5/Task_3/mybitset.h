#ifndef MYBITSET_H
#define MYBITSET_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <qtypes.h>

const size_t ULL_BITS = sizeof(size_t);

template<size_t N>
class BitSet
{
private:
    size_t* _data;

    struct BitReference;

    constexpr size_t capacity() const noexcept;

public:
    BitSet();
    BitSet(const BitSet& other);
    BitSet(BitSet&& other) noexcept;
    explicit BitSet(size_t val);
    explicit BitSet(const std::string& str);

    BitSet& operator=(const BitSet& other);
    BitSet& operator=(BitSet&& other) noexcept;

    ~BitSet();

    bool operator[](size_t pos) const;
    BitReference operator[](size_t pos);

    bool test(size_t pos ) const;

    bool all() const noexcept;
    bool any() const noexcept;
    bool none() const noexcept;
    size_t count() const noexcept;

    size_t size() const noexcept;

    BitSet& set() noexcept;
    BitSet& set(size_t pos, bool value = true);
    BitSet& reset() noexcept;
    BitSet& reset(size_t pos);
    BitSet& flip() noexcept;
    BitSet& flip(size_t pos); // to check

    std::string to_string() const;
    auto to_ulong() const -> unsigned long;
    auto to_ullong() const -> unsigned long long;

    bool operator==(const BitSet& rhs) const;
    bool operator!=(const BitSet& rhs) const;

    BitSet& operator&=(const BitSet<N>& rhs);
    BitSet& operator|=(const BitSet<N>& rhs);
    BitSet& operator^=(const BitSet<N>& rhs);
    BitSet operator~() const noexcept;

    template<size_t M>
    friend BitSet<M> operator&(const BitSet<M>& lhs, const BitSet<M>& rhs);
    template<size_t M>
    friend BitSet<M> operator|(const BitSet<M>& lhs, const BitSet<M>& rhs);
    template<size_t M>
    friend BitSet<M> operator^(const BitSet<M>& lhs, const BitSet<M>& rhs);

    template<size_t M>
    friend std::ostream& operator<<(std::ostream& os, const BitSet<M>& bs);
    template<size_t M>
    friend std::istream& operator>>(std::istream& is, BitSet<M>& bs);

private:
    struct BitReference
    {
        quint8 _pos;
        size_t* _origin;

        BitReference(quint8 pos, size_t* origin) : _pos(pos), _origin(origin) {}

        BitReference& operator=(bool newValue);
        operator bool() const;
    };
};


//*************************************************************************************************************************************//


template<size_t N>
constexpr size_t BitSet<N>::capacity() const noexcept
{
    return (N + ULL_BITS - 1ULL) / ULL_BITS;
}

template<size_t N>
BitSet<N>::BitSet() : _data(new size_t[capacity()]) {}

template<size_t N>
BitSet<N>::BitSet(const BitSet &other) : _data(new size_t[capacity()])
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] = other._data[i];
    }
}

template<size_t N>
BitSet<N>::BitSet(BitSet &&other) noexcept : _data(other._data)
{
    other._data = nullptr;
}

template<size_t N>
BitSet<N>::BitSet(size_t val) : _data(new size_t[capacity()])
{
    _data[0] = val;
}

template<size_t N>
BitSet<N>::BitSet(const std::string& str) : _data(new size_t[capacity()])
{
    if (str.size() != N) {
        throw std::invalid_argument("String length does not match BitSet size");
    }

    for (size_t i = 0; i < N; ++i) {
        if (str.at(i) == '1') {
            set(i, true);
        } else {
            if (str.at(i) != '0') {
                throw std::invalid_argument("String contains invalid characters");
            }
        }
    }
}

template<size_t N>
BitSet<N>& BitSet<N>::operator=(const BitSet& other)
{
    if (other != this) {
        for (size_t i = 0; i < capacity(); ++i) {
            _data[i] = other._data[i];
        }
    }

    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator=(BitSet&& other) noexcept
{
    delete[] _data;
    _data = other._data;
    other._data = nullptr;

    return *this;
}

template<size_t N>
BitSet<N>::~BitSet()
{
    delete[] _data;
}

template<size_t N>
bool BitSet<N>::operator[](size_t pos) const
{
    return _data[pos / ULL_BITS] & (1ULL << pos);
}

template<size_t N>
typename BitSet<N>::BitReference BitSet<N>::operator[](size_t pos)
{
    return BitReference(pos, _data + pos / ULL_BITS);
}

template<size_t N>
bool BitSet<N>::test(size_t pos) const
{
    if (pos >= N) {
        throw std::out_of_range("Wrong index");
    }

    return _data[pos / ULL_BITS] & (1ULL << (pos % ULL_BITS));
}

template<size_t N>
bool BitSet<N>::all() const noexcept
{
    for (size_t i = 0; i < capacity(); ++i) {
        if (_data[i] != ~(0ULL)) {
            return false;
        }
    }

    return true;
}

template<size_t N>
bool BitSet<N>::any() const noexcept
{
    for (size_t i = 0; i < capacity(); ++i) {
        if (_data[i] != 0ULL) {
            return true;
        }
    }

    return false;
}

template<size_t N>
bool BitSet<N>::none() const noexcept
{
    return !any();
}

template<size_t N>
size_t BitSet<N>::count() const noexcept
{
    size_t cntr = 0;
    size_t temp = 0;

    for (size_t i = 0; i < capacity(); ++i) {
        if (_data[i] == 0ULL) {
            continue;
        }

        temp = _data[i];
        for (quint8 j = 0; j < ULL_BITS; ++j) {
            if (_data[i] & 1ULL) {
                ++cntr;
            }
            temp /= 2;
        }
    }

    return cntr;
}

template<size_t N>
size_t BitSet<N>::size() const noexcept
{
    return N;
}

template<size_t N>
BitSet<N> &BitSet<N>::set() noexcept
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] = ~(0ULL);
    }

    return *this;
}

template<size_t N>
BitSet<N> &BitSet<N>::set(size_t pos, bool value)
{
    if (pos >= N) {
        throw std::out_of_range("Wrong index");
    }

    _data[pos / ULL_BITS] &= ~(1ULL << (pos % ULL_BITS));
    _data[pos / ULL_BITS] |= (static_cast<size_t>(value) << (pos % ULL_BITS));
    return *this;
}

template<size_t N>
BitSet<N> &BitSet<N>::reset() noexcept
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] = 0;
    }

    return *this;
}

template<size_t N>
BitSet<N> &BitSet<N>::reset(size_t pos)
{
    if (pos >= N) {
        throw std::out_of_range("Wrong index");
    }

    _data[pos / ULL_BITS] &= ~(1ULL << (pos % ULL_BITS));
    return *this;
}

template<size_t N>
BitSet<N> &BitSet<N>::flip() noexcept
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] = ~(_data[i]);
    }

    return *this;
}

template<size_t N>
BitSet<N> &BitSet<N>::flip(size_t pos)
{
    if (pos >= N) {
        throw std::out_of_range("Wrong index");
    }

    _data[pos / ULL_BITS] ^= (1ULL << (pos % ULL_BITS));
    return *this;
}

template<size_t N>
std::string BitSet<N>::to_string() const
{
    std::string retStr;

    for (size_t i = 0; i < N; ++i) {
        retStr.insert(retStr.begin(), (test(i) ? '1' : '0'));
    }

    return retStr;
}

template<size_t N>
auto BitSet<N>::to_ulong() const -> unsigned long
{
    unsigned long retInt = 0;

    for (size_t i = 0; i < N; ++i) {
        retInt |= ((test(i) ? 1UL : 0UL) << i);
    }

    return retInt;
}

template<size_t N>
auto BitSet<N>::to_ullong() const -> unsigned long long
{
    return _data[0];
}

template<size_t N>
bool BitSet<N>::operator==(const BitSet &rhs) const
{
    for (size_t i = 0; i < capacity(); ++i) {
        if (_data[i] != rhs._data[i]) {
            return false;
        }
    }

    return true;
}

template<size_t N>
bool BitSet<N>::operator!=(const BitSet &rhs) const
{
    return !(*this == rhs);
}

template<size_t N>
BitSet<N>& BitSet<N>::operator&=(const BitSet<N> &rhs)
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] &= rhs._data[i];
    }

    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator|=(const BitSet<N> &rhs)
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] |= rhs._data[i];
    }

    return *this;
}

template<size_t N>
BitSet<N>& BitSet<N>::operator^=(const BitSet<N> &rhs)
{
    for (size_t i = 0; i < capacity(); ++i) {
        _data[i] ^= rhs._data[i];
    }

    return *this;
}

template<size_t N>
BitSet<N> BitSet<N>::operator~() const noexcept
{
    return BitSet(*this).flip();
}

template<size_t N>
BitSet<N> operator&(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
    BitSet<N> retSet;

    for (size_t i = 0; i < lhs.capacity(); ++i) {
        retSet._data[i] = lhs._data[i] & rhs._data[i];
    }

    return retSet;
}

template<size_t N>
BitSet<N> operator|(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
    BitSet<N> retSet;

    for (size_t i = 0; i < lhs.capacity(); ++i) {
        retSet._data[i] = lhs._data[i] | rhs._data[i];
    }

    return retSet;
}

template<size_t N>
BitSet<N> operator^(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
    BitSet<N> retSet;

    for (size_t i = 0; i < lhs.capacity(); ++i) {
        retSet._data[i] = lhs._data[i] ^ rhs._data[i];
    }

    return retSet;
}

template<size_t N>
std::ostream& operator<<(std::ostream& os, const BitSet<N>& bs)
{
    return os << bs.to_string();
}

template<size_t N>
std::istream& operator>>(std::istream& is, BitSet<N>& bs)
{
    std::string inStr;
    is >> inStr;
    bs = BitSet<N>(inStr);
    return is;
}

template<size_t N>
auto BitSet<N>::BitReference::operator=(bool newValue) -> typename BitSet<N>::BitReference&
{
    *_origin &= ~(1ULL << _pos);
    *_origin |= static_cast<size_t>(newValue);
    return *this;
}

template<size_t N>
BitSet<N>::BitReference::operator bool() const
{
    return *_origin & (1ULL << _pos);
}

#endif // MYBITSET_H
