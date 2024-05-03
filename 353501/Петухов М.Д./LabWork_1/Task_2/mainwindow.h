#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <circle.h>
#include <QTimer>
#include <figure.h>
#include <rectangle.h>
#include <triangle.h>
#include <rhombus.h>
#include <star.h>
#include <hexagon.h>
#include <customscene.h>
#include <polyline.h>

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
    void onMousePressed(const QPointF &position);

    void on_increase_pressed();
    void on_increase_released();
    void upSize();

    void on_decrease_pressed();
    void on_decrease_released();
    void downSize();

    void on_moveRight_pressed();
    void on_moveRight_released();
    void moveRight();

    void on_moveDown_pressed();
    void on_moveDown_released();
    void moveDown();

    void on_moveLeft_pressed();
    void on_moveLeft_released();
    void moveLeft();

    void on_moveUp_pressed();
    void on_moveUp_released();
    void moveUp();

    void selectFigure();

    void valueCsideChange(double arg1);
    void valueAsideChange(double arg1);
    void valueBsideChange(double arg1);

    void on_rotateRight_pressed();
    void on_rotateRight_released();
    void rotateRight();

    void on_rotateLeft_pressed();
    void on_rotateLeft_released();
    void rotateLeft();

    void on_innerRadiusUp_pressed();
    void starInnerRadUp();
    void on_innerRadiusUp_released();

    void on_outerRadiusUp_pressed();
    void starOuterRadUp();
    void on_outerRadiusUp_released();

    void on_vertexes_valueChanged(int arg1);
    void PolygonVertexes(int arg1);

    void innerRadiusDownPressed();
    void innerRadiusDownRealesed();
    void setInnerRadiusDown();

    void outerRadiusDownPressed();
    void setOuterRadiusDown();
    void outerRadiusDownRealesed();

    void setWidthRectangle(double arg1);
    void setHeightRectangle(double arg1);

    void setRhombHeight(double arg1);
    void setRhombWidth(double arg1);

    void disconnectCenter();
    void connectCenter();
    void changePolyline();

private:
    int selectedFigure = 10;
    Figure **figuresArray;
    Circle* circle;
    Rectangle* rectangle;
    Triangle* triangle;
    Rhombus* rhombus;
    Star* star;
    Hexagon* hexagon;
    QTimer* timer;
    Ui::MainWindow *ui;
    polyline* myPolyline;
    CustomScene *Myscene;
    void setInfo();
    bool wasChangingUsed = false;
};
#endif // MAINWINDOW_H
