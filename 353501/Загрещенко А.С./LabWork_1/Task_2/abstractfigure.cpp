#include "abstractfigure.h"
#include "QPainter"
#include "QPen"
#include "QBrush"

AbstractFigure::AbstractFigure() {
    setAcceptHoverEvents(true);
    selected_fill_color = Qt::yellow;
    is_show_borders = true;
    is_show_correct_point = false;

}

QRectF AbstractFigure::boundingRect() const {
    return rect;
}

void AbstractFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    drawFigure(painter);
    if (is_show_borders) {
        drawBorders(painter);
    }
    if (is_show_correct_point) {
        drawCorrectPoint(painter);
    }
    update();
}

void AbstractFigure::drawBorders(QPainter *painter) {
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);


    QBrush brush;
    brush.setStyle(Qt::Dense7Pattern);
    brush.setColor(Qt::gray);
    painter->setBrush(brush);

    painter->drawRect(rect.x(), rect.y(), rect.width(), rect.height());
}

void AbstractFigure::setShowBorders(bool value) {
    is_show_borders = value;
}

void AbstractFigure::setShowCorrectPoints(bool value) {
    is_show_correct_point = value;
}


void AbstractFigure::setFillColor(QColor color) {
    selected_fill_color = color;
}

void AbstractFigure::setRect(double dx1, double dy1, double dx2, double dy2) {
    double width = rect.width();
    double height = rect.height();
    if (dx1 != 0) {
        if (width - dx1 > 10) {
            rect.setRect(rect.left() + dx1, rect.top(), rect.width() - dx1, rect.height());
        }
    }
    if (dy1 != 0) {
        if (height - dy1 > 10) {
            rect.setRect(rect.left(), rect.top() + dy1, rect.width(), rect.height() - dy1);
        }

    }
    if (dx2 != 0) {
        if (width + dx2 > 10) {
            rect.setRect(rect.left(), rect.top(), rect.width() + dx2, rect.height());
        }
    }
    if (dy2 != 0) {
        if (height + dy2 > 10) {
            rect.setRect(rect.left(), rect.top(), rect.width(), rect.height() + dy2);
        }
    }
}

void AbstractFigure::setSize(double width, double height)
{
    rect.setWidth(width);
    rect.setHeight(height);
}

double AbstractFigure::getSquare()
{
    return 1;
}

double AbstractFigure::getPerimetr()
{

}


void AbstractFigure::drawFigure(QPainter *painter) {

}

void AbstractFigure::drawCorrectPoint(QPainter *painter) {
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);

    painter->drawEllipse(this->boundingRect().topLeft(), 3, 3);
    painter->drawEllipse(this->boundingRect().topRight(), 3, 3);
    painter->drawEllipse(this->boundingRect().bottomLeft(), 3, 3);
    painter->drawEllipse(this->boundingRect().bottomRight(), 3, 3);


}





