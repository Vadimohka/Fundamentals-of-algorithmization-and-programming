#pragma once

#include <QGraphicsObject>
#include <QPainter>
#include <qcolor.h>
#include <qgraphicsitem.h>
#include <qnamespace.h>
#include <qtmetamacros.h>

class KeyObject : public QGraphicsObject {
    Q_OBJECT
public:
    KeyObject(int w = 64, int h = 64, QGraphicsObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const override;

    void setColor(QColor color);

    Qt::Key getName() { return name; }

private:
    int w;
    int h;
    QColor color;

public:
    Qt::Key name;
};
