#include <climits>
#include "iostream"
#include "mybitset.h"

int main() {
    MyBitset bits1 = MyBitset(10, 0b0101001110);
    MyBitset bits2 = MyBitset(10, 0b1011101101);
    std::cout << bits1.to_string() << '\n';
    std::cout << bits2.to_string() << '\n';
    std::cout << bits1[0] << ' ' << bits2[0] << '\n';
    bits2.set(1);
    bits1.reset(1);
    bits1[0] = 1;
    std::cout << bits1.to_string() << '\n';
    std::cout << bits2.to_string() << '\n';
    return 0;
}
