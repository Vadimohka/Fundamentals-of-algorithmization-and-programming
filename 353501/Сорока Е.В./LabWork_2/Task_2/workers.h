#ifndef WORKERS_H
#define WORKERS_H

#include <QString>
#include <QDate>

class workers
{
public:
    workers(QString fio, QString name, QString task, QString dated, QString start, QString finish);
    QString getfio();
    QString getname();
    QString gettask();
    QString getdated();
    QString getstart();
    QString getfinish();

    QString fio;
    QString name;
    QString task;
    QString dated;
    QString start;
    QString finish;
};

#endif // WORKERS_H
