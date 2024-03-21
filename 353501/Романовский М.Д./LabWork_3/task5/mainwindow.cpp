#include "mainwindow.h"
#include "FolderCounter.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFuture>
#include <QSharedPointer>
#include <QtCompare>
#include <QtConcurrent>
#include <qfuturewatcher.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onOpen);

  connect(&waiter, &QFutureWatcher<CountResults>::finished, this,
          &MainWindow::onFinished);
}

void MainWindow::onOpen() {
  QString dir = QFileDialog::getExistingDirectory(
      this, tr("Open Directory"), "",
      QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  ui->label->setText("Loading...");
  ui->pushButton->setDisabled(true);

  waiter.setFuture(QtConcurrent::run([dir]() -> CountResults {
    return FolderCounter::CountFoldersAndFile(dir);
  }));
}

void MainWindow::onFinished() {
  CountResults res = waiter.result();
  ui->label->setText(QString("Folders: %0\nFiles: %1\nErrors:%2")
                         .arg(res.folders)
                         .arg(res.files)
                         .arg(res.errors));
  ui->pushButton->setDisabled(false);
}