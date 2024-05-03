#ifndef SOLUTION_H
#define SOLUTION_H
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <utility>

class Solution
{
public:
    Solution();
    int getNumberFoldersAndFiles(QString strPath, int n = 0);
    int getNumberFolders(QString strPath, int n = 0);
private:
    QStringList nameFilter;
    int numberFileTxtExtensionOnDirectory(QString strPath);
    QFileInfoList getInfoListAboutFolder(QString strPath);
};

#endif // SOLUTION_H
