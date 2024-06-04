#include "hanoi.h"
#include <QDebug>

Hanoi::Hanoi() = default;

void Hanoi::solution(int n, QString from, QString to, QString center){
    if (n == 1) {
        qDebug() << "Переместить диск 1 с " << from << " на " << to;
        _stepByStepInfo += "Переместить диск 1 с " + from + " на " + to + '\n';
    } else {
        solution(n - 1, from, center, to);
        qDebug() << "Переместить диск " << n << " с " << from << " на " << to;
        _stepByStepInfo += "Переместить диск " + QString::number(n) + " с " + from + " на " + to + '\n';
        solution(n - 1, center, to, from);
    }
}

QString Hanoi::getStepInfo(){ return _stepByStepInfo; }
