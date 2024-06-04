#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "figure.h"
#include "circle.h"
#include "triangle.h"
#include "polygon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "rectangle.h"
#include "romb.h"
#include "hexagon.h"
#include "trapezoid.h"
#include "square.h"
#include "line.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *me);
    //void mouseMoveEvent(QMouseEvent *me);

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void SetValue();

    void on_Create_Circle_clicked();

    void on_CreateTriangle_clicked();

    void on_Rotate_Right_pressed();

    void on_Rotate_Right_released();

    void rotate_right_slot();

    void rotate_left_slot();

    void move_up_slot();

    void move_down_slot();

    void move_left_slot();

    void move_right_slot();

    void size_slot();

    void size_plus_slot();

    void size_minus_slot();

    void on_Rotate_Left_pressed();

    void on_Rotate_Left_released();

    void on_Clear_clicked();

    void on_exit_clicked();

    void on_Create_Star_5_clicked();

    void on_Create_Star_6_clicked();

    void on_Create_Star_8_clicked();

    void on_Create_Rectangle_clicked();

    void on_Create_Romb_clicked();

    void on_Create_Hexagon_clicked();

    void on_Create_Square_clicked();

    void on_Create_Trapezoid_clicked();

    void on_SizeUP_pressed();

    void on_SizeUP_released();

    void on_SizeDOWN_pressed();

    void on_SizeDOWN_released();

    void on_MoveUP_pressed();

    void on_MoveUP_released();

    void on_MoveDN_pressed();

    void on_MoveDN_released();

    void on_MoveLF_pressed();

    void on_MoveLF_released();

    void on_MoveRG_pressed();

    void on_MoveRG_released();

    void on_LineON_clicked();

    void on_LineOFF_clicked();



private:
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    Figure *currentItem = nullptr;
    QTimer *timer;
    Polygon *polygon;
    Line *line;
    bool flag;
    bool check;
    float scale = 1;
    void turnON();
    void turnOFF();
    void PrintInfo();
    void turnONFIG();
    void turnOFFFIG();


};
#endif // MAINWINDOW_H
