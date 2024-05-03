#include "rectangledialog.h"
#include "ui_rectangledialog.h"

RectangleDialog::RectangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RectangleDialog)
{
    ui->setupUi(this);
}

RectangleDialog::~RectangleDialog()
{
    delete ui;
}

void RectangleDialog::on_buttonBox_accepted()
{
    QString t1 = ui->lineEdit->text();
    QString t2 = ui->lineEdit_2->text();
    bool isOk1, isOk2;
    int a = t1.toInt(&isOk1);
    int b = t2.toInt(&isOk2);


    if (!(isOk1 && isOk2) || a > 1000 || b > 850 || a < 1 || b < 1) {
        a = 0;
        b = 0;
    }
    emit sendRectangleSignals(a, b);
}

