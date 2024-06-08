#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"

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
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_EraseElement_clicked();

    void on_ShowFirst_clicked();

    void on_ShowSecond_clicked();

    void on_Queue1Button_clicked();

    void on_Queue2Button_clicked();

    void on_solveTask_clicked();

private:
    Ui::MainWindow *ui;
    Queue queueMain;
    Queue queue1;
    Queue queue2;
    Queue additional;
};
#endif // MAINWINDOW_H
