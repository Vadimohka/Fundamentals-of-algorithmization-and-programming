#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <vector>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include "date.h"
#include "convertibleinstance.h"

class FileService
{
public:
    FileService();
    std::vector<Date> ReadQFileDialogForDatesByLines(QWidget* parentWindow);
    void WriteInQFileDialogDatesByLines(QWidget* parentWindow, std::vector<Date> toWrite);
};

#endif // FILESERVICE_H
