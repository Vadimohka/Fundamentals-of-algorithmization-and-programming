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
    QGraphicsItem* item;
signals:
    void signalMove(QPointF point);
    void signalPressLeft(QPointF point);
    void signalPressRight(QPointF point);
    void signalRelease(QPointF point);
    void signalDelete();
public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    QPointF mousePos;
};

#endif // CUSTOMSCENE_H
