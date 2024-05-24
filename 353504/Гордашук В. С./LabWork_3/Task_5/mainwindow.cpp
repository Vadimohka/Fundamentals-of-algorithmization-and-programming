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

void MainWindow::on_open_clicked()
{
    counter = new FileCounter;
    path = QFileDialog::getExistingDirectory();
    counter->countFilesAndDirs(path);
    ui->label->setText("Количество файлов и папок: " + QString::number(counter->num));
}
