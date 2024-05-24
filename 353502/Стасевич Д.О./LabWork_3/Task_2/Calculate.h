//
// Created by darina on 4/8/24.
//

#ifndef TASK123_CALCULATE_H
#define TASK123_CALCULATE_H


#include <QString>


class Calculate {

public:
    static long double CalculateMaxSt(double d, long double cur);
    static QString DecimaltoBinary(double d, long double st, int after_one);
    static QString DecimaltoBinary(double d, double st);
    static unsigned long long Akkerman(int m, unsigned long long n);
    static int FindSize(int n);
    static int swap(int n, int i, int j);

private:
    constexpr static const double exp = 1e-9;
    constexpr static long long a[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
};


#endif //TASK123_CALCULATE_H
