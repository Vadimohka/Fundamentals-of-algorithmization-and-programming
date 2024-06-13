#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>

class MyClass
{
private:
    QString fio;
    QString club;
    QString amplua;
    int goals;
    int penalty;

public:
    MyClass() = default;

    QString getFio();
    void setFio(QString info);

    QString getClub();
    void setClub(QString info);

    QString getAmplua();
    void setAmplua(QString info);

    int getGoals();
    void setGoals(int info);

    int getPenalty();
    void setPenalty(int info);

    QString getAllInfo();
};

#endif // MYCLASS_H
