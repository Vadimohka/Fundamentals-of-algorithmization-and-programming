#include "SubThird.h"
#include "Buisenessman.h"
#include "ui_SubThird.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qspinbox.h>
#include <qtablewidget.h>
#include <qwidget.h>

SubThird::SubThird(QWidget *parent) : QWidget(parent), ui(new Ui::SubThird) {
  ui->setupUi(this);

  ui->creditRatingInp->setMaxLength(1);

  // connect(ui->countInp, &QSpinBox::valueChanged, this,
  // &SubThird::onNewCount);
  connect(ui->saveBtn, &QPushButton::clicked, this, &SubThird::onSave);
  connect(ui->openBtn, &QPushButton::clicked, this, &SubThird::onOpen);
}

SubThird::~SubThird() {}

void SubThird::append(Buisnessman bm) {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::Append);

  QTextStream out(&file);
  out << bm.name() << "\n";
  out << bm.age() << "\n";
  out << bm.bragsPerDay() << "\n";
  out << bm.creditRating() << "\n";
  out << bm.evil() << "\n";
  out << bm.networth(0) << "\n";
  out << bm.networth(1) << "\n";
  out << bm.networth(2) << "\n";
  out << "\n";

  file.close();
}

QList<Buisnessman> SubThird::load() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QTextStream inp(&file);
  QVector<Buisnessman> bbb;
  while (!inp.atEnd()) {
    QString name = inp.readLine();
    int age;
    inp >> age;
    double bragsPerDay;
    inp >> bragsPerDay;
    QChar creditRating;
    // READ TWICE TO SKIP NEWLINE
    inp >> creditRating >> creditRating;
    long long evilN = 0;
    inp >> evilN;
    bool evil = evilN == 0;
    long long networth[3];
    inp >> networth[0] >> networth[1] >> networth[2];

    QChar skip;
    inp >> skip >> skip;

    bbb.append(Buisnessman(name, age, bragsPerDay, creditRating, evilN,
                           networth[0], networth[1], networth[2]));
  }

  file.close();

  return bbb;
}

void SubThird::onSave() {
  Buisnessman bm(ui->nameInp->text(), ui->ageInp->value(),
                 ui->bragsPerDayInp->value(), ui->creditRatingInp->text()[0],
                 ui->evilInp->isChecked(), ui->networth0Inp->value(),
                 ui->networth1Inp->value(), ui->networth2Inp->value());

  append(bm);
}

void SubThird::onOpen() {
  QVector<Buisnessman> bs = load();
  ui->mainTable->setRowCount(bs.count());
  for (int i = 0; i < bs.count(); i++) {
    QString roow[] = {bs[i].name(),
                      QString::number(bs[i].age()),
                      QString::number(bs[i].bragsPerDay()),
                      QString(bs[i].creditRating()),
                      bs[i].evil() ? "Yes" : "No",
                      QString::number(bs[i].networth(0)),
                      QString::number(bs[i].networth(1)),
                      QString::number(bs[i].networth(2))};

    for (int j = 0; j < sizeof(roow) / sizeof(roow[0]); j++) {
      ui->mainTable->setItem(i, j, new QTableWidgetItem(roow[j]));
    }
  }
}