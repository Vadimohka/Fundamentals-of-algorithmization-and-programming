#ifndef TICKET_H
#define TICKET_H

#include <QDate>
#include <QTime>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QMessageBox>

#include "name.h"

const int Height = 20;
const int Width = 100;

class Ticket : public QObject
{
    Q_OBJECT
public:
    Ticket(QObject *parent = nullptr);
    Ticket(QDate date, QTime time, int queueNumber, int cabinetNumber, QString doctorName, QString doctorSurname, QString doctorPatronymic, QString patientName, QString patientSurname, QString patientPatronymic, QObject *parent = nullptr);
    Ticket(const Ticket &other);
    Ticket& operator=(const Ticket &other);

    QDate getDate();
    QTime getTime();
    int getQueueNumber();
    int getCabinetNumber();

    void startFoarm();

private:
    QDate date;
    QTime time;
    int queueNumber, cabinetNumber;
    Name doctorName, patientName;

    QDialog dialog;
    QLineEdit *nameLine, *surnameLine, *patronymicLine;
    QTextEdit *dateText, *timeText, *cabinetNumberText, *queueNumberText;
    QLabel *nameLabel, *surnameLabel, *patronymicLabel, *dateLabel, *timeLabel, *cabinetNumberLabel, *queueNumberLabel;
    QPushButton *saveTicketButton;

    void initialize();
    void authorization();
};

#endif // TICKET_H
