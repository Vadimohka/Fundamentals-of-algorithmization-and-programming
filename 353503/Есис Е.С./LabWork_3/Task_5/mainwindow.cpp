#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
    void MainWindow::countFoldersAndFiles(const QString& path, int& folderCount, int& fileCount)
    {
        QDir dir(path);
        dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden | QDir::NoSymLinks);

        QFileInfoList fileList = dir.entryInfoList();
        foreach (const QFileInfo& fileInfo, fileList) {
            if (fileInfo.isDir()) {
                folderCount++;
                countFoldersAndFiles(fileInfo.filePath(), folderCount, fileCount);
            } else {
                fileCount++;
            }
        }
    }


void MainWindow::on_OpenButton_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку", QDir::homePath());

    if (!folderPath.isEmpty()) {
        int folderCount = 0;
        int fileCount = 0;
        countFoldersAndFiles(folderPath, folderCount, fileCount);
        ui->filesCount->setText(QString::number(fileCount));
        ui->foldersCount->setText(QString::number(folderCount));
    } else {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }
}
