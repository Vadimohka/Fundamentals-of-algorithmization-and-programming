#include "dialoginputdata.h"
#include "ui_dialoginputdata.h"

DialogInputData::DialogInputData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInputData)
{
    isWritedName = false;
    isWritedglavnu = false;

    ui->setupUi(this);
    ui->endComboBox->addItems({"true", "false"});

    ui->actorsSpinBox->setValue(18);
    ui->dengiSpinBox->setValue(60);

    ui->nameLineEdit->setMaxLength(20);

    QRegularExpression rx("[mf]");

    QValidator *validator = new QRegularExpressionValidator(rx, ui->glavnuLineEdit);

    ui->glavnuLineEdit->setValidator(validator);

    connect(this->ui->nameLineEdit, &QLineEdit::textChanged, [this](QString text) {
        if (!text.isEmpty())
            isWritedName = true;
        else
            isWritedName = false;

        if (isWritedName && isWritedglavnu)
            ui->buttonBox->setEnabled(true);
        else
            ui->buttonBox->setEnabled(false);
    });

    connect(this->ui->glavnuLineEdit, &QLineEdit::textChanged, [this](QString text) {
        if (!text.isEmpty())
            isWritedglavnu = true;
        else
            isWritedglavnu = false;

        if (isWritedName && isWritedglavnu)
            ui->buttonBox->setEnabled(true);
        else
            ui->buttonBox->setEnabled(false);
    });
}

DialogInputData::~DialogInputData()
{
    delete ui;
}

Kinoserial DialogInputData::getKinoserial()
{
    Kinoserial Kinoserial;
    Kinoserial.actors = ui->actorsSpinBox->value();
    Kinoserial.dengi = ui->dengiSpinBox->value();
    Kinoserial.glavnu = ui->glavnuLineEdit->text()[0].toLatin1();
    Kinoserial.end = (ui->endComboBox->currentText() == "true" ? true : false);

    QByteArray byteArray = ui->nameLineEdit->text().toUtf8();
    const char *charArray = byteArray.constData();

    strcpy(Kinoserial.name, charArray);
    Kinoserial.medals[0] = ui->goldMedalsSpin->value();
    Kinoserial.medals[1] = ui->silverMedalsSpin->value();
    Kinoserial.medals[2] = ui->bronzeMedalsSpin->value();

    return Kinoserial;
}
