#include "diretoryiterator.h"

#include <QDebug>

DiretoryIterator::DiretoryIterator() = default;

void DiretoryIterator::countFilesAndDirs(const std::filesystem::path& path, int& fileCount, int& dirCount)
{
    if (!std::filesystem::exists(path)) {
        qDebug() << "Путь не существует.\n";
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(entry.path())) {
            dirCount++;
            /* рекурсивный вызов для подкаталога */
            countFilesAndDirs(entry.path(), fileCount, dirCount);
            _allDirPath += QString::fromStdString(entry.path()) + '\n';  // Перемещено сюда
        }
        else if (std::filesystem::is_regular_file(entry.path())) {
            if (!entry.path().extension().empty()){
                qDebug() << QString::fromStdString(entry.path());
                _allFileName += QString::fromStdString(entry.path()) + '\n';
            }
            fileCount++;
        }
    }
}

QString DiretoryIterator::getAllDirPath() { return _allDirPath; }

QString DiretoryIterator::getAllFileName() { return _allFileName; }
