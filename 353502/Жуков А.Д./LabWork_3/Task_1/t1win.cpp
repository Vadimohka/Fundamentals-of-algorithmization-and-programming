#include "t1win.h"
#include "ui_t1win.h"

T1Win::T1Win(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::T1Win)
{
    ui->setupUi(this);
}

T1Win::~T1Win()
{
    delete ui;
}

void T1Win::on_button_convert_clicked()
{
    bool ok = false;
    ui->decimalInput->text().toDouble(&ok);
    if (!ok) { return; }

    QString bin = "";
    ToBinary(ui->decimalInput->text(), bin);
    ui->binaryText->setText(bin);

    if (ui->binaryText->text().length() >= 20)
    {
        ui->binaryText->setText(ui->binaryText->text().insert(20, ' '));
    }
    if (ui->binaryText->text().length() >= 40)
    {
        ui->binaryText->setText(ui->binaryText->text().insert(41, ' '));
    }
}

void T1Win::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
}


void T1Win::ToBinary(QString dec, QString & bin)
{
    if (dec != "0")
    {
        if (bin == "" && dec.indexOf(".") != -1 && dec.indexOf(".") + 1 != dec.length())
        {
            bin.append(".");
            SixDigiysAfterPoint(dec, bin, 0);
        }

        QChar digit = (long long)dec.toDouble() % 2 == 0 ? '0' : '1';
        dec = QString::number((long long)dec.toDouble()/2);
        bin.prepend(digit);

        ToBinary(dec, bin);
    }
}

void T1Win::SixDigiysAfterPoint(QString dec, QString & bin, short c)
{
    if (c != ui->horizontalSlider->value())
    {
        double digits = dec.toDouble() - (long long)dec.toDouble();
        bin.append((long long)(digits * 2) == 1 ? "1" : "0");
        c++;

        SixDigiysAfterPoint(QString::number(digits * 2), bin, c);
    }
}
