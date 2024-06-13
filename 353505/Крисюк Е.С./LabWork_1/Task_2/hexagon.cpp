#include "hexagon.h"


Hexagon::Hexagon(qreal x1, qreal y1, qreal radius, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Centre_of_mass.setX(x1);
    Centre_of_mass.setY(y1);
    Hexagon::radius = radius;

    width = radius * sqrt(3);

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

    Down_point.setX(x1);
    Down_point.setY(y1 + radius);

    hexagon << Up_point << Left_up_point << Left_down_point << Down_point << Right_down_point << Right_up_point;
    setPolygon(hexagon);


    setFlag(QGraphicsItem::ItemIsMovable);

}

void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    Current_Up_point = Up_point;
    Current_Left_down_point = Left_down_point;
    Current_Right_down_point = Right_down_point;
    Current_Left_up_point = Left_up_point;
    Current_Right_up_point = Right_up_point;
    Current_Down_point = Down_point;

    line_of_Square -> setText(QString::number(abs(3 /2 * (width + delta.x()) * (width + delta.x())  * sqrt(3))));
    line_of_Perimetr -> setText(QString::number(abs(6 * width + delta.x())));

    mousePressType = event -> type();
    setFlag(QGraphicsItem::ItemIsMovable);
    All_shapes::item = HEXAGON;
    QGraphicsPolygonItem::mousePressEvent(event);
}
void Hexagon::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    Centre_of_mass.setX(Left_up_point.x());
    Centre_of_mass.setY(Left_up_point.y() + radius);

    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));


    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;

        if(Mouse_last_pos.x() < Right_down_point.x() + 30 && Mouse_last_pos.x() > Left_down_point.x() && Mouse_last_pos.y() > Left_up_point.y()){
            qDebug() << "123";
            setFlag(QGraphicsItem::ItemIsMovable, false);

            Right_down_point.setX(Current_Right_down_point.x() + delta.x());
            Right_down_point.setY(Current_Right_down_point.y() + delta.y());

            Right_up_point.setX(Current_Right_up_point.x() + delta.x());
            Right_up_point.setY(Current_Right_up_point.y() - delta.y() / sqrt(3));

            Left_down_point.setX(Current_Left_down_point.x() - delta.x());
            Left_down_point.setY(Current_Left_down_point.y() + delta.y());

            Left_up_point.setX(Current_Left_up_point.x()  - delta.x());
            Left_up_point.setY(Current_Left_up_point.y()  - delta.y() / sqrt(3));


            Up_point.setY(Current_Up_point.y() - delta.y());
            Down_point.setY(Current_Down_point.y() + delta.y());


            hexagon << Up_point << Left_up_point << Left_down_point << Down_point << Right_down_point << Right_up_point;


            this -> setPolygon(hexagon);
            hexagon.clear();

            Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
            Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

            line_of_Square -> setText(QString::number(abs(3 /2 * (width + delta.x()) * (width + delta.x())  * sqrt(3))));
            line_of_Perimetr -> setText(QString::number(abs(6 * width + delta.x())));

        }
        else {
            qDebug() << "1212";
            qDebug() << "Mouse" << Mouse_last_pos;
            qDebug() << "Right" << Right_down_point;
            qDebug() << "LEft" << Left_down_point;
        }
    }

    QGraphicsPolygonItem::mouseMoveEvent(event);


}
void Hexagon::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();

    mousePressType = event -> type();

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

void Hexagon::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        radius += delta.y();

        width = radius * sqrt(3);

        //        Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
        //        Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        QGraphicsPolygonItem::mouseReleaseEvent(event);

        delta.setX(0);
        delta.setY(0);
        Mouse_last_pos = QPointF();
    }

}
