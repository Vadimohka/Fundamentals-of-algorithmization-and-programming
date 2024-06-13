#include "hanoitower.h"

HanoiTower::HanoiTower(QObject *parent) : QObject(parent) {}

void HanoiTower::solve(int numRings) {
    tower[0].clear();
    tower[1].clear();
    tower[2].clear();

    for (int i = numRings; i >= 1; --i) {
        tower[0].append(i);
    }

    hanoi(numRings, 0, 2, 1);
}

void HanoiTower::hanoi(int n, int start, int finish, int temp) {
    if (n == 1) {
        int ring = tower[start].takeLast();
        tower[finish].append(ring);
        emit movePerformed(ring, start + 1, finish + 1);
    } else {
        hanoi(n - 1, start, temp, finish);

        int ring = tower[start].takeLast();
        tower[finish].append(ring);
        emit movePerformed(ring, start + 1, finish + 1);

        hanoi(n - 1, temp, finish, start);
    }
}
