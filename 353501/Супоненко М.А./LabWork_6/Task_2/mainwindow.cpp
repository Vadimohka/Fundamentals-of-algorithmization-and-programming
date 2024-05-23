#include "mainwindow.h"
#include "array.h"
#include "paragraph.h"
#include "paragraphAppend.h"
#include "service.h"
#include "struct.h"
#include "structBin.h"
#include "ui_mainwindow.h"
#include <qinputdialog.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  on_chooseBtn_clicked();
  // service = new IOArray(ui->input, ui->output, ui->instruction, this);
  // service->init();
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

  auto option = QInputDialog::getInt(this, "Выбор", actions, 1, 1, 5, 1, &ok);
  switch (option) {
  case 1:
    service = new Paragraph(ui->input, ui->output, ui->instruction, this);
    break;
  case 2:
    service = new Array(ui->input, ui->output, ui->instruction, this);
    break;
  case 3: {
    int io = QInputDialog::getInt(this, "Ввод/вывод", "1 - Ввод\n2 - Вывод", 1,
                                  1, 2);
    service = new Struct(ui->input, ui->output, ui->instruction, this,
                           (ServiceType)io);
  } break;

  case 4: {
    int io = QInputDialog::getInt(this, "Ввод/вывод", "1 - Ввод\n2 - Вывод", 1,
                                  1, 2);
    service = new StructBin(ui->input, ui->output, ui->instruction, this,
                           (ServiceType)io);

  } break;

  case 5:
    int io = QInputDialog::getInt(this, "Ввод/вывод", "1 - Ввод\n2 - Вывод", 1,
                                  1, 2);
    service = new ParagraphAppend(ui->input, ui->output, ui->instruction,
                                    this, (ServiceType)io);
    break;
  }

  if (ok) {
    service->init();
  }
}
