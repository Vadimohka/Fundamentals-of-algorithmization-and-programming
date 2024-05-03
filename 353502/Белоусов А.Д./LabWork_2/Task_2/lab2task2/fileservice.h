#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <type_traits>
#include "convertibleinstance.h"

class FileService
{
public:
    FileService();
    void GetDataFromTheQFileDialog(QWidget* parent, ConvertibleInstance& instance);
    void SaveDataIntoTheQFileDialog(QWidget* parent, ConvertibleInstance& instance);
};

#endif // FILESERVICE_H
