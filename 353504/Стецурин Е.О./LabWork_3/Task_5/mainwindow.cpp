#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QStandardItemModel>
#include "filesystemmodel.h"
#include <QFileDialog>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    fileCount = 0;
    folderCount = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Выберите папку"), QDir::homePath());

    FileSystemModel *model = new FileSystemModel();
    model->setRootPath(path);
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(path));
    ui->label_4->setText(QString::number(model->countNestedFolders(path)));
    ui->label_5->setText(QString::number(model->countNestedFiles(path)));
}

