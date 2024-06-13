#include<workfiles.h>
#include <QDir>

void countFilesAndFolders(const QString& path, int& fileCount, int& folderCount, QStringList& dirList, QStringList& fileList) {
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "No found Directory: " << path;
        return;
    }

    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList entries = dir.entryInfoList();
    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            folderCount++;
            dirList.append(entry.absoluteFilePath());
            countFilesAndFolders(entry.absoluteFilePath(), fileCount, folderCount, dirList, fileList);
        } else if (entry.isFile()) {
            fileCount++;
            fileList.append(entry.absoluteFilePath());
        }
    }
}
