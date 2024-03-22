#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Reverser.h"
#include "LongValidator.h"
#include <climits>
#include <qlineedit.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->inputLine->setValidator(new LongValidator());
  connect(ui->inputLine, &QLineEdit::textChanged,
          this, &MainWindow::setReversedValue);
}

void MainWindow::setReversedValue() {
  bool ok;
  long inp = ui->inputLine->text().toLong(&ok);
  long res = Reverser::reverse(inp);
  if (ok) {
    ui->resultLabel->setText(QString::number(res));
  } else {
    ui->resultLabel->setText("");
  }
}
