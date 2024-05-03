#include <iostream>
#include <cmath>

std::string solveInteger(long long integer) {
    if (integer < 0) {
        integer *= -1;
        return "-" + solveInteger(integer);
    }
    if (integer / 2 != 0) {
        return solveInteger(integer / 2) + std::to_string(integer % 2);
    }
    return std::to_string(integer % 2);
}

std::string solveFractional(long double fraction) {
    std::string binaryFraction = ".";
    int i = 12;
    while (i--) {
        fraction *= 2;
        int bit = fraction;
        if (bit == 1) {
            fraction -= bit;
            binaryFraction += '1';
        } else {
            binaryFraction += '0';
        }
    }
    return binaryFraction;
}

std::string toBinary(long double n) {
    long long integer;
    integer = (long long) n;
    long double fractional = static_cast<long double>(n - integer);
    return solveInteger(integer) + solveFractional(fractional);
}

int main() {
    long double n;
    std::cin >> n;
    std::cout << toBinary(n);
    return 0;
}
