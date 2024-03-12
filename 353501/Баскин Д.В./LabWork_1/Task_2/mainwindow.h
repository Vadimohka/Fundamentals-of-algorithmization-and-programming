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
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "star6.h"
#include "square.h"
#include "polygon.h"
#include "line.h"
#include "basicshape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    BasicShape *shape;
    BasicShape *figure = nullptr;
    Polygon *polygon = nullptr;
    bool draw;
    float scale = 1;
    double angle = 0;
    void setDraw(bool);
    void SetInfo();
    void paintEvent(QPaintEvent *);
private slots:
    void on_comboBox_currentIndexChanged(int);
    void on_pushButton_draw_clicked();
    void on_pushButton_sizeup_pressed();
    void on_pushButton_sizedown_pressed();
    void on_pushButton_sizeup_released();
    void on_pushButton_sizedown_released();
    void on_pushButton_origin_up_pressed();
    void on_pushButton_origin_up_released();
    void on_pushButton_origin_down_pressed();
    void on_pushButton_origin_down_released();
    void on_pushButton_origin_left_pressed();
    void on_pushButton_origin_left_released();
    void on_pushButton_origin_right_pressed();
    void on_pushButton_origin_right_released();
    void on_pushButton_moveup_pressed();
    void on_pushButton_moveup_released();
    void on_pushButton_movedown_pressed();
    void on_pushButton_movedown_released();
    void on_pushButton_moveleft_pressed();
    void on_pushButton_moveleft_released();
    void on_pushButton_moveright_pressed();
    void on_pushButton_moveright_released();
    void on_pushButton_rotleft_pressed();
    void on_pushButton_rotleft_released();
    void on_pushButton_rotright_pressed();
    void on_pushButton_rotright_released();
    void size_up_slot();
    void size_down_slot();
    void move_up_slot();
    void move_down_slot();
    void move_left_slot();
    void move_right_slot();
    void origin_up_slot();
    void origin_down_slot();
    void origin_left_slot();
    void origin_right_slot();
    void rotate_left_slot();
    void rotate_right_slot();
    void on_spinBox_radius_valueChanged(int);
    void on_spinBox_radiusA_valueChanged(int);
    void on_spinBox_radiusB_valueChanged(int);
    void on_spinBox_side_valueChanged(int);
    void on_spinBox_length_valueChanged(int);
    void on_spinBox_width_valueChanged(int);
    void on_pushButton_reset_clicked();
    void on_spinBox_angle_valueChanged(int);
};
#endif // MAINWINDOW_H
