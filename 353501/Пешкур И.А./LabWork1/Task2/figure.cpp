#include "figure.h"

Figure::Figure(){}

// 300 na 250

void Figure :: paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){}

QRectF Figure :: boundingRect() const
{

    return QRectF( -500 , -500 , 1000 , 1000 );

}

float Figure :: getScale()
{

    return scale;

}

void Figure :: setCenterX( int CenterX )
{

    center = QPoint( CenterX , center.ry() );

}

void Figure :: setCenterY( int CenterY )
{

    center = QPoint( center.rx() , CenterY );

}

QPoint Figure :: getCenter()
{

    return QPoint( center.rx() , center.ry() );

}

void Figure :: makeFlagTrue()
{

    Flag = true;

}

float Figure :: Area()
{

    return 0;

}

float Figure :: Perimeter()
{

    return 0;

}

void Figure :: changeRadius( int newRadius )
{

    Radius = newRadius;

}

void Figure :: changeLength( int newLength )
{

    Length = newLength;

}

void Figure :: changeWidth( int newWidth )
{

    Width = newWidth;

}

void Figure :: changeSize( int newSize )
{

    Size = newSize;

}

void Figure :: changeRadius1( int newRadius1 )
{

    Radius1 = newRadius1;

}

void Figure :: changeRadius2( int newRadius2 )
{

    Radius2 = newRadius2;

}

void Figure :: changeScale( int newScale )
{

    Scale = newScale;

}
