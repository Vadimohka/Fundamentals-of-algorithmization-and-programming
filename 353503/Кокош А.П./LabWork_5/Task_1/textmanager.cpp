#include "textmanager.h"
#include <QDebug>

TextManager::TextManager(QVector<QString>* d, QVector<QString>* t, Ui::MainWindow *u)
{
    dictionary = d;
    trainingText = t;
    ui = u;
}

void TextManager::AddTextToNext()
{
    QString text = ui->lineEdit_train->text();
    int spaceCount = 0;
    for (QString i : text)
    {
        if (i == ' ')
        {
            ++spaceCount;
        }
    }
    if (spaceCount < 16)
    {
        if (!trainingText->isEmpty())
        {
            if (ui->lineEdit_train->text().isEmpty())
            {
                ui->lineEdit_train->setText(trainingText->front());
            }
            else
            {
                ui->lineEdit_train->setText(ui->lineEdit_train->text() + " " + trainingText->front());
            }
            trainingText->pop_front();
            AddTextToNext();
        }
    }
}

void TextManager::LoadTest()
{
    ui->textEdit_train->setText("");
    ui->lineEdit_train->setText("");
    ui->textEdit_input->setText("");
    ui->lineEdit_input->setText("");

    QString fileName = QFileDialog::getOpenFileName(nullptr, QMessageBox::tr("Open"), "//", QMessageBox::tr("Text Documents (*.txt)"));
    QFile file(fileName);
    QTextStream in(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd())
    {
        QMessageBox::critical(0, QMessageBox::tr("Error"), QMessageBox::tr("Invalid data format!"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    trainingText->clear();

    while (!in.atEnd())
    {
        trainingText->push_back(in.readLine());
        ui->textEdit_train->setText(ui->textEdit_train->toPlainText() + " " + trainingText->back());
    }
    AddTextToNext();
    file.close();
}

void TextManager::SetDictionary(int locale)
{
    dictionary->clear();
    QFile file;
    switch (locale)
    {
    case 0:
        file.setFileName("dictionary/arabic.txt");
        break;
    case 1:
        file.setFileName("dictionary/belarusian.txt");
        break;
    case 2:
        file.setFileName("dictionary/chinese.txt");
        break;
    case 3:
        file.setFileName("dictionary/english.txt");
        break;
    case 4:
        file.setFileName("dictionary/french.txt");
        break;
    case 5:
        file.setFileName("dictionary/german.txt");
        break;
    case 6:
        file.setFileName("dictionary/hebrew.txt");
        break;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, QMessageBox::tr("Error"), QMessageBox::tr("Unable to read dictionary!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    QTextStream in(&file);
    QString line;
    while (!in.atEnd())
    {
        line = in.readLine();
        dictionary->push_back(line);
    }
    file.close();
}

void TextManager::Generate()
{
    ui->textEdit_train->setText("");
    ui->lineEdit_train->setText("");
    ui->textEdit_input->setText("");
    ui->lineEdit_input->setText("");
    trainingText->clear();

    int n = ui->spinBox->value(), m = dictionary->size();
    for (int i = 0; i < n; ++i)
    {
        int k = QRandomGenerator::global()->bounded(0, m);
        trainingText->push_back(dictionary->at(k));
    }
    if (n > 0)
    {
        ui->textEdit_train->setText(ui->textEdit_train->toPlainText() + trainingText->first());
    }
    for (int i = 1; i < n; ++i)
    {
        ui->textEdit_train->setText(ui->textEdit_train->toPlainText() + " " + trainingText->at(i));
    }
    AddTextToNext();
}
