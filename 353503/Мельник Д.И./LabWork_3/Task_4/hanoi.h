#ifndef HANOI_H
#define HANOI_H

#include <QString>

class Hanoi
{
public:
    Hanoi();
    void solution(int n, QString from = "A", QString to = "C", QString center = "B");
    QString getStepInfo();
private:
    QString _stepByStepInfo = "";
};

#endif // HANOI_H
