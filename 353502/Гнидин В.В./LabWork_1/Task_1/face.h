//
// Created by volodya-petarda on 3/9/24.
//

#ifndef GALAVA_FACE_H
#define GALAVA_FACE_H

#include <QGraphicsObject>
#include <QGraphicsView>
#include "movingEllipse.h"

class face : public QGraphicsObject {
    Q_OBJECT
public slots:

    void scaleMouth();

    void moveEyes();

private slots:

    void scaleEyes();

    void setMouthAnimationFalse();

    void setEyesAnimationFalse();

public:
    face(int xPos, int yPos, QGraphicsScene *scene);

private:
    bool isMouthAnimation = false, isEyesAnimation = false;
    int xPos, yPos;
    movingEllipse *mainFace, *leftEye, *rightEye, *mouth;

    [[nodiscard]] QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};


#endif //GALAVA_FACE_H
