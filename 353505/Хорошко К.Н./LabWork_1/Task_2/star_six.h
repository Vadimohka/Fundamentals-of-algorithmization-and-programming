#ifndef STAR_SIX_H
#define STAR_SIX_H


#include <QObject>
#include <QGraphicsItem>
#include <figure.h>

class Star_Six : public Figure
{
    Q_OBJECT
public:
    explicit Star_Six(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
};

#endif // STAR_SIX_H
