#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <queue>
#include <iostream>
#include <vector>
#include <QKeyEvent>
#include <QtGui>
#include "paintscene.h"
#include "mouse.h"
#include "figure.h"
#include "triangle.h"
#include "rhombus.h"
#include "ellipse.h"
#include "foursquare.h"
#include "star.h"
#include "rectangle.h"
#include "hexagon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum currentType
{
    triangleMode,
    rhombusMode,
    ellipseMode,
    squareMode,
    star6Mode,
    star8Mode,
    circleMode,
    hexagonMode,
    star5Mode,
    rectangleMode,
    editMode,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    mouseCatcher *mouse;
    currentType current{currentType::triangleMode};
    Ui::MainWindow *ui;
    std::queue<QPointF>* points;
    paintScene* mainScene;
    std::vector<figure*>* figures;
    int currentFigureIterator;
    void processMouseClick(int x, int y);
    void processMouseDrag(int x1, int y1, int x2, int y2);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void keyPressEvent(QKeyEvent *event) override;

    void on_pushButtonTriangle_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();
};
#endif // MAINWINDOW_H
