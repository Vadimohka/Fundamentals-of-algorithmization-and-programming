#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    at = dynamic_cast<Figure*>(itemAt(event->scenePos(), {}));
    if (at && event->button() == Qt::LeftButton)
    {
        at->setCursor(Qt::ClosedHandCursor);
        at->setFlag(QGraphicsItem::ItemIsMovable);
        lastPos = event->scenePos();
        X = event->scenePos().x();
        Y = event->scenePos().y();
    }
    else if (at && event->button() == Qt::RightButton){
        rot = true;
        del = true;
    }
    else if (event->button() == Qt::LeftButton) {
        switch (m_typeFigure){
        case CircleType:{
            Circle *item = new Circle(event->scenePos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case ElipsType: {
            Elips *item = new Elips(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case HexagonType: {
            Hexagon *item = new Hexagon(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case RectangleType: {
            Rectangle *item = new Rectangle(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case RombType: {
            Romb *item = new Romb(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case SquareType: {
            Square *item = new Square(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case TriangleType: {
            Triangle *item = new Triangle(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case Star_FiveType: {
            Star_Five *item = new Star_Five(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case Star_SixType: {
            Star_Six *item = new Star_Six(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case Star_EightType: {
            Star_Eight *item = new Star_Eight(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            tempFigure = item;
            break;
        }
        case DrawType:{
            Draw *item = new Draw(event->scenePos());
            item->setPos(event->pos());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            points_draw = &item->points;
            tempFigure = item;
            it = item;
            break;
        }
        }
        this->addItem(tempFigure);
        this->update(QRectF(0,0,this->width(), this->height()));
    }

}

void PaintScene::updateLabel()
{
    x = QString::number(int(tempFigure->X));
    y = QString::number(int(tempFigure->Y));
    s = QString::number(tempFigure->S);
    p = QString::number(tempFigure->P);
    xy = "(" + x + "," + y + ")";
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (at && event->buttons()==Qt::LeftButton)
    {
        at->setCursor(QCursor(Qt::ClosedHandCursor));
        at->setFlag(QGraphicsItem::ItemIsMovable);
        if (event->scenePos().x() < maxW - (at->a/2) && event->scenePos().x() > (at->a/2)  && event->scenePos().y() < maxH - (at->a/2)  && event->scenePos().y() > (at->a/2) ){
        QPointF newPos = event->scenePos() - lastPos;
        at->setPos(at->pos() + newPos);
        lastPos = event->scenePos();
        X += newPos.x();
        Y += newPos.y();
        S = at->S;
        P = at->P;
        x = QString::number(X);
        y = QString::number(Y);
        s = QString::number(S);
        p = QString::number(P);
        xy = "(" + x + "," + y + ")";
        this->update(QRectF(0,0,this->width(), this->height()));
        }
    }
    else if ((m_typeFigure == DrawType) && event->buttons()==Qt::LeftButton && points_draw != nullptr){

    if (event->scenePos().x() < maxW && event->scenePos().x() > 0  && event->scenePos().y() < maxH  && event->scenePos().y() > 0 ){
    (*points_draw).append(event->scenePos());
    this->update(QRectF(0,0,this->width(), this->height()));

    s = "";
    p = "";

    X += event->scenePos().x();
    Y += event->scenePos().y();
    X = X / ((*points_draw).size()+1);
    Y = Y / ((*points_draw).size()+1);
    x = QString::number(int(X));
    y = QString::number(int(Y));
    X = X * ((*points_draw).size()+1);
    Y = Y * ((*points_draw).size()+1);
    xy = "(" + x + "," + y + ")";
    }
    }
}


void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if (at && event->button() == Qt::LeftButton)
    {
    at->setCursor(QCursor(Qt::ArrowCursor));
    at = nullptr;
    if (m_typeFigure != DrawType){
     updateLabel();
            }
     this->update(QRectF(0,0,this->width(), this->height()));
    }
    else if (at && event->button() == Qt::RightButton){
     if (del == false){
     at = nullptr;
     }
     rot = false;
     this->update(QRectF(0,0,this->width(), this->height()));
    }
    else if (m_typeFigure == DrawType && event->button() == Qt::LeftButton && points_draw != nullptr)
    {
        s = "";
        p = "";
        X = (X / ((*points_draw).size()));
        Y = (Y / ((*points_draw).size()));
        x = QString::number(int(X));
        y = QString::number(int(Y));
        xy = "(" + x + "," + y + ")";
        points_draw = nullptr;
        if (it != nullptr){
        it->X = X;
        it->Y = Y;
        it = nullptr;
        }
    }

}

void PaintScene::wheelEvent(QGraphicsSceneWheelEvent *event){
    Figure *item = dynamic_cast<Figure*>(itemAt(event->scenePos(), {}));
    if (item && rot == false){
        if (item->a > 10 && event->delta() < 0){
            item->a -= 5;
        }
        else if (event->delta()>0) {
            item->a+=5;
        }
        x = QString::number(int(item->X));
        y = QString::number(int(item->Y));
        s = QString::number(item->S);
        p = QString::number(item->P);
        xy = "(" + x + "," + y + ")";
         this->update(QRectF(0,0,this->width(), this->height()));
    }
    else if (at && rot == true){
        if (event->delta() > 0)
        {
            at->grad += 5;
        }
        else
        {
            at->grad -= 5;
        }
        at->setTransformOriginPoint(at->X, at->Y);
        at->setRotation(at->grad);
        this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::keyPressEvent(QKeyEvent *event){
    if (at && del){
        if (event->key() == Qt::Key_Delete)
        {
            delete at;
            at = nullptr;
            del = false;
            qDebug("sfds");
        }
    }
}
