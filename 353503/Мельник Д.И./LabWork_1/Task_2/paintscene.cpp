#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "rectangle.h"
#include "hexagon.h"
#include "star_5.h"
#include "star_6.h"
#include "star_8.h"


PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

QPointF PaintScene::getEndPoint()
{
    return this->endp;
}

QPointF PaintScene::getStartPoint()
{
    return this->startp;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setStartPoint(QPointF startPoint)
{
    startp = startPoint;
}

void PaintScene::setEndPoint(QPointF endPoint)
{
    endp = endPoint;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (deletButtonActive){
        return;
    }
    if (tempFigure != nullptr && event->buttons() & Qt::RightButton){
    moveFigure(event);
    }
    if (tempFigure != nullptr && (event->buttons() & (Qt::ForwardButton | Qt::BackButton))){
        return;
    }
    setEndPoint(event->scenePos());

    this->update(QRectF(0,0,this->width(), this->height()));
    /* Устанавливаем конечную координату положения мыши
         * в текущую отрисовываемую фигуру
         * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
         * необходимо для устранения артефактов при отрисовке фигур
         * */
    if (tempFigure != nullptr){
    emit areaChanged(tempFigure->area());
    emit perimeterChanged(tempFigure->perimeter());
    }
    qDebug () <<"move";

    this->update(QRectF(0,0,this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
     * и помещаем её на сцену, сохранив указатель на неё в переменной
     * tempFigure
     * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    deletButtonActive = false;
    setStartPoint(event->scenePos());

    if (event->buttons() & (Qt::ForwardButton | Qt::BackButton)){
        rotationFigure(event);
        return;
    }

    switch (m_typeFigure) {
    case RectangleType: {
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case EllipseType: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case SquareType:{
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case CircleType: {
        Circle *item = new Circle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case HexagonType:{
        Hexagon *item = new Hexagon(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star_5Type:{
        Star_5 *item = new Star_5(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star_6Type:{
        Star_6 *item = new Star_6(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star_8Type:{
        Star_8 *item = new Star_8(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case DeleteType:{
        if (tempFigure != nullptr){
        deletButtonActive = true;

        QList<QGraphicsItem *> foundItems = this->items(QPolygonF()
            << QPointF(event->scenePos().x(), event->scenePos().y())
            << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
            << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
            << QPointF(event->scenePos().x() + 1, event->scenePos().y()));

        if (!foundItems.isEmpty()){
            qDebug() << " DELETE ITEM ";
            for (int i =0; i < foundItems.size(); ++i) {
                if (foundItems[i] == tempFigure){
                    foundItems[i]->hide();
                }
                else{
                removeItem(foundItems[i]);
                }
            }
        }
        this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
        break;
        }
    }
    case WarpType:{
        if (tempFigure != nullptr){
        tempFigure->setStartPoint(event->scenePos());
        this->update(QRectF(0,0,this->width(), this->height()));
        break;
        }
    }
    default:{
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    if (!(event->buttons() & Qt::RightButton)){
    this->addItem(tempFigure);
    qDebug () << "Add item";
    }
}

void PaintScene::rotationFigure(QGraphicsSceneMouseEvent *event)
{

    this->update(QRectF(0,0,this->width(), this->height()));

    if (tempFigure != nullptr) {
        tempFigure->setTransformOriginPoint(QCursor::pos().x()-50,QCursor::pos().y()-50);

        if (event->buttons() & Qt::BackButton) {
            rotationTimer = new QTimer(this);
            connect(rotationTimer, &QTimer::timeout, this, &PaintScene::rotateRight);
            rotationTimer->start(100); // Запуск таймера с интервалом в 100 мс
        } else if (event->buttons() & Qt::ForwardButton) {
            rotationTimer = new QTimer(this);
            connect(rotationTimer, &QTimer::timeout, this, &PaintScene::rotateLeft);
            rotationTimer->start(100); // Запуск таймера с интервалом в 100 мс
        }
    }
}

void PaintScene::rotateLeft()
{
    if (tempFigure != nullptr) {
        tempFigure->setRotation(tempFigure->rotation() - 15); // Поворот на 15 градусов влево
        this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::rotateRight()
{
    if (tempFigure != nullptr) {
        tempFigure->setRotation(tempFigure->rotation() + 15); // Поворот на 15 градусов вправо
        this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->button() == Qt::BackButton || event->button() == Qt::ForwardButton) && rotationTimer) {
        rotationTimer->stop(); // Остановка таймера при отпускании боковой кнопки мыши
        delete rotationTimer;
        rotationTimer = nullptr;
    }
}

void PaintScene::keyPressEvent(QKeyEvent *shiftKey)
{
    if(shiftKey->key() == Qt::Key_Shift) {
        qDebug () <<"Shift event";
        QPointF endPoint = getEndPoint();
        QPointF startPoint = getStartPoint();
        QPointF diff = endPoint - startPoint;
        if (diff.x() < diff.y()){
            endPoint.rx() = startPoint.x() + diff.y();
            tempFigure->setEndPoint(endPoint);
        }
        else if (diff.x() > diff.y()){
            endPoint.ry() = startPoint.y() + diff.x();
            tempFigure->setEndPoint(endPoint);
        }
        if (tempFigure != nullptr){
            emit areaChanged(tempFigure->area());
            emit perimeterChanged(tempFigure->perimeter());
        }
        update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (tempFigure !=nullptr){
    QPointF endPoint = getEndPoint();
    QPointF startPoint = getStartPoint();
    endPoint   += QPointF(5, 5);
    startPoint -= QPoint(5, 5);
    if (event->delta() > 0){
        endPoint   += QPointF(5, 5);
        startPoint -= QPoint(5, 5);
        qDebug() << event->delta();
    }
    else if (event->delta() < 0){
        endPoint   -= QPointF(10, 10);
        startPoint += QPoint(10, 10);
        qDebug() << event->delta();
    }
    setEndPoint(endPoint);
    setStartPoint(startPoint);

    tempFigure->setStartPoint(startPoint);
    tempFigure->setEndPoint(endPoint);

    qDebug () << "Whel" << startPoint << endPoint;
    emit areaChanged(tempFigure->area());
    emit perimeterChanged(tempFigure->perimeter());
    }
    update(QRectF(0,0,this->width(), this->height()));
}

Figure* PaintScene::currentFigure() const {
    return tempFigure;
}

void PaintScene::moveFigure(QGraphicsSceneMouseEvent *event)
{

    QList<QGraphicsItem *> foundItems = this->items(QPolygonF()
        << QPointF(event->scenePos().x(), event->scenePos().y())
        << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
        << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
        << QPointF(event->scenePos().x() + 1, event->scenePos().y()));
    if (!foundItems.empty()){
    QPointF diff = event->scenePos() - event->lastScenePos();
    foundItems[0]->moveBy(diff.x(), diff.y());
    qDebug () <<"Move event " << diff;
    }
}
