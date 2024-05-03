#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qplaintextedit.h>
#include <qtextedit.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->inpA, &QPlainTextEdit::textChanged, this,
          &MainWindow::updateOuts);
  connect(ui->inpB, &QPlainTextEdit::textChanged, this,
          &MainWindow::updateOuts);

  ui->inpA->setPlainText("Hello world");
  ui->inpB->setPlainText("Test test teste");
  updateOuts();
}

void MainWindow::updateOuts() {
  String a(ui->inpA->toPlainText().toStdString().c_str());
  String b(ui->inpB->toPlainText().toStdString().c_str());

  ui->outA->setText(generateData(a, b));
  ui->outB->setText(generateData(b, a));
}

QString MainWindow::generateData(String cur, String another) {
  String tokenized = "";
  for(auto t: cur.tokenize(" .,!")) {
    tokenized = tokenized + t + "; ";
  }

  return QString(R"ff(
    <table>
    <tr><td>Contents:</td><td>%0</td></tr>
    <tr><td>Len:</td><td>%1</td></tr>
    <tr><td>Slice [2, 6] :</td><td align="right">%2</td></tr>
    <tr><td>Concat:</td><td align="right">%3</td></tr>
    <tr><td>Compare:</td><td align="right">%4</td></tr>
    <tr><td>Tokens:</td><td align="right">%5</td></tr>
    </table>
  )ff")
      .arg(cur.c_str())
      .arg(cur.len())
      .arg(cur.slice(1, 4).c_str())
      .arg((cur + another).c_str())
      .arg(cur.cmp(another))
      .arg(tokenized.c_str());
}