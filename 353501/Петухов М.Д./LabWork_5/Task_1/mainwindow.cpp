#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit_input, &InputManager::keyPressed, this, &MainWindow::buttonPressed);
    connect(ui->lineEdit_input, &InputManager::keyReleased, this, &MainWindow::buttonReleased);

//////////////////////////////////////////

    connect(ui->pushButton_reset, &QPushButton::clicked, this, &MainWindow::on_pushButton_reset_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &MainWindow::on_pushButton_stop_clicked);
    connect(ui->pushButton_open, &QPushButton::clicked, this, &MainWindow::on_pushButton_open_clicked);

    ui->pushButton_10_1->setStyleSheet("background-color: #f0f0f0;color: #000000");
    ui->pushButton_10_2->setStyleSheet("background-color: #f0f0f0;color: #000000");

    /*initKeyboard();
    setKeyboard(0);
    textManager = new TextManager(&dictionary, &trainingText, ui);
    textManager->SetDictionary(0);*/
    ui->stackedWidget->setCurrentIndex(0);
    initSymbolsOfAlphabet();
    initKeyboard();

    ui->comboBox->setCurrentIndex(0);
    setLanguage();
    //on_pushButton_reset_clicked();

    initDictionaryes();

    ui->pushButton_start->setEnabled(false);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

void MainWindow::on_pushButton_reset_clicked(){
    for(int i = 0; i < keyboard.size(); i++){
        keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
    }
    ui->lineEdit_input->setEnabled(true);
    setLanguage();
    generateText();
/////
    
/////    ////
    ui->pushButton_start->setEnabled(true);

    words = 0;
    incorrectPresses = 0;
    correctPresses = 0;

}


void MainWindow::updateTimer()
{
    ++seconds;
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
    ui->labelSpeed->setText(QString::number((60. * words) / (seconds + 1)));
}

void MainWindow::setLanguage(){
    if(ui->comboBox->currentIndex() != 7){
        lanIndex = ui->comboBox->currentIndex();
        for(int i = 0; i < 33; i++){
            keyboard[i]->setText(simvols[lanIndex].at(i*2));
        }
    }
    else{
        for(int i = 0; i < 33; i++){
            keyboard[i]->setText(simvols[0].at(i*2));
        }
    }

}

void MainWindow::initKeyboard(){
    keyboard.resize(34);
    keyboard[0] = ui->pushButton_1;
    keyboard[1] = ui->pushButton_2;
    keyboard[2] = ui->pushButton_3;
    keyboard[3] = ui->pushButton_4;
    keyboard[4] = ui->pushButton_5;
    keyboard[5] = ui->pushButton_6;
    keyboard[6] = ui->pushButton_7;
    keyboard[7] = ui->pushButton_8;
    keyboard[8] = ui->pushButton_9;
    keyboard[9] = ui->pushButton_10;
    keyboard[10] = ui->pushButton_10_1;
    keyboard[11] = ui->pushButton_10_2;
    keyboard[12] = ui->pushButton_11;
    keyboard[13] = ui->pushButton_12;
    keyboard[14] = ui->pushButton_13;
    keyboard[15] = ui->pushButton_14;
    keyboard[16] = ui->pushButton_15;
    keyboard[17] = ui->pushButton_16;
    keyboard[18] = ui->pushButton_17;
    keyboard[19] = ui->pushButton_18;
    keyboard[20] = ui->pushButton_19;
    keyboard[21] = ui->pushButton_20;
    keyboard[22] = ui->pushButton_21;
    keyboard[23] = ui->pushButton_22;
    keyboard[24] = ui->pushButton_23;
    keyboard[25] = ui->pushButton_24;
    keyboard[26] = ui->pushButton_25;
    keyboard[27] = ui->pushButton_26;
    keyboard[28] = ui->pushButton_27;
    keyboard[29] = ui->pushButton_28;
    keyboard[30] = ui->pushButton_29;
    keyboard[31] = ui->pushButton_30;
    keyboard[32] = ui->pushButton_31;
    keyboard[33] = ui->pushButton_32;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDictionaryes(){
    QString line;
    dictionary.resize(7);
    {
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/english.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/german.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/french.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/hebrew.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/arabic.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/chinese.txt");
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
        QFile file("/home/__maks__/LabWork_5/My_Task_1/dictionary/belarusian.txt");
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
    if(ui->comboBox->currentIndex() != 7){
        ui->textEdit_input->setText("");
        int n = ui->spinBox->value(), m = dictionary[lanIndex].size();

            if (n > 0){
            testText.push_back(dictionary[lanIndex][QRandomGenerator::global()->bounded(0, m)]);
            ui->textEdit_input->setText(ui->textEdit_input->toPlainText() + testText.back());
        }

        for (int i = 1; i < n; ++i) {
            testText.push_back(dictionary[lanIndex][QRandomGenerator::global()->bounded(0, m)]);
            ui->textEdit_input->setText(ui->textEdit_input->toPlainText() + " " + testText.back());
        }
        currentText = ui->textEdit_input->toPlainText();
        qDebug() << currentText;
    }
    else{
        ui->textEdit_input->setText("话电话电电脑");
        currentText = ui->textEdit_input->toPlainText();
    }
}


void MainWindow::on_pushButton_start_clicked()
{
    for(int i = 0; i < keyboard.size(); i++){
        keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
    }
    ui->lineEdit_input->setEnabled(true);
    setLanguage();
    timer->setInterval(1000);
    timer->start();
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
    ui->lineEdit_input->setReadOnly(false);
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_input->setKeyboardInInputManager(keyboard, currentText, ui->comboBox->currentIndex(), 
                                                        SIMVOLS, simvols);

    correctPresses = 0; 
    incorrectPresses = 0;
    words = 0;

    ui->correctSymbolsLabel->setText(QString::number(correctPresses));
    ui->incorrectSymbolsLabel->setText(QString::number(incorrectPresses));
    ui->wordLabel->setText(QString::number(words));
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
    ui->pushButton_start->setEnabled(false);
    ui->lineEdit_input->numSimvol = 0;
    ui->lineEdit_input->chineseWritenWords.resize(0);
    currentText.clear();
    ui->lineEdit_input->setText("");
    ui->textEdit_input->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_open_clicked()
{
    on_pushButton_stop_clicked();
    
    QString fileName = QFileDialog::getOpenFileName(this, QMessageBox::tr("Open"), QMessageBox::tr("Text Documents (*.txt)"));
    QFile file(fileName);


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);

    if (in.atEnd()){
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    while (!in.atEnd())
    {
        currentText.push_back(in.readLine());
    }
    ui->pushButton_start->setEnabled(true);
    ui->textEdit_input->setText(ui->textEdit_input->toPlainText() + currentText);
    file.close();
}
