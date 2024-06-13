//
// Created by acryoz on 08.06.24.
//

#include "ackerman.h"

int64_t computeAckermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return computeAckermann(m - 1, 1);
    }
    return computeAckermann(m - 1, computeAckermann(m, n - 1));
}