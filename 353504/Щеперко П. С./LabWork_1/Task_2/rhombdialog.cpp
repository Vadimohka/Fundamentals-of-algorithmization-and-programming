#include "rhombdialog.h"
#include "ui_rhombdialog.h"

RhombDialog::RhombDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RhombDialog)
{
    ui->setupUi(this);
}

RhombDialog::~RhombDialog()
{
    delete ui;
}

void RhombDialog::on_buttonBox_accepted()
{
    QString t1 = ui->lineEdit->text();
    QString t2 = ui->lineEdit_2->text();
    bool isCorrect1, isCorrect2;
    int a = t1.toInt(&isCorrect1);
    int b = t2.toInt(&isCorrect2);


    if (!(isCorrect1 && isCorrect2) || a > 1000 || b > 1000 || a < 1 || b < 1) {
        a = 0;
        b = 0;
    }
    emit sendRhombSignals(a, b);
}

