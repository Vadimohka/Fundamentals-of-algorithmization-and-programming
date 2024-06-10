#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QTimer>

#include "circle.h"
#include "customscene.h"
#include "ellips.h"
#include "hexagon.h"
#include "rectangle.h"
#include "rhomb.h"
#include "shape.h"
#include "square.h"
#include "star_5.h"
#include "star_6.h"
#include "star_8.h"
#include "triangle.h"

enum Currect_Shape
{
    triangle = 0,
    circle,
    rectangle,
    square,
    ellipse,
    rhomb,
    star_5,
    star_6,
    star_8,
    hexagon
};

QT_BEGIN_NAMESPACE
namespace Ui
{
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
    CustomScene *scene;

    int FigureID = Currect_Shape::triangle;
    QVector<Shape*>all_figures[10];//// bad make just simple  QVector<Shape*>all_figures;
    QVector<Shape*> type;
    Rhomb *rhomb;
    Ellips *ellips;
    Rectangle *rectangle;
    Square *square;
    Triangle *triangle;
    Circle *circle;
    Star_5 *star_5;
    Star_6 *star_6;
    Star_8 *star_8;
    Hexagon *hexagon;

    int count = 0;
    bool isClck_R = 0;
    bool isClck_L = 0;
    QColor color;
    Shape *item = nullptr;
    QPointF targetPoint;
    QPointF start;
    QPointF end;
    QVector<QPointF> p;
    QTimer *timer;
private slots:
    void selectFigure();
    void selectColor();
    void selectFilling();
    void setInfo(Shape*);
    void on_comboBox_Shape_currentIndexChanged(int index);
    void on_comboBox_Filling_currentIndexChanged(int index);
    void onTimerTimeout();
    void slotDelete();
    void on_btn_select_color_clicked();

    void on_dbl_spn_box_first_param_valueChanged(double arg1);

    void on_dbl_spn_box_second_param_valueChanged(double arg1);

protected:
    void mouse_Press_L_Event(QPointF);

    void mouse_Press_R_Event(QPointF);

    void mouse_Move_Event(QPointF);

    void mouse_Release_Event(QPointF);

};
#endif // MAINWINDOW_H
