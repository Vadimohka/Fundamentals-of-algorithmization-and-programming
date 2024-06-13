#include "textwork.h"
#include "ConstTextWork.h"

TextWork::TextWork(QVector<QString> *dictionary, QVector<QString> *tranningText, Ui::MainWindow *ui)
    : dictionary(dictionary)
    , tranningText(tranningText)
    , ui(ui)
{}

void TextWork::AddTextToProgressLine()
{
    QString text = ui->progressTextEdit->text();
    int spaceCount = 0;
    for (QString i : text) {
        if (i == ' ') {
            ++spaceCount;
        }
    }
    if (spaceCount < MAX_WORDS_IN_LINE) {
        if (!tranningText->isEmpty()) {
            if (ui->progressTextEdit->text().isEmpty()) {
                ui->progressTextEdit->setText(tranningText->front());
            } else {
                ui->progressTextEdit->setText(ui->progressTextEdit->text() + " "
                                              + tranningText->front());
            }
            tranningText->pop_front();
            AddTextToProgressLine();
        }
    }
}

void TextWork::SetDictionary(int locale)
{
    dictionary->clear();
    QFile file;
    switch (locale) {
    case ARABIC_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/arabic.txt");
        break;
    case BELARUSIAN_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/belarusian.txt");
        break;
    case CHINESE_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/chinese.txt");
        break;
    case ENGLISH_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/english.txt");
        break;
    case FRENCH_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/french.txt");
        break;
    case GERMAN_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/german.txt");
        break;
    case HEBREW_LANGUAGE:
        file.setFileName(
            "/home/lq-84i/QTProjects/l5/Task_1/ListLanguages/hebrew.txt");
        break;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr,
                              QMessageBox::tr("Error"),
                              QMessageBox::tr("Unable to read Files"),
                              QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        dictionary->push_back(line);
    }
    file.close();
}

void TextWork::GenerateText()
{
    ui->textEdit->setText("");
    ui->progressTextEdit->setText("");
    ui->inputTextEdit->setText("");
    ui->startEdit->setText("");
    tranningText->clear();

    for (int i = 0; i < ui->spinBox->value(); ++i) {
        tranningText->push_back(
            dictionary->at(QRandomGenerator::global()->bounded(0, dictionary->size())));
    }
    ui->textEdit->setText(ui->textEdit->toPlainText() + tranningText->first());

    for (int i = 1; i < ui->spinBox->value(); ++i) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + " " + tranningText->at(i));
    }
    AddTextToProgressLine();
}
