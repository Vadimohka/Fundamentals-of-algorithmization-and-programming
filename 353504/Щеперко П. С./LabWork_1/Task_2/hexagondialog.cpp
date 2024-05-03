#include "hexagondialog.h"
#include "ui_hexagondialog.h"

HexagonDialog::HexagonDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HexagonDialog)
{
    ui->setupUi(this);
}

HexagonDialog::~HexagonDialog()
{
    delete ui;
}

void HexagonDialog::on_buttonBox_accepted()
{
    QString a = ui->lineEdit->text();
    bool isCorrect;
    int b = a.toInt(&isCorrect);


    if (!isCorrect || b > 500 || b < 1) {
        b = 0;
    }
    emit sendHexagonSignals(b);
}

