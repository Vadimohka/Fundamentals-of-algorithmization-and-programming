#include "akermannfunction.h"

AkermanFunction::AkermanFunction() = default;

int AkermanFunction::recursiveCalculation(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return recursiveCalculation(m - 1, 1);
    } else {
        return recursiveCalculation(m - 1, recursiveCalculation(m, n - 1));
    }
}

int AkermanFunction::startCalculation() { return recursiveCalculation(_m, _n); }

void AkermanFunction::setFirstArg(int m){ this->_m = m; }

void AkermanFunction::setSecondArg(int n){ this->_n = n; }

int AkermanFunction::getFirstArg() { return _m; }

int AkermanFunction::getSecondArg() { return _n; }
