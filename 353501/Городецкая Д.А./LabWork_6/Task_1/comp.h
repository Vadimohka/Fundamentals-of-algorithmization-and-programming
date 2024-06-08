#ifndef COMP_H
#define COMP_H

#include <QChar>

struct Animal
{
    int age;
    double weight;
    char dietType;
    bool isMale;
    static const int MAX_CHAR_ARRAY_SIZE = 20;
    static const int MAX_INT_ARRAY_SIZE = 7;
    static QChar species[MAX_CHAR_ARRAY_SIZE];
    static int hoursOfSleep[MAX_INT_ARRAY_SIZE];
};

#endif // COMP_H
