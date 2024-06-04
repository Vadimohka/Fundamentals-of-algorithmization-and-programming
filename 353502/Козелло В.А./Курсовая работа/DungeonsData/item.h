#ifndef ITEM_H
#define ITEM_H

#include <QDebug>
#include <QObject>
#include <QString>
#include "constants.h"

class Item : public QObject
{
    Q_OBJECT
public:
    Item();
    Item(int id, QString name, QString description, int type);
    ~Item() override = default;

    QString getName();
    void setName(QString);

    QString getDescription();
    void setDescription(QString);

    void setType(int type);
    int getType();

    void setId(int id);
    int getId();

    virtual int use();
    void copy(Item &other);

protected:
    QString name;
    QString description;
    int type;
    int id;
};

#endif // ITEM_H
