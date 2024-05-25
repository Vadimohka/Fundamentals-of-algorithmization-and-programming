//
// Created by zgdarya on 4/13/24.
//

#include "Worker.h"

Worker::Worker(QString workerFIO) {
    _workerFIO = workerFIO;
}

void Worker::setProject(QString projectName) {
    _projectName = projectName;
}

void Worker::setDateGave(QString dateGave) {
    QString day;
    QString month;
    QString year;
    day = QString(dateGave[0]) + QString(dateGave[1]);
    month = QString(dateGave[3]) + QString(dateGave[4]);
    year = QString(dateGave[6]) + QString(dateGave[7]) + QString(dateGave[8]) + QString(dateGave[9]);
    _dateGave = Date(day.toInt(), month.toInt(), year.toInt());
}

void Worker::setDateComplete(QString dateComplete) {
    QString day;
    QString month;
    QString year;
    day = QString(dateComplete[0]) + QString(dateComplete[1]);
    month = QString(dateComplete[3]) + QString(dateComplete[4]);
    year = QString(dateComplete[6]) + QString(dateComplete[7]) + QString(dateComplete[8]) + QString(dateComplete[9]);
    _dateComplete = Date(day.toInt(), month.toInt(), year.toInt());
}

void Worker::setDeadline(QString deadline) {
    QString day;
    QString month;
    QString year;
    day = QString(deadline[0]) + QString(deadline[1]);
    month = QString(deadline[3]) + QString(deadline[4]);
    year = QString(deadline[6]) + QString(deadline[7]) + QString(deadline[8]) + QString(deadline[9]);
    _deadline = Date(day.toInt(), month.toInt(), year.toInt());
}

void Worker::setMentorFIO(QString mentorFIO) {
    _mentorFIO = mentorFIO;
}

QString Worker::getWorkerFIOString() {
    return _workerFIO;
}

QString Worker::getProjectNameString() {
    return _projectName;
}

QString Worker::getTaskString() {
    return _task;
}

QString Worker::getMentorFIOString() {
    return _mentorFIO;
}

QString Worker::getDatesString() {
    return getDateGaveString() + ' ' + getDeadlineString() + ' ' + getDateCompleteString();
}

void Worker::setWorkerFIO(QString workerFIO) {
    _workerFIO = workerFIO;
}

void Worker::setTask(QString task) {
    _task = task;
}

QString Worker::getDateGaveString() {
    return QString::number(_dateGave.getDay()) + '.' + QString::number(_dateGave.getMonth()) + '.' + QString::number(_dateGave.getYear());
}

QString Worker::getDeadlineString() {
    return QString::number(_deadline.getDay()) + '.' + QString::number(_deadline.getMonth()) + '.' + QString::number(_deadline.getYear());
}

QString Worker::getDateCompleteString() {
    return QString::number(_dateComplete.getDay()) + '.' + QString::number(_dateComplete.getMonth()) + '.' + QString::number(_dateComplete.getYear());
}

Date Worker::getDateGaveDate() {
    return _dateGave;
}

Date Worker::getDeadlineDate() {
    return _deadline;
}

Date Worker::getDateCompleteDate() {
    return _dateComplete;
}
