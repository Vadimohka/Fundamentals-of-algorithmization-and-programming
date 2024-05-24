#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hanoiclass.h"

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

    void on_startButton_clicked();
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    HanoiClass *hanoi_towers;

    int row = 1;

    void moveDisk(int number,char from,char to);
    void start(int n, char from, char temp, char to);
};
#endif // MAINWINDOW_H
