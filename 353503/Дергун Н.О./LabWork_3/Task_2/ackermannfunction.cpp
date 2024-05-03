#include "ackermannfunction.h"


uint AckermannFunction::maxRinningFunc() const
{
    return maxRinningFunc_;
}

void AckermannFunction::setMaxRinningFunc(uint newMaxRinningFunc)
{
    if (newMaxRinningFunc > MIN_FUNC_NUM && newMaxRinningFunc < MAX_FUNC_NUM) { maxRinningFunc_ = newMaxRinningFunc; };
}

void AckermannFunction::_rememberValue(const QPair<quint32, quint32> pair, const quint128 value)
{
    if (rememberedValues.size() < MB_CAPACITY * MAX_MB)
    {
        rememberedValues.insert(pair, value);
    }
}

qint64 AckermannFunction::Evaluate(quint32 m,  quint32 n)
{
    if ((m == static_cast<quint32>(4) && n != static_cast<quint32>(0))
        || m > static_cast<quint32>(4))
    {
        return -2;
    }

    QPair<quint32, quint32> pair(m, n);
    if (rememberedValues.contains(pair)) { return rememberedValues[pair]; }
    if (runCntr_ > maxRinningFunc_) { isOverflowed_ = true; }
    if (isOverflowed_) { return -1; }

    ++runCntr_;
    quint128 resultValue = 0;
    if (m == 0)
    {
        resultValue = n + 1;
    }
    else if (m > 0 && n == 0)
    {
        resultValue = Evaluate(m - 1, 1);
    }
    else
    {
        // int tempArg = n - 1, tempValue = n - 1;
        resultValue = Evaluate(m - 1, Evaluate(m, n - 1));
    }

    _rememberValue(pair, resultValue);

    --runCntr_;
    if (runCntr_ == 0) { isOverflowed_ = false; };
    return resultValue;
}
