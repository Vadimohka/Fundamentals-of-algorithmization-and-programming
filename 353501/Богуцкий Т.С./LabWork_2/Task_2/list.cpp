#include "list.h"

List::List()
{

}

float List::averageScore()
{
    return (float(markEnglish) + float(markMATH) + float(markProgramming))/3;
}

void List::setName(QString name)
{
    if (name == "") throw "Ошибка";
    this->Name = name;
}

void List::setSurname(QString surname)
{
    if (surname == "") throw "Ошибка";
    this->Surname = surname;
}

void List::setDadsname(QString dadsname)
{
    if (dadsname == "") throw "Ошибка";
    this->Dadsname = dadsname;
}

void List::setspeciality(QString speciality)
{
    if (speciality == "") throw "Ошибка";
    this->speciality = speciality;
}

void List::setgroup(QString group)
{
    // формат 6 цифр
    bool ok;
    if (group == "") throw "Ошибка";
    int intValue = group.toInt(&ok);
    if (ok && group.size() == 6) this->group = group.toInt();
    else throw "Ошибка";
}

void List::setmarkMATH(QString mark)
{
    // формат от 0 до 10
    bool ok;
    if (mark == "") throw "Ошибка";
    int intValue = mark.toInt(&ok);
    if (ok && mark.toInt() >= 0 && mark.toInt() <= 10) this->markMATH = mark.toInt();
    else throw "Ошибка";
}

void List::setmarkProgramming(QString mark)
{
    // формат от 0 до 10
    bool ok;
    if (mark == "") throw "Ошибка";
    int intValue = mark.toInt(&ok);
    if (ok && mark.toInt() >= 0 && mark.toInt() <= 10) this->markProgramming = mark.toInt();
    else throw "Ошибка";
}

void List::setmarkEnglish(QString mark)
{
    // формат от 0 до 10
    bool ok;
    if (mark == "") throw "Ошибка";
    int intValue = mark.toInt(&ok);
    if (ok && mark.toInt() >= 0 && mark.toInt() <= 10) this->markEnglish = mark.toInt();
    else throw "Ошибка";
}
