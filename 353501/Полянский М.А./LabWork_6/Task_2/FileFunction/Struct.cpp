#include "Struct.h"
#include "../Footwear.h"
#include "Service.h"
#include <QFile>
#include <QMessageBox>
#include <stdexcept>

QString PrStruct::getInstructions() {
    Q_ASSERT(type != BOTH);

    if (type == INP) {
        return "Enter the fields of the Footwear structure in the format NAME (max. 128 characters) | SIZE | GENDER(M/F/U) | CHILD(+/-)\n"
               "The structure will then be added to the file.";
    } else if (type == OUT) {
        return "If the user has not broken the structure file, the contents of the file with structure fields will be displayed on the screen.";
    }
}

void PrStruct::initInput() {
    connect(input, &QPlainTextEdit::textChanged, [=] {
        auto s = input->toPlainText();
        if (!s.isEmpty() && s.back() == '\n') {
            enterInput();
        }
    });
}

void PrStruct::initOutput() {
    QFile f(FNAME);
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox::warning(input, "Warning",
                             "Failed to read the file. Perhaps you haven't written any structure to it yet.");
        return;
    }

    QTextStream ts(&f);
    output->setText(ts.readAll());
    f.close();
}

void PrStruct::processOutput() {
    output->setText("<Writing to file completed.>");
}

void PrStruct::enterInput() {

    QString s = input->toPlainText();
    s.chop(1);

    try {
        Foot fw(s.toStdString());
    } catch (const std::invalid_argument &ex) {
        QMessageBox::warning(input, "Warning",
                             QString("Failed to read all structure fields. Parser message: %1").arg(ex.what()));
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
