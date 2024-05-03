#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFormLayout>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLabel>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QComboBox>
#include<QPushButton>
#include<QTimer>
#include<QPainter>
#include<QGroupBox>
#include<QGridLayout>
#include <QColorDialog>
#include<QSpinBox>
#include"shape.h"
#include"triangle.h"
#include"rhomb.h"
#include"square.h"
#include"circle.h"
#include"rectangle.h"
#include"hexagon.h"
#include"parallelogramm.h"
#include"star.h"
#include"custom.h"

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
    void selectFigure(int index);

    void ResetCenter();

    QPointF anchorPoint();

    void closeButton();

    void sizeUp_on();

    void sizeUp_of();

    void sizeU();

    void sizeDown_on();

    void sizeDown_of();

    void sizeD();

    void rotateLeft_on();

    void rotateLeft_of();

    void rotateLeft();

    void rotateRight_on();

    void rotateRight();

    void rotateRight_of();

    void rectWidth();

    void rectHeight();

    void squareSide();

    void SideA();

    void SideB();

    void SideC();

    void diag1();

    void diag2();

    void circleRadius();

    void hexRadius();

    void parallsideA();

    void parallsideB();

    void changeStarPts();

    void starOuterR();

    void starInnerR();

    void clearPts();

    void penColor();

    void PenWidth();

    void setDrawMode();
protected:
    void paintEvent(QPaintEvent *) override;

    void mouseMoveEvent(QMouseEvent*e)override;

private:
    Ui::MainWindow *ui;

    Shape **arr=new Shape*[10];
    QWidget *widget;

    //Layout
    QWidget *infoWidget;
    QVBoxLayout *infoLayout;
    QVBoxLayout *figureLayout;
    QVBoxLayout *optionsLayout;
    QVBoxLayout *transformLayout;
    QVBoxLayout *rotateLayout;
    QHBoxLayout *scaleShow;

    //Boxes
    QGroupBox *figure;
    QComboBox *figures;
    QComboBox *drawMode;
    QComboBox *pen;
    QGroupBox *option;
    QGroupBox *transf;
    QGroupBox *rotat;
    QSpinBox *spinX;
    QSpinBox *spinY;
    QSpinBox *A;
    QSpinBox *B;
    QSpinBox *C;
    QSpinBox *D;
    QSpinBox *E;
    QSpinBox *F;
    QSpinBox *G;
    QSpinBox *H;
    QSpinBox *I;
    QSpinBox *J;
    QSpinBox *K;
    QSpinBox *L;
    QSpinBox *width;
    QSpinBox *outerR;
    QSpinBox *innerR;
    QSpinBox *points;
    QGraphicsView *view;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;

    //Buttons
    QPushButton *closeBtn;
    QPushButton *sizeUp;
    QPushButton *sizeDown;
    QPushButton *rotateL;
    QPushButton *rotateR;
    QPushButton *resetCenter;
    QPushButton *clear;

    //Labels
    QLabel *color;
    QLabel *penWidth;
    QGridLayout *info;
    QLabel *Figure;
    QLabel *options;
    QLabel *massCenter;
    QLabel *perimetr;
    QLabel *area;
    QLabel *text1;
    QLabel *text2;
    QLabel *text3;
    QLabel *text4;
    QLabel *transform;
    QLabel *scale;
    QLabel *rotate;
    QLabel *Center;
    QLabel *yLabel;
    QLabel *sideA;
    QLabel *sideB;
    QLabel *sideC;
    QLabel *diagonal1;
    QLabel *diagonal2;
    QLabel *radius;
    QLabel *R1;
    QLabel *R2;
    QLabel *PTS;
    QLabel *mode;
    //Shapes
    Triangle *triangle;
    Square *square;
    Rhomb *rhomb;
    Circle *circle;
    Rectangle *rect;
    Hexagon *hex;
    Parallelogramm *parall;
    Star *star;
    Custom *custom;

    int ID=0;

    void Info();
};
#endif // MAINWINDOW_H
