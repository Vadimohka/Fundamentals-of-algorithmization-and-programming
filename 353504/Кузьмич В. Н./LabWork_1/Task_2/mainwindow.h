#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "figures.h"

#include "line.h"

#include <typeinfo>

#include "hexagon.h"

#include "square.h"

#include "star.h"

#include "rectangle.h"

#include "rhombus.h"

#include "circle.h"

#include "triangle.h"

#include <QMainWindow>

#include <QGraphicsScene>

#include <QTimer>

#include <QString>

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
    figures *obgect;
    QGraphicsScene* scene;
    line* obgect2;
    Ui::MainWindow *ui;
    QTimer *timer;
    long double per = 0, pl = 0, center_x = 0, center_y = 0;
    bool is_line = false;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void ritht();
    void left();
    void up();
    void down();
    void skalee_up();
    void skalee_down();
    void on_pushButton_5_pressed();
    void on_pushButton_7_pressed();
    void on_pushButton_4_pressed();
    void on_pushButton_6_pressed();
    void on_pushButton_2_pressed();
    void on_pushButton_3_pressed();
    void on_pushButton_10_clicked();
    void on_pushButton_9_pressed();
    void pov_r();
    void pov_l();
    void on_pushButton_8_pressed();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void fun();
    void on_pushButton_11_pressed();
    void h_up();
    void h_down();
    void s_up();
    void s_down();
    void on_pushButton_12_pressed();
    void on_pushButton_13_pressed();
    void on_pushButton_14_pressed();
    void on_pushButton_15_pressed();
    void rad_min_up();
    void rad_min_down();
    void rad_max_up();
    void rad_max_down();
    void on_pushButton_16_pressed();
    void on_pushButton_17_pressed();
    void on_pushButton_18_pressed();
    void on_pushButton_19_pressed();
    void t1_x_up();
    void t1_x_down();
    void t2_x_up();
    void t2_x_down();
    void t3_y_up();
    void t3_y_down();
    void on_pushButton_20_pressed();
    void on_pushButton_21_pressed();
    void on_pushButton_22_pressed();
    void on_pushButton_23_pressed();
    void on_pushButton_24_pressed();
    void on_pushButton_pressed();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_27_pressed();
    void on_pushButton_29_clicked();
    void on_pushButton_29_pressed();
    void on_pushButton_28_clicked();
    void on_pushButton_28_pressed();
    void on_pushButton_30_clicked();
    void on_pushButton_30_pressed();
    void x_up_point_vr();
    void x_down_point_vr();
    void y_up_point_vr();
    void y_down_point_vr();
};
#endif // MAINWINDOW_H
