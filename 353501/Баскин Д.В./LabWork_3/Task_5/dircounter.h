#ifndef DIRCOUNTER_H
#define DIRCOUNTER_H

#include <QDir>

class DirCounter
{
public:
    static void FoldersCount(QString);

    static void Reset();
    static int GetFolders();
    static int GetFiles();
private:
    static int Folders;
    static int Files;
};

#endif // DIRCOUNTER_H
