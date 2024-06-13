#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <QString>
#include <QFileInfo>
#include <QDir>

class FileCounter
{
public:
    FileCounter();
    void countFilesAndDirs(const QString &path);
    int num = 0;

};

#endif // FILECOUNTER_H
