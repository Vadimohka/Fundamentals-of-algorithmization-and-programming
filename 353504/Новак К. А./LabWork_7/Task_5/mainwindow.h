#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "deque.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Push_Back_clicked();

    void on_Push_front_clicked();

    void on_PopBack_clicked();

    void on_Pop_Front_clicked();

    void on_pushButton_clicked();

    void on_Clear_clicked();

    void on_Size_clicked();

    void on_Empty_clicked();

    void on_Index_clicked();

private:
    QString Print();

    Deque<int> deque;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
