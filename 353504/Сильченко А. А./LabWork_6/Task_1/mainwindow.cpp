#include "mainwindow.h"
#include "Cloth.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qspinbox.h>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), cloth(new Cloth) {
  ui->setupUi(this);

    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(162, 243, 241));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);

  fillUiFromStruct();
  ui->creditRatingInp->setMaxLength(1);

  connect(ui->nameInp, &QLineEdit::textChanged,
          [&](QString newVal) { cloth->setName(newVal); });

  connect(ui->ageInp, &QSpinBox::valueChanged,
          [&](int newVal) { cloth->setCount(newVal); });

  connect(ui->bragsPerDayInp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { cloth->setPrice(newVal); });

  connect(ui->creditRatingInp, &QLineEdit::textChanged,
          [&](QString newVal) { cloth->setSize(newVal[0]); });

  connect(ui->evilInp, &QCheckBox::stateChanged,
          [&](int checked) { cloth->setAvaliable(checked == Qt::Checked); });

  connect(ui->networth0Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { cloth->setLenght(newVal * 1e9, 0); });

  connect(ui->networth1Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { cloth->setLenght(newVal * 1e9, 1); });

  connect(ui->networth2Inp, &QDoubleSpinBox::valueChanged,
          [&](double newVal) { cloth->setLenght(newVal * 1e9, 2); });
}

void MainWindow::fillUiFromStruct() {
  ui->nameInp->setText(cloth->name());
  ui->ageInp->setValue(cloth->count());
  ui->bragsPerDayInp->setValue(cloth->price());
  ui->creditRatingInp->setText(QString(cloth->size()));
  ui->evilInp->setChecked(cloth->isAvaliable());
  ui->networth0Inp->setValue(cloth->lenght(0) / 1e9);
  ui->networth1Inp->setValue(cloth->lenght(1) / 1e9);
  ui->networth2Inp->setValue(cloth->lenght(2) / 1e9);
}
