#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit CustomScene(QObject *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void leftMousePressed(QPointF pos);
    void rightMousePressed(QGraphicsSceneMouseEvent *event);
    void mouseMoved(QPointF prev_pos, QPointF curr_pos);
    void deleteItem();

private:
    QPointF last_pos;
    QPointF previous_pos;
};

#endif // CUSTOMSCENE_H
