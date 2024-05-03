#include "trapezoiddialog.h"
#include "ui_trapezoiddialog.h"

TrapezoidDialog::TrapezoidDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrapezoidDialog)
{
    ui->setupUi(this);
}

TrapezoidDialog::~TrapezoidDialog()
{
    delete ui;
}

void TrapezoidDialog::on_buttonBox_accepted()
{
    QString t1 = ui->lineEdit->text();
    QString t2 = ui->lineEdit_2->text();
    QString t3 = ui->lineEdit_3->text();

    bool isOk1, isOk2, isOk3;
    int a = t1.toInt(&isOk1);
    int b = t2.toInt(&isOk2);
    int h = t3.toInt(&isOk3);


    if (!(isOk1 && isOk2 && isOk3) || a > 1000 || b > 1000 || h > 850 || a < 1 || b < 1 || h < 1) {
        a = 0;
        b = 0;
        h = 0;
    }
    emit sendTrapezoidSignals(a, b, h);
}

