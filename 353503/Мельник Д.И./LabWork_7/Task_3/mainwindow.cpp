#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <climits>
#include <qmessagebox.h>
#include <stdexcept>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->keyBox->setRange(INT_MIN, INT_MAX);
  ui->amountBox->setRange(4, 32768);
}

void MainWindow::refresh() {
  hashtable.setUpTreeWidget(ui->tree);
  ui->sizeLbl->setText(QString::number(hashtable.size()));
}
void MainWindow::on_insertBtn_clicked() {
  auto key = ui->keyBox->value();
  auto txt = ui->textEdit->text();
  hashtable.insert(key, txt);

  refresh();
}
void MainWindow::on_removeBtn_clicked() {
  const auto key = ui->keyBox->value();
  if (hashtable.remove(key)) {
    refresh();
  } else {
    QMessageBox::warning(this, "Warning", "No item with given key found");
  }
}
void MainWindow::on_searchBtn_clicked() {
  const auto key = ui->keyBox->value();

  try {
    auto el = hashtable.get(key);
    ui->textEdit->setText(el);
  } catch (const std::runtime_error &ex) {
    QMessageBox::warning(this, "Warning", "No item with given key found");
  }
}
void MainWindow::on_randomBtn_clicked() {
  hashtable.initRandom(ui->amountBox->value());
  refresh();
}

void MainWindow::on_minKeyBtn_clicked() {
  if (hashtable.size() == 0) {
    QMessageBox::information(this, "Minimal key", "No elements in hash table");
  } else {
    auto pair = hashtable.findMinKey();
    QMessageBox::information(this, "Minimal key",
                             QString("Bucket: %1\nKey: %2\nValue: %3")
                                 .arg(pair.first)
                                 .arg(pair.second)
                                 .arg(hashtable.get(pair.second)));
  }
}
