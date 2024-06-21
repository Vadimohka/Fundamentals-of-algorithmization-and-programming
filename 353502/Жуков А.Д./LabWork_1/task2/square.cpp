#include "square.h"

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getEP().x() - getSP().x() : getEP().y() - getSP().y());
    QSizeF size(side, side);

    if (getEP().x() > getSP().x() && getEP().y() < getSP().y()){
        side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getEP().x() - getSP().x() : getSP().y() - getEP().y());
        size.setHeight(-side);
        size.setWidth(side);
    }
    else if(getEP().x() < getSP().x() && getEP().y() > getSP().y()){
        side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getSP().x() - getEP().x() : getEP().y() - getSP().y());
        size.setWidth(-side);
        size.setHeight(side);
    }

    QRectF sq(getSP(), size);
    painter->drawRect(sq);

    setPerimeter(4 * qAbs(size.rwidth()));
    setArea(size.rwidth() * size.rwidth());

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Square::boundingRect() const
{
    int side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getEP().x() - getSP().x() : getEP().y() - getSP().y());
    QSizeF size(side, side);

    if (getEP().x() > getSP().x() && getEP().y() < getSP().y()){
        side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getEP().x() - getSP().x() : getSP().y() - getEP().y());
        size.setHeight(-side);
        size.setWidth(side);
    }
    else if(getEP().x() < getSP().x() && getEP().y() > getSP().y()){
        side = (qAbs(getEP().x() - getSP().x()) > qAbs(getEP().y() - getSP().y()) ?
                    getSP().x() - getEP().x() : getEP().y() - getSP().y());
        size.setWidth(-side);
        size.setHeight(side);
    }

    return {QRectF(getSP(), size)};
}
