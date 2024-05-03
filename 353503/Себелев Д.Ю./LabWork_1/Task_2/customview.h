#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H

#include <QGraphicsScene>
class CustomView : public QGraphicsScene
{
public:
    explicit CustomView(QObject *parent = nullptr);

//     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

// signals:
//     void leftMousePressed(QPointF pos);
};

#endif // CUSTOMVIEW_H
