#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "circle.h"
#include "figure.h"
#include "hexagon.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "ellipse.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "customeshape.h"
#include "customscene.h"

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

private:

    Ui::MainWindow *ui;
    CustomScene* scene;
    Figure* figure;
    CustomeShape* customeshapeTemp;
    CustomeShape* customeshape;
    bool wasChangingUsed = false;
    void putHexagon();
    void putCircle();
    void putTriangle();
    void putRectangle();
    void putSquare();
    void putEllipse();
    void putStar5();
    void putStar6();
    void putStar8();
    void putKaLL();
    void setSliderValue();
    void setValue();

private slots:
    void onMousePressed(const QPointF &position);
    void makeCenterX( int newCenterX );
    void makeCenterY( int newCenterY );
    void makeRadius( int newRadius );
    void makeLength( int newLength );
    void makeWidth( int newWidth );
    void makeSize( int newSize );
    void makeScale( int newScale );
    void makeRadius1( int newRadius1 );
    void makeRadius2( int newRadius2 );
    void change_figure( int currentIndex );
    void move_figure_x( int newX );
    void move_figure_y( int newY );
    void rotate_figure( int newAngle );

};
#endif // MAINWINDOW_H
