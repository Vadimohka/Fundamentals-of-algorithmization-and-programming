//
// Created by darina on 4/10/24.
//

#include "Hanoi.h"

QString Hanoi::hanoi(int n, int l, int r) {
    if(n == 1)
    {
        return QString::number(l) + QString::number(r);
    }
    return hanoi(n - 1, l, 6 - l - r) + QString::number(l) + QString::number(r) + hanoi(n - 1, 6 - l - r, r);
}
