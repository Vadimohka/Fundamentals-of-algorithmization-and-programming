#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include <QtWidgets>
#include "circle.h"
#include "triangle.h"
#include "star8.h"
#include "star5.h"
#include "hexagon.h"
#include "parallelohram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "star6.h"
#include "square.h"
#include "shape.h"
#include "polygon.h"
#include "line.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setEnabled(bool);
    void mousePressEvent(QMouseEvent *me);
    void mouseMoveEvent(QMouseEvent *me);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Shape *scene1;
    QTimer *timer;
    Shape *item=nullptr;
    bool flag;
    polygon *pol;
    float scale = 1;
    void paintEvent(QPaintEvent *);
    double angle = 0;
private slots:
    void changeAngle();
    void on_pushButton_triangle_clicked();
    void on_pushButton_square_clicked();
    void on_pushButton_rhombus_clicked();
    void on_pushButton_rectangle_clicked();
    void on_pushButton_star5_clicked();
    void on_pushButton_star6_clicked();
    void on_pushButton_star8_clicked();
    void on_pushButton_circle_clicked();
    void on_pushButton_hexagon_clicked();
    void on_pushButton_sizeup_pressed();
    void on_pushButton_sizedown_pressed();
    void SetValue();
    void size_slot();
    void on_pushButton_sizeup_released();
    void on_pushButton_sizedown_released();
    void on_pushButton_moveup_pressed();
    void on_pushButton_moveup_released();
    void move_up_slot();
    void on_pushButton_movedown_pressed();
    void on_pushButton_movedown_released();
    void move_down_slot();
    void on_pushButton_moveleft_pressed();
    void on_pushButton_moveleft_released();
    void move_left_slot();
    void on_pushButton_moveright_pressed();
    void on_pushButton_moveright_released();
    void move_right_slot();
    void on_pushButton_rotleft_pressed();
    void on_pushButton_rotleft_released();
    void on_pushButton_rotright_pressed();
    void on_pushButton_rotright_released();
    void rotate_right_slot();
    void rotate_left_slot();
    void on_pushButton_drawlineon_clicked();
    void timer_slot();
    void on_pushButton_drawlineoff_clicked();
    void on_pushButton_moveline_clicked();
    void on_pushButton_sizelineup_pressed();
    void on_pushButton_sizelineup_released();
    void on_pushButton_sizelinedown_pressed();
    void on_pushButton_sizelinedown_released();
    void on_pushButton_rotliner_pressed();
    void on_pushButton_rotlinel_pressed();
    void on_pushButton_rotliner_released();
    void on_pushButton_rotlinel_released();
    void size_plus_slot();
    void updateSizeTrianA(double arg1);
    void updateSizeTrianB(double arg1);
    void updateSizeTrianC(double arg1);
    void size_minus_slot();
    void rotate_left_slot1();
    void rotate_right_slot1();
    void updateSize(double arg1);
    void updateSizeW(double arg1);
    void updateSizeRadius(double arg1);
    void updateSizeRadius8(double arg1);
    void updateSizeRadius5(double arg1);
    void updateHexagon(double arg1);
};
#endif // MAINWINDOW_H
