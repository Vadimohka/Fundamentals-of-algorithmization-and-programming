#include "dirchecker.h"

int DirChecker::fileCnt() const
{
    return fileCnt_;
}

int DirChecker::dirCnt() const
{
    return dirCnt_;
}

void DirChecker::changeDirectory(QString path)
{
    path_ = path;
    dirCnt_ = 0;
    fileCnt_ = 0;
    dirPlan_.clear();
    _checkFolder(path_, dirCnt_, fileCnt_, 0);
}

QString DirChecker::directory() const
{
    return path_;
}

QString DirChecker::dirPlan() const
{
    return dirPlan_;
}

void DirChecker::_checkFolder(QString path, int &dirCnt, int &fileCnt, int nesting)
{
    fileVector_.clear();
    QDir dir(path);
    if (!dir.exists()) { return; }

    QString tab(nesting * TAB_SIZE, ' ');
    dirPlan_.append(tab);
    if (nesting != 0) { dirPlan_ += "|- "; }
    dirPlan_ += "Dir: " + dir.dirName() + QString('\n');

    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList dirList = dir.entryInfoList();
    for (const auto & dirElement : dirList)
    {
        if (dirElement.isFile())
        {
            ++fileCnt;
            tab = QString((nesting + 1) * TAB_SIZE, ' ');
            dirPlan_.append(tab);
            dirPlan_ += "|- ";
            dirPlan_ += "File: " + dirElement.fileName() + QString('\n');
            fileVector_.push_back(dirElement);
        }
        else if (dirElement.isDir())
        {
            ++dirCnt_;
            _checkFolder(dirElement.absoluteFilePath(), dirCnt, fileCnt, nesting + 1);
        }
    }
}

DirChecker::DirChecker(QString path)
    : path_(path)
{
    dirPlan_.clear();
    _checkFolder(path_, dirCnt_, fileCnt_, 0);
}
