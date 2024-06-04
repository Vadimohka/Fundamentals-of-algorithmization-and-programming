#include "diretoryiterator.h"

#include <QDebug>
#include <QDir>

DiretoryIterator::DiretoryIterator() = default;

void DiretoryIterator::countFilesAndDirs(const QString& path, int& fileCount, int& dirCount)
{
    QDir dir(path);

    if (!dir.exists()) {
        qDebug() << "Путь не существует.\n";
        return;
    }
\
    /* Учитываем скрытые файлы и папки, а также символические ссылки */
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);

    QFileInfoList entries = dir.entryInfoList();

    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            ++dirCount;
            /* Рекурсивный вызов для подкаталога */
            countFilesAndDirs(entry.filePath(), fileCount, dirCount);
            _allDirPath += entry.filePath() + '\n';
        }
        else if (entry.isFile()) {
            if (!entry.suffix().isEmpty()) {
                qDebug() << entry.filePath();
                _allFileName += entry.filePath() + '\n';
            }
            ++fileCount;
        }
    }
}

QString DiretoryIterator::getAllDirPath() { return _allDirPath; }

QString DiretoryIterator::getAllFileName() { return _allFileName; }
