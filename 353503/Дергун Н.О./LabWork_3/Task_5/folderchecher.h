#ifndef FOLDERCHECHER_H
#define FOLDERCHECHER_H

#include <QDesktopServices>
#include <QDir>
#include <QObject>

class FolderChecher
{
    QString path_;
    int fileCnt_;
    int dirCnt_;

public:
    FolderChecher(QString, parent);
};

#endif // FOLDERCHECHER_H
