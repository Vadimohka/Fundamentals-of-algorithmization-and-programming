#ifndef TOY_H
#define TOY_H

#include <QString>
#include <QVector>

struct Toy {
    int id;
    double price;
    QChar category;
    bool isAvailable;
    QString name;
    QVector<int> ratings;
};

#endif // TOY_H
