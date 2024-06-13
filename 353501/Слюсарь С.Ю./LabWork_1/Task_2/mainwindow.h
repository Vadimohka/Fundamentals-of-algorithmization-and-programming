#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include "hexagon.h"
#include "rectangle.h"
#include "rhomb.h"
#include "round.h"
#include "square.h"
#include "triangle.h"
#include "fivepointedstar.h"
#include "sixpointedstar.h"
#include "eightpointedstar.h"

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
public:
    int Error_ = 0;
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *animationTimer;
    QTimer *animationTimerBack;
    QTimer *rotationAnim;
    QTimer *rotationAnimBack;
    QTimer *scaleAnim;
    QTimer *scaleAnimBack;
    Hexagon *hex;
    Rectangle *rect;
    Rhomb *rhomb;
    Round *round;
    Square *square;
    Triangle *triangle;
    FivePointedStar *fivePointedStar;
    SixPointedStar *sixPointedStar;
    EightPointedStar *eightPointedStar;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    double startX = 0;
    double startY = 0;
    double endX = 0;
    double endY = 0;
    int flag = 1;
    int whoOnScene = 0;

private slots:

    void on_toRight_clicked();
    void on_toLeft_clicked();
    void on_Rhomb_clicked();
    void on_Round_clicked();
    void on_Square_clicked();
    void on_Triangle_clicked();
    void on_Rectangle_clicked();
    void on_Hexagon_clicked();
    void on_RotateBack_clicked();
    void on_ScaleChange_clicked();
    void on_ScaleChangeBack_clicked();
    void on_Perimetr_clicked();
    void on_Rotate_clicked();
    void on_Area_clicked();
    void on_CenterOfMass_clicked();
    void on_FivePointedStar_clicked();
    void on_SixPointedStar_clicked();
    void on_EightPointedStar_clicked();
    void on_Clear_clicked();
};
#endif // MAINWINDOW_H
