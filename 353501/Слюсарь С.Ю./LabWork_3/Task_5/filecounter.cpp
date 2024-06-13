#include "filecounter.h"

FileCounter::FileCounter() {}

void FileCounter::countFilesAndDirs(const QString &path)
{
    QDir *dir = new QDir(path);
    QFileInfoList list = dir->entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    qDebug() << &dir;
    num += list.length();
    qDebug() << &list[0];
    qDebug() << int((int*)&dir - (int*)&list[0]);
    qDebug() << list[0].fileName();
    qDebug() << &list[1];


    foreach (QFileInfo fileInfo, list)
    {
        if (fileInfo.isDir())
        {
            countFilesAndDirs(fileInfo.absoluteFilePath());
        }
    }
}
