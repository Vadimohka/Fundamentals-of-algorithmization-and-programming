#include "files.h"

int Files::CountFiles(const QString &path)
{
    int numOfSubfolders = 0;

    QDirIterator it(path, QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        numOfSubfolders++;
    }
    return numOfSubfolders;
}

int Files::CountSubfolders(const QString &path)
{
    int numOfFiles = 0;

    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        numOfFiles++;
    }
    return numOfFiles;
}
