#include "mainwindow.h"
#include "ui_mainwindow.h"

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

long long MainWindow::countSubfolders(QString path)
{
    long long foldersCount = 0;

    QDir directory(path);
    QFileInfoList allItems = directory.entryInfoList();

    foreach(QFileInfo item, allItems)
    {
        if(item.isDir() && item.fileName() != "." && item.fileName() != "..")
        {
            foldersCount += (1 + countSubfolders(item.filePath()));
        }
    }

    return foldersCount;
}

long long MainWindow::countFiles(QString path, QString pref)
{
    long long filesCount = 0;

    QDir directory(path);
    directory.setFilter(QDir::Files | QDir::AllDirs | QDir::Hidden);

    QFileInfoList allItems = directory.entryInfoList();

    foreach(QFileInfo item, allItems)
    {
        if(item.fileName() != "." && item.fileName() != "..")
        {
            ui -> textEdit -> append(pref + item.fileName());
            if(item.isDir())
            {
                filesCount += countFiles(item.absoluteFilePath(), "    " + pref);
            }
            else
            {
                filesCount++;
            }
        }
    }

    return filesCount;
}

void MainWindow::on_openFileButton_clicked()
{
    _filePath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Выберите папку"), "/home/bahmatok", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!_filePath.isEmpty())
    {
        ui -> subfoldersLineEdit -> setText(QString::number(countSubfolders(_filePath)));
        ui -> filesLineEdit -> setText(QString::number(countFiles(_filePath, "|- ")));
    }
}

