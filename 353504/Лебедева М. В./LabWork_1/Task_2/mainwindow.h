#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "figures.h"
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    Figures *item=nullptr;
    bool flag;
    float scale = 1;
    double angle = 0;
private slots:
    void on_pushButton_triangle_clicked();
    void on_pushButton_square_clicked();
    void on_pushButton_rhombus_clicked();
    void on_pushButton_rectangle_clicked();
    void on_pushButton_star5_clicked();
    void on_pushButton_star6_clicked();
    void on_pushButton_star8_clicked();
    void on_pushButton_circle_clicked();
    void on_pushButton_parallel_clicked();
    void on_pushButton_hexagon_clicked();
    void on_pushButton_sizeup_pressed();
    void on_pushButton_sizedown_pressed();
    void GetInformation();
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


    void timer_slot();
};
#endif // MAINWINDOW_H
