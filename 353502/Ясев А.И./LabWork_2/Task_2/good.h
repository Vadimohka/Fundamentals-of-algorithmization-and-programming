#ifndef GOOD_H
#define GOOD_H

#include "qglobal.h"
#include <QString>
#include <QRegularExpression>
class Good
{
public:
    enum Group : qint8{
        NONE = -1,
        FOOD = 0,
        TECH = 1,
        GARDENING = 2
    };
    Good(Group group = NONE,
         qint64 code = 0,
         QString name = "",
         qreal price = 0,
         qint64 count = 0);
    QString toString();
    QString toFullInfoString();
    static Good fromString(QString from);
    Group getGroup();
    qint64 getCode();
    qreal getPrice();
    qint64 getCount();
    QString getName();
private:
    Group group;
    qint64 code;
    qreal price;
    qint64 count;
    QString name;
};

#endif // GOOD_H
