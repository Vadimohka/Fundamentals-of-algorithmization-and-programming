#include "product.h"

Product::Product(QString group, QString code, QString name, QString model, double cost, int count)
{
    this->group = group;
    this->code = code;
    this->name = name;
    this->model = model;
    this->cost = cost;
    this->count = count;
}

void Product::SetGroup(QString to)
{
    this->group = to;
}

void Product::SetCode(QString to)
{
    this->code = to;
}

void Product::SetName(QString to)
{
    this->name = to;
}

void Product::SetModel(QString to)
{
    this->model = to;
}

void Product::SetCost(double to)
{
    this->cost = to;
}

void Product::SetCount(int to)
{
    this->count = to;
}

QString Product::GetGroup() const
{
    return group;
}

QString Product::GetCode() const
{
    return code;
}

QString Product::GetName() const
{
    return name;
}

QString Product::GetModel() const
{
    return model;
}

double Product::GetCost() const
{
    return cost;
}

int Product::GetCount() const
{
    return count;
}
