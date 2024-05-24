#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <QString>
#include <QDir>

class FileCounter
{
public:
    FileCounter();
    int countFolders(const QString &directory);
    int countFiles(const QString &directory);
private:
    int countFoldersHelper(const QDir &dir);
    int countFilesHelper(const QDir &dir);
};

#endif // FILECOUNTER_H
