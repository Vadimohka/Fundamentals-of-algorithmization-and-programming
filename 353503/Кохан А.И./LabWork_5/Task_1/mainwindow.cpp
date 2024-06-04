#include "mainwindow.h"
#include "ConstUI.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , timer(new QTimer)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(INDEX_START_WINDOW);
    initKeyboard();
    setKeyboard(0);
    connect(ui->startEdit, &PressOnKeyboard::keyPressed, this, &MainWindow::buttonPressed);
    connect(ui->startEdit, &PressOnKeyboard::keyReleased, this, &MainWindow::buttonReleased);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateInfo);
    textWork = new TextWork(&dictionary, &tranningText, ui);
    textWork->SetDictionary(0);
    textWork->GenerateText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    buttonSetWhiteColor();
    ui->stackedWidget->setCurrentIndex(INDEX_TRANNING_WINDOW);
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    ui->timeEdit->startTimer(0);
    ui->stackedWidget->setCurrentIndex(INDEX_START_WINDOW);
    ui->lcdAmountWords->display(0);
    ui->timeEdit->setTime(QTime(0, 0, 0));
    ui->inputTextEdit->setText("");
    ui->startEdit->setText("");
    amountWords = 0;
    errorInput = 0;
    amountSymbol = 0;
    ui->progressTextEdit->setText(ui->textEdit->toPlainText());
}

void MainWindow::updateInfo()
{
    ui->timeEdit->setTime(ui->timeEdit->time().addMSecs(SPEED_TIMER_EQUAL_1SECOND));
    passedTime = ui->timeEdit->time().hour() * ONE_HOUR_IN_SECONDS
                 + ui->timeEdit->time().minute() * ONE_MINUTE_IN_SECONDS
                 + ui->timeEdit->time().second();
    (passedTime > ONE_MINUTE_IN_SECONDS) ? ui->lcdAmountWords->display(
        qRound(static_cast<double>(amountWords) * ONE_MINUTE_IN_SECONDS / passedTime))
                                         : ui->lcdAmountWords->display(amountWords);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    localizationType = index;
    textWork->SetDictionary(index);
    setKeyboard(index);
    textWork->GenerateText();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    textWork->GenerateText();
}

void MainWindow::on_generateButton_clicked()
{
    textWork->GenerateText();
}

void MainWindow::on_startEdit_selectionChanged()
{
    if (!timer->isActive()) {
        timer->start(SPEED_TIMER_EQUAL_1SECOND);
    }
}
