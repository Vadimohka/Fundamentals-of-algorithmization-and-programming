#include "face.h"
#include "ellipse.h"

Face::Face(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):Ellipse(x, y, width, height, parent)
{
    Ellipse* leftEye = new Ellipse(2.25 * width / 12, 2.75 * height / 12, 2.5 * width / 12, 2.5 * height / 12, this);
    Ellipse* rightEye = new Ellipse(7.25 * width / 12, 2.75 * height / 12, 2.5 * width / 12, 2.5 * height / 12, this);
    leftEye -> setBrush(Qt::white);
    rightEye -> setBrush(Qt::white);

    leftPupil = new Ellipse(3.25 * width / 12, 3.5 * height / 12, 1 * width / 24, 1 * height / 24, this);
    rightPupil = new Ellipse(8.25 * width / 12, 3.5 * height / 12, 1 * width / 24, 1 * height / 24, this);
    leftPupil -> setBrush(Qt::black);
    rightPupil -> setBrush(Qt::black);

    upperLip = new Ellipse(4 * width / 12, 8.5 * height / 12, 4 * width / 12, height / 12, this);
    lowerLip = new Ellipse(4 * width / 12, 8.5 * height / 12, 4 * width / 12, height / 12, this);
    upperLip -> setBrush(Qt::red);
    lowerLip -> setBrush(Qt::red);

    timerEyes = new QTimer;
    timerLips = new QTimer;
}

void Face::movePupils()
{
    _startAndEndPosPupils++;
    leftPupil -> setPos(_startAndEndPosPupils, 0);
    rightPupil -> setPos(_startAndEndPosPupils, 0);
    if(_startAndEndPosPupils > 20)
    {
        _rightPosPupils--;
        leftPupil -> setPos(_rightPosPupils, 0);
        rightPupil -> setPos(_rightPosPupils, 0);
        if(_rightPosPupils < -20)
        {
            _leftPosPupils++;
            leftPupil -> setPos(_leftPosPupils, 0);
            rightPupil -> setPos(_leftPosPupils, 0);
            if(_leftPosPupils == 0) timerEyes -> stop();
        }
    }
}

void Face::startMovingPupils()
{
    _startAndEndPosPupils = 0;
    _rightPosPupils = 20;
    _leftPosPupils = -20;
    timerEyes -> start(1000/120);
}

void Face::moveLips()
{
    _startAndEndPosOfLowerLip--;
    _startAndEndPosOfUpperLip++;
    upperLip -> setPos(0, _startAndEndPosOfUpperLip);
    lowerLip -> setPos(0, _startAndEndPosOfLowerLip);
    if(_startAndEndPosOfLowerLip < -20 && _startAndEndPosOfUpperLip > 20)
    {
        _upPosOfUpperLip--;
        _lowPosOfLowerLip++;
        upperLip -> setPos(0, _upPosOfUpperLip);
        lowerLip -> setPos(0, _lowPosOfLowerLip);
        if(_lowPosOfLowerLip == 0 && _upPosOfUpperLip == 0) timerLips -> stop();
    }
}

void Face::startMovingLips()
{
    _startAndEndPosOfLowerLip = 0;
    _startAndEndPosOfUpperLip = 0;
    _upPosOfUpperLip = 20;
    _lowPosOfLowerLip = -20;
    timerLips -> start(1000/90);
}
