#include "product.h"
#include <QStringList>

Product::Product() {}

QString Product::ToString() {
    return group + "." + code + "." + name + "." + model + "." + QString::number(cost) + "." + QString::number(count);
}

Product::Product(const QString& line) {
    QStringList fields = line.split(".");
    if (fields.size() != 6) {
        return;
    }
    group = fields[0];
    code = fields[1];
    name = fields[2];
    model = fields[3];
    cost = fields[4].toDouble();
    count = fields[5].toInt();
}

void Product::SetGroup(QString to){
    this->group = to;
}

void Product::SetCode(QString to){
    this->code = to;
}

void Product::SetName(QString to){
    this->name = to;
}

void Product::SetModel(QString to){
    this->model = to;
}

void Product::SetCost(double to){
    this->cost = to;
}

void Product::SetCount(int to){
    this->count = to;
}

QString Product::GetGroup() const{
    return group;
}

QString Product::GetCode() const{
    return code;
}

QString Product::GetName() const{
    return name;
}

QString Product::GetModel() const{
    return model;
}

double Product::GetCost() const{
    return cost;
}

int Product::GetCount() const{
    return count;
}
