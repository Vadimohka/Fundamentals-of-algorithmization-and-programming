#ifndef WRISTWATCH_H
#define WRISTWATCH_H
#include <QChar>
struct WristWatch{
    QChar model;
    bool isWhaterProof;
    double price;
    int hour;
    int minutes[2];
    QChar partOfDay[2]; //AM or PM
};
#endif // WRISTWATCH_H
