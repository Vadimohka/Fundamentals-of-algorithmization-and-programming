//
// Created by zgdarya on 5/30/24.
//

#ifndef L7_T1_MAINWINDOW_H
#define L7_T1_MAINWINDOW_H

#include <QMainWindow>
#include "Deque.h"


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
    void on_deleteButton_clicked();
    void on_addButton_clicked();
    void on_showButton_clicked();
    void on_frontButton_clicked();
    void on_backButton_clicked();

private:
    Ui::MainWindow *ui;
    Deque deque; // Двухсвязная очередь
    int elementCounter; // Счетчик элементов для генерации новых значений

    void print();
};


#endif //L7_T1_MAINWINDOW_H
