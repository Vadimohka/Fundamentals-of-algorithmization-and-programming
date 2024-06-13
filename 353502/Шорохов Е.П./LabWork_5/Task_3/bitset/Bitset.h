//
// Created by shosh on 5/25/24.
//

#ifndef LABWORK_5_BITSET_H
#define LABWORK_5_BITSET_H
#include "QString"

template<size_t count_of_bits>
class bitset {
    int countOfOnes;
    QString* BitsArray = nullptr;
    QString* ReversedBitsArray = nullptr;
public:
    bitset();
    bool all();
    bool test(uint i);
    bool any();
    bool none();
    void set(uint i);
    void set();
    size_t size();
    int count();
    void flip(uint i);
    void flip();
    bool operator[](uint pos) const;
    bitset& operator&=(const bitset &test);
    bitset& operator|=(const bitset &test);
    bitset& operator^=(const bitset &test);
    bitset<count_of_bits>& operator=(const bitset& initializer);
};

template<size_t count_of_bits>
bitset<count_of_bits>& bitset<count_of_bits>::operator^=(const bitset &test) {
    for (uint i = 0; i < size(); i++) {
        (*BitsArray)[i] = (*BitsArray)[i].unicode() % 2 &= test[i];
        (*BitsArray)[i] = (*BitsArray)[i].unicode() + '0';
        (*ReversedBitsArray)[i] = (*BitsArray)[i].unicode() - (*BitsArray)[i].unicode() % 2;
    }
    return *this;
}

template<size_t count_of_bits>
bitset<count_of_bits>& bitset<count_of_bits>::operator|=(const bitset &test) {
    for (uint i = 0; i < size(); i++) {
        (*BitsArray)[i] = (*BitsArray)[i].unicode() % 2 |= test[i];
        (*BitsArray)[i] = (*BitsArray)[i].unicode() + '0';
        (*ReversedBitsArray)[i] = (*BitsArray)[i].unicode() - (*BitsArray)[i].unicode() % 2;
    }
    return *this;
}

template<size_t count_of_bits>
bitset<count_of_bits>& bitset<count_of_bits>::operator&=(const bitset &test) {
    for (uint i = 0; i < size(); i++) {
        (*BitsArray)[i] = (*BitsArray)[i].unicode() % 2 &= test[i];
        (*BitsArray)[i] = (*BitsArray)[i].unicode() + '0';
        (*ReversedBitsArray)[i] = (*BitsArray)[i].unicode() - (*BitsArray)[i].unicode() % 2;
    }
    return *this;
}

template<size_t count_of_bits>
bool bitset<count_of_bits>::operator[](uint pos) const {
    return (*BitsArray)[pos] == QChar('1');
}

template<size_t count_of_bits>
bitset<count_of_bits> &bitset<count_of_bits>::operator=(const bitset &initializer) {
    if (initializer != this) {
        for (int i = 0; i < count(); i++) {
           BitsArray[i] = QChar('0') + initializer[i];
           ReversedBitsArray[i] = QChar('1') - initializer[i];
        }
    }
    return *this;
}

template<size_t count_of_bits>
int bitset<count_of_bits>::count() {
    return countOfOnes;
}

template<size_t count_of_bits>
bool bitset<count_of_bits>::all() {
    return count_of_bits == countOfOnes;
}

template<size_t count_of_bits>
void bitset<count_of_bits>::flip() {
   std::swap(ReversedBitsArray,BitsArray);
}

template<size_t count_of_bits>
void bitset<count_of_bits>::flip(uint i) {
    if (BitsArray[i] == '1') {
        (*BitsArray)[i] = QChar('0');
    } else {
        (*BitsArray)[i] = QChar('1');
    }
}

template<size_t count_of_bits>
size_t bitset<count_of_bits>::size() {
    return count_of_bits;
}

template<size_t count_of_bits>
bool bitset<count_of_bits>::none() {
    return countOfOnes == 0;
}

template<size_t count_of_bits>
bool bitset<count_of_bits>::any() {
    return countOfOnes > 0;
}

template<size_t count_of_bits>
void bitset<count_of_bits>::set(uint i) {
    (*BitsArray)[i] = QChar('1');
    (*ReversedBitsArray)[i] = QChar('1');
    countOfOnes++;
}

template<size_t count_of_bits>
void bitset<count_of_bits>::set() {
    countOfOnes = count_of_bits;
    for (int i = 0; i < BitsArray->size(); i++) {
        (*BitsArray)[i] = QChar('1');
        (*ReversedBitsArray)[i] = QChar('0');
    }
}

template<size_t count_of_bits>
bool bitset<count_of_bits>::test(uint i) {
    return (*BitsArray)[i].unicode() % 2;
}

template <size_t count_of_bits>
bitset<count_of_bits>::bitset() {
    BitsArray = new QString(count_of_bits, '0');
    ReversedBitsArray = new QString(count_of_bits, '1');
    countOfOnes = 0;
}

#endif //LABWORK_5_BITSET_H
