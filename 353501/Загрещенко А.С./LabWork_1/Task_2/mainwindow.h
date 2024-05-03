#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "abstractfigure.h"
#include <QMainWindow>
#include "QVector"
#include "QGraphicsItem"
#include "QMouseEvent"
#include "QVBoxLayout"
#include "QGraphicsSceneMouseEvent"
#include "QWheelEvent"
#include "QWidget"
#include "QGridLayout"
#include "QButtonGroup"
#include "QPushButton"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "canva.h"
#include "QLabel"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    bool is_left_button_pressed;
    bool is_ctrl_pressed;
    bool is_shift_pressed;
    bool is_right_button_pressed;

    bool is_left_bottom_resize{};
    bool is_right_bottom_resize{};
    bool is_left_top_resize{};
    bool is_right_top_resize{};

    QPointF cord_offset;
    QPointF past_cord;
    QPointF start_pos;
    double start_angle{};

    bool is_drawing;

    QVector<AbstractFigure *> items;
    QVector<QPushButton*> action_buttons;
    QVector<QPushButton*> color_buttons;
    QVector<QColor> colors;
    QVector<QString> figures_img;

    QGridLayout *layout;
    QButtonGroup action_group;
    QButtonGroup color_group;
    Canva *scene;
    QGraphicsView *view;
    AbstractFigure *selected_figure;
    QColor selected_color;

    void doubleClickLeftButton(QGraphicsSceneMouseEvent *event);

    void setLeftButtonPress(QGraphicsSceneMouseEvent *event);

    void setLeftButtonUnPress(QGraphicsSceneMouseEvent *event);

    void setRightButtonPress(QGraphicsSceneMouseEvent *event);

    void setRightButtonUnPress(QGraphicsSceneMouseEvent *event);

    void MouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    void setResizePoint(QGraphicsSceneMouseEvent *event);

    QLabel *label_center;
    QLabel *label_square;
    QLabel *label_perimetr;

    QPushButton *button_ellipse;
    QPushButton *button_rect;
    QPushButton *button_triangle;
    QPushButton *button_rhombus;

private slots:
    void chooseColor(QColor color);

};

#endif // MAINWINDOW_H
