#include "FolderCounter.h"
#include <QDir>
#include <qdir.h>

CountResults FolderCounter::CountFoldersAndFile(QString path) {
  QDir d(path);
  CountResults res = {0, 0, 0};
  QFileInfoList files =
      d.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

  for (auto &entry : files) {
    if (entry.isSymLink() || entry.isSymbolicLink())
      continue;

    if (entry.isFile()) {
      res.files++;
    } else {
      try {
        res.folders++;
        CountResults subdir = CountFoldersAndFile(entry.filePath());
        res.folders += subdir.folders;
        res.files += subdir.files;
        res.errors += subdir.errors;
      } catch (...) {
        res.errors++;
      }
    }
  }

  return res;
};