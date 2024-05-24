#ifndef SHOP_H
#define SHOP_H

struct Shop {
    int numberOfEmployees;
    double area;
    char shopType;
    bool hasParking;
    static const int MAX_CHAR_ARRAY_SIZE = 10;
    static const int MAX_INT_ARRAY_SIZE = 5;
    static char districtAdministrationAddress[MAX_CHAR_ARRAY_SIZE];
    static int employeeSalary[MAX_INT_ARRAY_SIZE];
};

#endif // SHOP_H
