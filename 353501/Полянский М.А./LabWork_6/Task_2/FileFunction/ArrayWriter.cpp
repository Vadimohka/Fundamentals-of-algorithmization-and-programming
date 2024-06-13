#include "ArrayWriter.h"
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qplaintextedit.h>
#include <sstream>
#include <stdexcept>
#include <string>

void ArrayWrite::initInput() {
  size = QInputDialog::getInt(
      input, "Size", "Enter array size: ", 10, 1, 50);
  array = new double[size];

  connect(input, &QPlainTextEdit::textChanged, [=] {
    auto s = input->toPlainText();
    if (!s.isEmpty() && s.back() == '\n') {
      onEnterInput();
    }
  });
}

void ArrayWrite::initOutput() {}

QString ArrayWrite::getInstructions() {
  return QString("Enter %1 elements of array type double, shared value "
                 "symbols %2.")
      .arg(size)
      .arg(DELIM);
   
}

ArrayWrite::~ArrayWrite() {
  if (array)
    delete[] array;
}

void ArrayWrite::onEnterInput() {

  auto lst = input->toPlainText().split(DELIM);

  if (lst.size() > size) {
    QMessageBox::warning(input, "Warning",
                         "you entered too much data.");
    clear();
    return;
  }

  int i = 0;
  bool ok;
  foreach (auto s, lst) {
    array[i] = s.toDouble(&ok);
    if (!ok) {
      QMessageBox::warning(input, "Warning",
                           "program can't read data."
                           "check how you enter data.");
      clear();
      return;
    }
    ++i;
  }
  for (int j = i; j < size; ++j) {
    array[j] = 0.0;
  }

  QFile f(FNAME);
  f.open(QFile::WriteOnly);
  QTextStream ts(&f);
  for (int i = 0; i < size; ++i) {
    ts << array[i] << ' ';
  }
  f.close();

  processOutput();
  clear();
}

void ArrayWrite::processOutput() {
  QFile f(FNAME);
  f.open(QFile::ReadOnly);
  QTextStream ts(&f);
  output->setText(ts.readAll());
  f.close();
}


