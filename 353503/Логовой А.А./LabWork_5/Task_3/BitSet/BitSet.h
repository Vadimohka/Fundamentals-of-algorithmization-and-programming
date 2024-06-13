#ifndef BITSET_H
#define BITSET_H

#include<cstddef>
#include<cstdint>
#include<climits>
#include <QString>
#include <cstring>

template <size_t N>
class BitSet {
private:
    static constexpr size_t bits_per_long_long = sizeof(unsigned long long) * 8;
    uint64_t bits;
    void setBit(size_t index, bool value)
    {
        if (value)
        {
            bits |= (1ULL << index);
        }
        else
        {
            bits &= ~(1ULL << index);
        }
    }

    bool getBit(size_t index) const
    {
        return (bits & (1ULL << index)) != 0;
    }

public:
    
    BitSet() : bits(0) {}
    
    BitSet(unsigned long long value) : bits(value & ((1ULL << std::min(N, bits_per_long_long)) - 1)) {}

    bool operator[](size_t index) const
    {
        return getBit(index);
    }

    bool& operator[](size_t index)
    {
        return const_cast<bool&>(const_cast<const BitSet<N>*>(this)->getBit(index));
    }

    bool all() const
    {
        unsigned long long mask = (1ULL << std::min(N, bits_per_long_long)) - 1;
        return (bits & mask) == mask;
    }

    bool any() const
    {
        return bits != 0;
    }

    size_t count() const
    {
        size_t cnt = 0;
        unsigned long long value = bits;
        for (size_t i = 0; i < std::min(N, bits_per_long_long); ++i)
        {
            if (value & (1ULL << i))
            {    
                ++cnt;
            }
        }
        return cnt;
    }

    BitSet<N>& flip()
    {
        unsigned long long mask = (1ULL << std::min(N, bits_per_long_long)) - 1;
        bits = (~bits) & mask;
        return *this;
    }

    BitSet<N>& flip(size_t pos)
    {
        if (pos < N) {
            setBit(pos, !getBit(pos));
        }
        return *this;
    }

    bool none() const
    {
        return !any();
    }

    BitSet<N>& reset()
    {
        bits = 0;
        return *this;
    }

    BitSet<N>& reset(size_t pos)
    {
        if (pos < N) {
            setBit(pos, false);
        }
        return *this;
    }

    BitSet<N>& set()
    {
        unsigned long long mask = (1ULL << std::min(N, bits_per_long_long)) - 1;
        bits = mask;
        return *this;
    }

    BitSet<N>& set(size_t pos, bool value = true)
    {
        if (pos < N)
        {
            setBit(pos, value);
        }
        return *this;
    }

    constexpr size_t size() const
    {
        return N;
    }

    bool test(size_t pos) const
    {
        if (pos < N)
        {
            return getBit(pos);
        }
        return false;
    }

    QString to_string() const
    {
        QString s(N, '0');
        for (size_t i = 0; i < std::min(N, bits_per_long_long); ++i) {
            s[N - i - 1] = getBit(i) ? '1' : '0';
        }
        return s;
    }

    unsigned long long to_ullong() const
    {
        unsigned long long mask = (1ULL << std::min(N, bits_per_long_long)) - 1;
        return bits & mask;
    }

    unsigned long to_ulong() const
    {
        return static_cast<unsigned long>(to_ullong());
    }

    BitSet<N> operator~() const
    {
        BitSet<N> result(*this);
        result.flip();
        return result;
    }

    BitSet<N> operator&(const BitSet<N>& other) const
    {
        BitSet<N> result;
        result.bits = bits & other.bits;
        return result;
    }

    BitSet<N> operator|(const BitSet<N>& other) const {

        BitSet<N> result;
        result.bits = bits | other.bits;
        return result;
    }
};

#endif // BITSET_H
