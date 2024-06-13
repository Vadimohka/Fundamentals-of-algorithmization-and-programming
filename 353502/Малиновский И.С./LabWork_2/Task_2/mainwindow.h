#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QScreen>

#include "doctor.h"

const int ADD_TICKET_DIALOG_HEIGHT = 400;
const int ADD_TICKET_DIALOG_WIDTH = 400;
const int DOCTOR_INFO_HEIGHT = 50;
const int DOCTOR_INFO_WIDTH = 350;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addDoctorButton_clicked();

    void on_addTicketButton_clicked();

    void on_deleteDoctorButton_clicked();

    void on_dateQueue_clicked();

private:
    Ui::MainWindow *ui;

    QVector <Doctor> doctors;

    QCalendarWidget calendar;
    QDialog addTicketDialog, deleteDoctorDialog, showQueueNumber, showCalendar;
    QVBoxLayout *ticketLayout, *deleteLayout;
    QPushButton addTicketButton, deleteDoctorButton, dateSelected;
    QComboBox comboBox;

    void addDoctor();
    void doctorDeleteSelected();
    void doctorSelected();
    void dateSelect();
};
#endif // MAINWINDOW_H
