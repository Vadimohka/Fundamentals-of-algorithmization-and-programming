#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QTimer>
#include "rectungle.h"
//#include "base.h"
#include "circle.h"
#include "trungle.h"
#include "romb.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void plusZoom();

    void minusZoom();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void showPerimetr(double perimetr);

    void showSquare(double square);

    void mUp();

    void mDown();

    void mLeft();

    void mRight();

    void rotateL();

    void rotateR();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_pushButton_7_pressed();

    void on_pushButton_7_released();

    void on_pushButton_8_pressed();

    void on_pushButton_8_released();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    base *basa;
    Ui::MainWindow *ui;
    QGraphicsView *view;
    QGraphicsScene *scene;
    //rectungle *rectangle;
    QTimer *plus;
    QTimer *minus;
    QTimer *up;
    QTimer *down;
    QTimer *left;
    QTimer *right;
    QTimer *rotateLef;
    QTimer *rotateRig;
    int x;
    int y;
    int abss;
};
#endif // MAINWINDOW_H
