#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->optionLineEdit->setValidator(
        new QRegularExpressionValidator(*new QRegularExpression("[1-9]")));
    ui->arrayElementLineEdit->setValidator(new QDoubleValidator);
    ui->ratingPosLineEdit->setValidator(new QIntValidator);
    ui->sportTeamInfoLabel->hide();
    ui->ratingPosLineEdit->hide();
    ui->ratingPositionLabel->hide();
    ui->winPercentageLineEdit->setMaxLength(19);
    ui->winPercentageLineEdit->setValidator(new QDoubleValidator(0.0, 100.0, 1223));
    ui->winPercentageLineEdit->hide();
    ui->winPercentageLabel->hide();
    ui->winPercentageLabel->hide();
    ui->divisionLineEdit->setValidator(
        new QRegularExpressionValidator(*new QRegularExpression("[A-D]")));
    ui->divisionLineEdit->hide();
    ui->divisionLabel->hide();
    ui->passedToChampionsLeagueLineEdit->setValidator(
        new QRegularExpressionValidator(*new QRegularExpression("[0-1]")));
    ui->passedToChampionsLeagueLineEdit->hide();
    ui->passedToChampionsLeagueLabel->hide();
    ui->passedToChampionsLeagueLabel_2->hide();
    ui->nameAbbreviationLineEdit->setValidator(
        new QRegularExpressionValidator(*new QRegularExpression("[A-Z]{3}")));
    ui->nameAbbreviationLineEdit->hide();
    ui->nameAbbreviationLabel->hide();
    ui->nameAbbreviationLabel_2->hide();
    ui->playerNumberLineEdit->setValidator(new QIntValidator(1, 99));
    ui->playerNumberLineEdit->hide();
    ui->playerNumberLabel->hide();
    ui->arraySizeLabel->hide();
    ui->arraySizeLineEdit->hide();
    ui->arrayElementLabel->hide();
    ui->arrayElementLineEdit->hide();

    ui->winPercentageLimitLabel->hide();\

    connect(ui->optionLineEdit, SIGNAL(textChanged(QString)), this, SLOT(Menu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Menu()
{
    switch (ui->optionLineEdit->text().toUShort()) {
    case 1:
        EnterWritePrintText();
        break;
    case 2:
        EnterWritePrintArray();
        break;
    case 3:
        EnterWritePrintSportTeamInfo();
        break;
    case 4:
        EnterWritePrintSportTeamInfo();
        break;
    case 5:
        EnterWritePrintSentence();
        break;
    case 6:
        QCoreApplication::quit();
        break;
    default:
        break;
    }
}

void MainWindow::EnterWritePrintText()
{
    ui->plainTextEdit->clear();
    ui->outputPlainTextEdit->clear();
    ui->optionLabel->setEnabled(false);
    ui->optionLineEdit->setEnabled(false);
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit->setPlainText("Enter text here");
}

void MainWindow::WriteTextToFileAndPrint()
{
    QFile file{"ShcheperkoLab6"};
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    for (qsizetype i = 0; i < ui->plainTextEdit->toPlainText().length() - 1; ++i) {
        stream << ui->plainTextEdit->toPlainText().at(i);
    }
    file.close();
    PrintText();
}

inline void MainWindow::PrintText()
{
    QFile file{"ShcheperkoLab6"};
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString text;
    while (!stream.atEnd()) {
        text += stream.read(1);
    }
    file.close();
    ui->outputPlainTextEdit->setPlainText(text);
}

void MainWindow::EnterWritePrintArray()
{
    spaceNumber = 0;
    ui->plainTextEdit->clear();
    ui->outputPlainTextEdit->clear();
    ui->optionLabel->setEnabled(false);
    ui->optionLineEdit->setEnabled(false);
    ui->arraySizeLabel->show();
    ui->arraySizeLineEdit->show();
}

void MainWindow::WriteArrayToFileAndPrint()
{
    QFile file{"ShcheperkoLab6_0"};
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    QString text = ui->plainTextEdit->toPlainText();
    text.removeLast();
    QStringList numbers = text.split(' ');
    for (auto number : numbers) {
        stream << number + '\\';
    }
    file.close();
    PrintArray();
}

void MainWindow::PrintArray()
{
    QFile file{"ShcheperkoLab6_0"};
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString text;
    while (!stream.atEnd()) {
        QChar ch;
        stream >> ch;
        if (ch != '\\') {
            text += ch;
        } else {
            text += " ";
        }
    }
    file.close();
    ui->outputPlainTextEdit->setPlainText(text);
}

void MainWindow::EnterWritePrintSportTeamInfo()
{
    playersNumber = 0;
    ui->plainTextEdit->clear();
    ui->optionLabel->setEnabled(false);
    ui->optionLineEdit->setEnabled(false);
    ui->sportTeamInfoLabel->show();
    ui->ratingPositionLabel->show();
    ui->ratingPosLineEdit->show();
    ui->ratingPosLineEdit->setEnabled(true);
    ui->ratingPositionLabel->setEnabled(true);
    ui->winPercentageLineEdit->setEnabled(true);
    ui->winPercentageLabel->setEnabled(true);
    ui->divisionLineEdit->setEnabled(true);
    ui->divisionLabel->setEnabled(true);
    ui->nameAbbreviationLineEdit->setEnabled(true);
    ui->nameAbbreviationLabel->setEnabled(true);
    ;ui->nameAbbreviationLabel_2->setEnabled(true);
    ui->passedToChampionsLeagueLineEdit->setEnabled(true);
    ui->passedToChampionsLeagueLabel->setEnabled(true);
    ui->passedToChampionsLeagueLabel_2->setEnabled(true);
    ui->playerNumberLineEdit->setEnabled(true);
    ui->playerNumberLabel->setEnabled(true);
}

void MainWindow::WriteSportTeamInfoToFileAndPrint()
{
    QFile file{"ShcheperkoLab6_1"};
    file.open(QIODevice::Append);
    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    PrintSportTeamInfo();
}

void MainWindow::PrintSportTeamInfo()
{
    QFile file{"ShcheperkoLab6_1"};
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString text = "";
    while (!stream.atEnd()) {
        QChar ch;
        stream >> ch;
        if (ch != ' ') {
            text += ch;
        } else {
            text += "|";
        }
    }
    file.close();
    ui->outputPlainTextEdit->setPlainText(text);
}

void MainWindow::WriteSportTeamInfoToBinFileAndPrint()
{
    QFile file{"ShcheperkoLab6_2.bin"};
    file.open(QIODevice::Append);
    QDataStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();
    PrintBinSportTeamInfo();
}

void MainWindow::PrintBinSportTeamInfo()
{
    QFile file{"ShcheperkoLab6_2.bin"};
    file.open(QIODevice::ReadOnly);
    QDataStream stream(&file);
    QString text = "";
    while (!stream.atEnd()) {
        QChar ch;
        stream >> ch;
        if (ch != ' ') {
            text += ch;
        } else {
            text += ";";
        }
    }
    for (int i = 0; i < 100; ++i) {
        if (text.indexOf('\u0000') != -1 ) {
            text.removeAt(text.indexOf('\u0000') + 1);
            text.removeAt(text.indexOf('\u0000'));
        }
    }
    file.close();
    ui->outputPlainTextEdit->setPlainText(text);
}

void MainWindow::EnterWritePrintSentence()
{
    ui->plainTextEdit->clear();
    ui->outputPlainTextEdit->clear();
    ui->optionLabel->setEnabled(false);
    ui->optionLineEdit->setEnabled(false);
    ui->ratingPosLineEdit->setEnabled(true);
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit->setPlainText("Enter text here");
}

void MainWindow::WriteSentenceToFileAndPrint()
{
    QFile file{"ShcheperkoLab6_3"};
    file.open(QIODevice::Append);
    QTextStream stream(&file);
    QString text = ui->plainTextEdit->toPlainText();
    text.removeLast();
    if (file.size() == 0)
        stream << text;
    else
        stream << '\n' << text;
    file.close();
    PrintSentence();
}

void MainWindow::PrintSentence()
{
    QFile file{"ShcheperkoLab6_3"};
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString text;
    text = stream.readAll();
    file.close();
    ui->outputPlainTextEdit->setPlainText(text);
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString text = ui->plainTextEdit->toPlainText();
    switch (ui->optionLineEdit->text().toUShort()) {
    case 1:
        if (text.contains('\n')) {
            ui->plainTextEdit->setEnabled(false);
            ui->optionLabel->setEnabled(true);
            ui->optionLineEdit->setEnabled(true);
            WriteTextToFileAndPrint();
        }
        break;
    case 2:
        if (spaceNumber == ui->arraySizeLineEdit->text().toUShort() - 1) {
            ui->plainTextEdit->setEnabled(false);
            ui->plainTextEdit->setReadOnly(false);
            ui->optionLabel->setEnabled(true);
            ui->optionLineEdit->setEnabled(true);
            ui->arraySizeLabel->hide();
            ui->arraySizeLineEdit->hide();
            ui->arrayElementLineEdit->hide();
            ui->arrayElementLabel->hide();
            WriteArrayToFileAndPrint();
        }
        break;
    case 3:
        if (playersNumber == 10) {
            ui->sportTeamInfoLabel->hide();
            ui->ratingPosLineEdit->hide();
            ui->ratingPositionLabel->hide();
            ui->winPercentageLineEdit->hide();
            ui->winPercentageLabel->hide();
            ui->winPercentageLabel->hide();
            ui->divisionLineEdit->hide();
            ui->divisionLabel->hide();
            ui->passedToChampionsLeagueLineEdit->hide();
            ui->passedToChampionsLeagueLabel->hide();
            ui->passedToChampionsLeagueLabel_2->hide();
            ui->nameAbbreviationLineEdit->hide();
            ui->nameAbbreviationLabel->hide();
            ui->nameAbbreviationLabel_2->hide();
            ui->playerNumberLineEdit->hide();
            ui->playerNumberLabel->hide();
            ui->optionLabel->setEnabled(true);
            ui->optionLineEdit->setEnabled(true);
            WriteSportTeamInfoToFileAndPrint();
        }
        break;
    case 4:
        if (playersNumber == 10) {
            ui->sportTeamInfoLabel->hide();
            ui->ratingPosLineEdit->hide();
            ui->ratingPositionLabel->hide();
            ui->winPercentageLineEdit->hide();
            ui->winPercentageLabel->hide();
            ui->winPercentageLabel->hide();
            ui->divisionLineEdit->hide();
            ui->divisionLabel->hide();
            ui->passedToChampionsLeagueLineEdit->hide();
            ui->passedToChampionsLeagueLabel->hide();
            ui->passedToChampionsLeagueLabel_2->hide();
            ui->nameAbbreviationLineEdit->hide();
            ui->nameAbbreviationLabel->hide();
            ui->nameAbbreviationLabel_2->hide();
            ui->playerNumberLineEdit->hide();
            ui->playerNumberLabel->hide();
            ui->optionLabel->setEnabled(true);
            ui->optionLineEdit->setEnabled(true);
            WriteSportTeamInfoToBinFileAndPrint();
        }
    case 5:
        if (text.contains('\n')) {
            ui->plainTextEdit->setEnabled(false);
            ui->optionLabel->setEnabled(true);
            ui->optionLineEdit->setEnabled(true);
            WriteSentenceToFileAndPrint();
        }
        break;
    break;
    }
}

void MainWindow::on_arraySizeLineEdit_editingFinished()
{
    ui->arraySizeLabel->setEnabled(false);
    ui->arraySizeLineEdit->setEnabled(false);
    ui->plainTextEdit->setEnabled(true);
    ui->plainTextEdit->setReadOnly(true);
    ui->arrayElementLabel->show();
    ui->arrayElementLineEdit->show();
}

void MainWindow::on_arrayElementLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->arrayElementLineEdit->text() + " ");
    ++spaceNumber;
}

void MainWindow::on_ratingPosLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->ratingPosLineEdit->text() + ' ');
    ui->ratingPosLineEdit->setEnabled(false);
    ui->ratingPositionLabel->setEnabled(false);
    ui->winPercentageLineEdit->show();
    ui->winPercentageLabel->show();
}

void MainWindow::on_winPercentageLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->winPercentageLineEdit->text() + ' ');
    ui->winPercentageLineEdit->setEnabled(false);
    ui->winPercentageLabel->setEnabled(false);
    ui->divisionLineEdit->show();
    ui->divisionLabel->show();
}

void MainWindow::on_divisionLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->divisionLineEdit->text() + ' ');
    ui->divisionLineEdit->setEnabled(false);
    ui->divisionLabel->setEnabled(false);
    ui->nameAbbreviationLabel->show();
    ui->nameAbbreviationLabel_2->show();
    ui->nameAbbreviationLineEdit->show();
}

void MainWindow::on_nameAbbreviationLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->nameAbbreviationLineEdit->text() + ' ');
    ui->nameAbbreviationLabel->setEnabled(false);
    ui->nameAbbreviationLabel_2->setEnabled(false);
    ui->nameAbbreviationLineEdit->setEnabled(false);
    ui->passedToChampionsLeagueLineEdit->show();
    ui->passedToChampionsLeagueLabel->show();
    ui->passedToChampionsLeagueLabel_2->show();
}

void MainWindow::on_passedToChampionsLeagueLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->passedToChampionsLeagueLineEdit->text() + ' ');
    ui->passedToChampionsLeagueLineEdit->setEnabled(false);
    ui->passedToChampionsLeagueLabel->setEnabled(false);
    ui->passedToChampionsLeagueLabel_2->setEnabled(false);
    ui->playerNumberLabel->show();
    ui->playerNumberLineEdit->show();
}

void MainWindow::on_playerNumberLineEdit_editingFinished()
{
    ui->plainTextEdit->insertPlainText(ui->playerNumberLineEdit->text() + " ");
    ++playersNumber;
}

void MainWindow::on_winPercentageLineEdit_inputRejected()
{
    ui->winPercentageLimitLabel->show();
}

void MainWindow::on_winPercentageLineEdit_textChanged(const QString &arg1)
{
    if (arg1.toDouble() > 100.0) {
        ui->winPercentageLimitLabel->show();
    }
    else{
        ui->winPercentageLimitLabel->hide();
    }
}