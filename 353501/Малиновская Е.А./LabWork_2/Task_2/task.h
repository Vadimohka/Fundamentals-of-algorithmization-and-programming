#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task
{
public:
     Task(const QString& projectName, const QString& task, const QString& executor,
         const QString& supervisor, const QDate& issueDate, const QDate& dueDate);

    QString getProjectName() const;
    QString getTask() const;
    QString getExecutor() const;
    QString getSupervisor() const;
    QDate getIssueDate() const;
    QDate getDueDate() const;

    QString projectName;
    QString task;
    QString executor;
    QString supervisor;
    QDate issueDate;
    QDate dueDate;
};

#endif // TASK_H
