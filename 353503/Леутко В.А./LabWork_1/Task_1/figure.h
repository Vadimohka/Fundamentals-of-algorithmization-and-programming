#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtGui>
#include <QGraphicsSceneMouseEvent>

class figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    figure();
    ~figure();
    int w,h;
    bool filled;
    double perimeter = 0,now_perimeter = 0,area = 0,now_area = 0,ang = 0,now_ang = 0,size = 1,now_size = 1;
    QLabel *out_area,*out_perimeter,*out_angle,*out_centerX,*out_centerY;
    QLineEdit *rotate_angle,*change_size,*centergravity_x,*centergravity_y;
    QPushButton *Tgravity,*btn_fill;
    QRectF boundingRect() const;
    void Output();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // FIGURE_H
