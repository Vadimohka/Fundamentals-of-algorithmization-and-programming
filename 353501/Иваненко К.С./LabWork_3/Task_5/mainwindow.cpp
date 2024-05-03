#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QStandardItemModel>
#include "FileSystemModel.h"
#include <QFileDialog>

MainWindow::MainWindow(): ui(new Ui::MainWindow), timer(new QTimer(this)) {
  fileCount = folderCount = 0;
  ui->setupUi(this);
  timer->start(500);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::calculate); 


}

MainWindow::~MainWindow() { 
  
}

void MainWindow::calculate() {
  QString path = QFileDialog::getExistingDirectory(this, tr("Выберите папку"), QDir::homePath());

  FileSystemModel *model = new FileSystemModel();
  model->setRootPath(path);
  ui->treeView->setModel(model);
  ui->treeView->setRootIndex(model->index(path));
  qDebug() << model->index(path);
  ui->label_4->setText(QString::number(model->countNestedFolders(path)));
  ui->label_5->setText(QString::number(model->countNestedFiles(path)));
}

