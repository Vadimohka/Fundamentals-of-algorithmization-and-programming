#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDir>
#include <QFileInfoList>
#include <QDesktopServices>

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

void MainWindow::on_pushButton_clicked()
{
    QString pathToFile = QFileDialog::getExistingDirectory(nullptr, "Выберите папку", QString(), QFileDialog::DontResolveSymlinks);
    int dirCount = 0, fileCount = 0;

    countFilesAndDirs(pathToFile, fileCount, dirCount);

    ui->selectedPath->setText(pathToFile);
    ui->countDir->setText(QString::number(dirCount));
    ui->countFile->setText(QString::number(fileCount));
}

void MainWindow::countFilesAndDirs(const QString &path, int &fileCount, int &dirCount) {
    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    foreach (QFileInfo fileInfo, list) {
        if (fileInfo.isDir())
        {
            dirCount++;
            countFilesAndDirs(fileInfo.absoluteFilePath(), fileCount, dirCount);
        }

        else if (fileInfo.isFile())
        {
            fileCount++;
        }
    }
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "//home/artem_kokhan/QT/3lab", "Files (*.*)");

    if (fileName.isEmpty())
    {
        return;
    }

    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}

