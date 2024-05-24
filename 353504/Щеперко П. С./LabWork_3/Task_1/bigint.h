#ifndef BIGINT_H
#define BIGINT_H

#include <QString>

class BigInt
{

private:
    friend class Convert;
    static QPair<QString,QString> DivisionBy2(QString num);
    static QPair<QString,QString> MultipicationBy2(QString num);
};

#endif // BIGINT_H
