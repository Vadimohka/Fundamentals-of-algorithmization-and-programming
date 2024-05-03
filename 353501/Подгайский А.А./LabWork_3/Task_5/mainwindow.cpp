#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileSystemModel>
#include <QtConcurrent>
#include "DirCounter.h"


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->openDirBtn, &QPushButton::clicked,
  this, &MainWindow::openDir);

  connect(ui->countFilesBtn, &QPushButton::clicked,
  this, &MainWindow::countElements);

  connect(&watcher, &QFutureWatcher<long>::finished,
         this, &MainWindow::setNumberOfElements);
}

void MainWindow::openDir(){
  auto dirPath = QFileDialog::getExistingDirectory(this, "Open Directory");
  if(!dirPath.isEmpty()){
    if(model){
      model->deleteLater(); model = nullptr;
    }

    model = new FileSystemModel(ui->tableView);
    model->setRootPath(dirPath);
    ui->tableView->setModel(model);
    ui->tableView->setRootIndex(model->index(dirPath));
  }
}

void MainWindow::countElements(){
  auto ind = ui->tableView->currentIndex();
  auto path = model->filePath(ind);
  if(QFileInfo inf(path); !inf.isDir()){
    ui->numOfElements->setText("Not a directory");
  } else {
    watcher.setFuture(QtConcurrent::run(DirCounter::CountElements, path));
   ui->numOfElements->setText("Counting...");
  }
}

void MainWindow::setNumberOfElements(){
  ui->numOfElements->setText(QString::number(watcher.result()));
}


