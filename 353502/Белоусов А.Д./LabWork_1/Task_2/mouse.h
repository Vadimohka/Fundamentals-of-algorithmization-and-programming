#ifndef MOUSE_H
#define MOUSE_H

#include <QGraphicsSceneMouseEvent>
#include <QtCore>
#include "paintscene.h"

class mouseCatcher : public QObject
{
    Q_OBJECT

private:
    QPoint previous;
    paintScene* sceneToGetMouse;
public:
    explicit mouseCatcher(paintScene *sceneToGetMouse);
signals:
    void mouseDragged(int x1, int y1, int x2, int y2);
    void mouseClicked(int x, int y);
private slots:
    void processMouseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // MOUSE_H
