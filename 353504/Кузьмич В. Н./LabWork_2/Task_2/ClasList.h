#ifndef CLASLIST_H
#define CLASLIST_H

#include <QString>

class ClasList
{
public:
    ClasList();
    ClasList(int, int, int, QString);
    int order_number, table_number, col;
    QString nas;
};

#endif // CLASLIST_H
