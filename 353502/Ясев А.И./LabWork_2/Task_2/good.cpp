#include "good.h"

Good::Good(Group group, qint64 code, QString name, qreal price, qint64 count)
{
    this->code = code;
    this->count = count;
    this->group = group;
    this->name = name;
    this->price = price;
}

QString Good::toString()
{
    return name;

}

QString Good::toFullInfoString()
{
return QString("%1-%2-%3-%4-%5").arg(group).arg(code).arg(name).arg(price).arg(count);
}

Good Good::fromString(QString from)
{
    QStringList params = from.split(QRegularExpression("-"));
    Group group = NONE;
    switch (params[0].toInt()) {
    case 0:
        group = FOOD;
        break;
    case 1:
        group = TECH;
        break;
    case 2:
        group = GARDENING;
        break;
    }
    return Good(group, params[1].toLongLong(), params[2], params[3].toDouble(),params[4].toLongLong());
}

Good::Group Good::getGroup()
{
    return group;
}

qint64 Good::getCode()
{
    return code;
}

qreal Good::getPrice()
{
    return price;
}

qint64 Good::getCount()
{
    return count;
}

QString Good::getName()
{
    return name;
}
