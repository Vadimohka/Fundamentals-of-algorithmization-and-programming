#include "hum_move.h"

hum_move::hum_move(const QPointF &start_pos,const QSizeF &start_size) {
    setR(QRectF(start_pos, start_size));
    SetParams(start_pos, start_size);
}

void hum_move::SetParams(const QPointF &start_pos, const QSizeF &start_size)
{
    setR(QRectF(start_pos, start_size));
    rightH = QLineF(QPointF(50, 40), QPointF(70, 70));
    rightH1 = QLineF(QPointF(50, 40), QPointF(60, 25));
    rightH2 = QLineF(QPointF(60, 25), QPointF(70, 10));
    leftH = QLineF(QPointF(0, 70), QPointF(20, 40));
    rightL = QLineF(QPointF(35, 80), QPointF(50, 110));
    leftL = QLineF(QPointF(20, 110), QPointF(35, 80));
    head = QRectF(QPointF(25, 0), QSizeF(20, 20));
}

void hum_move::SetEnd()
{
    anrh = false;
    anrh1 = false;
    anrh2 = false;
    anrl = false;
    anlh = false;
    anll = false;
}

QLineF& hum_move::GetleftH()
{
    return leftH;
}

QLineF& hum_move::GetrightH()
{
    return rightH;
}

QLineF& hum_move::GetrightH2()
{
    return rightH2;
}

QLineF& hum_move::GetrightH1()
{
    return rightH1;
}

QLineF& hum_move::GetleftL()
{
    return leftL;
}

QLineF& hum_move::GetrightL()
{
    return rightL;
}

QRectF& hum_move::Gethead()
{
    return head;
}

bool hum_move::GetCenAn()
{
    return centre_animation;
}

void hum_move::SetHand(QLineF *l)
{
    rightH1 = QLineF(l->p1(), QPointF((l->p1().rx() + l->p2().rx())/2, (l->p1().ry() + l->p2().ry())/2));
    rightH2 = QLineF(QPointF((l->p1().rx() + l->p2().rx())/2, (l->p1().ry() + l->p2().ry())/2), l->p2());
    qDebug() << rightH1 << ' ' << rightH2 << '\n';
}

void hum_move::step_line(QLineF *l, QPointF p)
{
    l->setP1(l->p1() + p);
    l->setP2(l->p2() + p);
}

void hum_move::animation_line(QLineF *l, QPointF p, qreal delta)
{
    if ((*l == rightH && !anrh) || (*l == rightH1 && !anrh1) || (*l == rightH2 && !anrh2) || (*l == rightL && !anrl) || (*l == leftH && !anlh) || (*l == leftL && !anll)){
        if (*l == rightH) anrh = true;
        if (*l == rightH1) anrh1 = true;
        if (*l == rightH2) anrh2 = true;
        if (*l == rightL) anrl = true;
        if (*l == leftH) anlh = true;
        if (*l == leftL) anll = true;
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=](){
            step_line(l, 25*p / delta);
        });
        QObject::connect(time_end, &QTimer::timeout, [=](){
            step_line(l, 25*p / delta);
            deley->stop();
            time_end->stop();
            if (*l == rightH) anrh = false;
            if (*l == rightH1) anrh1 = false;
            if (*l == rightH2) anrh2 = false;
            if (*l == rightL) anrl = false;
            if (*l == leftH) anlh = false;
            if (*l == leftL) anll = false;
        });
        deley->start(25);
        time_end->start(delta);
    }
}

void hum_move::circular_animation(QLineF *l, qreal delta, qreal sp)
{
    qreal angle = qAtan2(l->dy(), l->dx());
    qreal angularSpeed = sp / delta;

    QTimer *delayTimer = new QTimer;
    QTimer *timeEndTimer = new QTimer;

    QObject::connect(delayTimer, &QTimer::timeout, [=]() mutable {
        qreal radius = l->length();
        qreal x = l->p1().x() + radius * cos(angle);
        qreal y = l->p1().y() + radius * sin(angle);
        l->setP2(QPointF(x, y));
        angle += angularSpeed;
    });

    QObject::connect(timeEndTimer, &QTimer::timeout, [=]() mutable {
        delayTimer->stop();
        timeEndTimer->stop();
        centre_animation = true;
    });

    delayTimer->start(25);
    timeEndTimer->start(delta);
}
