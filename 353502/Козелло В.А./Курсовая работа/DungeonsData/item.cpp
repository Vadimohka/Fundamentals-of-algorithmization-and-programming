#include "item.h"

Item::Item() = default;

Item::Item(int id, QString itemName, QString descrip, int type)
    : name(itemName)
    , description(descrip)
    , type(type)
    , id(id)
{}

QString Item::getName()
{
    return name;
}

void Item::setName(QString name)
{
    this->name = name;
}

QString Item::getDescription()
{
    return description;
}

void Item::setDescription(QString descrip)
{
    description = descrip;
}

void Item::setType(int type)
{
    this->type = type;
}

int Item::getType()
{
    return type;
}

void Item::setId(int id)
{
    this->id = id;
}

int Item::getId()
{
    return id;
}

int Item::use()
{
    qDebug() << this->getName();
    return 0;
}

void Item::copy(Item &other)
{
    this->name = other.name;
    this->description = other.description;
    this->type = other.type;
    this->id = other.id;
}
