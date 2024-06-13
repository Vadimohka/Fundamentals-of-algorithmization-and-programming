#include "star_5.h"


Star_5::Star_5(qreal x1, qreal y1, qreal radius, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Centre_of_mass.setX(x1);
    Centre_of_mass.setY(y1);
    Star_5::radius = radius;

    width = (radius * tan(3.14 / 10) * tan (3.14 / 10 * 3 / 2) ) / (sin(3.14 / 10) * (tan(3.14 / 10) + tan (3.14 / 10 * 3 / 2))) ;
    Small_Width = width * sin(3.14 / 10);

    Left_up_point.setX(x1);
    Left_up_point.setY(y1 - radius);

    Right_Centre_point = QPointF(x1 + Small_Width + width, y1 - radius * tan(3.14 / 10) / (tan(3.14 / 10) + tan (3.14 / 10 * 3 /2)));
    Left_Centre_point = QPointF(x1 - Small_Width - width, y1 - radius * tan (3.14 / 10) / (tan (3.14 / 10) + tan (3.14 / 10 * 3 /2)));
    Right_down_point = QPointF(x1 + radius * cos(3.14 / 10 * 3), y1 + radius * sin(3.14 / 10 * 3));
    Left_down_point = QPointF(x1 - radius * cos(3.14 / 10 * 3), y1 + radius * sin(3.14 / 10 * 3));


    star_5 << Left_up_point << Left_down_point << Right_Centre_point << Left_Centre_point << Right_down_point << Left_up_point;

    setPolygon(star_5);


    this -> setFlag(QGraphicsItem::ItemIsMovable);

}


void Star_5::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    Current_Left_down_point = Left_down_point;
    Current_Right_down_point = Right_down_point;
    Current_Left_up_point = Left_up_point;
    Current_Left_Centre_point = Left_Centre_point;
    Current_Right_Centre_point = Right_Centre_point;

    mousePressType = event -> type();
    this -> setFlag(QGraphicsItem::ItemIsMovable);
    All_shapes::item = STAR_5;
    QGraphicsPolygonItem::mousePressEvent(event);

}
void Star_5::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;

        qDebug() << Current_Left_up_point.y() + delta.y();
        qDebug() << Current_Left_Centre_point.y();


        if(current_Mouse_Pos.x() > Current_Left_up_point.x() && current_Mouse_Pos.y() > Current_Right_down_point.y() - 20){
            if(Mouse_last_pos.x() < Right_down_point.x() + 30 && Mouse_last_pos.x() > Left_down_point.x() && Mouse_last_pos.y() > Left_up_point.y()){

                setFlag(QGraphicsItem::ItemIsMovable, false);

                Right_down_point.setX(Current_Right_down_point.x() + delta.x());
                Right_down_point.setY(Current_Right_down_point.y() + delta.y());

                Left_down_point.setX(Current_Left_down_point.x() - delta.x());
                Left_down_point.setY(Current_Left_down_point.y() + delta.y());

                Left_up_point.setY(Current_Left_up_point.y() - delta.y());

                Right_Centre_point.setX(Current_Right_Centre_point.x() + delta.x());
                Left_Centre_point.setX(Current_Left_Centre_point.x() - delta.x());


                star_5 << Left_up_point << Left_down_point << Right_Centre_point << Left_Centre_point << Right_down_point << Left_up_point;

                this -> setPolygon(star_5);
                star_5.clear();

                line_of_Square -> setText(QString::number(abs((radius + sqrt(abs(delta.x() * delta.x() + delta.y() * delta.y())) * (radius + sqrt(abs(delta.x() * delta.x() + delta.y() * delta.y())) - (width + delta.x()) * (width + delta.x()) * 3.14 / 6)))));
                line_of_Perimetr -> setText(QString::number(abs(2 * (width + delta.x()) * 5 )));

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
void Star_5::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();

    mousePressType = event -> type();

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

void Star_5::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        radius += sqrt(abs(delta.x() * delta.x() + delta.y() * delta.y()));

        Centre_of_mass.setX(event -> scenePos().x() - radius * cos(3.14 / 20));
        Centre_of_mass.setY(event -> scenePos().y() - radius * sin(3.14 / 20));

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
