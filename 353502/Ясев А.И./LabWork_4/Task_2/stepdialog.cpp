#include "stepdialog.h"
#include "ui_stepdialog.h"

StepDialog::StepDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StepDialog)
{
    ui->setupUi(this);
}

StepDialog::~StepDialog()
{
    delete ui;
}

void StepDialog::set(QVector<int> vector)
{
    ui->listWidget->clear();
    foreach (int i, vector) {
        ui->listWidget->addItem(QString::number(i));
    }
}
