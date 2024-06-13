#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->file->setFocusPolicy(Qt::NoFocus);
    ui->comboBox->setFocusPolicy(Qt::NoFocus);
    ui->textEdit->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_activated(int index)
{

    key = new KeyBoard(ui->widget);
    connect(this, &MainWindow::textFromFile, key, &KeyBoard::setText);
    TypingStatistic* statistic = new TypingStatistic(ui->cor_percent, ui->words_minute, ui->current_time, ui->char_minute,ui->gridLayoutWidget);
    connect(key, &KeyBoard::characterTyped, statistic, &TypingStatistic::updateStatistics);
    connect(key, &KeyBoard::firstKeyPress, statistic, &TypingStatistic::startTimer);
    connect(key, &KeyBoard::realoadStatistic, statistic, &TypingStatistic::realoadStatistics);

    key->setFixedSize(ui->widget->size());
    key->setLineEdit(ui->textEdit);
    key->show();
    key->setFocus();
    statistic->update();

    switch(index){

    case 1:
        key->setLanguage(Belarus_lower_case, Belarus_upper_case);
        break;
    case 2:
        key->setLanguage(Germany_lower_case, Germany_upper_case);
        break;
    case 3:
        key->setLanguage(French_lower_case,French_upper_case);
        break;
    case 4:

        break;
    case 5:
        key->setLanguage(Arabian_lower_case, Arabian_upper_case);
        break;
    case 6:
        key->setLanguage(Hebrew_lower_case, Hebrew_upper_case);
        break;
    default:
        key->setText("Choose language");
        break;
    }

    key->setText(text);
    key->update();
    ui->widget->update();
}


void MainWindow::on_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open file", "", "(*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Problem to open file";
        }

        QTextStream in(&file);
        QString text = in.readAll();
        text12 = text;
        current_template = text;

        file.close();

        emit textFromFile(current_template);
    }
}


void MainWindow::on_pushButton_clicked()
{
    key->reloadtext();
}

