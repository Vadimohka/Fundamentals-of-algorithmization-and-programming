#include "potion.h"

Potion::Potion() {}

Potion::Potion(int id, QString name, QString descrip, int heal, int type)
{
    this->heal = heal;
    this->description = descrip;
    this->name = name;
    this->type = type;
    this->id = id;
}

int Potion::getHeal()
{
    return heal;
}

void Potion::setHeal(int heal)
{
    this->heal = heal;
}

int Potion::use()
{
    return heal;
}

void Potion::copy(Potion &other)
{
    name = other.getName();
    description = other.getDescription();
    heal = other.getHeal();
    type = other.getType();
    id = other.id;
}
