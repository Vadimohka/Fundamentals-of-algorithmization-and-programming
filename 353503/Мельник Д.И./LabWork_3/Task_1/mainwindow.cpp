#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow), _translation(new Translation())
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    _currentNumber = arg1;
}

void MainWindow::on_pushButton_clicked()
{
    QString answer = _translation->TranslationToIEEE754(_currentNumber);
    _ui->label_3->setText(answer);
}

