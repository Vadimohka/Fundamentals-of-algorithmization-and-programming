#ifndef FILES_H
#define FILES_H

#include <QString>
#include <QDirIterator>

class Files
{
public:
    static int CountFiles(const QString &path);
    static int CountSubfolders(const QString &path);
};

#endif // FILES_H
