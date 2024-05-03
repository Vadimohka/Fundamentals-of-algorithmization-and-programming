#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr short FIRST_TWO_DIGIT_NUMBER = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long MainWindow::reverseNumber(long long inputNumber, long long answerNumber = 0) {
    return inputNumber == 0 ? answerNumber : reverseNumber(inputNumber / FIRST_TWO_DIGIT_NUMBER,
                                                           answerNumber * FIRST_TWO_DIGIT_NUMBER + inputNumber % FIRST_TWO_DIGIT_NUMBER);
}

void MainWindow::on_answerButton_clicked()
{
    ui->answerLineEdit->setText(QString::number(reverseNumber(ui->inputSpinBox->value())));
}

