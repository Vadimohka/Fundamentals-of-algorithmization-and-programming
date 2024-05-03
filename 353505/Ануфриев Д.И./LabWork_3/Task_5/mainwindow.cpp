#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

unsigned long long MainWindow::countFolders(QString directoryPath)
{
    unsigned long long foldersCount = 0;

    QDir directory(directoryPath);

    QFileInfoList allItems = directory.entryInfoList();

    foreach(QFileInfo item, allItems)
    {
        if(item.isDir() && item.fileName() != "." && item.fileName() != "..")
        {
            foldersCount += (1 + countFolders(item.filePath()));
        }
    }

    return foldersCount;
}

unsigned long long MainWindow::countFiles(QString directoryPath)
{
    unsigned long long filesCount = 0;

    QDir directory(directoryPath);

    QFileInfoList allItems = directory.entryInfoList();

    foreach(QFileInfo item, allItems)
    {
        if(item.fileName() != "." && item.fileName() != "..")
        {
            filesCount += (1 + countFiles(item.filePath()));
        }
    }

    return filesCount;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Выберите папку"), "/home/deviyan", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!directoryPath.isEmpty())
    {
        ui->lineFolders->setText(QString::number(countFolders(directoryPath)));
        ui->lineFiles->setText(QString::number(countFiles(directoryPath)));
    }
}

