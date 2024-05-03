#ifndef ACKERMANNFUNCTION_H
#define ACKERMANNFUNCTION_H

#include <QtCore>

const uint MAX_MB = 1;
const uint MB_CAPACITY = 43690;
const uint MAX_FUNC_NUM = 9990;
const uint MIN_FUNC_NUM = 10;

class AckermannFunction
{
    QMap<QPair<quint32, quint32>, quint128> rememberedValues;

    uint maxRinningFunc_ = MAX_FUNC_NUM;
    uint runCntr_ = 0;
    bool isOverflowed_ = false;

    void _rememberValue(const QPair<quint32, quint32> pair, const quint128 value);

public:
    qint64 Evaluate(quint32 m, quint32 n);
    uint maxRinningFunc() const;
    void setMaxRinningFunc(uint newMaxRinningFunc);
};

#endif // ACKERMANNFUNCTION_H
