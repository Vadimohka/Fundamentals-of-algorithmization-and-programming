#include "mybitset.h"
#include <sys/types.h>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <stdexcept>
#include <system_error>

MyBitset::MyBitset(uint32_t bits) {
    this->vals = std::vector<uint64_t>(bits / SET_SIZE + 1, 0);
    this->len = bits;
    this->sets = bits / SET_SIZE + 1;
}

MyBitset::MyBitset(uint32_t bits, uint64_t val) {
    this->sets = bits / SET_SIZE + 1;
    this->vals = std::vector<uint64_t>(bits / SET_SIZE + 1, 0);
    this->len = bits;
    this->vals[0] = val;
}

MyBitset::MyBitset(const MyBitset& other) {
    this->len = other.len;
    this->sets = other.sets;
    this->vals = std::vector<uint64_t>(this->sets);
    std::copy(other.vals.begin(), other.vals.end(), this->vals.begin());
}

MyBitset::MyBitset(const std::string& str) {
    this->sets = str.length() / SET_SIZE + 1;
    this->vals = std::vector<uint64_t>(this->sets, 0);
    this->len = str.length();
    for (int i = str.length() - 1; i >= 0; ++i) {
        if (str[i] == '1') {
            this[i] = 1;
        } else if (str[i] == '0') {
            this[i] = 0;
        } else {
            throw new std::invalid_argument("nah");
        }
    }
}

MyBitset& MyBitset::operator=(const MyBitset& rhs) {
    this->len = rhs.len;
    this->sets = rhs.sets;
    std::copy(rhs.vals.begin(), rhs.vals.end(), this->vals.begin());
    return *this;
}

MyBitset MyBitset::operator~() const {
    MyBitset new_bitset(*this);
    for (uint64_t& set : new_bitset.vals) {
        set = ~set;
    }
    return new_bitset;
}

MyBitset& MyBitset::operator&=(const MyBitset& rhs) {
    for (uint32_t i = 0; i < std::min(rhs.sets, this->sets); ++i) {
        this->vals[i] &= rhs.vals[i];
    }
    return *this;
}

MyBitset& MyBitset::operator|=(const MyBitset& rhs) {
    for (uint32_t i = 0; i < std::min(rhs.sets, this->sets); ++i) {
        this->vals[i] |= rhs.vals[i];
    }
    return *this;
}

void MyBitset::bitshift_base_left(uint32_t n) {
    if (this->sets <= n) {
        for (auto& set : this->vals) {
            set = 0;
        }
    } else {
        for (int32_t i = this->sets - n; i >= 0; --i) {
            this->vals[i + n] = this->vals[i];
            this->vals[i] = 0;
        }
    }
}

void MyBitset::bitshift_base_right(uint32_t n) {
    if (this->sets <= n) {
        for (auto& set : this->vals) {
            set = 0;
        }
    } else {
        for (int32_t i = this->sets - n; i >= 0; --i) {
            this->vals[i] = this->vals[i + n];
            this->vals[i + n] = 0;
        }
    }
}

MyBitset& MyBitset::operator<<(uint32_t n) {
    if (n <= 0) {
        return *this;
    } else if (n <= SET_SIZE) {
        this->vals[this->sets - 1] <<= n;
        for (int64_t set = (int64_t)this->sets - 2; set >= 0; --set) {
            uint64_t mask = 0;
            for (int i = 0; i < n; ++i) {
                mask |= 1 << ((SET_SIZE - 1) - i);
            }
            mask &= this->vals[set];
            mask >>= SET_SIZE - n;
            this->vals[set + 1] |= mask;
            this->vals[set] <<= n;
        }
    } else {
        this->bitshift_base_left(n / SET_SIZE);
        return *this << (n - SET_SIZE);
    }
    return *this;
}

MyBitset& MyBitset::operator>>(uint32_t n) {
    if (n <= 0) {
        return *this;
    } else if (n <= SET_SIZE) {
        this->vals[0] >>= n;
        for (int64_t set = 1; set < this->sets; ++set) {
            uint64_t mask = 0;
            for (int i = 0; i < n; ++i) {
                mask |= 1 << i;
            }
            mask &= this->vals[set];
            mask <<= SET_SIZE - n;
            this->vals[set - 1] |= mask;
            this->vals[set] <<= n;
        }
    } else {
        this->bitshift_base_right(n / SET_SIZE);
        return *this >> (n - SET_SIZE);
    }
    return *this;
}

bool MyBitset::operator[](uint32_t i) const {
    if (i < 0 || i >= this->len) {
        throw std::out_of_range("no");
    }
    uint32_t set_number = i / SET_SIZE;
    uint32_t bit_index = i % SET_SIZE;
    uint64_t mask = (1 << bit_index);
    uint64_t res = (this->vals[set_number] & mask) >> bit_index;
    return res == 1;
}

bool_ref MyBitset::operator[](uint32_t i) {
    bool_ref ref(this->vals[i / SET_SIZE], i);
    return ref;
}

bool MyBitset::all() const {
    for (auto set : this->vals) {
        if (set != LLONG_MAX) {
            return false;
        }
    }
    return true;
}

bool MyBitset::any() const {
    for (auto set : this->vals) {
        if (set != 0) {
            return true;
        }
    }
    return false;
}

uint32_t MyBitset::count() const {
    uint32_t res = 0;
    for (auto set : this->vals) {
        res += (set & 1);
        set /= 2;
    }
    return res;
}

void MyBitset::flip() {
    *this = ~(*this);
}

void MyBitset::flip(uint32_t i) {
    if (i < 0 || i >= this->len) {
        throw std::out_of_range("no");
    }
    this[i].flip();
}

bool MyBitset::none() const {
    return !this->any();
}

void MyBitset::reset() {
    for (auto& set : this->vals) {
        set = 0;
    }
}

void MyBitset::reset(uint32_t i) {
    (*this)[i] = 0;
}

void MyBitset::set() {
    for (auto& set : this->vals) {
        set = ULLONG_MAX;
    }
}

void MyBitset::set(uint32_t i) {
    (*this)[i] = 1;
}

uint32_t MyBitset::size() const {
    return this->len;
}

bool MyBitset::test(uint32_t i) const {
    return (*this)[i] == 1;
}

uint64_t MyBitset::to_ullong() const {
    return (uint64_t)this->count();
}

uint32_t MyBitset::to_ulong() const {
    return (uint32_t)this->vals[0];
}

std::string MyBitset::to_string() const {
    std::string res;
    uint32_t total_bits = this->len;
    for (auto set : vals) {
        for (int i = 0; i < std::min(total_bits, SET_SIZE); ++i) {
            res.push_back('0' + (set & 1));
            set >>= 1;
        }
        total_bits -= SET_SIZE;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
