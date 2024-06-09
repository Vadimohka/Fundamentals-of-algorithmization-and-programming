#include <iostream>
#include <string>

template<size_t BITS>
class Bitset {
private:
    static constexpr size_t BLOCK_SIZE = 64;
    static constexpr size_t BLOCKS_COUNT = (BITS + BLOCK_SIZE - 1) / BLOCK_SIZE;
    static constexpr size_t STORABLE_BITS = BLOCKS_COUNT * BLOCK_SIZE;
    static constexpr size_t FINAL_BITS = BITS % BLOCK_SIZE;
    static constexpr uint64_t FINAL_MASK = (FINAL_BITS == 0) ? 0 : ((1ULL << FINAL_BITS) - 1);

    uint64_t blocks[BLOCKS_COUNT];

public:
    size_t size(){
        return BITS;
    }
 
    Bitset(): blocks{} {}

    Bitset(uint64_t init): blocks{} {
        blocks[0] = init;
    }

    Bitset(const Bitset& other) {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] = other.blocks[i];
        }
    }


    class Bit {
    private:
        Bitset& bitset;
        size_t pos;

    public:
        Bit(Bitset& b, size_t p): bitset(b), pos(p) {}

        operator bool() const {
            return bitset[pos];
        }

        Bit& operator=(bool value) {
            bitset[pos] = value;
            return *this;
        }
    };

    Bit at(size_t pos) {
        return Bit(*this, pos);
    }

    bool operator[](size_t pos) const {
        return (blocks[pos / BLOCK_SIZE] >> (pos % BLOCK_SIZE)) & 1;
    }


    void set(size_t pos) {
        blocks[pos / BLOCK_SIZE] |= (1ULL << (pos % BLOCK_SIZE));
    }

    void reset(size_t pos) {
        blocks[pos / BLOCK_SIZE] &= ~(1ULL << (pos % BLOCK_SIZE));
    }

    void flip(size_t pos) {
        blocks[pos / BLOCK_SIZE] ^= (1ULL << (pos % BLOCK_SIZE));
    }


    std::string to_string() const {
        std::string str;
        for (size_t i = 0; i < BITS; ++i) {
            str += (*this)[i] ? '1' : '0';
        }
        return str;
    }

    uint64_t to_ullong() const {
        uint64_t result = 0;
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            result |= (blocks[i] << (i * BLOCK_SIZE));
        }
        return result;
    }


    size_t count() const {
        size_t count = 0;
        for (size_t i = 0; i < BITS; ++i) {
            if ((*this)[i]) {
                ++count;
            }
        }
        return count;
    }

    bool all() const {
        for (size_t i = 0; i < BITS; ++i) {
            if (!(*this)[i]) {
                return false;
            }
        }
        return true;
    }

    bool any() const {
        for (size_t i = 0; i < BITS; ++i) {
            if ((*this)[i]) {
                return true;
            }
        }
        return false;
    }

    bool none() const {
        for (size_t i = 0; i < BITS; ++i) {
            if ((*this)[i]) {
                return false;
            }
        }
        return true;
    }

   
    void set() {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] = UINT64_MAX;
        }
        blocks[BLOCKS_COUNT - 1] &= FINAL_MASK;
    }

    void reset() {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] = 0;
        }
    }

    void flip() {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] = ~blocks[i];
        }
        blocks[BLOCKS_COUNT - 1] &= FINAL_MASK;
    }

    Bitset& operator~() {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] = ~blocks[i];
        }
        blocks[BLOCKS_COUNT - 1] &= FINAL_MASK;
        return *this;
    }

    Bitset& operator&=(const Bitset& other) {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] &= other.blocks[i];
        }
        return *this;
    }

    Bitset& operator|=(const Bitset& other) {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] |= other.blocks[i];
        }
        return *this;
    }

    Bitset& operator^=(const Bitset& other) {
        for (size_t i = 0; i < BLOCKS_COUNT; ++i) {
            blocks[i] ^= other.blocks[i];
        }
        return *this;
    }
};
