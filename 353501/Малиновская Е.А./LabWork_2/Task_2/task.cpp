#include "task.h"

Task::Task(const QString& projectName, const QString& task, const QString& executor,
           const QString& supervisor, const QDate& issueDate, const QDate& dueDate)
    : projectName(projectName), task(task), executor(executor), supervisor(supervisor),
    issueDate(issueDate), dueDate(dueDate)
{
    this->projectName = projectName;
    this->task = task;
    this->executor = executor;
    this->supervisor = supervisor;
    this->issueDate = issueDate;
    this->dueDate = dueDate;
}

QString Task::getProjectName() const
{
    return projectName;
}

QString Task::getTask() const
{
    return task;
}

QString Task::getExecutor() const
{
    return executor;
}

QString Task::getSupervisor() const
{
    return supervisor;
}

QDate Task::getIssueDate() const
{
    return issueDate;
}

QDate Task::getDueDate() const
{
    return dueDate;
}
