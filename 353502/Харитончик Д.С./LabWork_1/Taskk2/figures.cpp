#include "figures.h"

int Figure::action = 0;
QString Figure::figureNow = " ";

void Figure::setAction(int newAction)
{
    action = newAction;
}

void Figure::setFigureNow(const QString &newFigureNow)
{
    figureNow = newFigureNow;
}

QString Figure::getFigureNow()
{
    return figureNow;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit newItem(this, figureNow);

    emit centerSignal(getScenePosition());

    emit squareSignal(squareOfFigure());

    emit perimetrSignal(perimetrOfFigure());

    if (action == -1)
    {
        emit deleteItem(this);
    }
    if (action == 1)
    {
        previous = event->scenePos();
        setCenterOfFigureNow(scenePos());
    }
    if (action == 3)
    {
        emit mouseHasAlreadyClicked(event->scenePos());
    }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit squareSignal(squareOfFigure());

    emit perimetrSignal(perimetrOfFigure());

    if (action == 0)
    {
        setPositionOfTheFigure(event->pos());
        emit centerSignal(getScenePosition());
        setCenterOfFigureNow(scenePos());
    }
    if (action == 1)
    {
        emit mousePosition(event->scenePos());
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void Figure::setCenterOfFigureNow(QPointF center)
{
    centerOfFigure = center;
}

void Figure::setPositionOfTheFigure(QPointF pos)
{
    setPos(mapToScene(pos));
}

QPointF Figure::getScenePosition()
{
    return scenePos();
}

void Figure::resize(qreal changeSize)
{
    Q_UNUSED(changeSize);
}

void Figure::setLeftRotation()
{
    const int leftAngle = 5;
    angle -= leftAngle;
    update();
}

void Figure::setRightRotation()
{
    const int rightAngle = 5;
    angle += rightAngle;
    update();
}

Figure::Figure()
{
}




