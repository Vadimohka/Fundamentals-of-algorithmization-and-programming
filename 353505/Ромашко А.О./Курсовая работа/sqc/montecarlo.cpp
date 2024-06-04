#include "montecarlo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

MonteCarlo::MonteCarlo() {}

// Функция для генерации случайного числа в заданном диапазоне
int MonteCarlo::monteCarlo(int min, int max) {
    return min + QRandomGenerator::global()->bounded(0,100) % (max - min + 1);
}
