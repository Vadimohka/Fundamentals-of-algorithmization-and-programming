#ifndef FOOT_H
#define FOOT_H

#include <QString>
#include <QDebug>

struct Foot
{
    int totalNumber = 0;
    double price = 0.0;
    QChar type = '/0';
    bool isUniversal = false;

    char season[6];
    int sz[20];



    Foot(const QString& str);
    QString toString();

};

#endif // FOOT_H
