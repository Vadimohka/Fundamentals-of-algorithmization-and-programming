//
// Created by darina on 4/12/24.
//

#include "Calculate.h"
#include <QDebug>


int Calculate::CountDirectories(QString path) {
    int count = 0;
    QDir current_directory;
    current_directory.setPath(path);
    auto list = current_directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(auto dir : list)
    {
        count ++;
        count += CountDirectories(path+'/'+dir);
    }
    return count;
}

int Calculate::CountFiles(QString path) {
    int count = 0;
    QDir current_directory;
    current_directory.setPath(path);
    auto list = current_directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(auto dir : list)
    {
        count += CountFiles(path+'/'+dir);
    }
    list = current_directory.entryList(QDir::Files);
    for(auto file : list)
    {
        count ++;
    }
    return count;
}
