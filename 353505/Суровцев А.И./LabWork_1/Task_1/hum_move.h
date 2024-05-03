#ifndef HUM_MOVE_H
#define HUM_MOVE_H
#include "movement.h"

class hum_move : public movement
{
public:
    hum_move(const QPointF &start_pos,const QSizeF &start_size);
    void SetParams(const QPointF &start_pos,const QSizeF &start_size);
    void SetEnd();
    QLineF& GetleftH();
    QLineF& GetrightH();
    QLineF& GetrightH1();
    QLineF& GetrightH2();
    QLineF& GetleftL();
    QLineF& GetrightL();
    QRectF& Gethead();
    bool GetCenAn();
    void SetHand(QLineF *l);
    void step_line(QLineF *l, QPointF p);
    void animation_line(QLineF *l, QPointF p, qreal delta);
    void circular_animation(QLineF *l, qreal delta, qreal sp);
private:
    QLineF leftH;
    QLineF rightH;
    QLineF rightH1;
    QLineF rightH2;
    QLineF leftL;
    QLineF rightL;
    QRectF rect;
    QRectF head;
    bool anlh = false;
    bool anrh = false;
    bool anrh1 = false;
    bool anrh2 = false;
    bool anll = false;
    bool anrl = false;
    bool centre_animation = false;
};

#endif // HUM_MOVE_H
