
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    folderCount = 0;
    fileCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    ui->folderCount->clear();
    ui->fileCount->clear();
    folderCount = 0; // Обнуляем folderCount перед новым подсчетом
    fileCount = 0;   // Обнуляем fileCount перед новым подсчетом
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Select Folder"), QDir::homePath());
    if (!folderPath.isEmpty()) {
        countFoldersAndFiles(folderPath);
        ui->folderCount->setText("Total Folders: " + QString::number(folderCount));
        ui->fileCount->setText("Total Files: " + QString::number(fileCount));
    }
}

void MainWindow::countFoldersAndFiles(const QString& path)
{
    QDir directory(path);
    if (!directory.exists())
        return;

    QFileInfoList list = directory.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    foreach (QFileInfo fileInfo, list) {
        if (fileInfo.isDir()) {
            folderCount++;
            countFoldersAndFiles(fileInfo.absoluteFilePath());
        } else if (fileInfo.isFile()) {
            fileCount++;
        }
    }
}
