#include "triangle.h"


Triangle::Triangle(qreal x1, qreal y1, qreal width,QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Left_up_point.setX(x1);
    Left_up_point.setY(y1);

    Right_down_point.setX(x1 + width / 2);
    Right_down_point.setY(y1 + width * sqrt(3) / 2);

    Left_down_point.setX(x1 - width / 2);
    Left_down_point.setY(y1 + width * sqrt(3) / 2);

    triangle << Left_up_point << Left_down_point << Right_down_point;

    setPolygon(triangle);
    Triangle::width = width;
    Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
    Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

    setFlag(QGraphicsItem::ItemIsMovable);

}


void Triangle::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    Current_Left_down_point = Left_down_point;
    Current_Right_down_point = Right_down_point;
    Current_Left_up_point = Left_up_point;

    line_of_Square -> setText(QString::number(abs(width * width * sqrt(3) / 4)));
    line_of_Perimetr -> setText(QString::number(abs(3 * width )));

    mousePressType = event -> type();
    this -> setFlag(QGraphicsItem::ItemIsMovable);
    All_shapes::item = TRIANGLE;
    QGraphicsPolygonItem::mousePressEvent(event);
}
void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;


        if(Mouse_last_pos.x() < Right_down_point.x() + 30 && Mouse_last_pos.x() > Right_down_point.x() - width / 2 && Mouse_last_pos.y() < Right_down_point.y() + 20){

            setFlag(QGraphicsItem::ItemIsMovable, false);

            Right_down_point.setX(Current_Right_down_point.x() + delta.x());
            Left_down_point.setX(Current_Left_down_point.x() - delta.x());
            Left_up_point.setY(Current_Left_up_point.y() + delta.y());

            triangle << Left_up_point << Left_down_point << Right_down_point;

            this -> setPolygon(triangle);
            triangle.clear();

            line_of_Square -> setText(QString::number(abs((width + delta.x()) * (width + delta.x()) * sqrt(3) / 4)));
            line_of_Perimetr -> setText(QString::number(abs(3 * (width + delta.x()) )));

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
void Triangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();

    mousePressType = event -> type();

    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
}

void Triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        width += delta.x();
        line_of_Square -> setText(QString::number(abs(width * width * sqrt(3) / 4)));
        line_of_Perimetr -> setText(QString::number(abs(3 * width )));

        Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
        Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

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
