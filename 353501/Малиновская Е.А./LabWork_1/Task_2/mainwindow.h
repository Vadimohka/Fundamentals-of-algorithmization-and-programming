#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QPainter>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "star.h"
#include "right_polygone.h"
#include "rhombus.h"
#include "square.h"
#include "clear_scene.h"

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

    // CHANGING
    void startChangeX(double value);
    void handlerChangeX();
    void finishChangeX();
    void startChangeY(double value);
    void handlerChangeY();
    void finishChangeY();
    void startChangeSize(double value);
    void changesizehandler();
    void changesizecomplete();

    // ROTATION PART
    void change_rotation_start(double value);
    void change_rotation_handler();
    void change_rotation_complete();
    void change_rotationcenterX_start(double value);
    void change_rotationcenterX_handler();
    void change_rotationcenterX_complete();
    void change_rotationcenterY_start(double value);
    void change_rotationcenterY_handler();
    void change_rotationcenterY_complete();

    //void when_mousepressed(const QPointF &position);
    void on_comboBox_activated(int index);

    //  SPINBOXES
    void on_radiusSpinBox_valueChanged(double arg1);
    void on_side1trianglespin_valueChanged(double arg1);
    void on_side2trianglespin_valueChanged(double arg1);
    void on_side3trianglespin_valueChanged(double arg1);
    void on_heightrectspinbox_valueChanged(double arg1);
    void on_widthrectspinbox_valueChanged(double arg1);
    void on_apexes_spinbox_valueChanged(int arg1);
    void on_radius1_spinbox_valueChanged(double arg1);
    void on_radius2_spinbox_valueChanged(double arg1);
    void on_spinboxnumapexes_rp_valueChanged(int arg1);
    void on_spinboxside_rd_valueChanged(double arg1);
    void on_spinbox_angle_rh_valueChanged(double arg1);
    void on_spinbox_side_rh_valueChanged(double arg1);
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_connectCenterButton_toggled(bool checked);
    //void on_drawButton_clicked();

private:
    bool paintchoose;
    QPoint lastPoint;
    QTimer * timer;
    Ui::MainWindow * ui;
    QGraphicsScene * scene;
    Circle * circle;
    Triangle * triangle;
    Rectangle * rectangle;
    Star * star;
    Right_Polygone * right_polygone;
    Rhombus * rhombus;
    Square * square;
    Shape * shapesArray[8];
    Clear_scene * clear_scene;

    int shapeIndex = 0;
    double targetvalue;
    double currentvalue;
protected:
    void setInformation();
};
#endif // MAINWINDOW_H
