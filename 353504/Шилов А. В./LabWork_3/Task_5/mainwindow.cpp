#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow), _directoryIter(new DiretoryIterator())
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::on_pushButton_clicked()
{
    int fileCount = 0, dirCount = 0;
    _path = QFileDialog::getExistingDirectory(this, "Выберите нужную директорию", "/home/dmitry/3LabDirTest");
    qDebug() << _path;
    if (_path.isEmpty()){
        qDebug() << "path is empty";
    }
    else{
        _directoryIter->countFilesAndDirs(_path.toStdString(), fileCount, dirCount);
    }
    qDebug() << "file count: " << fileCount;
    qDebug() << "dir count: " << dirCount;
    _ui->label_2->setText(QString::number(fileCount));
    _ui->textBrowser->setText(_directoryIter->getAllDirPath());
    _ui->label_4->setText(QString::number(dirCount));
    _ui->textBrowser_2->setText(_directoryIter->getAllFileName());
}

