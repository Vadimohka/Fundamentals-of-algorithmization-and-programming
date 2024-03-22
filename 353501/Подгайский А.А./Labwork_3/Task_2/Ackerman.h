#include <cstdint>
#include <limits>
#include <optional>
#include <climits>
#include <array>
class Ackerman {

private:
  
  static int call;
  static bool ok;
  static const int c_maxCalls = 90'000'000;
  static uint32_t p_value(uint8_t m, uint32_t n);

public:
  static constexpr std::array<int, 5> c_limits = {
      std::numeric_limits<int>::max(), 250'000, 5100, 11, 1};
  
    static std::optional<uint32_t> Value(uint32_t m, uint32_t n);
};