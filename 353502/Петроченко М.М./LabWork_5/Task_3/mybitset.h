#include <cstdint>
#include <string>
#include <vector>
#include "reference.h"

static const uint32_t SET_SIZE = 64;

class MyBitset {
   private:
    std::vector<uint64_t> vals;
    uint32_t len;
    uint32_t sets;
    void bitshift_base_left(uint32_t);
    void bitshift_base_right(uint32_t);

   public:
    MyBitset(uint32_t);
    MyBitset(uint32_t, uint64_t);
    MyBitset(const std::string&);
    MyBitset(const MyBitset&);

    MyBitset& operator=(const MyBitset& rhs);
    bool operator[](uint32_t) const;
    bool_ref operator[](uint32_t);

    MyBitset operator~() const;
    MyBitset& operator&=(const MyBitset& rhs);
    MyBitset& operator|=(const MyBitset& rhs);
    MyBitset& operator<<(uint32_t);
    MyBitset& operator>>(uint32_t);

    bool all() const;
    bool any() const;
    uint32_t count() const;
    void flip();
    void flip(uint32_t);
    bool none() const;
    void reset();
    void reset(uint32_t);
    void set();
    void set(uint32_t);
    uint32_t size() const;
    bool test(uint32_t) const;
    std::string to_string() const;
    uint64_t to_ullong() const;
    uint32_t to_ulong() const;

    ~MyBitset() = default;
};
