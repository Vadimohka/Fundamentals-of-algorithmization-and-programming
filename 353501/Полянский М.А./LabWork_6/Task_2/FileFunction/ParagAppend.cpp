#include "ParagAppend.h"
#include "Service.h"
#include <QFile>
#include <QMessageBox>

QString ParagAppend::getInstructions() {
    Q_ASSERT(type != BOTH);
    if (type == INP) {
        return QString("Enter a paragraph of text (before pressing Enter) that will be written (appended) to the file %1.").arg(FNAME);
    } else if (type == OUT) {
        return "All paragraphs you entered previously will be displayed on the screen.";
    }
}

void ParagAppend::initInput() {
    connect(input, &QPlainTextEdit::textChanged, [=]{
        auto s = input->toPlainText();
        if (!s.isEmpty() && s.back() == '\n') {
            enterInput();
        }
    });
}

void ParagAppend::initOutput() {
    QFile f(FNAME);
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox::warning(input, "Warning", "Failed to read the file. Perhaps you have not chosen the input option yet.");
        output->setText({});
        return;
    }
    output->setText(f.readAll());
    f.close();
}

void ParagAppend::processOutput() {
    output->setText("<Writing to file completed>");
}

void ParagAppend::enterInput() {
    QFile f(FNAME);
    f.open(QFile::Append);
    QTextStream ts(&f);
    auto s = input->toPlainText();
    ts << s;
    f.close();
    clear();

    processOutput();
}
