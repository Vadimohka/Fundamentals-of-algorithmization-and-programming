#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "polygon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"
#include "star.h"
#include "triangle.h"
#include "ellipse.h"
#include "circle.h"
#include "custom.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QGroupBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(int index);

    void on_doubleCoordX_valueChanged(double arg1);

    void on_doubleCoordY_valueChanged(double arg1);

    void resizeEvent(QResizeEvent *event) override;

    void on_doubleRotateBox_valueChanged(double arg1);

    void on_doubleScaleBox_valueChanged(double arg1);

    void on_Reset_clicked();

    void on_doubleCoordX_2_valueChanged(double arg1);

    void on_doubleCoordY_2_valueChanged(double arg1);

    void on_doubleSideA_valueChanged(double arg1);

    void on_doubleSideB_valueChanged(double arg1);

    void on_doubleMajorAxis_valueChanged(double arg1);

    void on_doubleMinorAxis_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSideSqr_valueChanged(double arg1);

    void on_doubleRadiusCircle_valueChanged(double arg1);

    void on_StarPoints_valueChanged(int arg1);

    void on_doubleRadiusAStar_valueChanged(double arg1);

    void on_doubleRadiusBStar_valueChanged(double arg1);

    void on_doubleSidePoly_valueChanged(double arg1);

    void on_PolyPoints_valueChanged(int arg1);

    void on_TriangleSideA_valueChanged(double arg1);

    void on_TriangleSideB_valueChanged(double arg1);

    void on_TriangleSideC_valueChanged(double arg1);

    void Parameters();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene = nullptr;
    Shape *shape = nullptr;
    QGroupBox *current_Box = nullptr;
    Custom *custom = nullptr;
    Circle *circle = nullptr;
    Ellipse *ell = nullptr;
    Polygon *poly = nullptr;
    Rectangle *rect = nullptr;
    Rhombus *rhomb = nullptr;
    Square *square = nullptr;
    Star *star = nullptr;
    Triangle *triangle = nullptr;
};
#endif // MAINWINDOW_H
