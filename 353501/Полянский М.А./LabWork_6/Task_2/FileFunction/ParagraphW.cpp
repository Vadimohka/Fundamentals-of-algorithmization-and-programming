#include "ParagraphW.h"
#include <QLabel>
#include <QPlainTextEdit>
#include <QFile>

QString ParagraphWri::getInstructions() {
    return QString("Enter a paragraph of text (before pressing Enter), which will then be saved to a file named %1, and displayed on the screen from this file.").arg(FNAME);
}

void ParagraphWri::initInput() {
    connect(input, &QPlainTextEdit::textChanged, [=]{
        auto s = input->toPlainText();
        if (!s.isEmpty() && s.back() == '\n') {
            textChanged();
        }
    });
}

void ParagraphWri::initOutput() {}

void ParagraphWri::processOutput() {
    QFile f(FNAME);
    f.open(QFile::ReadOnly);
    QDataStream ds(&f);
    QString s;
    while (!ds.atEnd()) {
        wchar_t wch;
        ds.readRawData((char*)&wch, sizeof(wchar_t));
        s += QChar(wch);
    }
    output->setText(s);
    f.close();
}

void ParagraphWri::textChanged() {
    QFile f(FNAME);
    f.open(QFile::WriteOnly);
    auto s = input->toPlainText();
    for (int i = 0; i < s.size(); ++i) {
        wchar_t wch = s[i].unicode();
        f.write((const char*)&wch, sizeof(wchar_t));
    }
    f.close();

    clear();
    processOutput();
}
