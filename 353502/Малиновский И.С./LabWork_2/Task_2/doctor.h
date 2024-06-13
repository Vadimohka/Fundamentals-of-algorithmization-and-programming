#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QTime>
#include <QMap>
#include <QVector>
#include <QDialog>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>

#include "name.h"
#include "ticket.h"
#include "customcalendarwidget.h"

const int NumberDays = 7;
const int AddSecs = 15 * 60;
const int DialogHeight = 700;
const int DialogWidth = 700;
const QString DAYS_OF_WEEK[7] = {"понедельника", "вторника", "среды", "четверга", "пятницы", "субботы", "воскресенья"};

class Doctor : public QObject
{
    Q_OBJECT
public:
    Name name;

    Doctor(QObject *parent = nullptr);
    Doctor(QString specialization, QString name, QString surname, QString patronymic, int cabinetNumber, QTime* startTime, QTime* endTime, QObject *parent = nullptr);
    Doctor(const Doctor &other);
    Doctor& operator=(const Doctor &other);

    QString getSpecialization() const;
    QTime getStartTime(int ind) const;
    QTime getEndTime(int ind) const;
    QString getInfo() const;
    int getQueueNumber(const QDate &date);

    void selectDate();
    void addDoctor();
private:
    QString specialization;
    int cabinetNumber, queueNumber[NumberDays];
    QTime startTime[NumberDays], endTime[NumberDays];

    QDialog dateDialog, addDialog;
    CustomCalendarWidget doctorDates;

    QMap <QDate, QVector <Ticket> > dataQueue;

    QLineEdit nameLine, surnameLine, patronymicLine, specializationLine, cabinetNumberLine, startTimeLines[7], endTimeLines[7];
    QLabel nameLabel, surnameLabel, patronymicLabel, specializationLabel, cabinetNumberLabel, startTimeLabels[7], endTimeLabels[7], workSheduleLabel;
    QPushButton saveAddButton;

    void addTicket();
    void initialization();
    void checkAddDoctor();
};

#endif // DOCTOR_H
