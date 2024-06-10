#include "mainwindow.h"
#include <QDesktopServices>
#include <QDir>
#include <QFileInfoList>
#include <QListWidget>
#include <QPushButton>
#include "QFileDialog"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton, &QPushButton::pressed, this,
          &MainWindow::pre_countFiles);
  connect(ui->pushButton_2, &QPushButton::pressed, this,
          &MainWindow::OpenDirectory);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::openSelectedFile);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::pre_countFiles() {
  int folderC = 0, fileC = 0;
  countFoldersAndFiles(openedFolderPath, folderC, fileC, ui->listWidget);
  ui->label_2->setText(QString::number(folderC));
  ui->label_3->setText(QString::number(fileC));
}

void MainWindow::countFoldersAndFiles(const QString& path, int& folderCount,
                                      int& fileCount, QListWidget* listWidget,
                                      int64_t level) {
  QDir dir(path);
  QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllDirs |
                                         QDir::Files | QDir::Hidden);

  foreach (QFileInfo fileInfo, list) {
    QString indent(level * 3, ' ');
    QListWidgetItem* item = nullptr;
    if (fileInfo.isDir()) {
      folderCount++;
      item = new QListWidgetItem(indent + fileInfo.fileName());
      item->setData(Qt::UserRole, fileInfo.absoluteFilePath());
      listWidget->addItem(item);
      countFoldersAndFiles(fileInfo.absoluteFilePath(), folderCount, fileCount,
                           listWidget, level + 1);
    } else if (fileInfo.isFile()) {
      fileCount++;
      item = new QListWidgetItem(indent + fileInfo.fileName());
      item->setData(Qt::UserRole, fileInfo.absoluteFilePath());
      listWidget->addItem(item);
    }
  }
}

void MainWindow::openSelectedFile() {
  QListWidgetItem* item = ui->listWidget->currentItem();
  if (item) {
    QString filePath = item->data(Qt::UserRole).toString();
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
  }
}

void MainWindow::OpenDirectory() {
  openedFolderPath = QFileDialog::getExistingDirectory(
      nullptr, "Выберите папку", QDir::homePath());
  if (!openedFolderPath.isEmpty()) {
    ui->label->setText("Выбраная директория: " + openedFolderPath);
  } else {
    qDebug() << "Директория не выбрана не выбрана.";
  }
}
