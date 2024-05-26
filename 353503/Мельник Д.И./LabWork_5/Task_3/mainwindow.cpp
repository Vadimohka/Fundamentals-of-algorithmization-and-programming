#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qspinbox.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  for (int i = 0; i < 300; i++) {
    bits[i] = (i % 3 == 0) || (i % 5 == 0);
  }

  connect(ui->setBtn, &QPushButton::clicked, [&]() {
    bits.set(getPos());
    update();
  });

  connect(ui->flipBtn, &QPushButton::clicked, [&]() {
    bits.flip(getPos());
    update();
  });

  connect(ui->resetBtn, &QPushButton::clicked, [&]() {
    bits.reset(getPos());
    update();
  });

  connect(ui->setAllBtn, &QPushButton::clicked, [&]() {
    bits.set();
    update();
  });

  connect(ui->flipAllBtn, &QPushButton::clicked, [&]() {
    bits.flip();
    update();
  });

  connect(ui->resetAllBtn, &QPushButton::clicked, [&]() {
    bits.reset();
    update();
  });

  update();
  connect(ui->posInp, &QSpinBox::valueChanged, this, &MainWindow::update);
}

void MainWindow::update() {
  std::string bits_str = bits.to_string();
  QString bitsout = "";
  for (int i = 0; i < 300; i++) {
    bitsout += bits_str[i];
    if (i % 64 == 63)
      bitsout += "\n";
  }
  ui->bitsetout->setText(bitsout);

  QString infoOut = QString(R"ff(
    <table>
    <tr><td>Size:</td><td>%0</td></tr>
    <tr><td>Count:</td><td>%1</td></tr>
    <tr><td>In position:</td><td>%2</td></tr>
    <tr><td>All:</td><td align="right">%3</td></tr>
    <tr><td>None:</td><td align="right">%4</td></tr>
    <tr><td>Any:</td><td align="right">%5</td></tr>
    </table>
  )ff")
                        .arg(bits.size())
                        .arg(bits.count())
                        .arg(bits[getPos()])
                        .arg(bits.all() ? "Yes" : "No")
                        .arg(bits.none() ? "Yes" : "No")
                        .arg(bits.any() ? "Yes" : "No");

  ui->infoout->setText(infoOut);
}

size_t MainWindow::getPos() { return ui->posInp->value(); }
