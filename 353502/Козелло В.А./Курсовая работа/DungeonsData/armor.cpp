#include "armor.h"

Armor::Armor() = default;

Armor::Armor(int id, QString armorName, QString descrip, int def, int type)
    : defence(def)
{
    this->name = armorName;
    description = descrip;
    this->type = type;
    this->id = id;
}

int Armor::getDef()
{
    return defence;
}

void Armor::setDef(int def)
{
    defence = def;
}

void Armor::copy(Armor &other)
{
    this->name = other.name;
    this->defence = other.defence;
    this->description = other.description;
    this->type = other.type;
    this->id = id;
}

int Armor::use()
{
    return defence;
}
