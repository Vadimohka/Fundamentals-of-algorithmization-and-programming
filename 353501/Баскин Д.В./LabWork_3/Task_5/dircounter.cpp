#include "dircounter.h"

int DirCounter::Folders;
int DirCounter::Files;

void DirCounter::FoldersCount(QString path)
{
    QDir directory(path);
    QFileInfoList files = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    for (auto &element : files)
    {
        if (element.isSymLink() || element.isSymbolicLink())
        {
            continue;
        }

        if (element.isFile())
        {
            ++Files;
        }
        else
        {
            ++Folders;
            FoldersCount(element.filePath());
        }
    }
}

int DirCounter::GetFolders()
{
    return Folders;
}

int DirCounter::GetFiles()
{
    return Files;
}

void DirCounter::Reset()
{
    Folders = 0;
    Files = 0;
}
