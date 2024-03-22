#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdint>
#include <QPushButton>
#include "Ackerman.h"
#include <QtConcurrent>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->mValue->setMaximum(15);
  ui->evaluationLabel->setUpdatesEnabled(true);

  // connect(ui->mValue, &QSpinBox::valueChanged,
  // this, &MainWindow::calculate);
  // connect(ui->nValue, &QSpinBox::valueChanged,
  // this, &MainWindow::calculate);
  connect(ui->calculateBtn, &QPushButton::clicked,
  this, &MainWindow::calculate);

  connect(&watcher, &QFutureWatcher< std::optional<uint32_t> >::finished,
  this, &MainWindow::changeValue);
}

void MainWindow::calculate() {
  //ui->result->setText("...");
  //ui->evaluationLabel->setText("Computing...");
  //watcher.setFuture(QtConcurrent::run(Ackerman::Value, ui->mValue->value(), ui->nValue->value()));
  changeValue();
}

void MainWindow::changeValue(){
  //auto res = watcher.result();
  auto res = Ackerman::Value(ui->mValue->value(), ui->nValue->value());
  if (!res) {
    ui->result->setText("°º¤ø,¸¸,ø¤º°`°º¤ø,¸,ø¤°º¤ø,¸¸,ø¤º°`°º¤ø,¸");
  } else {
     ui->result->setText(QString::number(res.value()));
  }

  ui->evaluationLabel->setText({});
}