#include "reverse.h"

int Reverse::reverseNumber(int value, int result){
    if (value == 0) {
        return result;
    } else {
        return reverseNumber(value / 10, result * 10 + value % 10);
    }
}
