#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *w) : QMainWindow(w), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  h = new TreeHeap();
}

MainWindow::~MainWindow() { }

void MainWindow::on_pushBtn_clicked() { //
  h->push(ui->inpBox->value());
  refresh();
}
void MainWindow::on_initBtn_clicked() {
  for (int i = 0; i < 256; ++i) {
    h->push(std::rand() % 300);
  }
  refresh();
}

void MainWindow::refresh() {
  h->inspect(ui->tree);
  ui->maxLbl->setText(QString::number(h->max()));
}

void MainWindow::on_popBtn_clicked() {
    h->pop();
    refresh();
}
