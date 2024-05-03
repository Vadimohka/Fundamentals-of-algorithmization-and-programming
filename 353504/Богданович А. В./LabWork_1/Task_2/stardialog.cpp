#include "stardialog.h"
#include "ui_stardialog.h"

StarDialog::StarDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StarDialog)
{
    ui->setupUi(this);
}

StarDialog::~StarDialog()
{
    delete ui;
}


void StarDialog::on_buttonBox_accepted()
{
    int ch;
    QString t1 = ui->lineEdit->text();
    QString t2 = ui->lineEdit_2->text();
    bool isOk1, isOk2;
    int a = t1.toInt(&isOk1);
    int b = t2.toInt(&isOk2);


    if (!(isOk1 && isOk2) || a > 500 || b > 500 || a < 1 || b < 1) {
        a = 0;
        b = 0;
    }
    emit sendStarSignals(a, b);

    if (ui->radioButton->isChecked()) {
        ch = 5;
    } else if (ui->radioButton_2->isChecked()) {
        ch = 6;
    } else {
        ch = 8;
    }

    emit sendRBtnsSignal(ch);
}

