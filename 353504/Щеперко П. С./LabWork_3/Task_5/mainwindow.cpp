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

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Choose a folder", QDir::homePath());
    ui->numOfSubfoldersLabel->setText(QString::number(Files::CountSubfolders(path)));
    ui->numOfFilesLabel->setText(QString::number(Files::CountFiles(path)));
}

