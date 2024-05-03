#include "mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->filesCount->setText(QString::number(countFiles));
    ui->foldersCount->setText(QString::number(countFolders));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFolder_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "Select Directory");
    if (!dirPath.isEmpty()) {
        countFiles = 0;
        countFolders = 0;
        ui->textBrowser->clear();
        QString folderName = QDir(dirPath).dirName();
        ui->textBrowser->append("Current Directory: " + folderName);
        printDirectoryTree(dirPath, countFiles, countFolders, " ");
    }
}
void MainWindow::printDirectoryTree(const QString &dirPath,
                                    int &countFiles,
                                    int &countFolders,
                                    const QString &indent)
{
    QDir dir(dirPath);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    foreach (QFileInfo fileInfo, list) {
        if (fileInfo.isDir()) {
            countFolders++;
            ui->textBrowser->append(indent + "| - " + fileInfo.fileName());
            printDirectoryTree(fileInfo.absoluteFilePath(), countFiles, countFolders, indent + "  ");
        } else if (fileInfo.isFile()) {
            countFiles++;
            ui->textBrowser->append(indent + "| - " + fileInfo.fileName());
        }
    }

    ui->foldersCount->setText(QString::number(countFolders));
    ui->filesCount->setText(QString::number(countFiles));
}

void MainWindow::on_closeButton_clicked()
{
    QCoreApplication::quit();
}
