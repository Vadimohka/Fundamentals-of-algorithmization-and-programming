#ifndef AIRPORT_H
#define AIRPORT_H

#include<QString>
#include<magicnumbers.h>

struct Airport {
    int id;
    double altitude;
    bool isOpen;

    static char name[SIZE];
    static int flights[TEN];

    QString printInfo();
};

#endif // AIRPORT_H
