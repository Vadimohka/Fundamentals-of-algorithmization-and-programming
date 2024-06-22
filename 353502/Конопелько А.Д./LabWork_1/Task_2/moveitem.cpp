#include "moveitem.h"

QString MoveItem::nameOfTheItem;
QString MoveItem::typeOfMoving;
qreal MoveItem::xPos;
qreal MoveItem::yPos;
qreal MoveItem::xToMove;
qreal MoveItem::yToMove;
qreal MoveItem::xSpeed;
qreal MoveItem::perimeter;
qreal MoveItem::square;
qreal MoveItem::ySpeed;
qreal MoveItem::scale;
qreal MoveItem::angleSpeed;
bool MoveItem::allow;

MoveItem::MoveItem(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    allow = true;
    scale = 1;
}

void MoveItem::setItem(const QString& nameNewItem)
{
    this -> nameOfTheItem = nameNewItem;
}

void MoveItem::setMoving(const QString &newMoving)
{
    this -> typeOfMoving = newMoving;
}

void MoveItem::setScaling(QPointF pos)
{

}

void MoveItem::setXPos(const qreal &newXPos)
{
    this -> xToMove = newXPos;
}

void MoveItem::setYPos(const qreal &newYPos)
{
    this -> yToMove = newYPos;
}

MoveItem::~MoveItem()
{

}

QRectF MoveItem::boundingRect() const
{
    return QRectF(-100, -100, 200, 200);
}

qreal MoveItem::findPerimeter()
{

}

qreal MoveItem::findSquare()
{

}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //emit signalAskForTypeOfMoving();
    if(typeOfMoving == "move"){
        this -> setPos(mapToScene(event -> pos()));
        setItemPosition(/*mapToScene*/(event -> pos()));
        emit sharePosition(mapToScene(event -> pos()));
        //qDebug() << " * " << positionOfTheItem;
    }
    else if(typeOfMoving == "changeSize"){
        perimeter = findPerimeter();
        square = findSquare();
        xPos = (mapToScene(positionOfTheItem)).rx();
        yPos = (mapToScene(positionOfTheItem)).ry();
        scale = sqrt(((mapToScene(event -> pos()).rx()) - xPos) * (mapToScene(event -> pos()).rx() - xPos) + (mapToScene(event -> pos()).ry() - yPos) * (mapToScene(event -> pos()).ry() - yPos)) / 100;
        this -> setScale(scale);
        changePerimSquare(scale);
        emit sharePerimeterSquare(perimeter, square);
    }
    else
        return;
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << " PPP " << mapToScene(this -> positionOfTheItem);
    emit signalAskForTypeOfMoving();
    if(typeOfMoving == "move"){
        emit sharePosition(mapToScene(event -> pos()));
    }
    else if(typeOfMoving == "rotate"){
        smoothMoveTimer = new QTimer(this);
        connect(smoothMoveTimer, &QTimer::timeout, this, &MoveItem::advanceRotate);
        smoothMoveTimer -> start(1000/60);
    }
    else if(typeOfMoving == "moveTo" && allow){
        xPos = (mapToScene(positionOfTheItem)).rx();
        yPos = (mapToScene(positionOfTheItem)).ry();
        if(abs(xPos - xToMove) <= 0.4 && abs(yPos - yToMove) <= 0.4)
            return;
        emit signalBlockOK();
        allow = false;
        // xPos = positionOfTheItem.x();
        // yPos = positionOfTheItem.y();
        //qDebug() << xToMove << " " << xPos;
        //qDebug() << yToMove << " " << yPos;
        xSpeed = (xToMove - xPos) / 100;
        ySpeed = (yToMove - yPos) / 100;
        smoothMoveTimer = new QTimer(this);
        connect(smoothMoveTimer, &QTimer::timeout, this, &MoveItem::advance);
        smoothMoveTimer -> start(1000/60);

    }
    else if(typeOfMoving == "changeSize"){
        perimeter = findPerimeter();
        square = findSquare();
    //  emit sharePerimeterSquare(perimeter * scale, square * scale * scale);
    }
    else if(typeOfMoving == "deleteItem"){
        emit deleteItem(this);
    }
    emit signalChangeScene();
    this -> setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{    
    this -> setCursor(QCursor(Qt::ArrowCursor));
    if(typeOfMoving == "rotate"){
        disconnect(smoothMoveTimer, &QTimer::timeout, this, &MoveItem::advanceRotate);
    }
    Q_UNUSED(event);
}

void MoveItem::changePerimSquare(qreal scale)
{
    this -> perimeter *= scale;
    this -> square *= scale * scale;
}

void MoveItem::slotGetPosition(QPointF pointSetPos)
{
    this -> setItemPosition(mapToScene(pointSetPos));
    //qDebug() << "G" << pointSetPos;
}

void MoveItem::setItemPosition(QPointF pointPos)
{
    positionOfTheItem = /*mapToScene*/(pointPos);
    xPos = (positionOfTheItem.rx());
    yPos = (positionOfTheItem.ry());
}

void MoveItem::getAngleSpeed(qreal angleSpeedNew){
    this -> angleSpeed = angleSpeedNew;
}

void MoveItem::advance()
{
    if(typeOfMoving == "moveTo" && (abs(xPos - xToMove) >= 0.3 || abs(yPos - yToMove) >= 0.3)){
        moveBy(xSpeed, ySpeed);
        xPos += xSpeed;
        yPos += ySpeed;
        positionOfTheItem = mapToScene(QPointF(xPos, yPos));
    }
    else{
        disconnect(smoothMoveTimer, &QTimer::timeout, this, &MoveItem::advance);
        emit signalReleaseOK();
        allow = true;
        //qDebug() << mapToScene(positionOfTheItem) << '\n';
        positionOfTheItem = mapFromScene(QPointF(xPos, yPos));
        // xPos = xToMove;
        // yPos = yToMove;
    }
}

void MoveItem::advanceRotate()
{
    setRotation(this -> rotation() + angleSpeed);
}

