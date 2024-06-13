#include "product.h"

Product::Product(QString group, QString brand, bool complete, QDate acceptance, QDate execution)
{
    this->group = group;
    this->brand = brand;
    this->complete = complete;
    this->acceptance = acceptance;
    this->execution = execution;
}

QString Product::StringForSaveInFile() const
{
    QString strcomplete;
    if(complete){
        strcomplete = "Complete";
    }
    else{
        strcomplete = "Incomplete";
    }
    return ("Group: " + group + "\nBrand: " + brand + "\nComplete: " + strcomplete + "\nAcceptance date: " + acceptance.toString("dd.MM.yyyy") + "\nOrder execution date: " + execution.toString("dd.MM.yyyy") + "\n\n");
}

QString Product::Group() const
{
    return group;
}

QString Product::Brand() const
{
    return brand;
}

bool Product::isComplete() const
{
    return complete;
}

QDate Product::Acceptance() const
{
    return acceptance;
}

QDate Product::Execution() const
{
    return execution;
}

void Product::setGroup(QString newGroup)
{
    group = newGroup;
}

void Product::setBrand(QString newBrand)
{
    brand = newBrand;
}

void Product::setIsComplete(bool newComplete)
{
    complete = newComplete;
}

void Product::setAcceptance(QDate newAcceptance)
{
    acceptance = newAcceptance;
}

void Product::setExecution(QDate newExecution)
{
    execution = newExecution;
}
