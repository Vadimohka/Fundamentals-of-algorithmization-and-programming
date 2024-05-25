#ifndef AUTO_H
#define AUTO_H

#include "QChar"

struct Sportik
{
    int BirthdayYear;
    double wage;
    QChar teamletter;
    bool isCoolGuy;

    static const int MAX_NAME_SIZE = 16;
    static const int MAX_TOURNAMENTS_SIZE = 4;
    QChar name[MAX_NAME_SIZE];
    int tournametsYear[MAX_TOURNAMENTS_SIZE] = {0,0,0,0};
};

#endif // AUTO_H
