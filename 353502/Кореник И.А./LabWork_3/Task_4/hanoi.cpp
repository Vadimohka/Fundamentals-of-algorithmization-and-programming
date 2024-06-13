#include "hanoi.h"
#include <iostream>
Hanoi::Hanoi(int _n) {
    n = _n;
    solve(n);
}

void Hanoi::towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{

    if (n == 0) {
        return;
    }

    // Move (n-1) disks from 'from_rod' to 'aux_rod' using 'to_rod' as the auxiliary rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Move the nth disk from 'from_rod' to 'to_rod'
    movements.push_back(new QString(QString(from_rod) + QString(to_rod)));
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;

    // Move (n-1) disks from 'aux_rod' to 'to_rod' using 'from_rod' as the auxiliary rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void Hanoi::solve(int n)
{
    movements.resize(0);
    towerOfHanoi(n, 'A', 'B', 'C');
}
