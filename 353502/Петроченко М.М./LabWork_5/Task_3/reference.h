#include <cstdint>
#include <locale>

class bool_ref {
   private:
    uint32_t bit_position;
    uint64_t& value;
    bool bit;

   public:
    bool_ref(uint64_t&, uint32_t);
    bool_ref& operator=(bool rhs);
    bool_ref& operator=(const bool_ref& rhs);
    bool operator~() const;
    operator bool() const;
    bool_ref& flip();
    ~bool_ref() = default;
};
