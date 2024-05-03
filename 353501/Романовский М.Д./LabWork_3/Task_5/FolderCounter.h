#pragma once

#include <QString>

struct CountResults {
  int folders;
  int files;
  int errors;
};

class FolderCounter {
public:
  static CountResults CountFoldersAndFile(QString path);
};