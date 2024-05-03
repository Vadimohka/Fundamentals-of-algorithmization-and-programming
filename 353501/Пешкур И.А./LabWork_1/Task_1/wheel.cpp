#include "wheel.h"

Wheel :: Wheel(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : Circle( x , y , width , height , parent )
{}

void Wheel :: paint( QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget ){

    painter->setRenderHint(QPainter::Antialiasing);
    painter -> setBrush( QColorConstants :: Svg :: brown );
    painter -> drawEllipse( 190 , 190 , 120 , 120 );

    painter -> setBrush( Qt :: white );
    painter -> drawEllipse( 200 , 200 , 100 , 100 );

    painter -> setBrush( QColorConstants :: Svg :: brown );
    painter -> drawRect( 200 , 240 , 100 , 20 );
    painter -> drawRect( 240 , 200 , 20 , 100 );

    painter -> setBrush( Qt :: gray );
    painter -> drawEllipse( 242 , 242 , 15 , 15 );

}

void Wheel :: rotate( int angle ){

    setTransformOriginPoint( boundingRect().center() );
    setRotation( (qreal)angle );

}
