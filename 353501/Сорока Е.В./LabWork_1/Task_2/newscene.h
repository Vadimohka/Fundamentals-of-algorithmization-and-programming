#ifndef NEWSCENE_H
#define NEWSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

    class NewScene : public QGraphicsScene
{
    Q_OBJECT

public:
    NewScene(QObject *parent = nullptr);

signals:
    void mousePressed(const QPointF& point);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouse) override;

private:

    bool mouseHeld = false;

};

#endif // NEWSCENE_H
