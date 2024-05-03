#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "figure.h"
#include "triangle.h"
#include "circle.h"
#include "rhomb.h"
#include "square.h"
#include "rectangle.h"
#include "fivepointedstar.h"
#include "sixpointedstar.h"
#include "eightpointedstar.h"
#include "hexagon.h"
#include "trapezoid.h"

#include "triangledialog.h"
#include "circledialog.h"
#include "rhombdialog.h"
#include "squaredialog.h"
#include "rectangledialog.h"
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
    void moveUpSlot();
    void moveDownSlot();
    void moveRightSlot();
    void moveLeftSlot();
    void rotateRightSlot();
    void rotateLeftSlot();
    void upScaleSlot();
    void downScaleSlot();

    void on_toMoveLeftButton_clicked();

    void on_toMoveRightButton_clicked();

    void on_toMoveUpButton_clicked();

    void on_toMoveDownButton_clicked();

    void on_toDrawButton_clicked();

    void on_toRotateLeftButton_clicked();

    void on_toRotateRightButton_clicked();

    void on_toIncreaseSizeButton_clicked();

    void on_toReduceSizeButton_clicked();

    void on_xSpinBox_valueChanged(int x);

    void on_ySpinBox_valueChanged(int y);

    void on_toDeleteButton_clicked();

    void on_toMoveUpButton_pressed();

    void on_toMoveUpButton_released();

    void on_toMoveRightButton_pressed();

    void on_toMoveRightButton_released();

    void on_toMoveDownButton_pressed();

    void on_toMoveDownButton_released();

    void on_toMoveLeftButton_pressed();

    void on_toMoveLeftButton_released();

    void on_toRotateLeftButton_pressed();

    void on_toRotateLeftButton_released();

    void on_toRotateRightButton_pressed();

    void on_toRotateRightButton_released();

    void on_toIncreaseSizeButton_pressed();

    void on_toIncreaseSizeButton_released();

    void on_toReduceSizeButton_pressed();

    void on_toReduceSizeButton_released();

private:
    Ui::MainWindow *ui;
    Figure *figure = nullptr;
    QTimer *timer;
    QGraphicsEllipseItem *point = nullptr;
    QGraphicsScene *scene;
    TriangleDialog triangleD;
    CircleDialog circleD;
    RhombDialog rhombD;
    SquareDialog squareD;
    RectangleDialog rectangleD;
    HexagonDialog hexagonD;
    TrapezoidDialog trapezoidD;

protected:
    void paintEvent(QPaintEvent*);
};
#endif // MAINWINDOW_H
