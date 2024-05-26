#include "SubThird.h"
#include "Cloth.h"
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

  connect(ui->saveBtn, &QPushButton::clicked, this, &SubThird::onSave);
  connect(ui->openBtn, &QPushButton::clicked, this, &SubThird::onOpen);
}

SubThird::~SubThird() {}

void SubThird::append(Cloth bm) {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::Append);

  QTextStream out(&file);
  out << bm.name() << "\n";
  out << bm.count() << "\n";
  out << bm.price() << "\n";
  out << bm.size() << "\n";
  out << bm.isAvaliable() << "\n";
  out << bm.lenght(0) << "\n";
  out << bm.lenght(1) << "\n";
  out << bm.lenght(2) << "\n";
  out << "\n";

  file.close();
}

QList<Cloth> SubThird::load() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QTextStream inp(&file);
  QVector<Cloth> bbb;
  while (!inp.atEnd()) {
    QString name = inp.readLine();
    int count;
    inp >> count;
    double price;
    inp >> price;
    QChar size;
    // READ TWICE TO SKIP NEWLINE
    inp >> size >> size;
    long long avaliable = 0;
    inp >> avaliable;
    bool evil = avaliable == 0;
    long long lenght[3];
    inp >> lenght[0] >> lenght[1] >> lenght[2];

    QChar skip;
    inp >> skip >> skip;

    bbb.append(Cloth(name, count, price, size, avaliable, lenght[0], lenght[1],
                     lenght[2]));
  }

  file.close();

  return bbb;
}

void SubThird::onSave() {
  Cloth bm(ui->nameInp->text(), ui->ageInp->value(),
                 ui->bragsPerDayInp->value(), ui->creditRatingInp->text()[0],
                 ui->evilInp->isChecked(), ui->networth0Inp->value(),
                 ui->networth1Inp->value(), ui->networth2Inp->value());

  append(bm);
}

void SubThird::onOpen() {
  QVector<Cloth> bs = load();
  ui->mainTable->setRowCount(bs.count());
  for (int i = 0; i < bs.count(); i++) {
    QString roow[] = {bs[i].name(),
                      QString::number(bs[i].count()),
                      QString::number(bs[i].price()),
                      QString(bs[i].size()),
                      bs[i].isAvaliable() ? "Yes" : "No",
                      QString::number(bs[i].lenght(0)),
                      QString::number(bs[i].lenght(1)),
                      QString::number(bs[i].lenght(2))};

    for (int j = 0; j < sizeof(roow) / sizeof(roow[0]); j++) {
      ui->mainTable->setItem(i, j, new QTableWidgetItem(roow[j]));
    }
  }
}