#ifndef READTEXTFROMFILE_H
#define READTEXTFROMFILE_H
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QDebug>
#include <QVector>
class ReadTextFromFile
{
public:
    ReadTextFromFile();
    QDate date;
   ReadTextFromFile(const QString &strDate) {
        date = QDate::fromString(strDate, "dd/MM/yyyy");
    }
};

#endif // READTEXTFROMFILE_H
