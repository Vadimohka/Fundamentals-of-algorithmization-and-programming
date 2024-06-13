#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QIntValidator *intV = new QIntValidator();
    ui->codeLineEdit->setValidator(intV);
    ui->countLineEdit->setValidator(intV);
    QDoubleValidator *dV = new QDoubleValidator();
    ui->priceLineEdit->setValidator(dV);
}

Dialog::~Dialog()
{
    delete ui;
}

Good Dialog::getGood()
{
    if (ui->codeLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty() || ui->priceLineEdit->text().isEmpty() || ui->countLineEdit->text().isEmpty()){
        return Good();
    }
    QString from = "";
    from.append(QString::number(ui->comboBox->currentIndex())).append("-");
    from.append(ui->codeLineEdit->text()).append("-");
    from.append(ui->nameLineEdit->text()).append("-");
    from.append(ui->priceLineEdit->text()).append("-");
    from.append(ui->countLineEdit->text());
    return Good::fromString(from);
}
