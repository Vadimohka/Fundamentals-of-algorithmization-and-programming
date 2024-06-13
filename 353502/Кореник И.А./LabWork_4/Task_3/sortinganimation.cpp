#include "sortinganimation.h"
#include <QThread>
#include <QCoreApplication>
SortingAnimation::SortingAnimation() {}

void SortingAnimation::drawNumber(QHBoxLayout* arrAnimation, int i)
{
    arrAnimation->addWidget(new NumberVisual(i));
    QCoreApplication::processEvents();
    QThread::msleep(40);
}

void SortingAnimation::swappNumbers(QHBoxLayout* arrAnimation, QVector<int> *arr, int i, int j)
{

    qobject_cast<NumberVisual*>(arrAnimation->itemAt(i)->widget())->setHight((arr->at(j)));
    qobject_cast<NumberVisual*>(arrAnimation->itemAt(j)->widget())->setHight(arr->at(i));

    QCoreApplication::processEvents();
    QThread::msleep(005);

}

void SortingAnimation::changeValue(QHBoxLayout *arrAnimation, QVector<int> *arr, int i, int value)
{
    if (arrAnimation != nullptr){
        qobject_cast<NumberVisual*>(arrAnimation->itemAt(i)->widget())->setHight(value);

        QCoreApplication::processEvents();
        QThread::msleep(005);
    }
}
