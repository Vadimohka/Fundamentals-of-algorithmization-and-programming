#ifndef AUTOREPAIR_H
#define AUTOREPAIR_H

struct AutoRepair {
    int floors;
    double area;
    char type;
    bool hasVIP;
    static const int MAX_CHAR_ARRAY_SIZE = 9;
    static const int MAX_INT_ARRAY_SIZE = 3;
    static char streetName[MAX_CHAR_ARRAY_SIZE];
    static int addressNumbers[MAX_INT_ARRAY_SIZE];
};

#endif // AUTOREPAIR_H
