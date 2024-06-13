#include "task5.h"

Task5::Task5(QObject *parent)
{
    dialog.setWindowTitle("Дерево папок");

    scrollArea = new QScrollArea(&dialog);
    scrollContent = new QWidget;
    scrollLayout = new QVBoxLayout(scrollContent);
}

int Task5::countFoldersAndFiles(const QString& path, int& numFolders, int& numFiles) {
    QDir dir(path);
    if (!dir.exists()) {
        return -1;
    }

    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        if (fileInfo.isDir()) {
            numFolders++;
            countFoldersAndFiles(fileInfo.filePath(), numFolders, numFiles); // Recurse into subdirectory
        } else if (fileInfo.isFile()) {
            numFiles++;
        }
    }

    return 0;
}

void Task5::startDialog()
{
    // Получение пути к выбранной папке
    pathFile = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", "/", QFileDialog::ShowDirsOnly);
    if (pathFile.isEmpty())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Неверный путь");
        return;
    }

    // Переменные для хранения количества папок и файлов
    int numFolders = 0;
    int numFiles = 0;

    // Вызов функции для подсчета папок и файлов
    if (countFoldersAndFiles(pathFile, numFolders, numFiles) == 0) {
        // Создание текстового отчета с результатами
        QString report = "Количество папок: " + QString::number(numFolders) +
                         "\nКоличество файлов: " + QString::number(numFiles);

        // Создание диалогового окна для отображения результатов
        QMessageBox::information(nullptr, "Результат", report);
    } else {
        QMessageBox::warning(nullptr, "Ошибка", "Ошибка подсчета папок и файлов.");
    }
}
