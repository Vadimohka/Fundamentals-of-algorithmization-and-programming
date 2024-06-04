#include "projectClass.h"

#include <utility>

QString projectClass::getProjName() {
    return projName;
}

void projectClass::setProjName(QString info) {
    projName = std::move(info);
}

QString projectClass::getTask() {
    return task;
}

void projectClass::setTask(QString info) {
    task = std::move(info);
}

QString projectClass::getPmName() {
    return pmName;
}

void projectClass::setPmName(QString info) {
    pmName = std::move(info);
}

QString projectClass::getEmployeeName() {
    return employeeName;
}

void projectClass::setEmployeeName(QString info) {
    employeeName = std::move(info);
}

QDate projectClass::getStartDate() {
    return startDate;
}

void projectClass::setStartDate(QDate info) {
    startDate = info;
}

QDate projectClass::getBanDate() {
    return banDate;
}

void projectClass::setBanDate(QDate info) {
    banDate = info;
}

QDate projectClass::getEndDate() {
    return endDate;
}

void projectClass::setEndDate(QDate info) {
    endDate = info;
}

bool projectClass::isEmployeeBanned() {
    return (endDate.daysTo(banDate) < 0);
}

QString projectClass::getAllInfo() {
    QString allDate =
            "Project Name:\t" + projName + "\n" +
            "Task:\t\t" + task + "\n" +
            "PM Name:\t\t" + pmName + "\n" +
            "Employee Name:\t" + employeeName + "\n" +
            "Start Date:\t\t" + startDate.toString("dd.MM.yyyy") + "\n" +
            "End Date:\t\t" + endDate.toString("dd.MM.yyyy") + "\n" +
            "Ban Date:\t\t" + banDate.toString("dd.MM.yyyy") + "\n" +
            "Banned?\t\t";
    allDate += isEmployeeBanned() ? "Yes" : "No";
    allDate += "\n\n";

    return allDate;
}
