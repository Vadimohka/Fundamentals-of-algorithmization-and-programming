#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "truck.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_back_up_pressed();

    void on_back_up_released();

    void on_back_down_pressed();

    void on_back_down_released();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Truck *truck;
    QTimer *timer;
    float angle;
};
#endif // MAINWINDOW_H
