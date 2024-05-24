#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTick);
    connect(ui->lineEdit_input, &InputManager::keyPressed, this, &MainWindow::buttonPressed);
    connect(ui->lineEdit_input, &InputManager::keyReleased, this, &MainWindow::buttonReleased);
    initKeyboard();
    setKeyboard(0);
    textManager = new TextManager(&dictionary, &trainingText, ui);
    textManager->SetDictionary(0);
    on_pushButton_reset_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    timer->start(1000);
    ui->lineEdit_input->setReadOnly(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
    ui->textEdit_input->setText("");
    ui->lineEdit_input->setText("");
    ui->label_elapsed_value->setText("00:00");
    ui->lineEdit_input->setReadOnly(true);
    words = 0;
    symbols = 0;
    correctSymbols = 0;
    seconds = 0;
    ui->stackedWidget->setCurrentIndex(0);
    on_pushButton_reset_clicked();
}

void MainWindow::on_pushButton_load_clicked()
{
    on_pushButton_stop_clicked();
    textManager->LoadTest();
}

void MainWindow::on_pushButton_reset_clicked()
{
    textManager->Generate();
    ui->pushButton_start->setEnabled(true);
}

void MainWindow::timerTick()
{
    ++seconds;
    ui->label_elapsed_value->setText((seconds / 60 > 9 ? QString::number(seconds / 60) : "0" + QString::number((seconds / 60))) + ":"
                                     + (seconds % 60 > 9 ? QString::number(seconds % 60) : "0" + QString::number((seconds % 60))));
    ui->label_wpm_value->setText(QString::number((60. * words) / (seconds + 1)));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    locale = index;
    textManager->SetDictionary(locale);
    setKeyboard(locale);
    on_pushButton_reset_clicked();
}

void MainWindow::on_spinBox_valueChanged(int)
{
    on_pushButton_reset_clicked();
}
