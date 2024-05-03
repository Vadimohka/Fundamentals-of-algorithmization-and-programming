#include "mainwindow.h"
#include "Buisenessman.h"
#include "ui_mainwindow.h"
#include <QPrintDialog>
#include <QPrinter>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <QPainter>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), buisenessman(new Buisnessman) {
  ui->setupUi(this);

  fillUiFromStruct();
  ui->creditRatingInp->setMaxLength(1);

  connect(ui->nameInp, &QLineEdit::textChanged,
          [&](QString newVal) { buisenessman->setName(newVal); });

  connect(ui->ageInp, &QSpinBox::valueChanged,
          [&](int newVal) { buisenessman->setAge(newVal); });

  connect(ui->bragsPerDayInp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { buisenessman->setBragsPerDay(newVal); });

  connect(ui->creditRatingInp, &QLineEdit::textChanged,
          [&](QString newVal) { buisenessman->setCreditRating(newVal[0]); });

  connect(ui->evilInp, &QCheckBox::stateChanged,
          [&](int checked) { buisenessman->setEvil(checked == Qt::Checked); });

  connect(ui->networth0Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { buisenessman->setNetworth(newVal * 1e9, 0); });

  connect(ui->networth1Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { buisenessman->setNetworth(newVal * 1e9, 1); });

  connect(ui->networth2Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { buisenessman->setNetworth(newVal * 1e9, 2); });

  connect(ui->printBtn, &QPushButton::pressed, this, &MainWindow::print);
}

void MainWindow::fillUiFromStruct() {
  ui->nameInp->setText(buisenessman->name());
  ui->ageInp->setValue(buisenessman->age());
  ui->bragsPerDayInp->setValue(buisenessman->bragsPerDay());
  ui->creditRatingInp->setText(QString(buisenessman->creditRating()));
  ui->evilInp->setChecked(buisenessman->evil());
  ui->networth0Inp->setValue(buisenessman->networth(0) / 1e9);
  ui->networth1Inp->setValue(buisenessman->networth(1) / 1e9);
  ui->networth2Inp->setValue(buisenessman->networth(2) / 1e9);
}

void MainWindow::print() {
  QPrinter printer;
  QPrintDialog dialog(&printer, this);
  dialog.setWindowTitle(tr("Print Report"));
  if (dialog.exec() != QDialog::Accepted)
    return;
  // printer.setOutputFileName("print.ps"); 

  QTextDocument td;
  td.setHtml(buisenessman->generateHtmlReport());
  td.print(&printer);
  // painter.end();

}