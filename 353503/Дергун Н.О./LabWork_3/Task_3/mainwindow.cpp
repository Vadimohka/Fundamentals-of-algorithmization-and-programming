#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->inputSpinBox, SIGNAL(valueChanged(int)), SLOT(slotUpdateResult(int)));
    ui->resultLineEdit->setReadOnly(true);
    ui->inputSpinBox->setMaximum(INT_MAX);
    ui->inputSpinBox->setMinimum(INT_MIN);
    slotUpdateResult(0);
    QMessageBox::information(this, "Warning", "Given a number n whose decimal notation does not contain zeros. Get the number, written in the same numerals, but in the opposite order.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdateResult(int newValue)
{
    newValue = reverseFunc(newValue);
    ui->resultLineEdit->setText(QString::number(newValue));
}
