
#include "converter.h"

uint64_t reverse(uint64_t num, uint64_t reversed) {
    if (num == 0) {
        return reversed;
    }
    uint64_t remainder = num % 10;
    return reverse(num / 10, reversed * 10 + remainder);
}

uint64_t countDigits(uint64_t num) {
    uint64_t counter = 0;
    while (num > 0) {
        counter++;
        num /= 10;
    }
    return counter;
}