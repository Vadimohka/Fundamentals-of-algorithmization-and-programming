#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "par_polygon.h"
#include "circle.h"
#include "triangle.h"
#include "rect.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"
#include "hexagon.h"
#include "yourdrawing.h"
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
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setup_Buttons();
private slots:
    void on_bntResize_clicked();

    void on_bntNewAngle_clicked();

    void on_bntSandP_clicked();

    void on_bntMovement_clicked();

    void on_bntSave_clicked();

    void on_bntsaveok_clicked();

private:
    Ui::MainWindow *ui;
    int x = 0;
    int y = 0;
    FivePointedStar *figure5;
    SixPointedStar *figure6;
    EightPointedStar *figure8;
    Circle *cir;
    Triangle *triangle;
    Rect *rect;
    Square *square;
    Parallelogram *par;
    Rhombus *romb;
    Hexagon *hex;
    YourDrawing *yd;
    QVector <qreal> coord;
    QVector <QPointF> vec{QPointF(100, 0), QPointF(125, 50), QPointF(200, 50), QPointF(140, 90), QPointF(160, 150), QPointF(100, 110), QPointF(40, 150), QPointF(60, 90), QPointF(0, 50), QPointF(75, 50)};
    QVector<QPointF> star6 {
        QPointF(100, 50), QPointF(135, 20), QPointF(175, 40),
        QPointF(244, 42), QPointF(208, 97), QPointF(251, 155),
        QPointF(175, 157), QPointF(135, 220), QPointF(100, 151),
        QPointF(35, 155), QPointF(64, 97), QPointF(26, 50)
    };
    QVector<QPointF> star8 {
        QPointF(150, 75), QPointF(180, 125), QPointF(250, 125), QPointF(225, 175),
        QPointF(300, 225), QPointF(225, 275), QPointF(250, 325), QPointF(180, 325),
        QPointF(150, 375), QPointF(120, 325), QPointF(50, 325), QPointF(75, 275),
        QPointF(0, 225), QPointF(75, 175), QPointF(50, 125), QPointF(120, 125)
    };
    QVector <QPointF> vec_r{QPointF(20, 60), QPointF(40, 20), QPointF(60, 60), QPointF(40, 100)};
    QTimer *timer;
    const int time_animation = 5000;
    int turn_angle = -12*M_PI;
    double mov1 = 0.995;
    double mov2 = 1.003;
    double mov;
    QPointF mov_point1 = QPointF(250, 250);
    QPointF mov_point2 = QPointF(-250, -250);
    QPointF mov_point;
    int was_figure = -1;
    QVector<QPointF> objectPoints;
    bool isDrawing;
    bool xz_kak_nazvat = false;
};
#endif // MAINWINDOW_H
