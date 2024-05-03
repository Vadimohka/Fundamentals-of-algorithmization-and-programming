#ifndef FACE_H
#define FACE_H

#include "ellipse.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <QDebug>

class Face : public Ellipse
{
    Q_OBJECT
public:
    Face(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    Face();
    explicit Face(QObject *object = nullptr);
    Ellipse *leftPupil, *rightPupil;
    Ellipse *upperLip, *lowerLip;
    QTimer *timerEyes, *timerLips;
    qreal width = 300;
    qreal height = 300;
private slots:
    void movePupils();
    void startMovingPupils();
    void moveLips();
    void startMovingLips();
private:
    int _startAndEndPosPupils{}, _rightPosPupils{}, _leftPosPupils{};
    int _startAndEndPosOfUpperLip{}, _upPosOfUpperLip{};
    int _startAndEndPosOfLowerLip{}, _lowPosOfLowerLip{};
signals:
};

#endif // FACE_H
