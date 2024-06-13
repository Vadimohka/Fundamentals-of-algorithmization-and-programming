#include "IOStructBin.h"
#include "Footwear.h"
#include <QFile>
#include <QMessageBox>

QString IOStructBin::getInstructions() {
  Q_ASSERT(type != BOTH);

  if (type == INP) {
    return "Введите поля структуры Обувь в виде НАЗАНИЕ (макс. 128 символов) | "
           "РАЗМЕР | ПОЛ(M/F/U) "
           "| "
           "ДЕТСКАЯ(+/-)\n"
           "Структура затем будет добавлена в БИНАРНЫЙ файл";
  } else if (type == OUT) {
    return "Если пользователь не сломал БИНАРНЫЙ файл со структурами, на экран "
           "выведется содержание файла с полями структур";
  }
}

void IOStructBin::initInput() {
  connect(input, &QPlainTextEdit::textChanged, [=] {
    auto s = input->toPlainText();
    if (!s.isEmpty() && s.back() == '\n') {
      enterInput();
    }
  });
}

void IOStructBin::initOutput() {

  QFile f(FNAME);
  if (!f.open(QFile::ReadOnly)) {
    QMessageBox::warning(input, "Предупреждение",
                         "Не удалось прочитать файл. Возможно, вы еще ни разу "
                         "не записали туда структуру. ");
    return;
  }

  QDataStream ds(&f);
  QString res;

  while (!ds.atEnd()) {
    char data[sizeof(Footwear)];
    ds.readRawData(&data[0], sizeof(Footwear));
    Footwear *fw = reinterpret_cast<Footwear*>(&data);
    res += fw->to_string(';') + '\n';
  }
  output->setText(res);

}

void IOStructBin::enterInput() {
  QString s = input->toPlainText();
  s.chop(1);

  Footwear fw;
  try {
    fw = Footwear(s.toStdString());
  } catch (const std::invalid_argument &ex) {
    QMessageBox::warning(
        input, "Предупреждение",
        QString(
            "Не удалось считать все поля структуры. Сообщение от парсера: %1")
            .arg(ex.what()));
    clear();
    return;
  }

  QFile f(FNAME);
  f.open(QFile::Append);
  QDataStream ds(&f);
  ds.writeRawData(reinterpret_cast<char*>(&fw), sizeof(Footwear));
  f.close();

  clear();
  processOutput();
}


void IOStructBin::processOutput(){
  output->setText("<Запись в файл произедена.>");
}