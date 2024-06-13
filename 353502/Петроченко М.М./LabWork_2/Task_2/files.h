//
// Created by acryoz on 9.3.24.
//

#ifndef UNTITLED5_FILES_H
#define UNTITLED5_FILES_H
#include <QFile>
#include <QMap>
#include <QString>
#include "Party.h"
#include "Candidate.h"
#include <QTextStream>
#include <QDebug>


QMap<QString, Party>* readFile(QFile*);

void writeFile(QFile*, QMap<QString, Party>*);


#endif //UNTITLED5_FILES_H
