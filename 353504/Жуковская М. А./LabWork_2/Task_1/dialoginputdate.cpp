#include "dialoginputdate.h"
#include "ui_dialoginputdate.h"

DialogInputDate::DialogInputDate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInputDate)
{
    ui->setupUi(this);

    ui->spinDay->setValue(Date::Today().Day());
    ui->spinMonth->setValue(Date::Today().Month());
    ui->spinYear->setValue(Date::Today().Year());

    ui->spinDay->setRange(1, 31);
    ui->spinMonth->setRange(1, 12);
    ui->spinYear->setRange(0, 9999);

    QLineEdit *lineDayEdit = ui->spinDay->findChild<QLineEdit *>();
    QLineEdit *lineMonthEdit = ui->spinMonth->findChild<QLineEdit *>();
    QLineEdit *lineYearEdit = ui->spinYear->findChild<QLineEdit *>();

    lineDayEdit->setMaxLength(2);
    lineMonthEdit->setMaxLength(2);
    lineYearEdit->setMaxLength(4);

    connect(ui->spinMonth, &QSpinBox::valueChanged, [this](){

        if(ui->spinMonth->value() == 2)
        {
            if(Date::isLeapThe(ui->spinYear->value()))
            {
                ui->spinDay->setMaximum(29);
            }
            else
            {
                ui->spinDay->setMaximum(28);
            }
        }
        else if(ui->spinMonth->value() == 4 || ui->spinMonth->value() == 6 || ui->spinMonth->value() == 9 || ui->spinMonth->value() == 11)
        {
            ui->spinDay->setMaximum(30);
        }
        else ui->spinDay->setMaximum(31);

    });

    connect(ui->spinYear, &QSpinBox::valueChanged, [this](){

        if(ui->spinMonth->value() == 2)
        {
            if(Date::isLeapThe(ui->spinYear->value()))
            {
                ui->spinDay->setMaximum(29);
            }
            else ui->spinDay->setMaximum(28);
        }
    });
}

DialogInputDate::~DialogInputDate()
{
    delete ui;
}

Date DialogInputDate::getDate()
{
    return Date(ui->spinDay->value(), ui->spinMonth->value(), ui->spinYear->value());
}

void DialogInputDate::setDate(Date date)
{
    ui->spinDay->setValue(date.Day());
    ui->spinMonth->setValue(date.Month());
    ui->spinYear->setValue(date.Year());
}
