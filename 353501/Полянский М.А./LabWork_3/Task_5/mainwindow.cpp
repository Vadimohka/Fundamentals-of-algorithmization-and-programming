#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  fold = new FoldersView(this);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButton);
}

void MainWindow::onPushButton(){
  QString dir = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/", QFileDialog::ShowDirsOnly);

  if(dir.isEmpty()){
    return;
  }
  
  Counter::CounterAll(dir);
  ui->files->setText(QString::number(Counter::GetFiles()));
  ui->dir->setText(QString::number(Counter::GetFolders()));
  fold->setRootPath(dir);
  ui->treeView->setModel(fold);
  ui->treeView->setRootIndex(fold->index(dir));
  ui->treeView->setHeaderHidden(true);
  ui->treeView->setColumnWidth(0, 500);
}
