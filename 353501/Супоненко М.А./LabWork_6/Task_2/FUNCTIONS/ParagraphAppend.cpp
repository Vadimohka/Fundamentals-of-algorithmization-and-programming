#include "ParagraphAppend.h"
#include "IOService.h"
#include <QFile>
#include <qmessagebox.h>

QString ParagraphAppend::getInstructions() {
Q_ASSERT(type != BOTH);    
if(type == INP){
    return QString("Введите абзац текста (до нажатия Enter), который будет записан (дозаписан) в файл %1.").arg(FNAME);
} else if( type == OUT){
    return "Все введенные вами ранее абзацы будут выведены на экран.";
}
}

void ParagraphAppend::initInput() {
     connect(input, &QPlainTextEdit::textChanged, [=]{
        auto s = input->toPlainText();
        if(!s.isEmpty() &&s.back() == '\n'){
            enterInput();
        }
    });
    
}

void ParagraphAppend::initOutput() {
    QFile f(FNAME);
    if(!f.open(QFile::ReadOnly)){
        QMessageBox::warning(input, "Предупреждение", "Не удалось прочитать файл. Возможно, вы еще ни разу не выбрали опцию ввод.");
        output->setText({});
        return;
    }
    output->setText(f.readAll());
    f.close();
}

void ParagraphAppend::processOutput() {
    output->setText("<Запись в файл произведена>");
}

void ParagraphAppend::enterInput() {
    QFile f (FNAME);
    f.open(QFile::Append);
    QTextStream ts(&f);
    auto s = input->toPlainText();
    ts << s;
    f.close();
    clear(); 

    processOutput();
}