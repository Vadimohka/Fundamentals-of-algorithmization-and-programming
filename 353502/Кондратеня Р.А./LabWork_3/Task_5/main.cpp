#include <QApplication>
#include <QDir>
#include <QMessageBox>

void countFoldersAndFiles(const QString& folderPath, int& folderCount, int& fileCount) {
    QDir dir(folderPath);

    if (!dir.exists()) {
        return;
    }

    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList fileList = dir.entryInfoList();

    for (const QFileInfo& fileInfo : fileList) {
        if (fileInfo.isDir()) {
            ++folderCount;
            countFoldersAndFiles(fileInfo.filePath(), folderCount, fileCount);
        } else if (fileInfo.isFile()) {
            ++fileCount;
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString mainFolder = "/home/kbadpat/OAiP/Lab3";
    int folderCount = 0;
    int fileCount = 0;

    countFoldersAndFiles(mainFolder, folderCount, fileCount);

    QMessageBox::information(nullptr, "Результат",
                             "Количество подпапок: " + QString::number(folderCount) +
                             "\nОбщее количество файлов: " + QString::number(fileCount));

    return app.exec();
}
