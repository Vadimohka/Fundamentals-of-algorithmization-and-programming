#include "SubFive.h"
#include "ui_SubFive.h"
#include <QFileDialog>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qtablewidget.h>
#include <qwidget.h>

SubFive::SubFive(QWidget *parent) : QWidget(parent), ui(new Ui::SubFive) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  ui->setupUi(this);

  connect(ui->saveBtn, &QPushButton::clicked, this, &SubFive::onSave);
  connect(ui->openBtn, &QPushButton::clicked, this, &SubFive::onOpen);
}

SubFive::~SubFive() {}

void SubFive::onSave() {
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::Append);
  {
    QTextStream stream(&file);
    stream << ui->inp->text() << "\n";
  }
  file.close();
}

void SubFive::onOpen() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Save Text"), "",
                                                  tr("Text Files (*.txt)"));
  QFile file(fileName);
  file.open(QFile::ReadOnly);

  QList<QString> lines;

  QTextStream stream(&file);
  while (!stream.atEnd()) {
    lines.push_back(stream.readLine());
  }
  file.close();

  ui->out->setRowCount(lines.count());
  for (int i = 0; i < lines.count(); i++) {
    ui->out->setItem(i, 0, new QTableWidgetItem(lines[i]));
  }
}