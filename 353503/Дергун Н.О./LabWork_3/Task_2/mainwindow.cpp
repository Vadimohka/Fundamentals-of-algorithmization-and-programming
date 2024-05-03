#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->resultLineEdit->setReadOnly(true);
    connect(ui->nSpinBox, SIGNAL(valueChanged(int)), SLOT(slotShowResult()));
    connect(ui->mSpinBox, SIGNAL(valueChanged(int)), SLOT(slotShowResult()));
    slotShowResult();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowResult()
{
    quint32 m = ui->mSpinBox->value();
    quint32 n = ui->nSpinBox->value();
    qint32 tempResult = func_.Evaluate(m, n);
    if (tempResult == -1)
    {
        ui->mSpinBox->setValue(0);
        ui->nSpinBox->setValue(0);
        QMessageBox::critical(nullptr, "Stack Overflow", "The stack is on the verge of overflowing with "
                                                       + QString::number(func_.maxRinningFunc())
                                                       + " functions already on it. The computation process has been halted to prevent overflow.");
        ui->resultLineEdit->setText(QString::number(1));
    }
    else if (tempResult == -2)
    {
        ui->resultLineEdit->setText("Probably something very large or 65533");
    }
    else
    {
        ui->resultLineEdit->setText(QString::number(tempResult));
    }
}

