#include "SubFour.h"
#include "../sub3/Buisenessman.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qspinbox.h>
#include <qtablewidget.h>
#include <qwidget.h>

SubFour::SubFour(QWidget *parent) : SubThird(parent) {}

SubFour::~SubFour() {}

void SubFour::append(Buisnessman bm) {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Binary Data"), "",
                                                  tr("Binary Data (*.bin)"));
  QFile file(fileName);
  file.open(QFile::Append);
  file.write(bm.toBinData());
  file.close();
}

QList<Buisnessman> SubFour::load() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "",
                                                  tr("Binary Data (*.bin)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QVector<Buisnessman> bbb;
  while (!file.atEnd()) {
    bbb.append(Buisnessman(file.read(Buisnessman::BINDATA_SIZE)));
  }

  file.close();

  return bbb;
}
