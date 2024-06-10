#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QDebug>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomScene(QObject *parent = nullptr);
    ~CustomScene(){};
signals:
    void signalTargetCoordinate(QPointF point);
    void signalBlink();
    void signalTransform();

public slots:
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QPoint mousePos;
};

#endif // CUSTOMSCENE_H
