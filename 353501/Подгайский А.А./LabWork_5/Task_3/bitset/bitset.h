#ifndef BITSET_H_
#define BITSET_H_
#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <string>

template <size_t sz> class Bitset {
  static const uint8_t c_BlockSize = 8 * sizeof(uint64_t);
  static const size_t c_Blocks =
      sz % c_BlockSize == 0 ? sz / c_BlockSize : sz / c_BlockSize + 1;
  static const uint8_t c_EndBit =
      sz % c_BlockSize; // deal : not include end bit into data
  static const uint64_t c_MaxMidValue = std::numeric_limits<uint64_t>::max();
  static const uint64_t c_MaxLastValue =
      (c_EndBit == 0) ? c_MaxMidValue : (1ULL << c_EndBit) - 1ULL;

private:
  uint64_t * data = nullptr;

  class BitRef {
    uint64_t *ptr;
    uint8_t bit;
    friend class Bitset<sz>;

  private:
    BitRef(uint64_t *ptr_, int bit_) : ptr(ptr_), bit(bit_) {}

  public:
    BitRef operator=(bool val) {
      if (val)
        *ptr |= static_cast<uint64_t>(val << bit);
      else
        *ptr |= static_cast<uint64_t>(~(val << bit));
      return *this;
    }

    operator bool() { return static_cast<bool>((*ptr >> bit) & 0b1); }
  };

public:
  // -- Constructors --
  Bitset() {
    data = new uint64_t[c_Blocks];
    for (int i = 0; i < c_Blocks; ++i) {
      data[i] = 0;
    }
  }

  Bitset(const Bitset<sz> &other) {
    data = new uint64_t[c_Blocks];
    if (other.data != data) {
      for (int i = 0; i < c_Blocks; ++i) {
        data[i] = other.data;
      }
    }
  }

  Bitset(Bitset<sz> &&other) {
    this->data = other.data;
    other.data = nullptr;
  }

  ~Bitset() {
    if(data)
      delete[] data;
  }

public:
  // -- OPERTORS --
  bool operator[](size_t i) const { return test(i); }
  BitRef operator[](size_t i) {
    return BitRef(data + (i / c_BlockSize), i % c_BlockSize);
  }

  void operator~() { flip(); }

  Bitset<sz> operator|(const Bitset<sz> &other) {
    auto retval = *this;
    for (int i = 0; i < c_BlockSize; ++i) {
      retval.data[i] |= other.data[i];
    }
    return retval;
  }

  Bitset<sz> operator&(const Bitset<sz> &other) {
    auto retval = *this;
    for (int i = 0; i < c_BlockSize; ++i) {
      retval.data[i] &= other.data[i];
    }
    return retval;
  }

  size_t size() const{
    return sz;
  }

  bool all() const {

    for (int i = 0; i < c_Blocks - 1; ++i) {
      if (data[i] != c_MaxMidValue) {
        return false;
      }
    }
    return data[c_Blocks - 1] == c_MaxLastValue;
  }

  bool any() const {
    for (int i = 0; i < c_Blocks; ++i) {
      if (data[i] != 0ULL) {
        return true;
      }
    }
    return false;
  };

  bool none() const { return !any(); }

  size_t count() {
    size_t cnt = 0;
    for (size_t i = 0; i < c_Blocks; ++i) {
      // works faster since calls specific cpu instruction designed for it
      cnt += std::popcount(data[i]);
    }
    return cnt;
  }

  void flip() {
    for (int i = 0; i < c_Blocks - 1; ++i) {
      data[i] = ~data[i];
    }
    data[c_Blocks - 1] ^= c_MaxLastValue;
  }

  void flip(size_t i) { data[i / c_BlockSize] ^= (1ULL << (i % c_BlockSize)); }

  void reset() {
    for (int i = 0; i < c_BlockSize; ++i) {
      data[i] = 0ULL;
    }
  }

  void reset(size_t i) { data[i / c_BlockSize] &= ~(1ULL << (i % c_BlockSize)); }

  void set() {
    for (int i = 0; i < c_BlockSize - 1; ++i) {
      data[i] = c_MaxMidValue;
    }
    data[c_BlockSize - 1] = c_MaxLastValue;
  }

  void set(size_t i) { data[i / c_BlockSize] |= (1ULL << (i % c_BlockSize)); }

  bool test(size_t i) {
    return static_cast<bool>( (data[i / c_BlockSize] >> (i % c_BlockSize)) & 0b1);
  }

  std::string to_string() {
    std::string retval;
    retval.resize(sz);
    for (int i = 0; i < sz; ++i) {
      retval[i] = test(i) + '0';
    }
    return retval;
  }

  unsigned long long to_ullong() { return data[0]; }

  unsigned long to_ulong() { return data[0]; }
};

#endif // BITSET_H_