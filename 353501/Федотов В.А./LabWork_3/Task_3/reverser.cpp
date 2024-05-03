#include "reverser.h"

unsigned long long Reverser::reverse(unsigned long long inp, unsigned long long ret) {
    if (inp == 0) {
        return ret;
    } else {
        ret = ret * 10 + inp % 10;
        return reverse(inp / 10, ret);
    }
}