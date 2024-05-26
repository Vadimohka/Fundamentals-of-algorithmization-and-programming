#include "SubFour.h"
#include "../sub3/Cloth.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qspinbox.h>
#include <qtablewidget.h>
#include <qwidget.h>

SubFour::SubFour(QWidget *parent) : SubThird(parent) {}

SubFour::~SubFour() {}

void SubFour::append(Cloth bm) {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Binary Data"), "",
                                                  tr("Binary Data (*.bin)"));
  QFile file(fileName);
  file.open(QFile::Append);
  file.write(bm.toBinData());
  file.close();
}

QList<Cloth> SubFour::load() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text"), "",
                                                  tr("Binary Data (*.bin)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QVector<Cloth> bbb;
  while (!file.atEnd()) {
    bbb.append(Cloth(file.read(Cloth::BINDATA_SIZE)));
  }

  file.close();

  return bbb;
}
