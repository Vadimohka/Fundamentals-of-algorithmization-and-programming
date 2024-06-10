#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "figures.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "romb.h"
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
    int angle = 0;

private slots:
    void on_moveButton_clicked();

    void on_deleteButton_clicked();

    void on_circleButton_clicked();

    void on_rectangleButton_clicked();

    void on_squareButton_clicked();

    void on_rombButton_clicked();

    void on_triangleButton_clicked();

    void on_starButton_clicked();

    void on_polygonButton_clicked();

    void on_leftRotationButton_pressed();

    void on_leftRotationButton_released();

    void on_rightRotationButton_pressed();

    void on_rightRotationButton_released();

    void on_minusSizeButton_pressed();

    void on_minusSizeButton_released();

    void on_plusSizeButton_pressed();

    void on_plusSizeButton_released();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Figure* figure;
    QTimer *timer;
    QVector<QPointF> points;

    int numberOfStar = 0;

    void setNewItem(Figure* newFigure, QString newFigureForm);
    void removingItem(Figure* deleteShape);
    void addingItem();
    void updatingFunction();
    void getCoordinates(QPointF center);
    void getSquare(qreal square);
    void getPerimetr(qreal perimetr);


};
#endif // MAINWINDOW_H
