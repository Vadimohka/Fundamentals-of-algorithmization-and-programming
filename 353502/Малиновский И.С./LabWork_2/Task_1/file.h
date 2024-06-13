#ifndef FILE_H
#define FILE_H

#include <QDebug>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "date.h"

class File
{
public:
    File() = default;
    void convertFromFile(QWidget* parent, QVector <Date> &dates);
    void convertToFile(QWidget* parent, QVector <Date> &dates);
private:
};

#endif // FILE_H
