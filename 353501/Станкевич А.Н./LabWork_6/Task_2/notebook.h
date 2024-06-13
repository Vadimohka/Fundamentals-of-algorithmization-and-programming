#ifndef NOTEBOOK_H
#define NOTEBOOK_H

struct Notebook {
    int year;
    double price;
    char model[100];
    bool isAvailable;
    static char operatingSystem[50];
    static int performanceScores[5];
};

#endif // NOTEBOOK_H
