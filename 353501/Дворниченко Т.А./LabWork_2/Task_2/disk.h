#ifndef DISK_H
#define DISK_H

#include <QString>

class Detail
{
public:
    Detail(QString, QString, QString, QString, double, bool);
    QString GetType();
    QString GetName();
    QString GetAuthor();
    QString GetRemark();
    double GetCoast();
    bool isAvaliable();
private:
    QString information;
    QString name;
    QString author;
    QString remark;
    double coast;
    bool avaliable;
};

#endif // DISK_H
