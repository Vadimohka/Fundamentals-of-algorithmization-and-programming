#ifndef LAB2_WIDGET_H
#define LAB2_WIDGET_H
#define ZERO_D_T QString::fromStdString(std::string(1 - (service->todayDate().day() >= 10  ? 1 : 0), '0'))
#define ZERO_M_T QString::fromStdString(std::string(1 - (service->todayDate().month() >= 10  ? 1 : 0), '0'))
#define ZERO_Y_T QString::fromStdString(std::string(3 - (service->todayDate().year() >= 10 ? service->todayDate().year() >= 100 ? service->todayDate().year() >= 1000 ? 3 : 2 : 1 : 0), '0'))
#define ZERO_D_B QString::fromStdString(std::string(1 - (service->birthDayDate().day() >= 10  ? 1 : 0), '0'))
#define ZERO_M_B QString::fromStdString(std::string(1 - (service->birthDayDate().month() >= 10  ? 1 : 0), '0'))
#define ZERO_Y_B QString::fromStdString(std::string(3 - (service->birthDayDate().year() >= 10 ? service->birthDayDate().year() >= 100 ? service->birthDayDate().year() >= 1000 ? 3 : 2 : 1 : 0), '0'))
#define ZERO_D_ID QString::fromStdString(std::string(1 - (service->_date[ID].day() >= 10 ? 1 : 0), '0'))
#define ZERO_M_ID QString::fromStdString(std::string(1 - (service->_date[ID].month() >= 10  ? 1 : 0), '0'))
#define ZERO_Y_ID QString::fromStdString(std::string(3 - (service->_date[ID].year() >= 10 ? service->_date[ID].year() >= 100 ? service->_date[ID].year() >= 1000 ? 3 : 2 : 1 : 0), '0'))
#define ZERO_D_P QString::fromStdString(std::string(1 - (previousDate.day() >= 10 ? 1 : 0), '0'))
#define ZERO_M_P QString::fromStdString(std::string(1 - (previousDate.month() >= 10  ? 1 : 0), '0'))
#define ZERO_Y_P QString::fromStdString(std::string(3 - (previousDate.year() >= 10 ? previousDate.year() >= 100 ? previousDate.year() >= 1000 ? 3 : 2 : 1 : 0), '0'))
#define ZERO_D_N QString::fromStdString(std::string(1 - (nextDate.day() >= 10 ? 1 : 0), '0'))
#define ZERO_M_N QString::fromStdString(std::string(1 - (nextDate.month() >= 10  ? 1 : 0), '0'))
#define ZERO_Y_N QString::fromStdString(std::string(3 - (nextDate.year() >= 10 ? nextDate.year() >= 100 ? nextDate.year() >= 1000 ? 3 : 2 : 1 : 0), '0'))

#include "QPushButton"
#include "QLineEdit"
#include <QTableWidget>
#include <QSpinBox>

#include "DateService.h"

#define DEBUG

class Widget : public QWidget {
Q_OBJECT
    DateService *service;

    QTableWidget *dateTable;

    QPushButton *closeButton;
    QPushButton *fileButton;
    QPushButton *addToFileButton;
    QPushButton *birthDayButton;
    QPushButton *redactButton;

    QSpinBox *redactScrollBar;

    QLineEdit *dayLineEdit;
    QLineEdit *monthLineEdit;
    QLineEdit *yearLineEdit;

    QTimer *timer;
public:
    Widget(QWidget *parent = nullptr);

private slots:

    void addToFile();

    void redactFile();

    void setSpaces();

    void addBirthDay();

    void showTable();
};


#endif //LAB2_WIDGET_H
