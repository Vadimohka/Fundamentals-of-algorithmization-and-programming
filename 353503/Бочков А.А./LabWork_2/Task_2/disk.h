#ifndef DISK_H
#define DISK_H

#include "QString"

class disk
{
public:
    disk();
    disk(QString, QString, QString, int, QString);
    int cost = 0;
    QString type = "", name = "", author = "", prim = "";
private:

};

#endif // DISK_H
