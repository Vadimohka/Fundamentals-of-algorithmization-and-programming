#ifndef HANOIVISUALS_H
#define HANOIVISUALS_H

#include <QGraphicsScene>
#include <QTimer>

class HanoiVisuals : public QObject
{
    Q_OBJECT

public:
    HanoiVisuals();
    QGraphicsScene *scene;

    enum AnimationPhase
    {
        Finished,
        GoingUp,
        MovingHorizontally,
        GoingDown
    };

    int RODS_POS[3] = {-360, 0, 360};
    float ROD_W = 8;
    float ROD_H = 480;
    float BASE_W = 300;
    float RING_SIZE_H = 40;
    float RING_SIZE_W_ITER = 30;

    void reset(int, QVector<QPair<int, int>>*);
    void setSelection(int);
    void setSpeed(int);
private:
    QVector<QPair<int, int>> *list;
    QTimer *timer;
    QVector<QGraphicsRectItem*> rods[3];
    int speed = 1;
    int ringsCount;
    int currentSelection = 0;
    int currentAction = 0;
    int source = 0;
    int target = 0;
    int state = 0;

    void update();
};

#endif // HANOIVISUALS_H
