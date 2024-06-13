#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openDirButton, &QPushButton::clicked, this, &MainWindow::openDir);
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::openFile);
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

long long MainWindow::countFiles(QString path)
{
    long long filesCount = 0;

    QDir directory(path);
    directory.setFilter(QDir::Files | QDir::AllDirs | QDir::Hidden);

    QFileInfoList allItems = directory.entryInfoList();

    foreach(QFileInfo item, allItems)
    {
        if(item.fileName() != "." && item.fileName() != "..")
        {
            if(item.isDir())
            {
                filesCount += countFiles(item.absoluteFilePath());
            }
            else
            {
                filesCount++;
            }
        }
    }
    return filesCount;
}

void MainWindow::openDir()
{
    _filePath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Выберите папку"), "/home/masha", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!_filePath.isEmpty())
    {
        ui -> subfoldersLabel -> setText(QString::number(countSubfolders(_filePath)));
        ui -> filesLabel -> setText(QString::number(countFiles(_filePath)));
    }
}
void MainWindow::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "/home/masha", "Text Files (*.txt)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось открыть файл"));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}
