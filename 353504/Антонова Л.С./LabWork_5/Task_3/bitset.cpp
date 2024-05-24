#include "bitset.h"

template <size_t N>
void Bitset<N>::set(size_t pos) {
    if (pos < N) {
        bits[pos] = true;
    }
}

template <size_t N>
bool Bitset<N>::get(size_t pos) const {
    if (pos < N) {
        return bits[pos];
    }
    return false;
}

template <size_t N>
void Bitset<N>::set() {
    for (size_t i = 0; i < N; ++i) {
        bits[i] = true;
    }
}

template <size_t N>
void Bitset<N>::flip(size_t pos) {
    if (pos < N) {
        bits[pos] = !bits[pos];
    }
}

template <size_t N>
void Bitset<N>::flip() {
    for (size_t i = 0; i < N; ++i) {
        bits[i] = !bits[i];
    }
}

template <size_t N>
bool Bitset<N>::all() const {
    for (const auto& bit : bits) {
        if (!bit) {
            return false;
        }
    }
    return true;
}

template <size_t N>
bool Bitset<N>::any() const {
    for (const auto& bit : bits) {
        if (bit) {
            return true;
        }
    }
    return false;
}

template <size_t N>
bool Bitset<N>::none() const {
    return !any();
}

template <size_t N>
size_t Bitset<N>::count() const {
    size_t count = 0;
    for (const auto& bit : bits) {
        if (bit) {
            ++count;
        }
    }
    return count;
}

template <size_t N>
size_t Bitset<N>::getsize() const {
    return bits.size();
}

template <size_t N>
QString Bitset<N>::toString() const {
    QString str;
    for (const auto& bit : bits) {
        str += QString::number(bit) + ", ";
    }
    str.chop(2);
    return str;
}

template <size_t N>
unsigned long Bitset<N>::to_ulong() const {
    unsigned long value = 0;
    for (size_t i = 0; i < N; ++i) {
        if (bits[i]) {
            value |= 1UL << i;
        }
    }
    return value;
}

template <size_t N>
unsigned long long Bitset<N>::to_ullong() const {
    unsigned long long value = 0;
    for (size_t i = 0; i < N; ++i) {
        if (bits[i]) {
            value |= 1ULL << i;
        }
    }
    return value;
}

template <size_t N>
void Bitset<N>::reset() {
    for (size_t i = 0; i < N; ++i) {
        bits[i] = false;
    }
}

template <size_t N>
void Bitset<N>::reset(size_t pos) {
    if (pos < N) {
        bits[pos] = false;
    }
}

template <size_t N>
bool Bitset<N>::test(size_t pos) const {
    if (pos < N) {
        return bits[pos];
    }
    throw std::out_of_range("Bitset::test");
}
