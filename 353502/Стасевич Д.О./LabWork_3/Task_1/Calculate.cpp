//
// Created by darina on 4/8/24.
//

#include "Calculate.h"

#include <iostream>
#include <QDebug>

QString Calculate::DecimaltoBinary(double d, long double st, int after_one) {
  //  qDebug() << d << " " << st << " " << d + exp << " " << d - exp;
   // std::cout << d << " " << st << " " << (d - st < 0) << " " << after_one << " " << st << '\n';
    if(after_one >= 53 && st < 1)
        return "0";
    QString add;
    if(st == 1)
        add += '.';
    if(d - st < 0)
    {
        if(after_one == 0)
            return "0" + add + DecimaltoBinary(d, st / 2, 0);
        else
            return "0" + add + DecimaltoBinary(d, st / 2, after_one + 1);
    }
    else
    {
        if(after_one == 0)
            return "1" + add + DecimaltoBinary(d - st, st / 2, 1);
        else
            return "1" + add + DecimaltoBinary(d - st, st / 2, after_one + 1);
    }
}

unsigned long long Calculate::Akkerman(int m, unsigned long long n) {
    if(m == 0)
        return n + 1;
    if(n == 0)
        return Akkerman(m - 1, 1);
    return Akkerman(m - 1, Akkerman(m, n - 1));
}

int Calculate::FindSize(int n) {
    if(n == 0)
        return 0;
    return 1 + FindSize(n / 10);
}

int Calculate::swap(int n, int i, int j) {
    if(i >= j)
        return n;
    int l = (n / a[i]) % 10;
    int r = (n / a[j]) % 10;
    n = n - l * a[i] - r * a[j] + l * a[j] + r * a[i];
    return swap(n, i + 1, j - 1);
}

long double Calculate::CalculateMaxSt(double d, long double cur) {
    if(d > cur)
        return CalculateMaxSt(d, cur * 2);
    else
        return cur;
}

QString Calculate::DecimaltoBinary(double d, double st) {
    if(st < 1)
    {
        return "";
    }
    if(d < st)
    {
        return "0" + DecimaltoBinary(d, st / 2);
    }
    return "1" + DecimaltoBinary(d - st, st / 2);
}
