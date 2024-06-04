#include "func.h"

unsigned long long func::recurs(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }

    reversed = reversed * 10 + num % 10;
    num = num / 10;
    return recurs(num, reversed);
}
