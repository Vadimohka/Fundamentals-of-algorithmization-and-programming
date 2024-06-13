//
// Created by acryoz on 08.06.24.
//

#include "hanoi.h"

void hanoi(uint32_t n, uint32_t from, uint32_t to, uint32_t aux, QString& log) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, from, aux, to, log);
    QString step = QString("Move ring %1 from rod %2 to rod %3\n")
                       .arg(n)
                       .arg(from)
                       .arg(to);
    log.append(step);
    hanoi(n - 1, aux, to, from, log);
}