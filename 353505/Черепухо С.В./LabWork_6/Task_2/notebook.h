#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QString>
#include <QStringList>

struct Notebook
{
    int usbs;
    double cpuCore;
    char model;
    bool isGaming;
    int id[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char company[10];

    QString tooString();
    Notebook toSelf(QString string);
};

#endif // NOTEBOOK_H
