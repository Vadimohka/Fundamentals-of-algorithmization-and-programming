#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"
#include "star.h"
#include "rhombus.h"
#include "hexagon.h"
#include "customScene.h"
#include "customShape.h"
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
    void updateShape(int index);
    void moveleft();
    void moveright();
    void moveup();
    void movedown();
    void zoomIn();
    void zoomOut();
    void moveCenterX(double x);
    void moveCenterY(double y);
    void rotateClockwise();
    void rotateUntiClockwise();
    void rezTr1(int newside);
    void rezTr2(int newside);
    void rezTr3(int newside);
    void resRect1(int newwidth);
    void resRect2(int newhieght);
    void resSquare(int newside);
    void changerad1(int newrad1);
    void changerad2(int newrad2);
    void numberApex(int newapexes);
    void changeRhomA(double newangle);
    void changeRhomS(double newside);
    void changeSideHex(double newside);
    void changeApexHex(double newapex);
    void setInfo();
    void handlMousePress(const QPointF &Position);
    void disconCustom();
protected:
    Ui::MainWindow *ui;
    customScene *scene;
    Shape *shapes[8]; 
    int index; 
    Shape* currentIndex;
    
};
