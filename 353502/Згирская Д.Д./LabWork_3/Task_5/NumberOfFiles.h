//
// Created by zgdarya on 4/27/24.
//

#ifndef LAB3_TASK5_NUMBEROFFILES_H
#define LAB3_TASK5_NUMBEROFFILES_H

#include <QString>
#include <QDir>

struct FilesAndDirecories {
    int numberOfFiles;
    int numberOfDirectories;
};

class NumberOfFiles {
public:
    static FilesAndDirecories calculateNumberOfFiles(QString path);
};


#endif //LAB3_TASK5_NUMBEROFFILES_H
