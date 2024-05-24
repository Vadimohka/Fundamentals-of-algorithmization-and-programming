#include "SubSecond.h"
#include "ui_SubSecond.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qspinbox.h>
#include <qwidget.h>

SubSecond::SubSecond(QWidget *parent) : QWidget(parent), ui(new Ui::SubSecond) {
  ui->setupUi(this);

  connect(ui->countInp, &QSpinBox::valueChanged, this, &SubSecond::onNewCount);
  connect(ui->saveBtn, &QPushButton::clicked, this, &SubSecond::onSave);
  connect(ui->openBtn, &QPushButton::clicked, this, &SubSecond::onOpen);
}

SubSecond::~SubSecond() {}

void SubSecond::resizeTable(int targetCount) {
  int prevCount = ui->mainTable->rowCount();
  ui->mainTable->setRowCount(targetCount);
  for (int i = prevCount; i < targetCount; i++) {
    ui->mainTable->setCellWidget(i, 0, new QSpinBox());
  }
}

void SubSecond::onNewCount() { resizeTable(ui->countInp->value()); }

void SubSecond::onSave() {

  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::WriteOnly);

  QTextStream out(&file);

  for (int i = 0; i < ui->mainTable->rowCount(); i++) {
    QSpinBox *spinbox = (QSpinBox *)ui->mainTable->cellWidget(i, 0);
    if (i != 0)
      out << ",";
    out << spinbox->value();
  }
  file.close();
}

void SubSecond::onOpen() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QVector<long long> values;
  try {
    QTextStream inp(&file);

    while (!inp.atEnd()) {
      long long inNum;
      inp >> inNum;
      values.append(inNum);

      QChar sep;
      inp >> sep;
    }
  } catch (std::exception &e) {
    QMessageBox::critical(this, "Failed to load file",
                          QString("Failed to load file:\n%0").arg(e.what()));
  }
  file.close();

  ui->countInp->setValue(values.count());
  resizeTable(values.count());
  for (int i = 0; i < values.count(); i++) {
    QSpinBox *spinbox = (QSpinBox *)ui->mainTable->cellWidget(i, 0);
    spinbox->setValue(values[i]);
  }

  // ui->out->setText(res);
}