#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <shape.h>
#include "customscene.h"
#include "polyline.h"
#include "point.h"

//-setTransformOriginPoint(point)
//->rotation()+1

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

    // void mouseMoveEvent(QMouseEvent*)override;
    // void mousePressEvent(QMouseEvent*)override;
    // void paintEvent(QPaintEvent*) override;


private:
    Ui::MainWindow *ui;
    Shape *item=nullptr;
    point*pivot;
    QTimer *timer = nullptr;
   // QGraphicsScene *scene;
    CustomScene*scene;
    ShapePolyline*polyline;
    bool added = false;
    bool created = false;



    bool isPoly=false;

    bool isDraw;
 private slots:
    void combo_clicked(int index);
    void sizeUpPressed();
    void sizeUpReleased();
    void sizeDownPressed();
    void sizeDownReleased();
    void sizePlus();
    void sizeMinus();
    void SetValues();
    void xChanged(int str);
    void yChanged(int str);
    void rotationL_on();
    void rotationL_off();
    void rotationR_on();
    void rotationR_off();

    void rotRight();
    void rotLeft();

    void nChanged(int num);
    void radAChanged(int num);
    void radBChanged(int num);
    void hideAll();

    void FRadChanged();
    void SRadChanged();

    void FRadStart(int);
    void SRadStart(int) ;

    void heiStart(int);
    void heiChanged();

    void widStart(int);
    void widChanged() ;

    void fStart(int);
    void fChanged();

    void handleMousePressed(const QPointF& position);
    void handleShapeCreated();

   /* void sStart(int);
    void sChanged();

    void tStart(int);
    void tChanged();*/

    void diam1Start(double);
    void diam1Changed();

    void diam2Start(double);
    void diam2Changed() ;

    void ui_back();

    void edgsChanged(int);

    void actDraw();

};
#endif // MAINWINDOW_H
