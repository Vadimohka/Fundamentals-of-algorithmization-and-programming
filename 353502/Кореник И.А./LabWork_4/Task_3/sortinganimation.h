#ifndef SORTINGANIMATION_H
#define SORTINGANIMATION_H

#include <QVector>
#include <QHBoxLayout>
#include <QListView>
#include "numbervisual.h"
#include <QTimer>
class SortingAnimation
{
public:
    SortingAnimation();

    static void drawNumber(QHBoxLayout*, int);

    static void swappNumbers(QHBoxLayout*, QVector<int>*, int, int);

    static void changeValue(QHBoxLayout*, QVector<int>*, int, int);

};

#endif // SORTINGANIMATION_H
