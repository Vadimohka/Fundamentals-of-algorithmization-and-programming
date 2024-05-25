//
// Created by zgdarya on 4/27/24.
//

#include "NumberOfFiles.h"

FilesAndDirecories NumberOfFiles::calculateNumberOfFiles(QString path) {
    QDir directory(path);
    FilesAndDirecories number = {0, 0};

    QFileInfoList files =
            directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);

    for (int i = 0; i < files.size(); ++i) {
        if (files[i].isSymLink() || files[i].isSymbolicLink()) {
            continue;
        }
        else if (files[i].isFile()) {
            ++number.numberOfFiles;
        }
        else {
            try {
                ++number.numberOfDirectories;
                FilesAndDirecories temp = calculateNumberOfFiles(files[i].filePath());
                number.numberOfFiles += temp.numberOfFiles;
                number.numberOfDirectories += temp.numberOfDirectories;
            }
            catch (...) {}
        }
    }

    return number;
}
