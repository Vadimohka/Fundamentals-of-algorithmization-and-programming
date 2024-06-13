#include "mainwindow.h"
#include "./ui_mainwindow.h"

//I am booored
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
    QString path = QFileDialog::getExistingDirectory(this);

    ui->textEdit->setPlainText(QString::number(FileCounter::fileCount(path.toStdString())));
}

