#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openDirectoryDialog);
}

void MainWindow::openDirectoryDialog()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!directoryPath.isEmpty())
    {
        unsigned long long foldersCount = countFoldersRecursively(directoryPath);
        unsigned long long filesCount = countFilesRecursively(directoryPath);

        ui->lineFolders->setText(QString::number(foldersCount));
        ui->lineFiles->setText(QString::number(filesCount));
    }
}

unsigned long long MainWindow::countFoldersRecursively(const QString& directoryPath)
{
    unsigned long long foldersCount = 0;
    QDir directory(directoryPath);
    QFileInfoList entries = directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    for (const QFileInfo& entry : entries)
    {
        foldersCount++;
        foldersCount += countFoldersRecursively(entry.filePath());
    }

    return foldersCount;
}

unsigned long long MainWindow::countFilesRecursively(const QString& directoryPath)
{
    unsigned long long filesCount = 0;
    QDir directory(directoryPath);
    QFileInfoList entries = directory.entryInfoList(QDir::Files | QDir::NoSymLinks);
    filesCount += entries.size();

    for (const QFileInfo& entry : directory.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks))
    {
        filesCount += countFilesRecursively(entry.filePath());
    }

    return filesCount;
}

MainWindow::~MainWindow()
{
    delete ui;
}
