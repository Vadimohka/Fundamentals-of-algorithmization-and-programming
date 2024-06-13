#include "rect.h"

Rect::Rect(qreal x, qreal y, qreal width, qreal height,QGraphicsItem* parent): QGraphicsRectItem(parent){
    QGraphicsRectItem::setRect(x,y,width,height);

    Left_up_point.setX(x);
    Left_up_point.setY(y);

    Rect::width = width;
    Rect::height = height;
    Centre_of_mass.setX(Left_up_point.x() + width / 2);
    Centre_of_mass.setY(Left_up_point.y() + height / 2);

    setFlag(QGraphicsItem::ItemIsMovable);

}


void Rect::mousePressEvent(QGraphicsSceneMouseEvent* event) {

    line_of_X -> setText(QString::number(Centre_of_mass.x()));
    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    line_of_Square -> setText(QString::number(abs(width + delta.x() ) * (height + delta.y())) );
    line_of_Perimetr -> setText(QString::number(abs(2 * (width + delta.x() + height + delta.y()))));
    Current_Left_up_point = Left_up_point;

    mousePressType = event -> type();

    this -> setFlag(QGraphicsItem::ItemIsMovable);


    All_shapes::item = All_shapes::Item::RECT;
    qDebug() << "123" << All_shapes::item;
    QGraphicsRectItem::mousePressEvent(event);

}
void Rect::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

        current_Mouse_Pos = event -> pos();
        delta = current_Mouse_Pos - Mouse_last_pos;

        if(current_Mouse_Pos.x() > Current_Left_up_point.x() && current_Mouse_Pos.y() > Current_Left_up_point.y() ) {

            qDebug() << "234";

            if(Mouse_last_pos.x() < Current_Left_up_point.x() + width && Mouse_last_pos.x() > Current_Left_up_point.x()  + width - 40 && Mouse_last_pos.y() < Current_Left_up_point.y() + height && Mouse_last_pos.y() > Current_Left_up_point.y() + height - 40){
                setFlag(QGraphicsItem::ItemIsMovable, false);

                this -> setRect(Current_Left_up_point.x() ,Current_Left_up_point.y(), width + delta.x(), height + delta.y());

                line_of_Square -> setText(QString::number(abs((width + delta.x()) * (height + delta.y()))));
                line_of_Perimetr -> setText(QString::number(abs(2 * (height + delta.y() + width + delta.x()))));

            }
        }

    }
    else {
        this -> setFlag(QGraphicsItem::ItemIsMovable);

        Centre_of_mass = QPointF(mapToScene(event -> scenePos()));
        qDebug() << event -> scenePos();
        qDebug() << Centre_of_mass;

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

    }


    QGraphicsRectItem::mouseMoveEvent(event);

}
void Rect::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

    Mouse_last_pos = event -> pos();
    mousePressType = QEvent::GraphicsSceneMouseDoubleClick;

    qDebug() << mousePressType;

    QGraphicsRectItem::mouseDoubleClickEvent(event);

}

void Rect::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {


    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {
        qDebug() << delta;
        width += delta.x();
        height += delta.y();

        Centre_of_mass.setX(event -> scenePos().x() - width / 2);
        Centre_of_mass.setY(event -> scenePos().y() - height / 2);


        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));



        delta = QPointF();
        Mouse_last_pos = QPointF();

        setFlag(QGraphicsItem::ItemIsMovable);
        QGraphicsRectItem::mouseReleaseEvent(event);

    }
    else {

        line_of_X -> setText(QString::number(Centre_of_mass.x()));
        line_of_Y -> setText(QString::number(Centre_of_mass.y()));
    }
    mousePressType = event -> type();

}
