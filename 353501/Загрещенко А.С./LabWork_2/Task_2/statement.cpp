#include "statement.h"


Statement::Statement(int count, int price, QString model, QString name, int code, QString group)
{
    this->count = count;
    this->price = price;
    this->model = model;
    this->name = name;
    this->code = code;
    this->group = group;
}


int Statement::getCount() const {
    return count;
}

void Statement::setCount(int newCount) {
    count = newCount;
}


int Statement::getPrice() const {
    return price;
}

void Statement::setPrice(int newPrice) {
    price = newPrice;
}


QString Statement::getModel() const {
    return model;
}

void Statement::setModel(const QString& newModel) {
    model = newModel;
}

QString Statement::getName() const {
    return name;
}

void Statement::setName(const QString& newName) {
    name = newName;
}

int Statement::getCode() const {
    return code;
}

void Statement::setCode(int newCode) {
    code = newCode;
}


QString Statement::getGroup() const {
    return group;
}

void Statement::setGroup(const QString& newGroup) {
    group = newGroup;
}

