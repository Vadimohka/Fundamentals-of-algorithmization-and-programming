#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>

#include <QTimer>

#include "rectangle.h"

#include "truck.h"

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
    QGraphicsScene* scene;
    rectangle* object;
    rectangle* object2;
    QTimer *timer;
private slots:

    void on_pushButton_2_clicked();

    void on_per_left_clicked();

    void on_per_left_pressed();

    void on_per_rigth_clicked();

    void on_per_rigth_pressed();

    void fun_left();

    void fun_right();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
