#include "squaredialog.h"
#include "ui_squaredialog.h"

SquareDialog::SquareDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SquareDialog)
{
    ui->setupUi(this);
}

SquareDialog::~SquareDialog()
{
    delete ui;
}

void SquareDialog::on_buttonBox_accepted()
{
    QString a = ui->lineEdit->text();
    bool isCorrect;
    int b = a.toInt(&isCorrect);


    if (!isCorrect || b > 1000 || b < 1) {
        b = 0;
    }
    emit sendSquareSignals(b);
}

