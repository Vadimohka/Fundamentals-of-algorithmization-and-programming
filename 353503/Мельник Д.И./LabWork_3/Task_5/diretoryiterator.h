#ifndef DIRETORYITERATOR_H
#define DIRETORYITERATOR_H

#include "filesystem"

#include <QString>

class DiretoryIterator
{
private:
    QString _allDirPath = "";
    QString _allFileName = "";
public:
    DiretoryIterator();

    void countFilesAndDirs(const QString& path, int& fileCount, int& dirCount);

    QString getAllDirPath();
    QString getAllFileName();
};

#endif // DIRETORYITERATOR_H
