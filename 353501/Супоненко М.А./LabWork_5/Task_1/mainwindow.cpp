#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit_input, &Input::keyPressed, this, &MainWindow::buttonPressed);
    connect(ui->lineEdit_input, &Input::keyReleased, this, &MainWindow::buttonReleased);

    connect(ui->pushButton_reset, &QPushButton::clicked, this, &MainWindow::reset);

    ui->pushButton_10_1->setStyleSheet("background-color: #f0f0f0;color: #000000");
    ui->pushButton_10_2->setStyleSheet("background-color: #f0f0f0;color: #000000");

    ui->stackedWidget->setCurrentIndex(0);
    initializeAlphabet();

    ui->comboBox->setCurrentIndex(0);
    selectLanguage();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

void MainWindow::reset()
{
    for(int i = 0; i < keyboard.size(); i++){
        keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
    }
    ui->lineEdit_input->setEnabled(true);
    selectLanguage();
    generateText();

    ui->pushButton_start->setEnabled(true);

    letters = 0;
    incorrectPresses = 0;
    correctPresses = 0;
}

void MainWindow::updateTimer()
{
    ++seconds;
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
    ui->labelSpeed->setText(QString::number((60. * letters) / (seconds + 1)));
}

void MainWindow::selectLanguage()
{
    if(ui->comboBox->currentIndex() != 7){
        languageIndex = ui->comboBox->currentIndex();
        for(int i = 0; i < 33; i++){
            keyboard[i]->setText(symbols[languageIndex].at(i*2));
        }
    }
    else{
        for(int i = 0; i < 33; i++){
            keyboard[i]->setText(symbols[0].at(i*2));
        }
    }
}

void MainWindow::initializeKeyboard()
{
    keyboard.resize(34);
    keyboard[0] = ui->pushButton_1;
    keyboard[1] = ui->pushButton_2;
}

void MainWindow::initializeAlphabet()
{
    symbols.resize(7);
    symbols[0] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    symbols[1] = "abcdefghijklmnopqrstuvwxyz";
    
}

void MainWindow::generateText()
{
}
bool correctCurrent;

void MainWindow::buttonPressed(int code, bool correct, int &numSymbol)
{
    if(correct){
        QTextCursor cursor = ui->textEdit_input->textCursor();
        cursor.setPosition(numSymbol);
        cursor.setPosition(++numSymbol, QTextCursor::KeepAnchor);
        QTextCharFormat format;
        format.setForeground(Qt::green);
        cursor.setCharFormat(format);

        ++correctPresses;
        ui->correctSymbolsLabel->setText(QString::number(correctPresses));

        if(code == -1){
            ++letters;
            ui->wordLabel->setText(QString::number(letters));
        }
    }
    else{
        ++incorrectPresses;
        ui->incorrectSymbolsLabel->setText(QString::number(incorrectPresses));
    }

    if(numSymbol == ui->textEdit_input->toPlainText().length()){
        numSymbol = 0;
        timer->stop();
        ui->pushButton_start->setEnabled(false);
        ui->lineEdit_input->setEnabled(false);
        for(int i = 0; i < keyboard.size(); i++){
            keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
        }
    }
}

void MainWindow::buttonReleased(int code)
{
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDictionaries()
{
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
    switch (ui->comboBox->currentIndex()) {
        case 1:{
             ui->textEdit_input->setText("Hefsdfeggkdopgherj jkn n");
           currentText = ui->textEdit_input->toPlainText();
        }
        
        case 2:{
             ui->textEdit_input->setText("iotskhdipats tsatlushtsdeapuk I bpalk upzh");
           currentText = ui->textEdit_input->toPlainText();
        }

           case 3:{
             ui->textEdit_input->setText("akuatsupofjbya'puk mvyltseimkutoleautseivm r");
           currentText = ui->textEdit_input->toPlainText();
        }

           case 4:{
             ui->textEdit_input->setText("לפני חמש שנאמא שלי ני חזרנו לצ'או דוק");
           currentText = ui->textEdit_input->toPlainText();
        }

           case 5:{
             ui->textEdit_input->setText("مساعدة لا أعرف لذلك أنا سعيد معك سيد فلاديمتسيف");
           currentText = ui->textEdit_input->toPlainText();
        }

           case 6:{
             ui->textEdit_input->setText("дапамажыце, спадар Уладзімцячэў, я так задаволены вамі");
           currentText = ui->textEdit_input->toPlainText();
        }

           case 7:{
             ui->textEdit_input->setText("话电话电电脑");
           currentText = ui->textEdit_input->toPlainText();
        }
    }
}

void MainWindow::on_pushButton_start_clicked()
{
    reset();

    timer->setInterval(1000);
    timer->start();
    QString time = QString::number(seconds / 60) + ":" + QString::number(seconds % 60, 'g', 2);
    ui->timerLabel->setText(time);
    ui->lineEdit_input->setReadOnly(false);
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit_input->setKeyboardInInputManager(keyboard, currentText, ui->comboBox->currentIndex(), SYMBOLS, symbols);

    correctPresses = 0;
    incorrectPresses = 0;
    letters = 0;

    ui->correctSymbolsLabel->setText(QString::number(correctPresses));
    ui->incorrectSymbolsLabel->setText(QString::number(incorrectPresses));
    ui->wordLabel->setText(QString::number(letters));
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
    ui->pushButton_start->setEnabled(false);
    ui->lineEdit_input->numSymbol = 0;
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
        QMessageBox::critical(0, tr("Error"), tr("Invalid file data format"), QMessageBox::Ok|QMessageBox::NoButton);
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

