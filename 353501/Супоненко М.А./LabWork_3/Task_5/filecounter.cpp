#include "filecounter.h"

FileCounter::FileCounter() {}

int FileCounter::countFolders(const QString &directory) {
    QDir dir(directory);
    return countFoldersHelper(dir);
}

int FileCounter::countFiles(const QString &directory) {
    QDir dir(directory);
    return countFilesHelper(dir);
}

int FileCounter::countFoldersHelper(const QDir &dir) {
    int folderCount = 0;
    for (const QFileInfo &info : dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        folderCount++;
        folderCount += countFoldersHelper(QDir(info.absoluteFilePath()));
    }
    return folderCount;
}

int FileCounter::countFilesHelper(const QDir &dir) {
    int fileCount = dir.entryList(QDir::Files).size();
    for (const QFileInfo &info : dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        fileCount += countFilesHelper(QDir(info.absoluteFilePath()));
    }
    return fileCount;
}
