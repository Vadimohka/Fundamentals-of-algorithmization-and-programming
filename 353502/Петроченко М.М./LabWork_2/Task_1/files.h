//
// Created by acryoz on 6.3.24.
//

#ifndef UNTITLED5_FILES_H
#define UNTITLED5_FILES_H
#include <QFile>
#include <QTextStream>
#include "Date.h"


QVector<Date>* readDates(QFile*);
void writeDates(QFile*, QVector<Date>*);

#endif //UNTITLED5_FILES_H
