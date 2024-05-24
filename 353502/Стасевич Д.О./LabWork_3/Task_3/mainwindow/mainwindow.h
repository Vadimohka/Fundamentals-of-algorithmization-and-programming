//
// Created by darina on 4/8/24.
//

#ifndef TASK123_MAINWINDOW_H
#define TASK123_MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <algorithm>
#include "../Calculate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

protected:
    Ui::mainwindow *ui;

private slots:
    void task_choose_clicked(int);
    void execute_task1();
    void execute_task2();
    void execute_task3();
};


#endif //TASK123_MAINWINDOW_H
