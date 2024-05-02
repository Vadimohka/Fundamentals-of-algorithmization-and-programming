#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>

#include "GeomFigure.h"
#include "Circle.h"
#include "Triang.h"
#include "Pramouh.h"
#include "Kvadr.h"
#include "Shestiuh.h"
#include "MyLine.h"
#include "Star_5.h"
#include "Star_6.h"
#include "Star_8.h"
#include "Romb.h"

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

    virtual void paintEvent(QPaintEvent *event);

private slots:

    virtual void mousePressEvent(QMouseEvent *me);
    virtual void mouseMoveEvent(QMouseEvent *me);
    virtual void mouseReleaseEvent(QMouseEvent *me);

    void on_pushButton_15_pressed();
    void on_pushButton_16_pressed();

    void on_pushButton_26_pressed();
    void on_pushButton_27_pressed();

    void on_my_clicked(bool checked);


    void on_pushButton_15_clicked(bool checked);
    void on_pushButton_16_clicked(bool checked);
    void on_pushButton_26_clicked(bool checked);
    void on_pushButton_27_clicked(bool checked);

private:
    GeomFigure *fgr = nullptr;
    Ui::MainWindow *ui;
    QPointF MouseClick;
    int touch, pointsNum;
    const int pointsMax = 500;
    bool block = false;
};
#endif // MAINWINDOW_H
