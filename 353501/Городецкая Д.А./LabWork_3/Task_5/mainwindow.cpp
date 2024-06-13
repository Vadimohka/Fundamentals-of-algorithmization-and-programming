#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QFileInfoList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_openButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку", QDir::homePath());

    if (!folderPath.isEmpty()) {
        int subfolderCount = 0;
        int fileCount = 0;

        countItems(folderPath, subfolderCount, fileCount);

        QMessageBox::information(this, "Статистика", QString("Количество подпапок: %1\nКоличество файлов: %2")
                                                         .arg(subfolderCount).arg(fileCount));
    } else {
        QMessageBox::warning(this, "Предупреждение", "Папка не выбрана");
    }
}

void MainWindow::countItems(const QString &folderPath, int &subfolderCount, int &fileCount)
{
    QDir dir(folderPath);
    if (!dir.exists()) {
        QMessageBox::critical(this, "Ошибка", "Выбранная папка не существует");
        return;
    }

    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : fileInfoList) {
        if (fileInfo.isDir()) {
            subfolderCount++;
            countItems(fileInfo.absoluteFilePath(), subfolderCount, fileCount);
        } else if (fileInfo.isFile()) {
            fileCount++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
