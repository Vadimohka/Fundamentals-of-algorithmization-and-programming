#include "StructBin.h"
#include "../Footwear.h"
#include <QFile>
#include <QMessageBox>

QString StructBin::getInstructions() {
    Q_ASSERT(type != BOTH);

    if (type == INP) {
        return "Enter the fields of the Footwear structure in the format NAME (max. 128 characters) | SIZE | GENDER(M/F/U) | CHILD(+/-)\n"
               "The structure will then be added to the BINARY file.";
    } else if (type == OUT) {
        return "If the user has not broken the BINARY file with structures, the contents of the file with structure fields will be displayed on the screen.";
    }
}

void StructBin::initInput() {
    connect(input, &QPlainTextEdit::textChanged, [=] {
        auto s = input->toPlainText();
        if (!s.isEmpty() && s.back() == '\n') {
            enterInput();
        }
    });
}

void StructBin::initOutput() {

    QFile f(FNAME);
    if (!f.open(QFile::ReadOnly)) {
        QMessageBox::warning(input, "Warning",
                             "Failed to read the file. Perhaps you haven't written any structure to it yet.");
        return;
    }

    QDataStream ds(&f);
    QString res;

    while (!ds.atEnd()) {
        char data[sizeof(Foot)];
        ds.readRawData(&data[0], sizeof(Foot));
        Foot *fw = reinterpret_cast<Foot*>(&data);
        res += fw->to_string(';') + '\n';
    }
    output->setText(res);

}

void StructBin::enterInput() {
    QString s = input->toPlainText();
    s.chop(1);

    Foot fw;
    try {
        fw = Foot(s.toStdString());
    } catch (const std::invalid_argument &ex) {
        QMessageBox::warning(
            input, "Warning",
            QString(
                "Failed to read all structure fields. Parser message: %1")
                .arg(ex.what()));
        clear();
        return;
    }

    QFile f(FNAME);
    f.open(QFile::Append);
    QDataStream ds(&f);
    ds.writeRawData(reinterpret_cast<char*>(&fw), sizeof(Foot));
    f.close();

    clear();
    processOutput();
}


void StructBin::processOutput(){
    output->setText("<Writing to file completed.>");
}
