#include "student.h"

Student::Student() {}

Student::Student(int g, QString fio)
{
    numOfGroup_ = g;
    fio_ = fio;
}

Student::Student(int g, QString fio, int m1, int p1, int h1, int m2, int p2, int h2)
{
    numOfGroup_ = g;
    fio_ = fio;
    w_math = m1;
    w_prog = p1;
    w_history = h1;
    s_math = m2;
    s_prog = p2;
    s_history = h2;
}

QString Student::printStudent()
{
    QString res = "";
    res = QString::number(numOfGroup_) + ' ' + fio_ + QString::number(w_math) + ' ' + QString::number(w_prog) + ' ' + QString::number(w_history) + ' ' + QString::number(s_math) + ' ' + QString::number(s_prog) + ' ' + QString::number(s_history);
    return res;
}

QString Student::printFio()
{
    return fio_;
}
