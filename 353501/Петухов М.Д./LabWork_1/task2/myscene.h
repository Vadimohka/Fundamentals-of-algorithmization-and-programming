#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomScene(QObject *parent = nullptr);

signals:
    void mousePressed(const QPointF& position);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};
