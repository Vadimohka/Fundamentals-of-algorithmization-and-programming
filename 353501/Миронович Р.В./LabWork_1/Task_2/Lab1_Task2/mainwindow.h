#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "figures.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "hexagon.h"
#include "rhombus.h"
#include "starFive.h"
#include "starSix.h"
#include "starSeven.h"
#include "starEight.h"
#include "risovalka.h"

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


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void GetInfo();

    void sp_status();
private slots:
    void RotateLeft();
    void RotateRight();
    void SizeUp();
    void SizeDown();
    void on_TriangleButton_toggled(bool checked);

    void on_CircleButton_toggled(bool checked);

    void on_RhombusButton_toggled(bool checked);

    void on_RectangleButton_toggled(bool checked);

    void on_HexagonButton_toggled(bool checked);

    void on_PolylineButton_toggled(bool checked);

    void on_SqauerButton_toggled(bool checked);

    void on_Star5Button_toggled(bool checked);

    void on_Star6Button_toggled(bool checked);

    void on_Star7Button_toggled(bool checked);

    void on_Star8Button_toggled(bool checked);

    void on_RightRotateButton_released();
    void on_RightRotateButton_pressed();
    void on_LeftRotateButton_released();
    void on_LeftRotateButton_pressed();

    void on_PlusButton_pressed();
    void on_PlusButton_released();
    void on_MinusButton_pressed();
    void on_MinusButton_released();

    void on_ClearButton_clicked();


    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer;
    Triangle *triangle=new Triangle;
    Circle *circle=new Circle;
    Rectangle *rectangle=new Rectangle;
    Rectangle *square=new Rectangle;
    Hexagon *hex=new Hexagon;
    Rhombus *romb=new Rhombus;
    star5 *s5=new star5;
    star6 *s6=new star6;
    star7 *s7=new star7;
    star8 *s8=new star8;
    Polyline *poly = new Polyline;
    figure **figures=new figure *[11];// Array of figures to more comfortable work through them ID
    int8_t FigureID=0;
    bool sp=false;

};
#endif // MAINWINDOW_H
