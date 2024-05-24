#include "figureitem.h"
#include "qgraphicsscene.h"
#include "gamefield.h"

FigureItem::FigureItem(GameField* field, QPointF pos)
{
    isLive = true;
    this->field = field;
    this->startPlacePos = pos;
    setPos(startPlacePos);

    this->setZValue(1);

    relasePlayer = new QMediaPlayer();
    output = new QAudioOutput();

    relasePlayer->setAudioOutput(output);
    relasePlayer->setSource(QUrl::fromLocalFile("../../media/soundFall1.mp3"));
    output->setVolume(0.3);

    setCursor(Qt::OpenHandCursor);
    setFlag(QGraphicsItem::ItemIsSelectable, true);

}

FigureItem::~FigureItem(){}

void FigureItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setScale(1);
    this->setZValue(2);

    if(event->button() == Qt::LeftButton)
    {
        setCursor(Qt::ClosedHandCursor);
        xFromMouse = this->sceneBoundingRect().x() - event->scenePos().x();
        yFromMouse = this->sceneBoundingRect().y() - event->scenePos().y();
    }

    QGraphicsItem::mousePressEvent(event);
}

void FigureItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF newPos = QPointF(event->scenePos().x() + xFromMouse, event->scenePos().y() + yFromMouse);

    QRectF sceneRect = scene()->sceneRect();

    QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();
    QPointF topLeftShape = shapeBoundingRect.topLeft();

    qUnit = scene()->height() / 15.0;

    QRectF newShapeRect = QRectF(newPos.x() + (shapeBoundingRect.x() - sceneBoundingRect().x()),
                               newPos.y() + (shapeBoundingRect.y() - sceneBoundingRect().y()),
                               shapeBoundingRect.width(), shapeBoundingRect.height());

    if(sceneRect.contains(newShapeRect))
    {
        setPos(newPos.x(), newPos.y());

        shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();
        topLeftShape = shapeBoundingRect.topLeft();

        qreal xIndexOfSquare = round((topLeftShape.x() - 2.0 * qUnit) / qUnit);
        qreal yIndexOfSquare = round((topLeftShape.y() - 1.0 * qUnit) / qUnit);


        if(xIndexOfSquare >= 0 && xIndexOfSquare <= 9 - shapeBoundingRect.width() / (1.0 * qUnit) &&
            yIndexOfSquare >= 0 && yIndexOfSquare <= 9 - shapeBoundingRect.height() / (1.0 * qUnit))
        {
            //UpdateCoordinatesOfSquares();
            getField()->setShadowForFigure(leftTopPointsOfSquares, xIndexOfSquare, yIndexOfSquare);
        }

        else
        {
            getField()->resetShadowsAndLight();
        }
    }
    else
    {
        QPointF boundedPos;
        qreal leftBorder, rightBorder, topBorder, bottomBorder;

        leftBorder = sceneRect.left() - (shapeBoundingRect.x() - sceneBoundingRect().x());
        rightBorder = sceneRect.right() - (shapeBoundingRect.width() + (shapeBoundingRect.x() - sceneBoundingRect().x()));
        topBorder = sceneRect.top() - (shapeBoundingRect.y() - sceneBoundingRect().y());
        bottomBorder = sceneRect.bottom() - (shapeBoundingRect.height() + (shapeBoundingRect.y() - sceneBoundingRect().y()));;


        boundedPos.setX(qBound(leftBorder, newPos.x(), rightBorder));
        boundedPos.setY(qBound(topBorder, newPos.y(), bottomBorder));

        this->setPos(boundedPos);

        getField()->resetShadowsAndLight();
    }

    QGraphicsItem::mouseMoveEvent(event);
}

void FigureItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        setCursor(Qt::OpenHandCursor);
        this->setScale(0.9);
        this->setZValue(1);

        if(getField()->isAboveAnFigure())
        {
            relasePlayer->setSource(QUrl::fromLocalFile("../../media/soundFall1.mp3"));
            relasePlayer->play();

            //добавляем кол-во очков в виде кол-ва заполненных квадратов


            getField()->fillCellsByNewFigure();

            setLive(false);
            emit isPlaced();
            this->hide();

            if(scene() != nullptr) scene()->removeItem(this);
        }
        else
        {   
            setPos(startPlacePos);
        }
    }

    QGraphicsItem::mouseReleaseEvent(event);
}

void FigureItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        relasePlayer->setSource(QUrl::fromLocalFile("../../media/rotate.mp3"));
        relasePlayer->play();

        setRotation((rotation() + 90));
        if(rotation() >= 360) setRotation(rotation() - 360);

        UpdateCoordinatesOfSquares();
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void FigureItem::UpdateCoordinatesOfSquares()
{
    this->setScale(1);
    QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();
    QPainterPath path = mapToScene(shape());

    qUnit = scene()->height() / 15.0;
    path.moveTo(0,0);

    leftTopPointsOfSquares.clear();
    for(int i = 0; i < shapeBoundingRect.height() / qUnit; i++)
    {
        for(int j = 0; j < shapeBoundingRect.width() / qUnit; j++)
        {
            if(path.contains(QRectF(shapeBoundingRect.x() + j * qUnit + 1, shapeBoundingRect.y() + i * qUnit + 1, qUnit - 2, qUnit - 2)))
            {
                leftTopPointsOfSquares.push_back(std::make_pair(j, i));
            }
        }
    }
    this->setScale(0.9);
}

bool FigureItem::isCanBePlaced()
{
    qreal startRotation = this->rotation();
    qUnit = scene()->height() / 15;

    for(int r = 0; r < 4; r++)
    {
        this->setRotation(r * 90);
        UpdateCoordinatesOfSquares();
        QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();

        for(int i = 0; i < 9 - shapeBoundingRect.height() / qUnit; i++)
        {
            for(int j = 0; j < 9 - shapeBoundingRect.width() / qUnit; j++)
            {
                if(!getField()->AreCellsFilled(leftTopPointsOfSquares, j, i))
                {
                    setRotation(startRotation);
                    UpdateCoordinatesOfSquares();

                    return true;
                }
            }
        }
    }

    setRotation(startRotation);
    UpdateCoordinatesOfSquares();
    return false;
}

bool FigureItem::isCanBePlacedOn(int x, int y)
{
    qUnit = scene()->height() / 15;
    QRectF shapeBoundingRect = mapToScene(shape().boundingRect()).boundingRect();

    if(y < 9 - shapeBoundingRect.height() / qUnit && x < 9 - shapeBoundingRect.width() / qUnit)
    {
        if(!getField()->AreCellsFilled(leftTopPointsOfSquares, x, y))
        {
            return true;
        }
    }

    return false;
}

void FigureItem::placeOn(int x, int y)
{
    getField()->setShadowForFigure(leftTopPointsOfSquares, x, y);
    getField()->fillCellsByNewFigure();
}

void FigureItem::setLive(bool live)
{
    isLive = live;
}

bool FigureItem::getIsLive()
{
    return isLive;
}

QVector<std::pair<int, int> > FigureItem::getLeftTopPointsOfSquares()
{
    return leftTopPointsOfSquares;
}

GameField *FigureItem::getField()
{
    return this->field;
}
