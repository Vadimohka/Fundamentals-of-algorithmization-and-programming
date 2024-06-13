#include "square.h"

Square::Square(qreal x, qreal y, qreal height,QGraphicsItem* parent): QGraphicsRectItem(parent){
    setRect(x,y,height,height);

    Left_up_point.setX(x);
    Left_up_point.setY(y);

    Square::height = height;
    Centre_of_mass.setX(Left_up_point.x() + height / 2);
    Centre_of_mass.setY(Left_up_point.y() + height / 2);

    setFlag(QGraphicsItem::ItemIsMovable);

}


void Square::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    line_of_Square -> setText(QString::number(abs(height * height)));
    line_of_Perimetr -> setText(QString::number(abs(4 * height )));

    mousePressType = event -> type();
    this -> setFlag(QGraphicsItem::ItemIsMovable);

    All_shapes::item = All_shapes::Item::SQUARE;

    qDebug() << All_shapes::item;
    QGraphicsRectItem::mousePressEvent(event);

}
void Square::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    Centre_of_mass.setX(Left_up_point.x() + height / 2);
    Centre_of_mass.setY(Left_up_point.y() + height / 2);

    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));
mousePressType = event -> type();

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();

        delta = current_Mouse_Pos - Mouse_last_pos;

        if(current_Mouse_Pos.x() > Current_Left_up_point.x() && current_Mouse_Pos.y() > Current_Left_up_point.y() ) {

            if(Mouse_last_pos.x() < Current_Left_up_point.x() + height && Mouse_last_pos.x() > Left_up_point.x()  + height - 40 && Mouse_last_pos.y() < Left_up_point.y() + height && Mouse_last_pos.y() > Left_up_point.y() + height - 40){
                setFlag(QGraphicsItem::ItemIsMovable, false);

                this -> setRect(Current_Left_up_point.x() ,Current_Left_up_point.y(), height + delta.y(), height + delta.y());

                Square::line_of_Square -> setText(QString::number(abs((height + delta.y()) * (height + delta.y()))));
                Square::line_of_Perimetr -> setText(QString::number(abs(4 * (height + delta.y()))));

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

    QGraphicsRectItem::mouseMoveEvent(event);

}
void Square::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    Current_Left_up_point = Left_up_point;
    Mouse_last_pos = event -> pos();
    mousePressType = QEvent::GraphicsSceneMouseDoubleClick;


    QGraphicsRectItem::mouseDoubleClickEvent(event);
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        Centre_of_mass.setX(event -> scenePos().x() - height / 2);
        Centre_of_mass.setY(event -> scenePos().y() - height / 2);

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

        height += delta.y();

        QGraphicsRectItem::mouseReleaseEvent(event);

        delta = QPointF();
        Mouse_last_pos = QPointF();
    }
    else {

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));
    }
    mousePressType = event -> type();

}
