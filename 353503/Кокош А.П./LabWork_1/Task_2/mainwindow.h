#ifndef MAINWINDOW_H
#define MAINWINDOW_H

enum { NUMOFFIGURES = 10 };

#include <QMainWindow>
#include <QtWidgets>
#include "./фигуры/circle.h"
#include "./фигуры/figures.h"
#include "./фигуры/hexagon.h"
#include "./фигуры/polyline.h"
#include "./фигуры/rhombus.h"
#include "./фигуры/square.h"
#include "./фигуры/triangle.h"
#include "./фигуры/Звёзды/star5.h"
#include "./фигуры/Звёзды/star6.h"
#include "./фигуры/Звёзды/star7.h"
#include "./фигуры/Звёзды/star8.h"

/*
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
*/
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    //Ui::MainWindow *ui;

    figures **figuresArray = new figures *[NUMOFFIGURES];

    //My buttons
    QRadioButton *triangleButton;
    QRadioButton *circleButton;
    QRadioButton *rhombusButton;
    QRadioButton *rectangleButton;
    QRadioButton *starButton;
    QSpinBox *spin5to8;
    QRadioButton *hexagonButton;
    QRadioButton *polylineButton;

    //Move by cord
    QSpinBox *spinForX;
    QSpinBox *spinForY;
    QPushButton *moveByCord;

    QRadioButton *drawButton;
    QRadioButton *moveButton;
    QPushButton *sizePlus;
    QPushButton *sizeMinus;
    QPushButton *rotateLEFT;
    QPushButton *rotateRIGHT;

    //My Labels
    QLabel *textCenter;
    QLabel *textSquare;
    QLabel *textPerimeter;

    //My Timer
    QTimer *timer = new QTimer;

    //My figures
    triangle *myTriangle = new triangle;
    circle *myCircle = new circle;
    rhombus *myRhombus = new rhombus;
    square *mySquare = new square;
    hexagon *myHexagon = new hexagon;
    polyline *myPolyline = new polyline;
    star5 *myStar5 = new star5;
    star6 *myStar6 = new star6;
    star7 *myStar7 = new star7;
    star8 *myStar8 = new star8;

    bool isShift = false;
    int selectedFigureID = 0;
    int cnt = 0;

    void setInfo();

private slots:

    void selectFigure();

    void moveByCordButtonClicked();

    void closeButtonClicked();

    void surpriseButtonClicked();

    void upSize();

    void downSize();

    void rotateLeft();

    void rotateRight();

    void star();

    void on_sizePlus_pressed();

    void on_sizePlus_released();

    void on_sizeMinus_pressed();

    void on_sizeMinus_released();

    void on_rotateLEFT_pressed();

    void on_rotateLEFT_released();

    void on_rotateRIGHT_pressed();

    void on_rotateRIGHT_released();

protected:
    void paintEvent(QPaintEvent * /*event*/) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *keyEvent) override
    {
        if (keyEvent->modifiers() & Qt::ShiftModifier) {
            isShift = true;
        }
    }

    void keyReleaseEvent(QKeyEvent *keyEvent) override
    {
        if (!(keyEvent->modifiers() & Qt::ShiftModifier)) {
            isShift = false;
        }
    }
};
#endif // MAINWINDOW_H
