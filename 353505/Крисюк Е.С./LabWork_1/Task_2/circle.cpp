#include "circle.h"

Circle::Circle(qreal x, qreal y, qreal diametr,QGraphicsItem* parent): QGraphicsEllipseItem(parent){

    QGraphicsEllipseItem::setRect(x,y,diametr,diametr);
    Left_up_point.setX(x);
    Left_up_point.setY(y);

    Circle::diametr = diametr;
    Centre_of_mass.setX(Left_up_point.x() + diametr / 2);
    Centre_of_mass.setY(Left_up_point.y() + diametr / 2);

    setFlag(QGraphicsItem::ItemIsMovable);

}


void Circle::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    line_of_Square -> setText(QString::number(abs(3.14 * diametr * diametr / 4)));
    line_of_Perimetr -> setText(QString::number(abs(3.14 * diametr)));

    mousePressType = event -> type();

    this -> setFlag(QGraphicsItem::ItemIsMovable);
    All_shapes::item = CIRCLE;
    QGraphicsEllipseItem::mousePressEvent(event);

}
void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {


    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;


        if(Mouse_last_pos.x() < Centre_of_mass.x() + diametr / 2  && Mouse_last_pos.x() > Centre_of_mass.x() && Mouse_last_pos.y() > Centre_of_mass.y() && Mouse_last_pos.y() < Centre_of_mass.y() + diametr / 2){
            setFlag(QGraphicsItem::ItemIsMovable, false);

            this -> QGraphicsEllipseItem::setRect(Left_up_point.x() ,Left_up_point.y(), diametr + delta.y(), diametr + delta.y());

            Centre_of_mass.setX(Left_up_point.x() + diametr / 2);
            Centre_of_mass.setY(Left_up_point.y() + diametr / 2);

            line_of_Square -> setText(QString::number(abs(3.14 * (diametr + delta.y()) * (diametr + delta.y()) / 4)));
            line_of_Perimetr -> setText(QString::number(abs(3.14 * (diametr + delta.y()))));

        }
    }

    else {
        Centre_of_mass.setX(event -> scenePos().x());
        Centre_of_mass.setY(event -> scenePos().y());

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        this -> setFlag(QGraphicsItem::ItemIsMovable);

    }
    QGraphicsEllipseItem::mouseMoveEvent(event);

}
void Circle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    Mouse_last_pos = event -> pos();
    mousePressType = QEvent::GraphicsSceneMouseDoubleClick;


    QGraphicsEllipseItem::mouseDoubleClickEvent(event);
}

void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        diametr += delta.y();

        Centre_of_mass.setX(event -> scenePos().x() - diametr / 2);
        Centre_of_mass.setY(event -> scenePos().y() - diametr / 2);

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        QGraphicsEllipseItem::mouseReleaseEvent(event);

        delta = QPointF();
        Mouse_last_pos = QPointF();
    }
    else {

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));
    }
    mousePressType = event -> type();

}
