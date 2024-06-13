#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    Q_PROPERTY(int typeFigure READ typeFigure WRITE setTypeFigure NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = nullptr);

    int typeFigure() const;
    void setTypeFigure(const int type);

    enum FigureTypes{
        RectType,
        RhombType,
        TriangleType,
        EllipseType,
        StarType,
        EightStarType,
        SixStarType,
        DeleteType,
        MoveType,
        RotateType
    };

    QPointF getStartPoint();
    QPointF getEndPoint();

    void setStartPoint(QPointF startPoint);
    void setEndPoint(QPointF endPoint);
public slots:
    void rotateEvent();
signals:
    void typeFigureChanged();

private:
    Figure *tempFigure;
    int m_typeFigure;
    const int w = 1920, h = 1001, rotSpeed = 12;
    QList<QGraphicsItem *> foundItems;
    QList<Figure*> paintedItems{1};
    Figure *item;
    bool isMoving = false;
    bool isRotating = false;

    QTimer* rotateTimer;

    QPointF startp, endp;
    QPointF startMove;
    qreal rotate;
    qreal xCenter = 0, yCenter = 0;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PAINTSCENE_H
