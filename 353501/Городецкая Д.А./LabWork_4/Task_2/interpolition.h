#ifndef INTERPOLITION_H
#define INTERPOLITION_H

#include <QPair>
#include <QVector>

class Interpoliation
{
public:
    Interpoliation();
    void static swap(int& i, int& j);
    void static interpolation(QVector<int>& A, QVector <QVector<int>>& motionVector);
};

#endif // INTERPOLITION_H
