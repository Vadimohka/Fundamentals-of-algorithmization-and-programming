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
    bool isOk;
    int b = a.toInt(&isOk);


    if (!isOk || b > 500 || b < 1) {
        b = 0;
    }
    emit sendHexagonSignals(b);
}

