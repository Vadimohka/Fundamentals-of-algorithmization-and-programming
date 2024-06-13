#ifndef MYBITSET_H
#define MYBITSET_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>

const size_t ULLONG_BITS = sizeof(size_t);

template<std::size_t N>
class MyBitset
{
private:
    size_t *_data;

    struct BitRef
    {
        size_t *_ptr;
        unsigned _pos;

        constexpr BitRef(size_t *ptr, int8_t pos)
            : _ptr(ptr)
            , _pos(pos)
        {}
        constexpr BitRef &operator=(const BitRef &value)
        {
            *this = bool(value);
            return *this;
        }
        constexpr BitRef &operator=(bool value)
        {
            if ((((*_ptr) >> _pos) & 1ULL) != value) {
                *_ptr ^= 1ULL << _pos;
            }
            return *this;
        }
        constexpr BitRef &flip()
        {
            *this = bool(*this);
            return *this;
        }
    };

    constexpr size_t capacity() const noexcept;

public:
    MyBitset();
    MyBitset(const MyBitset &other);
    MyBitset(MyBitset &&other) noexcept = default;
    explicit MyBitset(unsigned long val);
    explicit MyBitset(std::string val, char zero = '0', char one = '1');

    MyBitset &operator=(const MyBitset &other);
    MyBitset &operator=(MyBitset &&other) noexcept;

    constexpr bool operator==(const MyBitset &rhs) const noexcept;
    constexpr bool operator!=(const MyBitset &rhs) const noexcept;

    constexpr bool operator[](std::size_t pos) const;
    constexpr BitRef operator[](std::size_t pos);

    constexpr bool test(std::size_t pos) const;

    constexpr bool all() const noexcept;
    constexpr bool any() const noexcept;
    constexpr bool none() const noexcept;

    constexpr std::size_t count() const noexcept;

    constexpr MyBitset<N> &operator&=(const MyBitset<N> &other) noexcept;
    constexpr MyBitset<N> &operator|=(const MyBitset<N> &other) noexcept;
    constexpr MyBitset<N> &operator^=(const MyBitset<N> &other) noexcept;
    constexpr MyBitset<N> &operator~() noexcept;

    constexpr MyBitset<N> operator<<(std::size_t pos) const noexcept;
    constexpr MyBitset<N> &operator<<=(std::size_t pos) const noexcept;
    constexpr MyBitset<N> operator>>(std::size_t pos) const noexcept;
    constexpr MyBitset<N> &operator>>=(std::size_t pos) const noexcept;

    constexpr MyBitset<N> &set() noexcept;
    constexpr MyBitset<N> &set(std::size_t pos, bool value = true);

    constexpr MyBitset<N> &reset() noexcept;
    constexpr MyBitset<N> &reset(std::size_t pos);

    constexpr MyBitset<N> &flip() noexcept;
    constexpr MyBitset<N> &flip(std::size_t pos);

    std::string to_string(char zero = '0', char one = '1') const;
    unsigned long to_ulong() const;
    unsigned long long to_ullong() const;
};

template<std::size_t N>
MyBitset<N>::MyBitset()
    : _data(new size_t[capacity()])
{}

template<std::size_t N>
MyBitset<N>::MyBitset(const MyBitset<N> &other)
    : _data(new size_t[capacity()])
{
    std::uninitialized_copy(other._data, other._data + capacity(), _data);
}

template<std::size_t N>
constexpr size_t MyBitset<N>::capacity() const noexcept
{
    return N / ULLONG_BITS + (N % ULLONG_BITS != 0);
}

template<std::size_t N>
MyBitset<N>::MyBitset(unsigned long val)
    : _data(new size_t(val))
{}

template<std::size_t N>
MyBitset<N>::MyBitset(std::string val, char zero, char one)
{
    size_t size = val.size();

    if (size != N) {
        throw std::invalid_argument("Length of string is not equal to length of bitset");
    }

    _data = new size_t[capacity()];

    for (int i = 0; i < size; i++) {
        if (val[i] == zero) {
            reset(i);
        } else if (val[i] == one) {
            set(i);
        } else {
            throw std::invalid_argument("String contains invalid characters");
        }
    }
}

template<std::size_t N>
MyBitset<N> &MyBitset<N>::operator=(const MyBitset &other)
{
    if (this == &other) {
        return *this;
    }

    std::uninitialized_copy(other._data, other._data + capacity(), _data);
    return *this;
}

template<std::size_t N>
MyBitset<N> &MyBitset<N>::operator=(MyBitset &&other) noexcept
{
    std::uninitialized_move(other._data, other._data + capacity(), _data);
    return *this;
}

template<std::size_t N>
constexpr bool MyBitset<N>::operator==(const MyBitset &rhs) const noexcept
{
    size_t cap = capacity();

    if (cap != rhs.capacity()) {
        return false;
    }

    for (int i = 0; i < cap; ++i) {
        if (_data[i] != rhs._data[i]) {
            return false;
        }
    }

    return true;
}

template<std::size_t N>
constexpr bool MyBitset<N>::operator!=(const MyBitset &rhs) const noexcept
{
    return !(*this == rhs);
}

template<std::size_t N>
constexpr bool MyBitset<N>::operator[](std::size_t pos) const
{
    return (_data[pos / ULLONG_BITS] >> (pos % ULLONG_BITS)) & 1ULL;
}

template<std::size_t N>
constexpr bool MyBitset<N>::test(std::size_t pos) const
{
    if (pos < 0 || pos >= N) {
        std::out_of_range("Index is out of range");
    }

    return this[pos];
}

template<std::size_t N>
constexpr bool MyBitset<N>::all() const noexcept
{
    size_t cap = capacity();
    for (int i = 0; i < cap; ++i) {
        if (_data[i] != ~(0ULL)) {
            return false;
        }
    }

    return true;
}

template<std::size_t N>
constexpr bool MyBitset<N>::any() const noexcept
{
    size_t cap = capacity();
    for (int i = 0; i < cap; ++i) {
        if (_data[i] != 0ULL) {
            return true;
        }
    }

    return false;
}

template<std::size_t N>
constexpr bool MyBitset<N>::none() const noexcept
{
    return !any();
}

template<std::size_t N>
constexpr std::size_t MyBitset<N>::count() const noexcept
{
    size_t cap = capacity();
    size_t count = 0;

    for (int i = 0; i < cap - 1; ++i) {
        count += __builtin_popcountll(_data[i]);
    }

    for (int i = (cap - 1) * ULLONG_BITS; i < N; ++i) {
        count += (*this)[i];
    }

    return count;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator&=(const MyBitset<N> &other) noexcept
{
    size_t cap = capacity();

    for (int i = 0; i < cap; ++i) {
        _data[i] &= other._data[i];
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator|=(const MyBitset<N> &other) noexcept
{
    size_t cap = capacity();

    for (int i = 0; i < cap; ++i) {
        _data[i] |= other._data[i];
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator^=(const MyBitset<N> &other) noexcept
{
    size_t cap = capacity();

    for (int i = 0; i < cap; ++i) {
        _data[i] ^= other._data[i];
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator~() noexcept
{
    size_t cap = capacity();

    for (int i = 0; i < cap; ++i) {
        _data[i] = ~_data[i];
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> MyBitset<N>::operator<<(std::size_t pos) const noexcept
{
    return MyBitset<N>(this) <<= pos;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator<<=(std::size_t pos) const noexcept
{
    for (int i = 0; i + pos < N; ++i) {
        set(i, this[i + pos]);
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> MyBitset<N>::operator>>(std::size_t pos) const noexcept
{
    return MyBitset<N>(this) >>= pos;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::operator>>=(std::size_t pos) const noexcept
{
    for (int i = N - 1; i - pos >= 0; --i) {
        set(i, this[i - pos]);
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::set() noexcept
{
    size_t cap = capacity();
    for (int i = 0; i < cap; ++i) {
        _data[i] = ~(0ULL);
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::set(std::size_t pos, bool value)
{
    (*this)[pos] = value;

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::reset() noexcept
{
    size_t cap = capacity();
    for (int i = 0; i < cap; ++i) {
        _data[i] = 0ULL;
    }

    return *this;
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::reset(std::size_t pos)
{
    return set(pos, false);
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::flip() noexcept
{
    return (*this) = ~(*this);
}

template<std::size_t N>
constexpr MyBitset<N> &MyBitset<N>::flip(std::size_t pos)
{
    return set(pos, ~this[pos]);
}

template<std::size_t N>
std::string MyBitset<N>::to_string(char zero, char one) const
{
    std::string answer = "";
    for (int i = 0; i < N; i++) {
        if ((*this)[i] == false) {
            answer += zero;
        } else {
            answer += one;
        }
    }

    return answer;
}

template<std::size_t N>
unsigned long MyBitset<N>::to_ulong() const
{
    unsigned long answer = 0;

    for (int i = 0; i < N; ++i) {
        answer += this[i] << i;
    }

    return answer;
}

template<std::size_t N>
unsigned long long MyBitset<N>::to_ullong() const
{
    return _data[0];
}

template<std::size_t N>
constexpr typename MyBitset<N>::BitRef MyBitset<N>::operator[](std::size_t pos)
{
    return BitRef(_data + (pos / ULLONG_BITS), pos % ULLONG_BITS);
}

template<std::size_t N>
constexpr MyBitset<N> operator&(const MyBitset<N> &lhs, const MyBitset<N> &rhs)
{
    return MyBitset<N>(lhs) &= rhs;
}

template<std::size_t N>
constexpr MyBitset<N> operator|(const MyBitset<N> &lhs, const MyBitset<N> &rhs)
{
    return MyBitset<N>(lhs) |= rhs;
}

template<std::size_t N>
constexpr MyBitset<N> operator^(const MyBitset<N> &lhs, const MyBitset<N> &rhs)
{
    return MyBitset<N>(lhs) ^= rhs;
}

template<std::size_t N>
std::ostream &operator<<(std::ostream &out, const MyBitset<N> &bs)
{
    return out << bs.to_string();
}

template<std::size_t N>
std::istream &operator>>(std::istream &in, MyBitset<N> &bs)
{
    std::string input;
    in >> input;
    bs = MyBitset<N>(input);
    return in;
}

#endif // MYBITSET_H
