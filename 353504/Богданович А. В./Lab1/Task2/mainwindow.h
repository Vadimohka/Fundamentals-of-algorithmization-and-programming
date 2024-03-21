#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "Figure.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rhombus.h"
#include "Square.h"
#include "Rectangle.h"
#include "Star5Pntd.h";
#include "Star6Pntd.h"
#include "Star8Pntd.h"
#include "Hexagon.h"
#include "Trapezoid.h"

#include "triangledialog.h"
#include "circledialog.h"
#include "rhombusdialog.h"
#include "squaredialog.h"
#include "rectangledialog.h"
#include "stardialog.h"
#include "hexagondialog.h"
#include "trapezoiddialog.h"


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
    void updateValues();
    int curF = 0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_moveUp_clicked();

    void on_pushButton_moveRight_clicked();

    void on_pushButton_moveDown_clicked();

    void on_pushButton_moveLeft_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_moveUp_pressed();

    void on_pushButton_moveUp_released();

    void moveUpSlot();
    void moveDownSlot();
    void moveRightSlot();
    void moveLeftSlot();
    void rotateRightSlot();
    void rotateLeftSlot();
    void upScaleSlot();
    void downScaleSlot();

    void on_pushButton_moveRight_pressed();

    void on_pushButton_moveRight_released();

    void on_pushButton_moveDown_pressed();

    void on_pushButton_moveDown_released();

    void on_pushButton_moveLeft_pressed();

    void on_pushButton_moveLeft_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_8_pressed();

    void on_pushButton_8_released();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

    void on_pushButton_6_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    Figure *figure = nullptr;
    QTimer *timer;
    QGraphicsEllipseItem *point = nullptr;
    QGraphicsScene *scene;
    TriangleDialog triangleD;
    CircleDialog circleD;
    RhombusDialog rhombusD;
    SquareDialog squareD;
    RectangleDialog rectangleD;
    StarDialog starD;
    HexagonDialog hexagonD;
    TrapezoidDialog trapezoidD;
    QVector<QPointF> points;

protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


};
#endif // MAINWINDOW_H
