#ifndef HANOISOLVER_H
#define HANOISOLVER_H

#include <qcontainerfwd.h>
#include <qvector.h>

class HanoiSolver
{
public:
    static QVector<QPair<int, int>> Execute(int, int = 1, int = 3);
};

#endif // HANOISOLVER_H
