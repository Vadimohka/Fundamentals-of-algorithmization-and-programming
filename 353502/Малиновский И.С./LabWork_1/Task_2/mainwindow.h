#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "hexagon.h"
#include "rhomb.h"

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

    void on_createTriangle_triggered();

    void on_createSquare_triggered();

    void on_moveFigure_triggered();

    void on_resizeFigure_triggered();

    void on_deleteFigure_triggered();

    void on_createCircle_triggered();

    void on_createStar5_triggered();

    void on_createStar6_triggered();

    void on_createStar8_triggered();

    void on_createParallelogram_triggered();

    void on_createRectangle_triggered();

    void on_createHexagon_triggered();

    void on_createRhomb_triggered();

    void on_rotateFigure_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector <Figure*> items;

    void updateScene();
    void printFigureSquare(const double& square);
    void printFigurePerimetr(const double& perimetr);
    void printFigureCentre(const QPointF& centre);
};
#endif // MAINWINDOW_H
