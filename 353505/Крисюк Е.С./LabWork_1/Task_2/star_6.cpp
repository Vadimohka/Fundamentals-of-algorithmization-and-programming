#include "star_6.h"


Star_6::Star_6(qreal x1, qreal y1, qreal radius, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Centre_of_mass.setX(x1);
    Centre_of_mass.setY(y1);
    Star_6::radius = radius;

    width = radius * sqrt(3);

    Up_point.setX(x1);
    Up_point.setY(y1 - radius);

    Up_point.setX(x1);
    Up_point.setY(y1 - radius);

    Left_down_point.setX(x1 - radius * cos(3.14 / 6));
    Left_down_point.setY(y1 + radius * sin (3.14 / 6));

    Right_down_point.setX(x1 + radius * cos(3.14 / 6));
    Right_down_point.setY(y1 + radius * sin (3.14 / 6));

    Left_up_point.setX(x1 - radius * cos(3.14 / 6));
    Left_up_point.setY(y1 - radius * sin (3.14 / 6));

    Right_up_point.setX(x1 + radius * cos(3.14 / 6));
    Right_up_point.setY(y1 - radius * sin (3.14 / 6));

    Centre.setX(x1 + radius * tan(3.14 / 6));
    Centre.setY(y1);

    Down_point.setX(x1);
    Down_point.setY(y1 + radius);

    star_6 << Up_point << Left_down_point << Right_down_point  << Centre << Right_up_point << Left_up_point << Down_point << Centre << Up_point;
    setPolygon(star_6);


    this -> setFlag(QGraphicsItem::ItemIsMovable);

}


void Star_6::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    Current_Up_point = Up_point;
    Current_Left_down_point = Left_down_point;
    Current_Right_down_point = Right_down_point;
    Current_Left_up_point = Left_up_point;
    Current_Right_up_point = Right_up_point;
    Current_Down_point = Down_point;
    Current_Centre = Centre;
    All_shapes::item = STAR_6;

    line_of_Square -> setText(QString::number(abs((width + delta.x()) * (width + delta.x()) * 3.14 / 6)));
    line_of_Perimetr -> setText(QString::number(abs(2 * (width + delta.x()) * 5 )));

    mousePressType = event -> type();
    this -> setFlag(QGraphicsItem::ItemIsMovable);
    QGraphicsPolygonItem::mousePressEvent(event);
}
void Star_6::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;
        if(current_Mouse_Pos.x() > Current_Left_up_point.x() && current_Mouse_Pos.y() > Current_Right_down_point.y() - 20){
            if(Mouse_last_pos.x() < Right_down_point.x() + 30 && Mouse_last_pos.x() > Left_down_point.x() && Mouse_last_pos.y() > Left_up_point.y()){

                setFlag(QGraphicsItem::ItemIsMovable, false);

                Right_down_point.setX(Current_Right_down_point.x() + delta.x());
                Right_down_point.setY(Current_Right_down_point.y() + delta.y());

                Right_up_point.setX(Current_Right_up_point.x() + delta.x());


                Left_down_point.setX(Current_Left_down_point.x() - delta.x());
                Left_down_point.setY(Current_Left_down_point.y() + delta.y());

                Left_up_point.setX(Current_Left_up_point.x()  - delta.x());

                Up_point.setY(Current_Up_point.y() - delta.y());
                Down_point.setY(Current_Down_point.y() + delta.y());

                Centre.setX((Right_down_point.x() + Up_point.x()) / 2) ;

                star_6 << Up_point << Left_down_point << Right_down_point  << Centre << Right_up_point << Left_up_point << Down_point << Centre << Up_point;

                this -> setPolygon(star_6);
                star_6.clear();

                line_of_Square -> setText(QString::number(abs((width + delta.x()) * (width + delta.x()) * 3.14 / 5)));
                line_of_Perimetr -> setText(QString::number(abs(2 * (width + delta.x()) * 6 )));

            }
        }

    }
    else {
        Centre_of_mass.setX(event -> scenePos().x());
        Centre_of_mass.setY(event -> scenePos().y());

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        this -> setFlag(QGraphicsItem::ItemIsMovable);;
    }

    QGraphicsPolygonItem::mouseMoveEvent(event);


}
void Star_6::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();

    mousePressType = event -> type();

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

void Star_6::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        radius += sqrt(abs(delta.x() * delta.x() + delta.y() * delta.y()));

        Centre_of_mass.setX(event -> scenePos().x() - radius * cos(3.14 / 12));
        Centre_of_mass.setY(event -> scenePos().y() - radius * sin(3.14 / 12));

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
    mousePressType = event -> type();

}
