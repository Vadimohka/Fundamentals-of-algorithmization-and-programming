#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "rhombus.h"
#include "square.h"
#include "hexagon.h"
#include "fivestar.h"
#include "sixstar.h"
#include "eightstar.h"

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

public slots:
    void updateCenterOfMass(double x, double y);

private slots:
    void on_rectangle_clicked();

    void on_calculate_clicked();

    void on_turnclockwise_pressed();

    void on_turncounterclockwise_pressed();

    void on_turnclockwise_released();

    void on_turncounterclockwise_released();

    void on_moveCenterButton_clicked();

    void on_scaleUpButton_pressed();

    void on_scaleUpButton_released();

    void on_scaleDownButton_pressed();

    void on_scaleDownButton_released();

    void on_moveup_pressed();

    void on_moveup_released();

    void on_moveleft_pressed();

    void on_moveleft_released();

    void on_moveright_pressed();

    void on_moveright_released();

    void on_movedown_pressed();

    void on_movedown_released();

    void on_triangle_clicked();

    void on_circle_clicked();

    void on_rhombus_clicked();

    void on_square_clicked();

    void on_hexagon_clicked();

    void on_fivestar_clicked();

    void on_sixstar_clicked();

    void on_eightstar_clicked();

    void on_secretfigure_clicked();

private:
    Ui::MainWindow *ui;
    Shape *currentShape;
    double width;
    double height;
    double side;
    double sideSquare;
    double diameter;
    double diagonal1;
    double diagonal2;
    double sideHexagon;
    double fradius;
    double sradius;
    double eradius;
    Rectangle* rect;
    Triangle* tri;
    Circle* cir;
    Rhombus* rhom;
    Square* square;
    Hexagon* hex;
    FiveStar* fstar;
    SixStar* sstar;
    EightStar* estar;
    QGraphicsScene *scene;
    QTimer *timerClockwise;
    QTimer *timerCounterClockwise;
    QTimer *timerScaleUp;
    QTimer *timerScaleDown;
    QTimer *timerMoveUp;
    QTimer *timerMoveDown;
    QTimer *timerMoveRight;
    QTimer *timerMoveLeft;
    QLabel* xLabel;
    QLabel* yLabel;
};

#endif // MAINWINDOW_H
