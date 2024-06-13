#include "reference.h"
#include <cstdint>

bool_ref::bool_ref(uint64_t& set, uint32_t bit_pos) : value(set) {
    this->bit_position = bit_pos;
    this->bit = (this->value & (1 << this->bit_position)) >> this->bit_position;
}

bool_ref::operator bool() const {
    return this->bit;
}

bool_ref& bool_ref::operator=(bool rhs) {
    uint64_t mask = 1 << bit_position;
    if (rhs) {
        this->value |= mask;
    } else {
        this->value &= (~mask);
    }
    this->bit = rhs;
    return *this;
}

bool_ref& bool_ref::operator=(const bool_ref& rhs) {
    this->value = rhs.value;
    this->bit = rhs.bit;
    this->bit_position = rhs.bit_position;
    return *this;
}

bool bool_ref::operator~() const {
    return !this->bit;
}

bool_ref& bool_ref::flip() {
    if (*this) {
        *this = false;
    } else {
        *this = true;
    }
    return *this;
}
