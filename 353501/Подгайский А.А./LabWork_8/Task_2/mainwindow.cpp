#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *w) : QMainWindow(w), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  tree = new PriorityTree<long>();
}

void MainWindow::on_pushBtn_clicked() { //
  tree->push(ui->inpBox->value());
  refresh();
}
void MainWindow::on_initBtn_clicked() {
  for (int i = 0; i < 256; ++i) {
    tree->push(std::rand());
  }
  refresh();
}

MainWindow::~MainWindow() { delete tree; }

void MainWindow::refresh() {
  tree->inspect(ui->tree);
  ui->maxLbl->setText(QString::number(tree->max()));
}

void MainWindow::on_popBtn_clicked() {
  if (tree->size() != 0) {
    tree->pop();
    refresh();
  }
  
}