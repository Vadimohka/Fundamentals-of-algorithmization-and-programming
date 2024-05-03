#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPointF>
#include <QEvent>
#include <QDebug>
#include <QTimer>

#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "triangle.h"
#include "hexagon.h"
#include "circle.h"
#include "star.h"
#include "ellipse.h"
#include "line.h"
#include "shape.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *pe);
    void mousePressEvent(QMouseEvent *mpe);
    void mouseMoveEvent(QMouseEvent *mme);



    ~MainWindow();

private slots:
    void on_BRotateL_pressed();

    void on_BRotateL_released();

    void on_BRotateR_pressed();

    void on_BRotateR_released();

    void on_BMSize_pressed();

    void on_BMSize_released();

    void on_BPSize_pressed();

    void on_BPSize_released();

private:
    Ui::MainWindow *ui;
    Figure* mFigure = nullptr;
    QVector<Figure*> figures ;
    QPainter* pntr;
    QPointF lastMousePoint;
    QTimer* timer;
    int customFlagNum;
    QPointF changedPoint;

};


#endif // MAINWINDOW_H
