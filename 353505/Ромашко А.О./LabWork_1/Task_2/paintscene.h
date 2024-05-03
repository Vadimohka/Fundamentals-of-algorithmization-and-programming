#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QCursor>
#include <QGraphicsView>
#include <QPoint>
#include <QTime>
#include <QtCore>

#include "basicfigure.h"


class PaintScene : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(int typeBasicFigure READ typeBasicFigure WRITE setTypeBasicFigure NOTIFY typeBasicFigureChanged FINAL)

public:
    PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeBasicFigure() const;
    void setTypeBasicFigure(const int type);

    enum BasicFigureT {
        Rectanglet,
        Rombt,
        Trianglet,
        Ellipset,
        Squaret,
        Circlet,
        Hexagont,
        Star_5t,
        Star_6t,
        Star_8t,
        Deletet,
        Warpt
    };
    BasicFigure* currentBasicFigure() const;

    QPointF getStartPoint();
    QPointF getEndPoint();
    void moveFigure(QGraphicsSceneMouseEvent *event);
    void setStartPoint(QPointF startPoint);
    void setEndPoint(QPointF endPoint);
signals:
    void typeBasicFigureChanged();
    void areaChanged(double area);
    void perimeterChanged(double perimeter);

private:
    BasicFigure *tempBasicFigure = nullptr;
    int m_typeBasicFigure;
    bool deletButtonActive;
    QPointF startp, endp;
    QTimer *rotationTimer;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
