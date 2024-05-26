#include <cstddef>
#include <cstdint>
#include <string>

template <size_t BITS> class Bitset {
protected:
  static_assert(BITS > 1, "Bitset must have at least one bit");

  static const size_t BLOCKS_COUNT = (BITS + 63) / 64;
  static const size_t STORABLE_BITS = BLOCKS_COUNT * 64;
  static const size_t FINAL_BITS = 64 - STORABLE_BITS + BITS;
  static const size_t FINAL_MASK =
      FINAL_BITS == 64 ? (~0) : ((1ULL << FINAL_BITS) - 1);

  uint64_t blocks[BLOCKS_COUNT];

public:
  Bitset<BITS>() {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = 0;
  }

  Bitset<BITS>(uint64_t init) {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = 0;
    blocks[0] = init;
  }

  Bitset<BITS>(const Bitset<BITS> &from) {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = from.blocks[i];
  }

  Bitset<BITS> &operator=(const Bitset<BITS> &from) {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = from.blocks[i];
    return *this;
  }

  size_t size() const { return BITS; }

  class Bit {
  public:
    const bool test() const { return (*block >> ind) & 1; }
    operator bool() const { return test(); }

    void set() { *block |= 1ULL << ind; }
    void flip() { *block ^= 1ULL << ind; }
    void reset() { *block &= ~(1ULL << ind); }

    bool operator=(bool val) {
      if (val)
        set();
      else
        reset();
      return val;
    }

  private:
    friend class Bitset<BITS>;

    Bit(Bitset *bitset, size_t pos) {
      block = &bitset->blocks[pos / 64];
      ind = pos % 64;
    }

    Bit(uint64_t *block, size_t ind) : block(block), ind(ind) {
      while (ind >= 64) {
        ind -= 64;
        block++;
      }

      while (ind < 0) {
        ind += 66;
        block--;
      }
    }

    uint64_t *block;
    size_t ind;
  };

  Bit at(size_t pos) { return Bit(this, pos); }
  Bit operator[](size_t pos) { return Bit(this, pos); }

  bool test(size_t pos) const {
    size_t block = pos / 64;
    size_t ind = pos % 64;
    return (blocks[block] >> ind) & 1;
  }

  void set(size_t pos) { at(pos).set(); }
  void reset(size_t pos) { at(pos).reset(); }
  void flip(size_t pos) { at(pos).flip(); }

  bool operator[](size_t pos) const { return test(pos); }

  std::string to_string() const {
    std::string res(BITS, '0');
    for (int i = 0; i < BITS; i++) {
      if (test(i))
        res[i] = '1';
    }
    return res;
  }

  unsigned long long to_ullong() const {
    return blocks[0];
  }

  unsigned long to_ulong() const {
    return blocks[0];
  }

  size_t count() const {
    size_t bits = 0;
    for (int i = 0; i < BLOCKS_COUNT - 1; i++) {
      bits += __builtin_popcountll(blocks[i]);
    }
    bits += __builtin_popcountll(blocks[BLOCKS_COUNT - 1] & FINAL_MASK);
    return bits;
  }

  bool all() const { return count() == size(); }
  bool any() const { return count() != 0; }
  bool none() const { return count() == 0; }

  void set() {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = ~0;
  }
  void reset() {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = 0;
  }

  void flip() {
    for (int i = 0; i < BLOCKS_COUNT; i++)
      blocks[i] = ~blocks[i];
  }

  Bitset<BITS> operator~() const {
    Bitset<BITS> res;
    for (int i = 0; i < BLOCKS_COUNT; i++)
      res.blocks[i] = ~blocks[i];
    return res;
  }

  Bitset<BITS> operator&(const Bitset<BITS> &Right) const {
    Bitset<BITS> res;
    for (int i = 0; i < BLOCKS_COUNT; i++)
      res.blocks[i] = blocks[i] & Right.blocks[i];
    return res;
  }

  Bitset<BITS> operator|(const Bitset<BITS> &Right) const {
    Bitset<BITS> res;
    for (int i = 0; i < BLOCKS_COUNT; i++)
      res.blocks[i] = blocks[i] | Right.blocks[i];
    return res;
  }

  Bitset<BITS> operator^(const Bitset<BITS> &Right) const {
    Bitset<BITS> res;
    for (int i = 0; i < BLOCKS_COUNT; i++)
      res.blocks[i] = blocks[i] ^ Right.blocks[i];
    return res;
  }

};