#ifndef COMPONENTS_H
#define COMPONENTS_H
#include<QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
class Components
{
public:
    Components();
    static QVector<Components> readComponents(const QString& fileName);
public:

    QString type;
    QString firm;
    QString model;
    QString parameters;
    double price;
    QString curr;
    QString available;
};

#endif // COMPONENTS_H
