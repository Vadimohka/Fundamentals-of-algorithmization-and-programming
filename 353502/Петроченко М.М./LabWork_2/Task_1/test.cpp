
// Created by acryoz on 28.2.24.
//
#include <iostream>
#include "../../headers/Date.h"


int main(){
    Date d1(30, 12, 1980);
    Date d2(1, 1, 1981);
    std::cout << d1.daysTo(d2) << '\n' << Date(9, 3, 2023).daynumber();
    return 0;
}