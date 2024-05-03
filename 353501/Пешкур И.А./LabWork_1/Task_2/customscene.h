#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT

public:

    CustomScene(QObject *parent = nullptr);

signals:
    void mousePressed(const QPointF& point);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;

private:

    bool mouseHeld = false;

};

#endif // CUSTOMSCENE_H
