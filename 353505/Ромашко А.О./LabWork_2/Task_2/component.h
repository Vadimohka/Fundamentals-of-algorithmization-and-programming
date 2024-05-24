#ifndef COMPONENT_H
#define COMPONENT_H

#include <QStandardItemModel>

class component
{
public:
    component();

    void getType(QString text);
    void getFirm(QString text);
    void getCompModel(QString text);
    void getParametrs(QString text);
    void getPrice(int x);
    void getAvailability(bool a);

    QString retType();
    QString retFirm();
    QString retCompModel();
    QString retParametrs();
    int retPrice();
    bool retAvailability();
private:
    QString type;
    QString firm;
    QString compModel;
    QString parametrs;
    int price;
    bool availability;
};

#endif // COMPONENT_H
