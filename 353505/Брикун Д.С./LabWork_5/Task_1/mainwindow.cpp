#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QFile>
#include <QRandomGenerator>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_49->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_10->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_11->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_12->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_13->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_14->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_15->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_16->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_17->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_18->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_19->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_20->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_21->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_24->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_25->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_26->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_27->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_28->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_29->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_30->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_31->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_32->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_33->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_34->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_35->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_51->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_66->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_38->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_39->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_40->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_41->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_42->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_43->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_44->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_45->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_46->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_47->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_48->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_50->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_52->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_53->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_54->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_55->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_56->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_57->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_58->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_59->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_60->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_61->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_62->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    ui->pushButton_65->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    initSymbols();
    connect(ui->lineEdit_in, &LineEditInput::keyPressed, this, &MainWindow::buttonClicked);
    connect(ui->lineEdit_in, &LineEditInput::keyReleased, this, &MainWindow::buttonReleased);
    // connect(qApp->inputMethod(), &QInputMethod::localeChanged, this, &MainWindow::myslot);
    initDictionaryes();
    curLocale = qApp->inputMethod()->locale().name();
/*    if (curLocale == "")  curLocaleNum = 0;
    else if (curLocale == "")  curLocaleNum = 1;
    else if (curLocale == "")  curLocaleNum = 2;
    else if (curLocale == "")  curLocaleNum = 3;
    else if (curLocale == "")  curLocaleNum = 4;
    else if (curLocale == "")  curLocaleNum = 5;
    else     */
    changedLocale();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(int code, bool proc)
{
    qDebug() << code;
    if (ui->textEdit_in->toPlainText().size() >= ui->textEdit_test->toPlainText().size()) return;
    static QPushButton * aa[]
        {nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            ui->pushButton_10,
            ui->pushButton_11,
            ui->pushButton_12,
            ui->pushButton_13,
            ui->pushButton_14,
            ui->pushButton_15,
            ui->pushButton_16,
            ui->pushButton_17,
            ui->pushButton_18,
            ui->pushButton_19,
            ui->pushButton_20,
            ui->pushButton_21,
            nullptr,
            nullptr,
            ui->pushButton_24,
            ui->pushButton_25,
            ui->pushButton_26,
            ui->pushButton_27,
            ui->pushButton_28,
            ui->pushButton_29,
            ui->pushButton_30,
            ui->pushButton_31,
            ui->pushButton_32,
            ui->pushButton_33,
            ui->pushButton_34,
            ui->pushButton_35,
            nullptr,
            nullptr
            ,
            ui->pushButton_38,
            ui->pushButton_39,
            ui->pushButton_40,
            ui->pushButton_41,
            ui->pushButton_42,
            ui->pushButton_43,
            ui->pushButton_44,
            ui->pushButton_45,
            ui->pushButton_46,
            ui->pushButton_47,
            ui->pushButton_48,
            ui->pushButton_49,
            ui->pushButton_50,
            ui->pushButton_51,
            ui->pushButton_52,
            ui->pushButton_53,
            ui->pushButton_54,
            ui->pushButton_55,
            ui->pushButton_56,
            ui->pushButton_57,
            ui->pushButton_58,
            ui->pushButton_59,
            ui->pushButton_60,
            ui->pushButton_61,
            ui->pushButton_62,
            nullptr,
            nullptr,
            ui->pushButton_65,
            ui->pushButton_66
        };

    if (proc){

    if (ui->lineEdit_in->text().size()!=0&&ui->lineEdit_in->text().back() == ui->lineEdit_test->text().front()){
            QString aa(ui->lineEdit_in->text().back());
            ++symbols;
            if (ui->lineEdit_test->text().front() == ' '){
                ++words;
                ui->label_speed->setText(QString::number((60. * words) / (seconds + 1)));
            }
            if (aa == " ") ui->textEdit_in->insertHtml("<span style='background-color: rgba(0, 128, 0, 0.5);'>&nbsp;</span>");
                else ui->textEdit_in->insertHtml("<font color='green'>" + aa +"</font>");
            ++symbolsOk;
                auto text1 = ui->lineEdit_test->text();
                text1.remove(0, 1);
                ui->lineEdit_test->setText(text1);
                addTextToLineEdit();
                ui->label_acc->setText(QString::number(100. * symbolsOk / symbols) + " %");
                if(ui->lineEdit_test->text() == ""){
                    on_pushButton_stop_clicked();
                    QMessageBox::information(nullptr, "Information", "Finish input.");
                }
        }
        else{
            ++symbols;
            ui->label_acc->setText(QString::number(100. * symbolsOk / symbols) + " %");
        }

    }
    if (code == -1) return;
    if(code < 67 && aa[code - 1] != nullptr && aa[code - 1]) {
        if (code == 66){
            caps = !caps;
            if (caps) aa[code - 1]->setStyleSheet("QPushButton:disabled {background-color: yellow;color: #000000;}");
                else aa[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
            setSymbols();
        } else if (code == 50 || code == 62){
            aa[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: yellow;color: #000000;}");
            aa[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: yellow;color: #000000;}");
            shift = true;
            setSymbols();
        } else
            aa[code - 1]->setStyleSheet("QPushButton:disabled {background-color: yellow;color: #000000;}");
    }
    if(ui->lineEdit_test->text() == "" || ui->lineEdit_in->isReadOnly()){
        buttonReleased(code);
    }
}

void MainWindow::buttonReleased(int code)
{
    static QPushButton * aa[]
        {nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            ui->pushButton_10,
            ui->pushButton_11,
            ui->pushButton_12,
            ui->pushButton_13,
            ui->pushButton_14,
            ui->pushButton_15,
            ui->pushButton_16,
            ui->pushButton_17,
            ui->pushButton_18,
            ui->pushButton_19,
            ui->pushButton_20,
            ui->pushButton_21,
            nullptr,
            nullptr,
            ui->pushButton_24,
            ui->pushButton_25,
            ui->pushButton_26,
            ui->pushButton_27,
            ui->pushButton_28,
            ui->pushButton_29,
            ui->pushButton_30,
            ui->pushButton_31,
            ui->pushButton_32,
            ui->pushButton_33,
            ui->pushButton_34,
            ui->pushButton_35,
            nullptr,
            nullptr,
            ui->pushButton_38,
            ui->pushButton_39,
            ui->pushButton_40,
            ui->pushButton_41,
            ui->pushButton_42,
            ui->pushButton_43,
            ui->pushButton_44,
            ui->pushButton_45,
            ui->pushButton_46,
            ui->pushButton_47,
            ui->pushButton_48,
            ui->pushButton_49,
            ui->pushButton_50,
            ui->pushButton_51,
            ui->pushButton_52,
            ui->pushButton_53,
            ui->pushButton_54,
            ui->pushButton_55,
            ui->pushButton_56,
            ui->pushButton_57,
            ui->pushButton_58,
            ui->pushButton_59,
            ui->pushButton_60,
            ui->pushButton_61,
            ui->pushButton_62,
            nullptr,
            nullptr,
            ui->pushButton_65,
            ui->pushButton_66
        };
    if(code < 67 && aa[code - 1] != nullptr && aa[code - 1]) {
        if (code != 66){
            if (code == 50 || code == 62){
                aa[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
                aa[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
                shift = false;
                setSymbols();
            } else
                aa[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
        }
    }
}

void MainWindow::changedLocale(){
    QMessageBox::information(nullptr, "Information", "Please remember to change your keybord according to combobox.");
    setSymbols();
    on_pushButton_clicked();
}

void MainWindow::setSymbols(){


    static QPushButton * aa[]
        {nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            ui->pushButton_10,
            ui->pushButton_11,
            ui->pushButton_12,
            ui->pushButton_13,
            ui->pushButton_16,
            ui->pushButton_16,
            ui->pushButton_16,
            ui->pushButton_17,
            ui->pushButton_18,
            ui->pushButton_19,
            ui->pushButton_20,
            ui->pushButton_21,
            nullptr,
            nullptr,
            ui->pushButton_24,
            ui->pushButton_25,
            ui->pushButton_26,
            ui->pushButton_27,
            ui->pushButton_28,
                             ui->pushButton_29,
            ui->pushButton_30,
            ui->pushButton_31,
            ui->pushButton_32,
            ui->pushButton_33,
            ui->pushButton_34,
            ui->pushButton_35,
            nullptr,
            nullptr
                             ,
            ui->pushButton_38,
            ui->pushButton_39,
            ui->pushButton_40,
            ui->pushButton_41,
            ui->pushButton_42,
            ui->pushButton_43,
            ui->pushButton_44,
            ui->pushButton_45,
            ui->pushButton_46,
            ui->pushButton_47,
            ui->pushButton_48,
            ui->pushButton_49,
            ui->pushButton_50,
            ui->pushButton_51,
            ui->pushButton_52,
            ui->pushButton_53,
            ui->pushButton_54,
            ui->pushButton_55,
            ui->pushButton_56,
                             ui->pushButton_57,
            ui->pushButton_58,
            ui->pushButton_59,
            ui->pushButton_60,
            ui->pushButton_61,
            ui->pushButton_62,
            nullptr,
            nullptr,
            ui->pushButton_65,
            ui->pushButton_66
        };
    int index;
    if (!caps && !shift) index = 0;
    if (!caps && shift) index = 1;
    if (caps && !shift) index = 2;
    if (caps && shift) index = 3;
    for (int  i = 0; i < 66; ++i) {
        if(aa[i] != nullptr && aa[i]) {
            aa[i]->setText(textKeys[curLocaleNum][index][i + 1]);
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    curLocaleNum = index;
    changedLocale();
}

void MainWindow::initDictionaryes(){
    QString line;
    dictionary.resize(7);
    {
        QFile file("/home/daniil/lab/test/dic/deu.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файа";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[0].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/fra.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[1].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/ara.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[2].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/eng.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[3].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/bel.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[4].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/her.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[5].push_back(line);
        }
        file.close();
    }
    {
        QFile file("/home/daniil/lab/test/dic/chn.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Ошибка открытия файла";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            dictionary[6].push_back(line);
        }
        file.close();
    }

}

void MainWindow::generateText()
{
    ui->textEdit_test->setText("Test:\n");
    ui->lineEdit_test->setText("");
    ui->textEdit_in->setText("");
    ui->lineEdit_in->setText("");
    testText.clear();
    int n = ui->spinBox->value(), m = dictionary[curLocaleNum].size();
    if (n > 0){
        testText.push_back(dictionary[curLocaleNum][QRandomGenerator::global()->bounded(0, m)]);
        ui->textEdit_test->setText(ui->textEdit_test->toPlainText() + testText.back());
    }

    for (int i = 1; i < n; ++i) {
        testText.push_back(dictionary[curLocaleNum][QRandomGenerator::global()->bounded(0, m)]);
        ui->textEdit_test->setText(ui->textEdit_test->toPlainText() + " " + testText.back());
    }
    addTextToLineEdit();
}

void MainWindow::addTextToLineEdit(){
    auto text = ui->lineEdit_test->text();
    int spaces = 0, sp = 0;
    for (auto i : text) {
        if (i == ' ') ++spaces;
    }
    if (spaces < 2){
        if (!testText.isEmpty()){
            if (ui->lineEdit_test->text().isEmpty())
                ui->lineEdit_test->setText(testText.front());
            else
                ui->lineEdit_test->setText(ui->lineEdit_test->text() + " " + testText.front());
            testText.pop_front();
            addTextToLineEdit();
        }
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_clicked()
{
    generateText();
    ui->pushButton_start->setEnabled(true);
}

void MainWindow::on_pushButton_start_clicked()
{
    on_pushButton_stop_clicked();
    ui->lineEdit_in->setReadOnly(false);
    seconds = 0;
    timer->setInterval(1000);
    timer->start();
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
    ui->pushButton_start->setEnabled(false);
    ui->pushButton_stop->setEnabled(true);
    words = 0;
    symbols = 0;
    symbolsOk = 0;
}

void MainWindow::updateTimer()
{
    ++seconds;
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
}

void MainWindow::on_pushButton_stop_clicked()
{
    if (ui->pushButton_stop->isEnabled()){
        ++words;
        ui->label_speed->setText(QString::number((60. * words) / (seconds + 1)));
        timer->stop();
        ui->lineEdit_in->setReadOnly(true);
        ui->pushButton_stop->setEnabled(false);
    }
}


void MainWindow::on_pushButton_open_clicked()
{
    on_pushButton_stop_clicked();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile file(fileName);
    QTextStream in(&file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd()){
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    ui->pushButton_start->setEnabled(true);
    ui->textEdit_test->setText("Test:\n");
    ui->lineEdit_test->setText("");
    ui->textEdit_in->setText("Your input:\n");
    ui->lineEdit_in->setText("");
    testText.clear();

    testText.push_back(in.readLine());
    ui->textEdit_test->setText(ui->textEdit_test->toPlainText() + testText.back());
    while (!in.atEnd())
    {
        testText.push_back(in.readLine());
        ui->textEdit_test->setText(ui->textEdit_test->toPlainText() + " " + testText.back());
    }
    addTextToLineEdit();
    file.close();
}

