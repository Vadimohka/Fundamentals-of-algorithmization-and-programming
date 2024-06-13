#ifndef WORK_H
#define WORK_H

#include <QString>

class Work
{
public:
    Work(QString);
    QString sotrydnikFIO;
    QString nameProject;
    QString zadanie;
    QString dateOfBegin;
    QString dateOfDone;
    int deadLine; //не дата,а сколько дней отведено
    QString rykovoditelFIO;
};

#endif // WORK_H
