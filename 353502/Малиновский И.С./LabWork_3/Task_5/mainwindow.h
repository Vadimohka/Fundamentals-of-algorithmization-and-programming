#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int BUTTON_H_SIZE=100;
const int BUTTON_W_SIZE=500;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QPushButton task1_Button, task2_Button, task3_Button, task4_Button, task5_Button;

    Task1 task1;
    Task2 task2;
    Task3 task3;
    Task4 task4;
    Task5 task5;
};
#endif // MAINWINDOW_H
