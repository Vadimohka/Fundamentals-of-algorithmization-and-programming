#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QMap>

class Project
{
public:
    Project(QString NameProjectInp, QString TaskProjectInp, QString ExecutorInp,
            QString SuperVisorInp, QString DateIssuingInp, QString TermInp, QString DateHInp);
    QString NameProjectOutput();
    QString ExecutorNameOutput();
    QString SupervisorNameOutput();
    QString TaskProjectOutput();
    QString DateIssuingOutput();
    QString TermOutput();
    QString DateHandingOutput();
    bool CheckTaskOverdue();

protected:
    QString NameProject;
    QString TaskProject;
    QString Executor;
    QString Supervisor;
    QString DateIssuing;
    QString Term;
    QString DateHanding;
private:
    int TransferDateToDay(QString date);
};

#endif // PROJECT_H
