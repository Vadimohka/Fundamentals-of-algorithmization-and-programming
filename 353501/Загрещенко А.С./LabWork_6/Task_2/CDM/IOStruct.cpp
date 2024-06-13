#include "IOStruct.h"
#include "Footwear.h"
#include "IOService.h"
#include <QFile>
#include <qassert.h>
#include <qmessagebox.h>
#include <stdexcept>

QString IOStruct::getInstructions() {
  Q_ASSERT(type != BOTH);

  if (type == INP) {
    return "Введите поля структуры Обувь в виде НАЗАНИЕ (макс. 128 символов) | РАЗМЕР | ПОЛ(M/F/U) "
           "| "
           "ДЕТСКАЯ(+/-)\n"
           "Структура затем будет добавлена в файл";
  } else if (type == OUT) {
    return "Если пользователь не сломал файл со структурами, на экран "
           "выведется содержание файла с полями структур";
  }
}

void IOStruct::initInput() {
  connect(input, &QPlainTextEdit::textChanged, [=] {
    auto s = input->toPlainText();
    if (!s.isEmpty() && s.back() == '\n') {
      enterInput();
    }
  });
}

void IOStruct::initOutput() {
  QFile f(FNAME);
  if (!f.open(QFile::ReadOnly)) {
    QMessageBox::warning(input, "Предупреждение",
                         "Не удалось прочитать файл. Возможно, вы еще ни разу "
                         "не записали туда структуру. ");
                         return;
  }

  QTextStream ts(&f);
  output->setText(ts.readAll());
  f.close();
}

void IOStruct::processOutput() {
  output->setText("<Запись в файл произедена.>");
}


void IOStruct::enterInput() {

  QString s = input->toPlainText();
  s.chop(1);

  try {
    Footwear fw(s.toStdString());
  } catch (const std::invalid_argument &ex) {
    QMessageBox::warning(input, "Предупреждение",
                         QString("Не удалось считать все поля структурыы. Сообщение от парсера: %1").arg(ex.what()));
    clear();
    return;
  }

  QFile f(FNAME);
  f.open(QFile::Append);
  QTextStream ts(&f);
  ts << s << '\n';
  f.close();

  clear();

  processOutput();
}
