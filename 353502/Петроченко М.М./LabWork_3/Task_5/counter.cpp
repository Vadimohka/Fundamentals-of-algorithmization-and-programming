//
// Created by acryoz on 08.06.24.
//

#include "counter.h"

Res count(QString path) {
    QDir dir(path);
    Res result = { 0, 0, 0 };
    QFileInfoList files =
        dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (auto& entry : files) {
        if (entry.isSymLink() || entry.isSymbolicLink()) {
            continue;
        }
        if (entry.isFile()) {
            ++result.files;
        } else {
            try {
                ++result.folders;
                Res subdirectory_result = count(entry.filePath());
                result.files += subdirectory_result.files;
                result.folders += subdirectory_result.folders;
                result.errors += subdirectory_result.errors;
            } catch (...) {
                ++result.errors;
            }
        }
    }
    return result;
}