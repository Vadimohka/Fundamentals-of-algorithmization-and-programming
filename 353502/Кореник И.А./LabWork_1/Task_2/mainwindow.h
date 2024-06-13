#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figure.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "rhomb.h"
#include "square.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "polygon_n.h"
#include <vector>
#include <QLabel>
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
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

private:
    Ui::MainWindow *ui;



    std::vector<Figure*> figuresArray;
    std::vector<QPolygonF>polygons;

    QGroupBox* selectLay;
    QGroupBox* infoLay;
    QGroupBox* buttonLay;

    QRadioButton* rectangleRadio;
    QRadioButton* triangleRadio;
    QRadioButton* circleRadio;
    QRadioButton* rhombRadio;
    QRadioButton* squareRadio;
    QRadioButton* hexagonRadio;
    QRadioButton* star5Radio;
    QRadioButton* star6Radio;
    QRadioButton* star8Radio;
    QRadioButton* polygon_NRadio;
    QSpinBox* polygonSpin;


    QLabel* areaT;
    QLabel* areaL;

    QLabel* centreL;
    QLabel* centreT;

    QLabel* perimetrL;
    QLabel* perimetrT;

    QPushButton* rotationLeft;
    QPushButton* rotationRight;


    QPushButton* rotation;
    QLineEdit* enterAngle;

    QPushButton* increaseButton;
    QPushButton* decreaseButton;

    QGroupBox* modesLay;
    QRadioButton* createMode;
    QRadioButton* moveMode;

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent*);

    QTimer* rotationTimer;

    int num = -1;

    int countForTriangle = 0;

    int selectedNum = -1;

private slots:
    void on_rotationLeft_pressed();

    void on_rotationLeft_released();

    void on_rotationRight_pressed();

    void on_rotationRight_released();

    void on_rotation_clicked();

    void on_increaseButton_pressed();

    void on_increaseButton_released();

    void on_decreaseButton_pressed();

    void on_decreaseButton_released();

    void updatePolygon(int selected);

    void updateInfo();
};
#endif // MAINWINDOW_H
