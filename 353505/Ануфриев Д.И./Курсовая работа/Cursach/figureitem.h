#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include "gamefield.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "figures/typesoffigures.h"
#include <QAudioOutput>
#include <QFileDialog>
#include <QObject>

class FigureItem : public QObject, public QGraphicsItem
{
    Q_OBJECT;

public:
    virtual QRectF boundingRect() const override = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;
    virtual QPainterPath shape() const override = 0;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    virtual TypesOfFigures::type getTypeOfFigure() = 0;
    virtual void UpdateCoordinatesOfSquares();

    bool isCanBePlaced();
    bool isCanBePlacedOn(int x, int y);
    void placeOn(int x, int y);

    void setLive(bool live);
    bool getIsLive();
    QVector <std::pair<int, int>> getLeftTopPointsOfSquares();

    GameField *getField();

    FigureItem(GameField* field, QPointF pos);
    ~FigureItem();

private:
    qreal xFromMouse, yFromMouse;

protected:
    qreal qUnit = 0;
    GameField* field;
    QPointF startPlacePos;
    bool isLive;

    QVector<std::pair<int, int>> leftTopPointsOfSquares;;

    QMediaPlayer* relasePlayer;
    QAudioOutput* output;

signals:
    void isPlaced();
};

#endif // FIGUREITEM_H
