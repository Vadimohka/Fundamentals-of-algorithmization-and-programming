#include "project.h"

extern QMap <int, int> monthMap;

Project::Project(QString NameProjectInp, QString TaskProjectInp, QString ExecutorInp,
                 QString SuperVisorInp, QString DateIssuingInp, QString TermInp, QString DateHInp) {
    NameProject = NameProjectInp;
    TaskProject = TaskProjectInp;
    Executor = ExecutorInp;
    Supervisor = SuperVisorInp;
    DateIssuing = DateIssuingInp;
    Term = TermInp;
    DateHanding = DateHInp;
}


QString Project::NameProjectOutput() {
    return NameProject;
}


QString Project::ExecutorNameOutput() {
    return Executor;
}


QString Project::SupervisorNameOutput() {
    return Supervisor;
}


QString Project::TaskProjectOutput() {
    return TaskProject;
}


QString Project::DateIssuingOutput() {
    return DateIssuing;
}


QString Project::TermOutput() {
    return Term;
}


QString Project::DateHandingOutput() {
    return DateHanding;
}

int Project::TransferDateToDay(QString date) {
    int day = date.mid(0, 2).toInt();
    int month = date.mid(3, 2).toInt();
    int year = date.mid(6, 4).toInt();
    int resultTransfing = 0;
    int leapYear = (year) % 4 - (year) % 100 + (year) % 400;
    bool IsLeap = false;
    if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {
        IsLeap = true;
    }
    resultTransfing += (year - leapYear) * 365 + leapYear * 366;
    for (int i = 1; i <= month - 1; ++i) {
        resultTransfing += monthMap[i];
        if (i == 2) {
            resultTransfing += int(IsLeap);
        }
    }
    resultTransfing += day;
    return resultTransfing;
}

bool Project::CheckTaskOverdue() {
    if (TransferDateToDay(DateHanding) - TransferDateToDay(DateIssuing) > Term.toInt()) {
        return true;
    }
    return false;
}
