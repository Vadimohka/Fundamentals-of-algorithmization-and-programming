#include "GameSquare.hpp"


GameSquare::GameSquare(double sideLength)
    :sideLength_(sideLength)
{}

QRectF GameSquare::boundingRect() const{
    return QRectF(0, 0, sideLength_, sideLength_);
}

void GameSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPainterPath gameSquarePath;
    QRectF rec = boundingRect();
    QRectF recEllipse(  0 + GAME_SQUARE_ELLIPSE_PERCENT/2*sideLength_,
                        0 + GAME_SQUARE_ELLIPSE_PERCENT/2*sideLength_,
                        sideLength_ - GAME_SQUARE_ELLIPSE_PERCENT*sideLength_,
                        sideLength_ - GAME_SQUARE_ELLIPSE_PERCENT*sideLength_);

    gameSquarePath.moveTo(0, 0);
    gameSquarePath.addRect(rec);
    gameSquarePath.addEllipse(recEllipse);

    gameSquarePath.setFillRule(Qt::OddEvenFill);

    painter->setBrush(SQUARE_COLOR);
    painter->drawPath(gameSquarePath);
}
