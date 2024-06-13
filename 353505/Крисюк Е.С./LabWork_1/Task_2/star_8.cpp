#include "star_8.h"

Star_8::Star_8(qreal x1, qreal y1, qreal radius, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Centre_of_mass.setX(x1);
    Centre_of_mass.setY(y1);
    Star_8::radius = radius;

    width = radius * sqrt(3);

    Top.setX(x1);
    Top.setY(y1 - radius);

    Up_Right_point.setX(Top.x() + radius * sin(3.14 / 8));
    Up_Right_point.setX(Top.y() + radius * cos(3.14 / 8));

    Down_Right_point.setX(Up_Right_point.x());
    Down_Right_point.setY(Up_Right_point.y() + 2 * radius * cos(3.14 / 8));

    Up_Left_point.setX(Top.x() - radius * sin(3.14 / 8));
    Up_Left_point.setX(Up_Right_point.x());


    star_8 << Up_Right_point << Down_Right_point << Up_Left_point;
    setPolygon(star_8);


    setFlag(QGraphicsItem::ItemIsMovable);

}


//void Star_6::mousePressEvent(QGraphicsSceneMouseEvent* event) {
//    line_of_X -> setText(QString::number(Centre_of_mass.x()));
//    line_of_Y -> setText(QString::number(Centre_of_mass.y()));

//    Current_Up_point = Up_point;
//    Current_Left_down_point = Left_down_point;
//    Current_Right_down_point = Right_down_point;
//    Current_Left_up_point = Left_up_point;
//    Current_Right_up_point = Right_up_point;
//    Current_Down_point = Down_point;
//    Current_Centre = Centre;


//    //    line_of_Square -> setText(QString::number(abs(height * height)));
//    //    line_of_Perimetr -> setText(QString::number(abs(4 * height )));

//    mousePressType = event -> type();
//    setFlag(QGraphicsItem::ItemIsMovable);
//    QGraphicsPolygonItem::mousePressEvent(event);
//}
//void Star_6::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {

//    Centre_of_mass.setX(Left_up_point.x());
//    Centre_of_mass.setY(Left_up_point.y() + radius);

//    line_of_X -> setText(QString::number(Centre_of_mass.x()));
//    line_of_Y -> setText(QString::number(Centre_of_mass.y()));


//    if (mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

//        current_Mouse_Pos = event -> pos();

//        delta = current_Mouse_Pos - Mouse_last_pos;

//        if(Mouse_last_pos.x() < Right_down_point.x() + 30 && Mouse_last_pos.x() > Left_down_point.x() && Mouse_last_pos.y() > Left_up_point.y()){
//            qDebug() << "123";
//            setFlag(QGraphicsItem::ItemIsMovable, false);

//            Right_down_point.setX(Current_Right_down_point.x() + delta.x());
//            Right_down_point.setY(Current_Right_down_point.y() + delta.y());

//            Right_up_point.setX(Current_Right_up_point.x() + delta.x());


//            Left_down_point.setX(Current_Left_down_point.x() - delta.x());
//            Left_down_point.setY(Current_Left_down_point.y() + delta.y());

//            Left_up_point.setX(Current_Left_up_point.x()  - delta.x());

//            Up_point.setY(Current_Up_point.y() - delta.y());
//            Down_point.setY(Current_Down_point.y() + delta.y());

//            Centre.setX((Right_down_point.x() + Up_point.x()) / 2) ;

//            star_6 << Up_point << Left_down_point << Right_down_point  << Centre << Right_up_point << Left_up_point << Down_point << Centre << Up_point;

//            this -> setPolygon(star_6);
//            star_6.clear();

//            Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
//            Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

//            //            line_of_Square -> setText(QString::number(abs((width + delta.x() ) * (height + delta.y()))));
//            //            line_of_Perimetr -> setText(QString::number(2 * (width + abs(delta.x()) + height + abs(delta.y())) ));

//        }
//        else {
//            qDebug() << "1212";
//            qDebug() << "Mouse" << Mouse_last_pos;
//            qDebug() << "Right" << Right_down_point;
//            qDebug() << "LEft" << Left_down_point;
//        }
//    }

//    QGraphicsPolygonItem::mouseMoveEvent(event);


//}
//void Star_6::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {

//    Mouse_last_pos = event -> pos();

//    mousePressType = event -> type();

//    QGraphicsPolygonItem::mouseDoubleClickEvent(event);
//}

//void Star_6::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
//    if(mousePressType == QEvent::GraphicsSceneMouseDoubleClick) {

//        width += delta.x();

//        //        Centre_of_mass.setX((Left_down_point.x() + Right_down_point.x() + Left_up_point.x()) / 3);
//        //        Centre_of_mass.setY((Left_down_point.y() + Right_down_point.y() + Left_up_point.y()) / 3);

//        line_of_X -> setText(QString::number(Centre_of_mass.x()));
//        line_of_Y -> setText(QString::number(Centre_of_mass.y()));

//        QGraphicsPolygonItem::mouseReleaseEvent(event);

//        delta.setX(0);
//        delta.setY(0);
//        Mouse_last_pos = QPointF();
//    }

//}

