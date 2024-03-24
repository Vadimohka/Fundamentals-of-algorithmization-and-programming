#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include <QComboBox>
#include <QFile>

#include "customScene.h"
#include "shapeCircle.h"
#include "shapeTriangle.h"
#include "shapeSquare.h"
#include "shapeRectangle.h"
#include "shapeRhombus.h"
#include "shapeStar.h"
#include "shapeRightPolygon.h"
#include "shapePolyline.h"


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

    qreal diffX = 0;
    qreal diffY = 0;
    qreal prevX;
    qreal prevY;
    qreal incrementX;
    qreal incrementY;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    CustomScene* customScene;

    //timer
    QTimer* timer;

    //startPoint
    QPointF startPoint;

    int selectedShapeID = -1;

    int currentValue = 0;
    int targetValue;

    //shapes
    ShapeCircle *circle;
    ShapeTriangle *triangle;
    ShapeSquare *square;
    ShapeRectangle *rectangle;
    ShapeRhombus *rhombus;
    ShapeStar *star;
    ShapeRightPolygon *rightPolygon;
    ShapePolyline *polyline;

    //shapes list
    Shape* shapesArray[8];
    QPainter painter;

private slots:
    void setInfo();

    void selectShape(int index);

    void setDetached(bool detached);

    void increaseSizePressed();
    void increaseSizeReleased();
    void decreaseSizePressed();
    void decreaseSizeReleased();

    void rotateLeftPressed();
    void rotateLeftReleased();
    void rotateRightPressed();
    void rotateRightReleased();

    void changeXStart(int value);
    void xChanged();
    void changeXComplete();
    void changeYStart(int value);
    void yChanged();
    void changeYComplete();

    void side1Changed(qreal value);
    void side2Changed(qreal value);
    void side3Changed(qreal value);

    void angleChanged(qreal value);

    void pointsChanged(int value);
    void radius1Changed(qreal value);
    void radius2Changed(qreal value);

    void upSize();
    void downSize();

    void rotateLeft();
    void rotateRight();

    void handleMousePressed(const QPointF& position);

    void handleShapeCreated();

};
#endif // MAINWINDOW_H
