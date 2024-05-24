#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new FoldersView(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory"));

    if (dir == NULL)
    {
        return;
    }

    DirCounter::FoldersCount(dir);
    ui->label_files->setText(QString::number(DirCounter::GetFiles()));
    ui->label_folders->setText(QString::number(DirCounter::GetFolders()));

    model->setRootPath(dir);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(dir));
    ui->treeView->setHeaderHidden(true);
    ui->treeView->setColumnWidth(0, 400);
}

