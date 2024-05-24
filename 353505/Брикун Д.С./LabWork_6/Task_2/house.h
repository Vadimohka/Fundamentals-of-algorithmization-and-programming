#ifndef HOUSE_H
#define HOUSE_H

struct House {
    int floors;
    double area;
    char letter;
    bool hasGarden;
    static const int MAX_CHAR_ARRAY_SIZE = 10;
    static const int MAX_INT_ARRAY_SIZE = 5;
    static char districtAdministrationAddress[MAX_CHAR_ARRAY_SIZE];
    static int floorTax[MAX_INT_ARRAY_SIZE];
};

#endif // HOUSE_H
