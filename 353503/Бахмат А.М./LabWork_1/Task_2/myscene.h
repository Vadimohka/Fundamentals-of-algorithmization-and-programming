#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = nullptr);
signals:
    void mousePressed(const QPointF& point);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;
private:
    bool _isMouseHelding = false;
};

#endif // MYSCENE_H
