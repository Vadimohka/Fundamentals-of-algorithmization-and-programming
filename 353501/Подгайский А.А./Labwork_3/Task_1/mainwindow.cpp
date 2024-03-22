#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Converter.h"
#include "LongDoubleValidator.h"
#include <climits>
#include <QFontDatabase>
#include <cstdint>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().size());

  auto monospace = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  monospace.setPointSize(12);
  ui->result->setFont(monospace);

  connect(ui->convertBtn, &QPushButton::clicked,
    this, &MainWindow::convert);
}

void MainWindow::convert(){
  auto inp = ui->input->text();
  if(!LDValidator::checkInput(inp)){
    ui->result->setText("-- wrong input -- ");
  } else {
     ui->result->setText(Converter::toIEE754(std::stold(inp.toStdString())));
  }
 
}