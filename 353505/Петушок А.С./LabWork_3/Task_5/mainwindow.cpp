#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


long long  MainWindow::Count_Folder(QString dirPath) {
    long long count_folder = 0;
    QDir directory(dirPath);
    QFileInfoList d = directory.entryInfoList();
    foreach(QFileInfo item, d) {
        if(item.isDir() && item.fileName() != "." && item.fileName() != "..") {
            count_folder += (1 + Count_Folder(item.filePath()));
        }
    }

    return count_folder;
}

long long  MainWindow::Count_File(QString dirPath) {
    long long count_file = 0;
    QDir directory(dirPath);
    QFileInfoList d = directory.entryInfoList();
    foreach(QFileInfo item, d) {
        if(item.isDir() && item.fileName() != "." && item.fileName() != "..") {
            count_file += (1 + Count_File(item.filePath()));
        }
    }

    return count_file;
}

void MainWindow::on_pushButton_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("Select folder"), "/Users/daryastasiuk/Documents/BSUIR", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dirPath.isEmpty())
    {
        ui->line_folder->setText(QString::number(Count_Folder(dirPath)));
        ui->line_file->setText(QString::number(Count_File(dirPath)));
    }
}

