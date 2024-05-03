#include "component.h"

component::component() {}

void component::getType(QString text)
{
    type = text;
}

void component::getFirm(QString text)
{
    firm = text;
}

void component::getCompModel(QString text)
{
    compModel = text;
}

void component::getParametrs(QString text)
{
    parametrs = text;
}

void component::getPrice(int x)
{
    price = x;
}

void component::getAvailability(bool a)
{
    availability = a;
}

QString component::retType()
{
    return type;
}
QString component::retFirm()
{
    return firm;
}

QString component::retCompModel()
{
    return compModel;
}

QString component::retParametrs()
{
    return parametrs;
}

int component::retPrice()
{
    return price;
}

bool component::retAvailability()
{
    return availability;
}
