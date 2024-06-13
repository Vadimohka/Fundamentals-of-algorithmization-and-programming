#include "name.h"

Name::Name() {}

Name::Name(QString name, QString surname, QString patronymic): name(name), surname(surname), patronymic(patronymic){}

QString Name::getName() const
{
    return name;
}

QString Name::getSurname() const
{
    return surname;
}

QString Name::getPatronymic() const
{
    return patronymic;
}

void Name::setName(QString name)
{
    this->name=name;
}

void Name::setSurname(QString surname)
{
    this->surname=surname;
}

void Name::setPatronymic(QString patronymic)
{
    this->patronymic=patronymic;
}
