#include "element.h"

Element::Element()
{
    _xEulerRotation = 45;
    _yEulerRotation = 45;
    _zEulerRotation = 45;
    _color = "green";
}

Element::Element(qreal initXRotation, qreal initYRotation, qreal initZRotation, QString initColor)
{
    _xEulerRotation = initXRotation;
    _yEulerRotation = initYRotation;
    _zEulerRotation = initZRotation;
    _color = initColor;
}

void Element::rotateAlong(char inaxis, bool clockwise)
{
    normalzeAngles();
    if (rotationsAre("gul1") || rotationsAre("gul2")) {
        _setRotationAngles("gul1");
        _slowChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gur1") || rotationsAre("gur2")) {
        _setRotationAngles("gur1");
        _slowChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gdr1") || rotationsAre("gdr2")) {
        _setRotationAngles("gdr1");
        _slowChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gdl1") || rotationsAre("gdl2")) {
        _setRotationAngles("gdl1");
        _slowChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("yul1") || rotationsAre("yul2") || rotationsAre("yul3") || rotationsAre("yul4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("yul1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("yul2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("yur1") || rotationsAre("yur2") || rotationsAre("yur3") || rotationsAre("yur4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("yur1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("yur2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("ydl1") || rotationsAre("ydl2") || rotationsAre("ydl3") || rotationsAre("ydl4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("ydl1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("ydl2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("ydr1") || rotationsAre("ydr2") || rotationsAre("ydr3") || rotationsAre("ydr4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("ydr1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("ydr2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("bur1") || rotationsAre("bur2")) {
        _setRotationAngles("bur1");
        _slowChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bul1") || rotationsAre("bul2")) {
        _setRotationAngles("bul1");
        _slowChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bur1") || rotationsAre("bur2")) {
        _setRotationAngles("bur1");
        _slowChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bdr1") || rotationsAre("bdr2")) {
        _setRotationAngles("bdr1");
        _slowChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bdl1") || rotationsAre("bdl2")) {
        _setRotationAngles("bdl1");
        _slowChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("wul1") || rotationsAre("wul2") || rotationsAre("wul3") || rotationsAre("wul4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wul1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wul2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wur1") || rotationsAre("wur2") || rotationsAre("wur3") || rotationsAre("wur4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wur1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wur2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wdl1") || rotationsAre("wdl2") || rotationsAre("wdl3") || rotationsAre("wdl4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wdl1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wdl2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wdr1") || rotationsAre("wdr2") || rotationsAre("wdr3") || rotationsAre("wdr4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wdr1");
            _slowChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wdr2");
            _slowChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("rur1") || rotationsAre("rur2")) {
        _setRotationAngles("rur1");
        if (inaxis == 'x') _slowChange('z', clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rul1") || rotationsAre("rul2")) {
        _setRotationAngles("rul1");
        if (inaxis == 'x') _slowChange('z', clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rdr1") || rotationsAre("rdr2")) {
        _setRotationAngles("rdr1");
        if (inaxis == 'x') _slowChange('z', clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rdl1") || rotationsAre("rdl2")) {
        _setRotationAngles("rdl1");
        if (inaxis == 'x') _slowChange('z', clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', !clockwise);
        return;
    }

    if (rotationsAre("our1") || rotationsAre("our2")) {
        _setRotationAngles("our1");
        if (inaxis == 'x') _slowChange('z', !clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', clockwise);
        return;
    }

    if (rotationsAre("oul1") || rotationsAre("oul2")) {
        _setRotationAngles("oul1");
        if (inaxis == 'x') _slowChange('z', !clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', clockwise);
        return;
    }

    if (rotationsAre("odl1") || rotationsAre("odl2")) {
        _setRotationAngles("odl1");
        if (inaxis == 'x') _slowChange('z', !clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', clockwise);
        return;
    }

    if (rotationsAre("odr1") || rotationsAre("odr2")) {
        _setRotationAngles("odr1");
        if (inaxis == 'x') _slowChange('z', !clockwise);
        else if (inaxis == 'y') _slowChange('y', !clockwise);
        else _slowChange('x', clockwise);
        return;
    }
}

void Element::normalzeAngles()
{
    if (_xEulerRotation >= 360) _xEulerRotation -= 360;
    if (_yEulerRotation >= 360) _yEulerRotation -= 360;
    if (_zEulerRotation >= 360) _zEulerRotation -= 360;
    if (_xEulerRotation < 0) _xEulerRotation += 360;
    if (_yEulerRotation < 0) _yEulerRotation += 360;
    if (_zEulerRotation < 0) _zEulerRotation += 360;
}

void Element::finalizeRotation()
{
    switch (axis) {
    case 'x':
        _xEulerRotation = targetAngle;
        break;
    case 'y':
        _yEulerRotation = targetAngle;
        break;
    case 'z':
        _zEulerRotation = targetAngle;
        break;
    default:
        return;
        break;
    }
}

void Element::_slowChange(char inaxis, bool clockwise)
{
    normalzeAngles();
    axis = inaxis;
    calculateTargetAngle(clockwise);
    animationTimer = new QTimer();
    endTimer = new QTimer();
    QObject::connect(animationTimer, &QTimer::timeout, [=] {
        updateRotation(clockwise);
    });
    QObject::connect(endTimer, &QTimer::timeout, [&] {
        finalizeRotation();
        animationTimer->stop();
        endTimer->stop();
        delete animationTimer;
        delete endTimer;
        normalzeAngles();
    });
    animationTimer->start(25);
    endTimer->start(animationDuration - 50);
}

bool Element::rotationsAre(QString key)
{
    return _xEulerRotation == possRotations[key][0] &&
           _yEulerRotation == possRotations[key][1] &&
           _zEulerRotation == possRotations[key][2];
}

void Element::_setRotationAngles(QString key)
{
    _xEulerRotation = possRotations[key][0];
    _yEulerRotation = possRotations[key][1];
    _zEulerRotation = possRotations[key][2];
}

void Element::_momentalChange(char inaxis, bool clockwise)
{
    normalzeAngles();
    axis = inaxis;
    calculateTargetAngle(clockwise);
    finalizeRotation();
}

void Element::calculateTargetAngle(bool clockwise)
{
    switch (axis) {
    case 'x':
        targetAngle = _xEulerRotation + ((clockwise ? 1 : -1) * 90);
        break;
    case 'y':
        targetAngle = _yEulerRotation + ((clockwise ? 1 : -1) * 90);
        break;
    case 'z':
        targetAngle = _zEulerRotation + ((clockwise ? 1 : -1) * 90);
        break;
    default:
        return;
        break;
    }
}

void Element::updateRotation(bool clockwise)
{
    switch (axis) {
    case 'x':
        _xEulerRotation += ((clockwise ? 1 : -1) * 90) / (animationDuration / 25);
        break;
    case 'y':
        _yEulerRotation += ((clockwise ? 1 : -1) * 90) / (animationDuration / 25);
        break;
    case 'z':
        _zEulerRotation += ((clockwise ? 1 : -1) * 90) / (animationDuration / 25);
        break;
    }
}

qreal Element::zRotation() const
{
    return _zEulerRotation;
}

void Element::momentalRotate(char inaxis, bool clockwise)
{
    normalzeAngles();
    if (rotationsAre("gul1") || rotationsAre("gul2")) {
        _setRotationAngles("gul1");
        _momentalChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gur1") || rotationsAre("gur2")) {
        _setRotationAngles("gur1");
        _momentalChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gdr1") || rotationsAre("gdr2")) {
        _setRotationAngles("gdr1");
        _momentalChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("gdl1") || rotationsAre("gdl2")) {
        _setRotationAngles("gdl1");
        _momentalChange(inaxis, !clockwise);
        return;
    }

    if (rotationsAre("yul1") || rotationsAre("yul2") || rotationsAre("yul3") || rotationsAre("yul4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("yul1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("yul2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("yur1") || rotationsAre("yur2") || rotationsAre("yur3") || rotationsAre("yur4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("yur1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("yur2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("ydl1") || rotationsAre("ydl2") || rotationsAre("ydl3") || rotationsAre("ydl4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("ydl1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("ydl2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("ydr1") || rotationsAre("ydr2") || rotationsAre("ydr3") || rotationsAre("ydr4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("ydr1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("ydr2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("bur1") || rotationsAre("bur2")) {
        _setRotationAngles("bur1");
        _momentalChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bul1") || rotationsAre("bul2")) {
        _setRotationAngles("bul1");
        _momentalChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bur1") || rotationsAre("bur2")) {
        _setRotationAngles("bur1");
        _momentalChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bdr1") || rotationsAre("bdr2")) {
        _setRotationAngles("bdr1");
        _momentalChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("bdl1") || rotationsAre("bdl2")) {
        _setRotationAngles("bdl1");
        _momentalChange(inaxis, (inaxis == 'y' ? !clockwise : clockwise));
        return;
    }

    if (rotationsAre("wul1") || rotationsAre("wul2") || rotationsAre("wul3") || rotationsAre("wul4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wul1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wul2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wur1") || rotationsAre("wur2") || rotationsAre("wur3") || rotationsAre("wur4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wur1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wur2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wdl1") || rotationsAre("wdl2") || rotationsAre("wdl3") || rotationsAre("wdl4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wdl1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wdl2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("wdr1") || rotationsAre("wdr2") || rotationsAre("wdr3") || rotationsAre("wdr4")) {
        if (inaxis == 'x' || inaxis == 'y') {
            _setRotationAngles("wdr1");
            _momentalChange(inaxis, !clockwise);
        }
        else {
            _setRotationAngles("wdr2");
            _momentalChange('x', clockwise);
        }
        return;
    }

    if (rotationsAre("rur1") || rotationsAre("rur2")) {
        _setRotationAngles("rur1");
        if (inaxis == 'x') _momentalChange('z', clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rul1") || rotationsAre("rul2")) {
        _setRotationAngles("rul1");
        if (inaxis == 'x') _momentalChange('z', clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rdr1") || rotationsAre("rdr2")) {
        _setRotationAngles("rdr1");
        if (inaxis == 'x') _momentalChange('z', clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', !clockwise);
        return;
    }

    if (rotationsAre("rdl1") || rotationsAre("rdl2")) {
        _setRotationAngles("rdl1");
        if (inaxis == 'x') _momentalChange('z', clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', !clockwise);
        return;
    }

    if (rotationsAre("our1") || rotationsAre("our2")) {
        _setRotationAngles("our1");
        if (inaxis == 'x') _momentalChange('z', !clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', clockwise);
        return;
    }

    if (rotationsAre("oul1") || rotationsAre("oul2")) {
        _setRotationAngles("oul1");
        if (inaxis == 'x') _momentalChange('z', !clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', clockwise);
        return;
    }

    if (rotationsAre("odl1") || rotationsAre("odl2")) {
        _setRotationAngles("odl1");
        if (inaxis == 'x') _momentalChange('z', !clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', clockwise);
        return;
    }

    if (rotationsAre("odr1") || rotationsAre("odr2")) {
        _setRotationAngles("odr1");
        if (inaxis == 'x') _momentalChange('z', !clockwise);
        else if (inaxis == 'y') _momentalChange('y', !clockwise);
        else _momentalChange('x', clockwise);
        return;
    }
}

qreal Element::yRotation() const
{
    return _yEulerRotation;
}

qreal Element::xRotation() const
{
    return _xEulerRotation;
}
