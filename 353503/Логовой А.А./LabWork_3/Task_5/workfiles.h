#ifndef WORKFILES_H
#define WORKFILES_H
#include <QString>
#include <QFileDialog>

void countFilesAndFolders(const QString& path, int& fileCount, int& folderCount, QStringList& dirList, QStringList& fileList);

#endif // WORKFILES_H
