#include "rhombusdialog.h"
#include "ui_rhombusdialog.h"

RhombusDialog::RhombusDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RhombusDialog)
{
    ui->setupUi(this);
}

RhombusDialog::~RhombusDialog()
{
    delete ui;
}

void RhombusDialog::on_buttonBox_accepted()
{
    QString t1 = ui->lineEdit->text();
    QString t2 = ui->lineEdit_2->text();
    bool isOk1, isOk2;
    int a = t1.toInt(&isOk1);
    int b = t2.toInt(&isOk2);


    if (!(isOk1 && isOk2) || a > 1000 || b > 1000 || a < 1 || b < 1) {
        a = 0;
        b = 0;
    }
    emit sendRhombusSignals(a, b);
}

