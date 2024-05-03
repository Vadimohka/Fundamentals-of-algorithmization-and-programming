#include "mainwindow.h"
#include "ToBin.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <qlineedit.h>
#include <qlogging.h>
#include <qspinbox.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::onUpdate);
  // onUpdate(ui->lineEdit->value());
}

void MainWindow::onUpdate(QString val) {
  std::string s = val.toStdString();
  const char *start = s.c_str();
  char *end;
  errno = 0;
  long double res = strtold(start, &end);
  if (*end != '\0' || errno != 0)
    ui->output->setText("Invalid number");
  else
    ui->output->setText(ToBin::ConvertToBit(res));
}