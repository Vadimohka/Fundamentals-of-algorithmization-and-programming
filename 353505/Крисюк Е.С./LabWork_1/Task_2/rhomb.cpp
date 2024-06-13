#include "rhomb.h"


Rhomb::Rhomb(qreal x1, qreal y1, qreal width, qreal angle, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Left_up_point.setX(x1);
    Left_up_point.setY(y1);

    Right_up_point.setX(x1 + width);
    Right_up_point.setY(y1);

    Left_down_point.setX(x1 - width * cos(3.14 / 180 * angle));
    Left_down_point.setY(y1 + width * sin(3.14 / 180 * angle));

    Right_down_point.setX(Left_down_point.x() + width);
    Right_down_point.setY(Left_down_point.y());


    rhomb << Left_up_point << Left_down_point << Right_down_point << Right_up_point;

    setPolygon(rhomb);
    Rhomb::width = width;
    Rhomb::angle = angle;

    Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x() + Right_up_point.x()) / 4);
    Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y() + Right_up_point.y()) / 4);

    this -> setFlag(QGraphicsItem::ItemIsMovable);

}


void Rhomb::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    Current_Left_down_point = Left_down_point;
    Current_Right_down_point = Right_down_point;
    Current_Left_up_point = Left_up_point;
    Current_Right_up_point = Right_up_point;

    line_of_Square -> setText(QString::number(abs(width * width)));
    line_of_Perimetr -> setText(QString::number(abs(4 * width )));

    mousePressType = event -> type();
    this -> setFlag(QGraphicsItem::ItemIsMovable);
    All_shapes::item = RHOMB;
    QGraphicsPolygonItem::mousePressEvent(event);

}
void Rhomb::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;


        if(Mouse_last_pos.x() < Right_down_point.x() && Mouse_last_pos.x() > Right_down_point.x() - width / 2 + 20 && Mouse_last_pos.y() > Left_up_point.y() && Mouse_last_pos.y() < Right_down_point.y()){

            setFlag(QGraphicsItem::ItemIsMovable, false);

            Right_down_point.setX(Current_Right_down_point.x() + delta.y());
            Right_down_point.setY(Current_Right_down_point.y() + delta.y());

            Left_down_point.setY(Current_Left_down_point.y() + delta.y() );

            Right_up_point.setX(Current_Right_up_point.x() + delta.y() );


            rhomb << Left_up_point << Left_down_point << Right_down_point << Right_up_point;

            this -> setPolygon(rhomb);
            rhomb.clear();


            line_of_Square -> setText(QString::number(abs((width + delta.x()) * (width + delta.x()))));
            line_of_Perimetr -> setText(QString::number(abs(4 * (width + delta.x()))));

        }
    }
    else {

        Centre_of_mass.setX(event -> scenePos().x());
        Centre_of_mass.setY(event -> scenePos().y());

        qDebug() << event -> scenePos();

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        this -> setFlag(QGraphicsItem::ItemIsMovable);
    }

    QGraphicsPolygonItem::mouseMoveEvent(event);


}
void Rhomb::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();
    mousePressType = event -> type();

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

void Rhomb::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        width += delta.y();

        line_of_Square -> setText(QString::number(abs(width * width)));
        line_of_Perimetr -> setText(QString::number(abs(4 * width )));

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        QGraphicsPolygonItem::mouseReleaseEvent(event);

        delta = QPointF();
        Mouse_last_pos = QPointF();
    }
    else {

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));
    }

}
