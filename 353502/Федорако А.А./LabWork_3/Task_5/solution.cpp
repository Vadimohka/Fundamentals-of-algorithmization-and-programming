#include "solution.h"
#include <QDebug>

Solution::Solution() {
  nameFilter << "*.txt";
}

int Solution::getNumberFoldersAndFiles(QString strPath, int result) {

  QDir dirPath(strPath);

  bool folderExists = QDir(strPath).exists();

  if (folderExists == true) {

    result += numberFileTxtExtensionOnDirectory(strPath);
    QFileInfoList folderList = getInfoListAboutFolder(strPath);
    QFileInfo fileInfo;
    foreach (fileInfo, folderList) {
      QString folderPath = fileInfo.filePath();
      qDebug() << strPath << ' ' << fileInfo.filePath() << ' ' << '\n';
      result += getNumberFoldersAndFiles(folderPath, result) - result;
    }
    return result;
  } else {
    return 0;
  }
}

int Solution::getNumberFolders(QString strPath, int result) {

  QDir dirPath(strPath);

  bool folderExists = QDir(strPath).exists();

  if (folderExists == true) {
    QFileInfoList folderList = getInfoListAboutFolder(strPath);
    QFileInfo fileInfo;
    foreach (fileInfo, folderList) {
      QString folderPath = fileInfo.filePath();
      result += getNumberFolders(folderPath);
      result++;
    }

    return result;
  } else {
    return 0;
  }
}

int Solution::numberFileTxtExtensionOnDirectory(QString strPath) {
  QDir dir(strPath);

  QFileInfoList list = dir.entryInfoList(nameFilter, QDir::Files);
  QFileInfo fileinfo;
  int result = 0;
  foreach (fileinfo, list) {
    result++;
  }
  return result;
}

QFileInfoList Solution::getInfoListAboutFolder(QString strPath) {
  QDir dir(strPath);

  QFileInfoList folderList =
      dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
  QFileInfo fileinfo;
  return folderList;
}
