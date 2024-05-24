//
// Created by u on 10.04.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <vector>
#include <fstream>
#include <string>
#include "../Date/Date.h"
#include "../Date/date.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget
{
Q_OBJECT

private slots:
    void setMaxDay();
    void save();
    void load();
    void add();
    void updateTable();
    void setBirthday();
    void change();

private:
    std::vector<Date> curDates;
    int birthdayDay = 1, birthdayMonth = 1, birthdayYear = 1;
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Ui::main_window *ui;

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;
};


#endif //TASK1_MAIN_WINDOW_H
