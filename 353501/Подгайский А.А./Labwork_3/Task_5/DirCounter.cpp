#include "DirCounter.h"
#include <QDir>
#include <QFileInfo>


long DirCounter::CountElements(const QString& dirPath) {
    {
        QFileInfo inf{dirPath};
        if(!inf.isDir()){
          return 1;
        }
    }

    QDir dir(dirPath);
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    long amount = 0;
    qDebug() << dir.entryList();
    foreach(auto path, dir.entryList()){
        amount += CountElements(dir.filePath(path));
    }

    return amount;
}
