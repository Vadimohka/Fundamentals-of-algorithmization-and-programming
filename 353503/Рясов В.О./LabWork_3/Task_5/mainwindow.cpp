#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    int fileCount = 0;
    int dirCount = 0;
    QString dirName = QFileDialog::getExistingDirectory();
    _directCheck.countFilesAndDirs(dirName, fileCount, dirCount, ui);
    ui->textEdit->append("Число директорий: " + (QString::number(dirCount)));
    ui->textEdit->append("Число файлов: " + (QString::number(fileCount)));
}

