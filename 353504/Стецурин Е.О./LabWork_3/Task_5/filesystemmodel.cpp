#include "filesystemmodel.h"

FileSystemModel::FileSystemModel(QObject* parent) : QFileSystemModel(parent) {

}

int FileSystemModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant FileSystemModel::data(const QModelIndex& ind, int role) const {
    if (role == Qt::DecorationRole) {
        return {};
    } else {
        return QFileSystemModel::data(ind, role);
    }
}

int FileSystemModel::countNestedFolders(const QString& path) {
    QDir dir(path);
    int folderCount = 0;

    QStringList entries = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (const QString& entry : entries) {
        QString subPath = dir.filePath(entry);
        folderCount++;
        folderCount += countNestedFolders(subPath);
    }

    return folderCount;
}

int FileSystemModel::countNestedFiles(const QString& path) {
    QDir dir(path);
    int fileCount = 0;

    if (dir.exists()) {
        QFileInfoList entries = dir.entryInfoList(QDir::Files, QDir::Name);
        fileCount += entries.size();

        QFileInfoList subdirectories = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
        for (const QFileInfo& subdir : subdirectories) {
            fileCount += countNestedFiles(subdir.absoluteFilePath());
        }
    }

    return fileCount;
}
