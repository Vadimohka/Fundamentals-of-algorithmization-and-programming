#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "romb.h"
#include "triangle.h"
#include "virtualshape.h"
#include "star.h"


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
    void on_moveButton_clicked();

    void on_deleteButton_clicked();

    void on_circleButton_clicked();

    void on_rectangleButton_clicked();

    void on_squareButton_clicked();

    void on_rombButton_clicked();

    void on_resizeButton_clicked();

    void on_triangleButton_clicked();

    void on_starButton_clicked();

    void on_minusButton_clicked();

    void on_plusButton_clicked();

    void on_polygonButton_clicked();

    void on_updatingButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Shape* shape;
    QVector<QPointF> points;

    int triangle = -1;
    int numberOfStar = 5;

    void setNewItem(Shape* newShape, QString newShapeForm);
    void removingItem(Shape* deleteShape);
    void addingItem();
    void updatingFunction();
    void getCoordinates(QPointF center);
    void getSquare(qreal square);
    void getPerimetr(qreal perimetr);

    void createTriangle(QPointF point);
    void clearTriangle();
};
#endif // MAINWINDOW_H
