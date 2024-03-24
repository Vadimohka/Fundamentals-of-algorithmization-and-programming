#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CustomScene(QObject *parent = 0);
    ~CustomScene();

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePressed(const QPointF& position);

};

#endif // CUSTOMSCENE_H
