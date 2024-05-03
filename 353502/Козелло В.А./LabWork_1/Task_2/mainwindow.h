#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MAX_FIGURES 100

#include <QMainWindow>
#include "square.h"
#include "rectangle.h"
#include "hexagon.h"
#include "circle.h"
#include "rhomb.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "triangle.h"
#include "octagon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Figures** figure;
    QTimer* timer;

    bool isPaint = 1;
    int selected = 0;
    int count = 0;
protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    bool isDigit(QString);
    void showPar();

private slots:
    void on_drawButton_clicked();
    void on_squareButton_clicked();
    void on_rectButton_clicked();
    void on_circleButton_clicked();
    void on_Rhombbutton_clicked();
    void on_HexButton_clicked();
    void on_trianglebutton_clicked();
    void on_starButton_5_clicked();
    void on_starButton_6_clicked();
    void on_starButton_8_clicked();
    void on_octbutton_clicked();
    void on_plusButton_pressed();
    void on_minusbutton_pressed();
    void on_plusButton_released();
    void on_minusbutton_released();
    void on_lineCenterX_editingFinished();
    void on_lineCenterY_editingFinished();
    void on_rotateLButton_pressed();
    void on_rotateLButton_released();
    void on_rotateRButton_pressed();
    void on_rotateRButton_released();
    void on_lineEditXY_editingFinished();
    void on_lineEditPar_editingFinished();
    void on_leftButton_clicked();
    void on_rightButton_clicked();

    void resizePlus();
    void resizeMinus();
    void rotateR();
    void rotateL();
    void showData();
    void on_deleteButton_clicked();
};
#endif // MAINWINDOW_H
