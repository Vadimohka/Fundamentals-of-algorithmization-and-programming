#include "mainwindow.h"
#include "Map.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <climits>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qnumeric.h>
#include <qstringliteral.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  bstgui = new MapInspector;

  ui->keyBox->setRange(INT_MIN, INT_MAX);
  ui->textEdit->setMaxLength(20);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_initBtn_clicked() {
  bstgui->initRandomly();
  bstgui->setUpTreeWidget(ui->tree);
}

void MainWindow::on_insertBtn_clicked() {
  auto key = ui->keyBox->value();
  auto txt = ui->textEdit->text();
  bstgui->insert(key, txt);

  bstgui->setUpTreeWidget(ui->tree);
}

void MainWindow::on_removeBtn_clicked() {
  auto key = ui->keyBox->value();
  if (bstgui->remove(key)) {
    bstgui->setUpTreeWidget(ui->tree);
  } else {
    QMessageBox::warning(this, "Warning",
                         "No item was removed with given key.");
  }
}

void MainWindow::on_findBtn_clicked() {
  auto key = ui->keyBox->value();

  if (bstgui->contains(key)) {
    ui->textEdit->setText(bstgui->get(key));
  } else {
    QMessageBox::warning(this, "Warning", "No item was found with given key.");
  }
}
