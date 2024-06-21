#include "mwscene.h"

constexpr int PRECISION = 8;

/////////////////////////ивенты

void MWscene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(Rect)
    {
        spawnFigure = new Rectangle(event->scenePos());
    }
    else if(Rombius)
    {
        spawnFigure = new Romb1(event->scenePos());
    }
    else if(Ellipsoid)
    {
        spawnFigure = new Circle(event->scenePos());
    }
    else if(Triangl)
    {
        spawnFigure = new Triangle(event->scenePos());
    }
    else if(Sqre)
    {
        spawnFigure = new Square(event->scenePos());
    }
    else if(SixStr)
    {
        spawnFigure = new SixStar(event->scenePos());
    }
    else if(Staar)
    {
        spawnFigure = new Star(corners, event->scenePos());
    }
    else if(Hex)
    {
        spawnFigure = new Hexagon(event->scenePos());
    }
    else if(DragButtToggled || ScaleButtChecked || RotateButtonToggled || DeleteButtChecked)
    {
        list.clear();
        list = this->items(QRectF(event->scenePos().x() - 1, event->scenePos().y() - 1, 1, 1));
        if (!list.isEmpty())
        {
            item = dynamic_cast<Figure*>(list[0]);

            emit sendPerimeter(QString::number(item->getPerimeter(), 'g', PRECISION));
            emit sendArea(QString::number(item->getArea(), 'g', PRECISION));

            if (DeleteButtChecked)
            {
                delete item;
            }
        }
    }

    if (Rect || Rombius || Ellipsoid || Triangl || Sqre || SixStr || Staar || Hex)
    {
        spawnFigure->setSP(event->scenePos());
        spawnFigure->upd();
        this->addItem(spawnFigure);
    }
    QGraphicsScene::mousePressEvent(event);
}

void MWscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (DragButtToggled && !Blank && !list.isEmpty())
    {
        item->setPos(event->scenePos().x() - (item->getSP().x() + item->getEP().x())/2,
                     event->scenePos().y() - (item->getSP().y() + item->getEP().y())/2);
    }
    else if(Rect || Rombius || Ellipsoid || Triangl || Sqre || SixStr || Staar || Hex)
    {
        spawnFigure->setEP(event->scenePos());

        emit sendPerimeter(QString::number(spawnFigure->getPerimeter(), 'g', PRECISION));
        emit sendArea(QString::number(spawnFigure->getArea(), 'g', PRECISION));

        this->update(0, 0, this->width(), this->height());
    }
}

/////////////////////Слоты

void MWscene::blank_checked(bool b) { Blank = b; }

void MWscene::buttRect_checked(bool b){ Rect = b; }

void MWscene::buttRomb_checked(bool b) { Rombius = b; }

void MWscene::buttCircle_checked(bool b) { Ellipsoid = b; }

void MWscene::buttTriangle_checked(bool b) { Triangl = b; }

void MWscene::buttSquare_checked(bool b) { Sqre = b; }

void MWscene::buttSixStar_checked(bool b) { SixStr = b; }

void MWscene::buttStar_checked(bool b) { Staar = b; }

void MWscene::buttHexagon_checked(bool b) { Hex = b; }

void MWscene::buttDrag_checked(bool b) { DragButtToggled = b; }

void MWscene::buttRotate_checked(bool b) { RotateButtonToggled = b; }

void MWscene::buttScale_checked(bool b) { ScaleButtChecked = b; }

void MWscene::buttDelete_checked(bool b) { DeleteButtChecked = b; }

void MWscene::getCorners(double corners) { this->corners = corners; }

//////////////////////Трансформирование

void MWscene::getScale(double sc)
{
    if(!list.isEmpty())
    {
        qDebug() << spawnFigure->getSEP().x() << spawnFigure->getSEP().y();
        double a = item->getSEP().x() > item->getSEP().y() ?
                   item->getSEP().y() / item->getSEP().x() : item->getSEP().x() / item->getSEP().y();

        if (item->getEP().x() > item->getSP().x() && item->getEP().y() > item->getSP().y())
        {
            item->setEP(QPointF(item->getEP().x() + sc/2 * (item->getSEP().x() > item->getSEP().y() ? 1 : a),
                                item->getEP().y() + sc/2 * (item->getSEP().x() < item->getSEP().y() ? 1 : a)));
            item->setSP(QPointF(item->getSP().x() - sc/2 * (item->getSEP().x() > item->getSEP().y() ? 1 : a),
                                item->getSP().y() - sc/2 * (item->getSEP().x() < item->getSEP().y() ? 1 : a)));
        }
        else
        {
            item->setEP(QPointF(item->getEP().x() - sc/2 * (item->getSEP().x() > item->getSEP().y() ? 1 : a),
                                item->getEP().y() - sc/2 * (item->getSEP().x() < item->getSEP().y() ? 1 : a)));
            item->setSP(QPointF(item->getSP().x() + sc/2 * (item->getSEP().x() > item->getSEP().y() ? 1 : a),
                                item->getSP().y() + sc/2 * (item->getSEP().x() < item->getSEP().y() ? 1 : a)));
        }

        emit sendPerimeter(QString::number(item->getPerimeter(), 'g', PRECISION));
        emit sendArea(QString::number(item->getArea(), 'g', PRECISION));

        this->update(0, 0, this->width(), this->height());
    }
}

void MWscene::getRotation(double rot)
{
    if(!list.isEmpty())
    {
        cx = (item->getEP().x() + item->getSP().x())/2;
        cy = (item->getEP().y() + item->getSP().y())/2;
        item->setTransformOriginPoint(QPointF(cx, cy));
        item->setRotation(item->rotation()+rot);
    }
}
