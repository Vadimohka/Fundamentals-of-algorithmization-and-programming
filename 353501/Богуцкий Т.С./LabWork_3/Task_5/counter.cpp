#include "counter.h"

long long  Counter::filesCount;
long long  Counter::dirCount;

void Counter::count(QString path)
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
            filesCount++;
        }
        else if(element.isDir())
        {
            dirCount++;
            count(element.filePath());
        }
    }
}

long long Counter::getF()
{
    return filesCount;
}

long long Counter::getD()
{
    return dirCount;
}

void Counter::toZero()
{
    dirCount = 0;
    filesCount = 0;
}
