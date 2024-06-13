#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, tr("Open Folder"), QDir::homePath());
    if (!folderPath.isEmpty()) {
        displayFoldersAndFiles(folderPath);
    }
}

void MainWindow::countFoldersAndFiles(const QString &folderPath, int &folderCount, int &fileCount)
{
    QDir dir(folderPath);

    QFileInfoList fileInfoList = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo &fileInfo : fileInfoList) {
        if (fileInfo.isDir()) {
            folderCount++;
            countFoldersAndFiles(fileInfo.filePath(), folderCount, fileCount);
        } else {
            fileCount++;
        }
    }
}

void MainWindow::displayFoldersAndFiles(const QString &folderPath)
{
    int folderCount = 0;
    int fileCount = 0;
    countFoldersAndFiles(folderPath, folderCount, fileCount);

    ui->label_2->setText(QString("Folders: %1").arg(folderCount));
    ui->label_4->setText(QString("Files: %1").arg(fileCount));

    QMessageBox::information(this, tr("Folder Information"), tr("Folder analysis complete!"));
}
