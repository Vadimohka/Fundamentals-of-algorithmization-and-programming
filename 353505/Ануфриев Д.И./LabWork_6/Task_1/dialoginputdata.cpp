#include "dialoginputdata.h"
#include "ui_dialoginputdata.h"

DialogInputData::DialogInputData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInputData)
{
    isWritedName = false;
    isWritedSex = false;

    ui->setupUi(this);
    ui->isJockComboBox->addItems({"true", "false"});

    ui->ageSpinBox->setValue(18);
    ui->weightSpinBox->setValue(60);

    ui->nameLineEdit->setMaxLength(20);

    QRegularExpression rx("[mf]");

    QValidator *validator = new QRegularExpressionValidator(rx, ui->sexLineEdit);

    ui->sexLineEdit->setValidator(validator);

    connect(this->ui->nameLineEdit, &QLineEdit::textChanged, [this](QString text){
        if(!text.isEmpty()) isWritedName = true;
        else isWritedName = false;

        if(isWritedName && isWritedSex) ui->buttonBox->setEnabled(true);
        else ui->buttonBox->setEnabled(false);
    });

    connect(this->ui->sexLineEdit, &QLineEdit::textChanged, [this](QString text){
        if(!text.isEmpty()) isWritedSex = true;
        else isWritedSex = false;

        if(isWritedName && isWritedSex) ui->buttonBox->setEnabled(true);
        else ui->buttonBox->setEnabled(false);
    });
}

DialogInputData::~DialogInputData()
{
    delete ui;
}

Sportsman DialogInputData::getSportsman()
{
    Sportsman sportsman;
    sportsman.age = ui->ageSpinBox->value();
    sportsman.weight = ui->weightSpinBox->value();
    sportsman.sex = ui->sexLineEdit->text()[0].toLatin1();
    sportsman.isJock = (ui->isJockComboBox->currentText() == "true" ? true : false);

    QByteArray byteArray = ui->nameLineEdit->text().toUtf8();
    const char *charArray = byteArray.constData();

    strcpy(sportsman.name, charArray);
    sportsman.medals[0] = ui->goldMedalsSpin->value();
    sportsman.medals[1] = ui->silverMedalsSpin->value();
    sportsman.medals[2] = ui->bronzeMedalsSpin->value();

    return sportsman;
}
