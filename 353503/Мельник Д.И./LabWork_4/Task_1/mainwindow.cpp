#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _ui(new Ui::MainWindow),
      _scene(new QGraphicsScene(this)),
      _visual(new Visual()) {
  _ui->setupUi(this);
  connect(_visual, &Visual::updatedScene, this, &MainWindow::updateScene);
}

MainWindow::~MainWindow() {
  delete _ui;
}

void MainWindow::on_lineEdit_2_textChanged(const QString& arg1) {
  bool isCorrectARG = false;
  arg1.toInt(&isCorrectARG);
  _scene->clear();

  if (isCorrectARG and arg1.toInt() < 2000 and arg1.toInt() > 0) {
    qDebug() << "before create Item";
    _visual->createItem(arg1.toInt());
    qDebug() << "after create Item";

    auto items = _visual->GetItems();
    for (const auto& item : items) {
      _scene->addItem(item);
    }
    _ui->graphicsView->setScene(_scene);
  }
}

void MainWindow::on_lineEdit_textChanged(const QString& arg1) {
  bool isIntARG = false;
  arg1.toInt(&isIntARG);
  if (isIntARG and arg1.toInt() > -1) {
    _visual->setSpeed(arg1.toInt());
  }
}

void MainWindow::on_pushButton_clicked() {
  if (isQuick) {
    _visual->quickSortStart();
    qDebug() << "Quick start";
  } else if (isHeap) {
    _visual->heapSortStart();
    qDebug() << "Heap start";
  } else if (isMerge) {
    _visual->mergeSortStart();
    qDebug() << "Merge start";
  }
}

void MainWindow::on_radioButton_2_toggled(bool checked) {
  isHeap = checked;
  qDebug() << "isHeap: [" << isHeap << "]";
}

void MainWindow::on_radioButton_toggled(bool checked) {
  isQuick = checked;
  qDebug() << "isQuick: [" << isQuick << "]";
}

void MainWindow::on_radioButton_3_toggled(bool checked) {
  isMerge = checked;
  qDebug() << "isMerge: [" << isMerge << "]";
}

void MainWindow::updateScene() {
  _scene->update();
  qDebug() << "Emit";
}
