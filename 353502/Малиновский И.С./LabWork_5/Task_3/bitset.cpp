#include "bitset.h"
#include <stdexcept>

BitSet::BitSet(size_t size) {
    if (size > 64) {
        throw std::out_of_range("Size exceeds maximum allowed bitset size of 64.");
    }
    bits = std::bitset<64>();
}

bool BitSet::all() const {
    return bits.all();
}

bool BitSet::any() const {
    return bits.any();
}

size_t BitSet::count() const {
    return bits.count();
}

void BitSet::flip(size_t pos) {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    bits.flip(pos);
}

void BitSet::flip() {
    bits.flip();
}

bool BitSet::none() const {
    return bits.none();
}

void BitSet::reset(size_t pos) {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    bits.reset(pos);
}

void BitSet::reset() {
    bits.reset();
}

void BitSet::set(size_t pos) {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    bits.set(pos);
}

void BitSet::set() {
    bits.set();
}

size_t BitSet::size() const {
    return bits.size();
}

bool BitSet::test(size_t pos) const {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    return bits.test(pos);
}

std::string BitSet::to_string() const {
    return bits.to_string();
}

unsigned long BitSet::to_ulong() const {
    return bits.to_ulong();
}

unsigned long long BitSet::to_ullong() const {
    return bits.to_ullong();
}

bool BitSet::operator[](size_t pos) const {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    return bits[pos];
}

bool BitSet::operator[](size_t pos) {
    if (pos >= bits.size()) throw std::out_of_range("Index out of range");
    return bits[pos];
}
