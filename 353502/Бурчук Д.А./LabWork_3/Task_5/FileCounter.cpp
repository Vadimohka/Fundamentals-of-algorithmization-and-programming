#include "FileCounter.h"

std::pair<int, int> FileCounter::countFiles(QString path) {
    QDir dir(path);
    std::pair<int, int> countOfFiles = {0, 0};
    QFileInfoList files =
            dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (auto &entry: files) {
        if (entry.isSymLink() || entry.isSymbolicLink()) { continue; }
        else if (entry.isFile()) { countOfFiles.first++; }
        else {
            try {
                countOfFiles.second++;
                std::pair<int, int> temp = countFiles(entry.filePath());
                countOfFiles.first += temp.first;
                countOfFiles.second += temp.second;
            }
            catch (...) {}
        }
    }
    return countOfFiles;
}