#include "IOArray.h"
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qplaintextedit.h>
#include <sstream>
#include <stdexcept>
#include <string>

void IOArray::initInput() {
  size = QInputDialog::getInt(
      input, "Размер", "Введите размер запрашиваемого массива: ", 10, 1, 50);
  array = new double[size];

  connect(input, &QPlainTextEdit::textChanged, [=] {
    auto s = input->toPlainText();
    if (!s.isEmpty() && s.back() == '\n') {
      onEnterInput();
    }
  });
}

void IOArray::initOutput() {}

QString IOArray::getInstructions() {
  return QString("Введите %1 элементов массива типа double, разделяя значения "
                 "символом %2.\n В результате массив будет записан в файл %3, "
                 "который затем будет прочитан и выведется на экран через "
                 "пробел.")
      .arg(size)
      .arg(DELIM)
      .arg(FNAME);
}

IOArray::~IOArray() {
  if (array)
    delete[] array;
}

void IOArray::onEnterInput() {

  auto lst = input->toPlainText().split(DELIM);

  if (lst.size() > size) {
    QMessageBox::warning(input, "Предупреждение",
                         "Было введено больше данных, чем необходимо.");
    clear();
    return;
  }

  int i = 0;
  bool ok;
  foreach (auto s, lst) {
    array[i] = s.toDouble(&ok);
    if (!ok) {
      QMessageBox::warning(input, "Предупреждение",
                           "Не удалось считать все данные. Убедитесь в "
                           "корректности их формата.");
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

void IOArray::processOutput() {
  QFile f(FNAME);
  f.open(QFile::ReadOnly);
  QTextStream ts(&f);
  output->setText(ts.readAll());
  f.close();
}


