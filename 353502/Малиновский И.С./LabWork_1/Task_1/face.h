#ifndef FACE_H
#define FACE_H

#include "movingellipse.h"

class Face : public MovingEllipse {
    Q_OBJECT

public:
    Face(QWidget* parent = nullptr);

public slots:
    void openMouth();
    void closeMouth();
    void moveEyes(int dx, int dy);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    bool mouthOpen;
    int eyeDx;
    int eyeDy;
};

#endif // FACE_H
