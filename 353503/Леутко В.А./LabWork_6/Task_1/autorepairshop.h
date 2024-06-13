#ifndef AUTOREPAIRSHOP_H
#define AUTOREPAIRSHOP_H

#include <array>

constexpr short MAX_NAME = 40;
constexpr short MAX_BREAKDOWNS = 10;

struct AutoRepairShop {
    int age;
    double repairBill;
    char category;
    bool isCertificated;
    static std::array<char, MAX_NAME> autoName;
    static int breakdowns[MAX_BREAKDOWNS];
};

#endif // AUTOREPAIRSHOP_H
