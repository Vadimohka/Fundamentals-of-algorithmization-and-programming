#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    paintScene();
private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void mouseEventOccured(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
