#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QDate>

class Product
{
    QString group, brand;
    bool complete;
    QDate acceptance, execution;

public:
    Product(QString group, QString brand, bool complete, QDate acceptance, QDate execution);
    QString StringForSaveInFile() const;

    QString Group() const;
    QString Brand() const;
    bool isComplete() const;
    QDate Acceptance() const;
    QDate Execution() const;

    void setGroup(QString newGroup);
    void setBrand(QString newBrand);
    void setIsComplete(bool newComplete);
    void setAcceptance(QDate newAcceptance);
    void setExecution(QDate newExecution);
};

#endif // PRODUCT_H
