#ifndef ELEMENT_H
#define ELEMENT_H


#include <QObject>
#include <QTimer>
#include <PossibleRotations.h>


class Element
{
public:
    explicit Element();
    explicit Element(qreal initXRotation, qreal initYRotation, qreal initZRotation,
                     QString initColor);
    void rotateAlong(char axis, bool clockwise);

    qreal xRotation() const;

    qreal yRotation() const;

    qreal zRotation() const;

    void momentalRotate(char axis, bool clockwise);
signals:
private:

    qreal _xEulerRotation;
    qreal _yEulerRotation;
    qreal _zEulerRotation;
    QString _color;

    void calculateTargetAngle(bool);
    void updateRotation(bool);
    void normalzeAngles();
    void finalizeRotation();

    QTimer* animationTimer;
    QTimer* endTimer;
    qreal animationDuration = 200;
    char axis;
    qreal targetAngle;

    void _slowChange(char axis, bool clockwise);

    bool rotationsAre(QString);

    void _setRotationAngles(QString);

    void _momentalChange(char axis, bool clockwise);
};

#endif // ELEMENT_H
