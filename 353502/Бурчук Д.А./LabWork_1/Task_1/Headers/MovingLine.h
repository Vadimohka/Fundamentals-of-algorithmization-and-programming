#ifndef MOVINGLINE_H
#define MOVINGLINE_H

#include "inclusions.h"


class MovingLine : public QWidget
{
    Q_OBJECT
public:
    explicit MovingLine(QWidget *parent);

    ~MovingLine();

    virtual void paintEvent(QPaintEvent *event);
private:
    QPolygon polygon;

    QTimer* timer = new QTimer;
public slots:
    void StopMoving();

    void MoveObject();

    void Up();
};

#endif // MOVINGLINE_H
