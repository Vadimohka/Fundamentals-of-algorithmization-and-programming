#include "myclass.h"

#include <utility>

QString MyClass::getFio()
{
    return fio;
}

void MyClass::setFio(QString info)
{
    fio = std::move(info);
}

QString MyClass::getClub()
{
    return club;
}

void MyClass::setClub(QString info)
{
    club = std::move(info);
}

QString MyClass::getAmplua()
{
    return amplua;
}

void MyClass::setAmplua(QString info)
{
    amplua = std::move(info);
}

int MyClass::getGoals()
{
    return goals;
}

void MyClass::setGoals(int info)
{
    goals = info;
}

int MyClass::getPenalty()
{
    return penalty;
}

void MyClass::setPenalty(int info)
{
    penalty = info;
}

QString MyClass::getAllInfo()
{
    QString allInfo = "ФИО:\t" + fio + "\n" + "Клуб:\t\t" + club + "\n" + "Амплуа:\t\t" + amplua
                      + "\n" + "Забитые мячи:\t" + QString::number(goals) + "\n" + "Штрафы:\t\t"
                      + QString::number(penalty) + "\n\n";
    return allInfo;
}
