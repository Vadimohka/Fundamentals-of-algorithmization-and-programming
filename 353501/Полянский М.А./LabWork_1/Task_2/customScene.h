#ifndef CUSTOMSCENE_N
#define CUSTOMSCENE_N
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
class customScene : public QGraphicsScene
{
    Q_OBJECT
public:
    customScene(QObject* parent = nullptr);
signals:
    void mousePressed(const QPointF &position);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
private:
    bool holdmouse;
    QPointF lastMousePos;
};

#endif 
