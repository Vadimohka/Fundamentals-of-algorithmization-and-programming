#include "SubFirst.h"
#include "ui_SubFirst.h"
#include <QFileDialog>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qwidget.h>

SubFirst::SubFirst(QWidget *parent) : QWidget(parent), ui(new Ui::SubFirst) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  ui->setupUi(this);

  connect(ui->saveBtn, &QPushButton::clicked, this, &SubFirst::onSave);
  connect(ui->openBtn, &QPushButton::clicked, this, &SubFirst::onOpen);
}

SubFirst::~SubFirst() {}

void SubFirst::onSave() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::WriteOnly);
  for (QChar c : ui->inp->text()) {
    file.write((const char *)&c, sizeof(QChar));
  }
  file.close();
}

void SubFirst::onOpen() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QString res;
  while (!file.atEnd()) {
    QChar c;
    file.read((char *)&c, sizeof(QChar));
    res += c;
  }

  ui->out->setText(res);
  file.close();
}