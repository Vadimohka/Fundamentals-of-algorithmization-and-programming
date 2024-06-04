#ifndef DATA_H
#define DATA_H
#include<QString>
class Data
{
public :
    void cr(QString *);
    QString check(QString);
    QString checker(QString);
    QString ret(int);
private:
    QString name;
    QString list;
    QString perf;
    QString lead;
    QString date;
    QString ex;
    QString*k=new QString [6];
    int days[12] {31,28,31,30,31,30,31,31,30,31,30,31};
};

#endif // DATA_H
