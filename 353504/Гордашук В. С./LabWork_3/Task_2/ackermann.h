#ifndef ACKERMANN_H
#define ACKERMANN_H

#include <QDebug>
#include <QString>

class Ackermann
{
public:
    Ackermann();
    int stop = 0;
    int func(int m, int n);
};

#endif // ACKERMANN_H
