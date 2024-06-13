#ifndef RHOMB_H
#define RHOMB_H
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>

#include "figure.h"

class Rhomb : public Figure
{
    Q_OBJECT

public:
    explicit Rhomb(QPointF point, QObject *parent = nullptr);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RHOMB_H
