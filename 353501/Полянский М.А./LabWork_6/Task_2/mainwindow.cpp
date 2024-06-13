#include "mainwindow.h"
#include "FileFunction/ArrayWriter.h"
#include "FileFunction/ParagraphW.h"
#include "FileFunction/ParagAppend.h"
#include "FileFunction/Service.h"
#include "FileFunction/Struct.h"
#include "FileFunction/StructBin.h"
#include "ui_mainwindow.h"
#include <qinputdialog.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  on_chooseBtn_clicked();
 
}

MainWindow::~MainWindow() {
  if (service) {
    delete service;
  }
  delete ui;
}

void MainWindow::on_chooseBtn_clicked() {

  if (service) {
    delete service;
  }

  bool ok;

  auto option = QInputDialog::getInt(this, "Choose", actions, 1, 1, 5, 1, &ok);
  switch (option) {
  case 1:
    service = new ParagraphWri(ui->input, ui->output, ui->instruction, this);
    break;
  case 2:
    service = new ArrayWrite(ui->input, ui->output, ui->instruction, this);
    break;
  case 3: {
    int io = QInputDialog::getInt(this, "Enter/OutPut", "1 - Enter\n2 - OutPut", 1,
                                  1, 2);
    service = new PrStruct(ui->input, ui->output, ui->instruction, this,
                           (ServiceType)io);
  } break;

  case 4: {
    int io = QInputDialog::getInt(this, "Enter/OutPut", "1 - Enter\n2 - OutPut", 1,
                                  1, 2);
    service = new StructBin(ui->input, ui->output, ui->instruction, this,
                           (ServiceType)io);

  } break;

  case 5:
    int io = QInputDialog::getInt(this, "Enter/OutPut", "1 - Enter\n2 - OutPut", 1, 1, 2);
    service = new ParagAppend(ui->input, ui->output, ui->instruction, this, (ServiceType)io);
    break;
  }
  if (ok) {
    service->init();
  }
}
