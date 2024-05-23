#include "Paragraph.h"
#include <QLabel>
#include <QPlainTextEdit>
#include <qnamespace.h>
#include <qplaintextedit.h>
#include <QFile>
#include <qstringconverter_base.h>

QString Paragraph::getInstructions()  {
    return QString("Введите абзац текста (до нажатия Enter), который затем будет сохранен в файл с именем %1, и выведен на экран из этого файла.").arg(FNAME);
}

void Paragraph::initInput()  {
        connect(input, &QPlainTextEdit::textChanged, [=]{
            auto s = input->toPlainText();
            if(!s.isEmpty() &&s.back() == '\n'){
                textChanged();
            }
        });
}

void Paragraph::initOutput()  {}

void Paragraph::processOutput() {
    QFile f(FNAME);
    f.open(QFile::ReadOnly);
    QDataStream ds (&f);
    QString s;
    while(!ds.atEnd()){
        wchar_t wch;
        ds.readRawData((char*)&wch, sizeof(wchar_t));
        s += QChar(wch);
    }
    output->setText(s);
    f.close();
} 

void Paragraph::textChanged() {
    QFile f (FNAME);
    f.open(QFile::WriteOnly);
    auto s = input->toPlainText();
    for(int i = 0; i < s.size(); ++i){
        wchar_t wch = s[i].unicode();
        f.write((const char*)&wch, sizeof(wchar_t));
    }
    f.close();

    clear();
    processOutput();
}
