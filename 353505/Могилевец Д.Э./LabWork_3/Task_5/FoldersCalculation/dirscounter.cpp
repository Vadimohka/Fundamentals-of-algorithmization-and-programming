#include "dirscounter.h"

DirsCounter::DirsCounter() {}

void DirsCounter::Count(QString path, long long &directoriesAmount, long long &filesAmount)
{
    QDir directory(path);
    if (!directory.exists()) {
        qDebug() << "Directory does not exist!";
        return;
    }
    QStringList folderNames;
    directory.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &info : directory.entryInfoList()) {
        folderNames.append(info.fileName());
        directoriesAmount++;
    }
    directory.setFilter(QDir::Files);
    filesAmount += directory.entryList().count();
    for (auto suffix : folderNames) {
        Count(path + '/' + suffix, directoriesAmount, filesAmount);
    }
}
