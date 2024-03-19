#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "car.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Car *C=new Car;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer* timer= new QTimer;

    void MyTimer();
public slots:
    void change_door_status();
private:
    Ui::MainWindow *ui;
    bool block=false;
protected:
    void paintEvent(QPaintEvent*)override;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_pressed();
};
#endif // MAINWINDOW_H
