#ifndef LAPTOP_H
#define LAPTOP_H

struct Notebook {
    int year;
    double price;
    char model[100];
    bool isAvailable;
    static char operatingSystem[50];
    static int performanceScores[5];
};

#endif // LAPTOP_H
