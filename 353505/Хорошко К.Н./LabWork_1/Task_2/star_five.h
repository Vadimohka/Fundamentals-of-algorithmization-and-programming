#ifndef STAR_FIVE_H
#define STAR_FIVE_H

#include <QObject>
#include <QGraphicsItem>
#include <figure.h>

class Star_Five : public Figure
{
    Q_OBJECT
public:
    explicit Star_Five(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
};

#endif // STAR_FIVE_H
