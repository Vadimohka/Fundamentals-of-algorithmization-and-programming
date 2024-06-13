#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>

#include "rect.h"
#include "square.h"
#include "triangle.h"
#include "star_5.h"
#include "star_6.h"
#include "circle.h"
#include "rhomb.h"
#include "hexagon.h"
#include "star_8.h"
#include "draw.h"
#include "all_shapes.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public All_shapes
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Rect* rect_1;
    Square* square_1;
    Triangle* triangle_1;
    Star_5* star_5_1;
    Star_6* star_6_1;
    Star_8* star_8_1;
    Circle* circle_1;
    Rhomb* rhomb_1;
    Hexagon* hexagon_1;
    Draw* draw_1;

    QPoint current_event;

    All_shapes* all_shapes;
    ~MainWindow();

private slots:

    void on_Rect_button_clicked();


    void on_Rotate_Right_button_pressed();


    void on_line_of_X_inputRejected();

    void on_line_of_X_editingFinished();

    void on_line_of_Y_editingFinished();

    void on_Square_button_clicked();

    void on_Triangle_button_clicked();

    void on_Scene_clear_clicked();

    void on_Star_5_clicked();

    void on_Star_6_clicked();


    void on_Circle_clicked();

    void on_Rhomb_clicked();

    void on_Hexagon_clicked();

    void on_Star_8_clicked();

    void on_Draw_toggled(bool checked);

    void on_Scale_up_pressed();

    void on_Scale_down_pressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    QPainter* painter;

protected:
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
};
#endif // MAINWINDOW_H
