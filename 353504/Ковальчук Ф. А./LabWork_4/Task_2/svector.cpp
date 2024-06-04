#include "svector.h"

void SVector::emitSignal(int index, int value)
{
    Vector<int>::operator[](index) = value;

    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents);
    }

    emit valueChange(index);
}
