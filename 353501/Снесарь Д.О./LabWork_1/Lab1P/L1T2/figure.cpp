#include "figure.h"

Figure::Figure()
{
    s = 0;
    p = 0;
}

void Figure::draw(QPainter *pntr)
{

}

void Figure::move(QPointF nPoint)
{
   // if(center.x() > 0 && center.y() > 0){

        center = nPoint;
   // }

  /*  if(center.x() <= 0){
        QPointF temp(5, 0);
        center += temp;
        for(int i = 0; i < points.count(); ++i){
            points[i] += temp;
        }
    }

    if(center.y() <= 0){
        QPointF temp(0, 5);
        center += temp;
        for(int i = 0; i < points.count(); ++i){
            points[i] += temp;
        }
    }
*/
}

void Figure::setSize(QPointF nPoint)
{

}

QPointF Figure::getCenter()
{
        return center;
}

QVector<QPointF> Figure::getPointsVector()
{

}

void Figure::setCenterEdit(QPointF newPoint, int pointN)
{

}

QPointF Figure::getRadSize()
{

}




void Figure::rotateR()
{

}

void Figure::rotateL()
{



}

void Figure::upScale()
{


}

void Figure::downScale()
{


}

double Figure::getS()
{

}

double Figure::getP()
{

}

int Figure::getId()
{
    return 0;
}



double Figure::getCordCenterX()
{
    return center.x();
}

double Figure::getCordCenterY()
{
    return center.y();
}




