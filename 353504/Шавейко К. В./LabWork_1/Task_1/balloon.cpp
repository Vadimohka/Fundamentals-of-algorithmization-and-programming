#include "balloon.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

balloon::balloon(QObject *parent) : movingellipse() {

    QRect rect(0, 0, 200, 200);
    QBrush(Qt::red);

}


