#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked()

{
  QString selectedDirectory = QFileDialog::getExistingDirectory(
      this, "Выберите папку", QDir::homePath());

  QFile file(selectedDirectory);

  ui->label_2->setText(selectedDirectory);

  ui->label_4->setText(
      QString::number(solution->getNumberFoldersAndFiles(selectedDirectory)));

  ui->label_5->setText(
      QString::number(solution->getNumberFolders(selectedDirectory)));
}
