#ifndef WIDGET_H
#define WIDGET_H

#include "headers.h"

enum Shapes{
    CRectangle = 0,
    CSquare,
    CRomb,
    CHexagon,
    CEllipse,
    CCircle,
    CTriangle,
    CStar_5,
    CStar_6,
    CStar_8,
    CDraw
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void UpdateInfo();

private slots:
    void MousePressed(QGraphicsSceneMouseEvent*);
    void MouseMoved(QGraphicsSceneMouseEvent*);
    void MouseReleased(QGraphicsSceneMouseEvent*);
    void WheelTrigered(QGraphicsSceneWheelEvent*);
    void KeyPressed(QKeyEvent*);

    void FigureChanged();

private:
    void CreateFigure(QGraphicsSceneMouseEvent*);

    QVector<Shape*> Figures[10];
    Shapes selected_shape;

    bool track_move = false;
    bool creation = false;
    bool scale = false;

    Ui::Widget *ui;
    Scene* scene;

    QPointF pt_pressed, pt_move, pt_released;
    Shape* item;
    Shape* current_item;
    qreal scale_on, rotate_on;
};

#endif // WIDGET_H
