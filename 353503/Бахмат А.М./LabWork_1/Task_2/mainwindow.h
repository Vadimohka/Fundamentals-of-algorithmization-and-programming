#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscene.h>
#include "myfigure.h"
#include "circle.h"
#include "hexagon.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "ellipse.h"
#include "fivepointedstar.h"
#include "sixpontedstar.h"
#include "eightpointedstar.h"
#include "paintedfigure.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    MyScene *scene;
    MyFigure *figure;
    PaintedFigure *paintedFigure{};
    bool _wasPaint = false;
    void putHexagon();
    void putCircle();
    void putTriangle();
    void putRectangle();
    void putSquare();
    void putEllipse();
    void putFivePointedStar();
    void putSixPointedStar();
    void putEightPointedStar();
    void putPaintedFigure();
    void setSliderValue();
    void setValue();
    const int _sliderValue = 50;
private slots:
    void onMousePressed(const QPointF &pos);
    void setCenterX(int newCenterX);
    void setCenterY(int newCenterY);
    void setRadius(int newRadius);
    void setHeight(int newHeight);
    void setWidth(int newWidth);
    void setSize(int newSize);
    void setScale(int newScale);
    void setRadius1(int newRadius1);
    void setRadius2(int newRadius2);
    void changeFigure(int currentIndex);
    void moveFigureByX(int newX);
    void moveFigureByY(int newY);
    void rotateFigure(int newAngle);
};
#endif // MAINWINDOW_H
