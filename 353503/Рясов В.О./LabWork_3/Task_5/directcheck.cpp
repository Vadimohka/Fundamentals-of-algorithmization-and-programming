#include "directcheck.h"
#include <QDir>
#include <QFileDialog>

DirectCheck::DirectCheck() {}

void DirectCheck::countFilesAndDirs(const QString &path, int &fileCount, int &dirCount, Ui::MainWindow *ui)
{
    QDir dir(path);
    QDir::Filters filters = QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs | QDir::Hidden;
    QFileInfoList list = dir.entryInfoList(filters);

    for (const QFileInfo &fileInfo : list) {
        if (fileInfo.isDir()) {
            dirCount++;
            ui->textEdit->append(QString("Найдена папка: %1").arg(fileInfo.absoluteFilePath()));
            countFilesAndDirs(fileInfo.absoluteFilePath(), fileCount, dirCount, ui);
        } else if (fileInfo.isFile()) {
            //if (fileInfo.suffix() == "txt") {
                fileCount++;
                ui->textEdit->append(QString("Найден текстовый файл: %1").arg(fileInfo.absoluteFilePath()));
            //}
        }
    }
}
