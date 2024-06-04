#include "Bitset.h"
#include <cstddef>
#include <cstdint>

Bitset::Bitset(size_t size) : m_size(size) {
    size_t arrSize = (SIZE + size - 1) / SIZE;
    m_data = new uint16_t[arrSize];

    for (int i = 0; i < arrSize; ++i) {
        m_data[i] = 0;
    }
}

bool Bitset::operator[](int pos) const {
    return test(pos);
}

bool &Bitset::operator[](int pos) {
    static bool val = false;
    if (pos < 0 || pos >= m_size) {
        return val;
    }

    return (bool&)(m_data[pos / SIZE] |= (1 << (pos % SIZE)));
}


void Bitset::set(int pos) {
    if (pos >= 0 && pos < m_size) {
        m_data[pos / SIZE] |= (1 << (pos % SIZE));
    }
}

void Bitset::set() {
    for (int i = 0; i < m_size; ++i) {
        m_data[i / SIZE] |= (1 << (i % SIZE));
    }
}

void Bitset::reset(int pos) {
    if (pos >= 0 && pos < m_size) {
        m_data[pos / SIZE] &= ~(1 << (pos % SIZE));
    }
}

void Bitset::reset() {
    for (int i = 0; i < m_size; ++i) {
        m_data[i / SIZE] &= ~(1 << (i % SIZE));
    }
}

bool Bitset::test(int pos) const {
    return (pos >= 0 && pos < m_size) &&
           (m_data[pos / SIZE] & (1 << (pos % SIZE)));
}

void Bitset::flip(int pos) {
    if (pos >= 0 && pos < m_size) {
        m_data[pos / SIZE] ^= (1 << (pos % SIZE));
    }
}

void Bitset::flip() {
    for (int i = 0; i < m_size; ++i) {
        m_data[i / SIZE] ^= (1 << (i % SIZE));
    }
}

bool Bitset::all() const {
    int fullSizedBlocks = m_size / SIZE;
    int partialSizedBlock = m_size % SIZE;
    for (int i = 0; i < fullSizedBlocks; ++i) {
        if (m_data[i] != (uint16_t)((1 << SIZE) - 1))
            return false;
    }

    if (partialSizedBlock > 0) {
        uint16_t block = (1 << partialSizedBlock) - 1;
        if (m_data[fullSizedBlocks] != block) {
            return false;
        }
    }
    return true;
}

bool Bitset::any() const {
    for (int i = 0; i < (SIZE + m_size - 1) / SIZE; ++i) {
        if (m_data[i] != 0) {
            return true;
        }
    }
    return false;
}

bool Bitset::none() const {
    return !any();
}

int Bitset::count() const {
    int n = 0;
    for (int i = 0; i < (SIZE + m_size - 1) / SIZE; ++i) {
        uint16_t value = m_data[i];
        while (value) {
            n += (value & 1);
            value >>= 1;
        }
    }
    return n;
}

QString Bitset::to_string() const {
    QString str;
    for (int i = m_size - 1; i >= 0; --i) {
        str += (test(i) ? '1' : '0');
    }
    return str;
}

unsigned long Bitset::to_ulong() const {
    unsigned long value = 0;
    for (int i = m_size - 1; i >= 0; --i) {
        if (test(i))
            value |= (1UL << i);
    }

    return value;
}

unsigned long long Bitset::to_ullong() const {
    unsigned long long value = 0;
    for (int i = m_size - 1; i >= 0; --i) {
        if (test(i))
            value |= (1ULL << i);
    }

    return value;
}
