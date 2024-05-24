#include "addcompany.h"
#include "ui_addcompany.h"

#include <QMessageBox>

AddCompany::AddCompany(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddCompany)
{
    ui->setupUi(this);
    txtCompanies = new QFile(
        "/home/artem_kokhan/QT/OAIP(QT - 2 sem)/LabWork_2/Task_2/Companies.txt");
}

AddCompany::~AddCompany()
{
    delete ui;
}

QFile* AddCompany::getTxt()
{
    return this->txtCompanies;
}

void AddCompany::on_buttonBox_accepted()
{
    if(checkCorrect()) {
    txtCompanies->open(QIODevice::Append | QIODevice::Text);
    QTextStream out(txtCompanies);

    out << ui->companyName->text() + "\n";

    (ui->specialtyCheck->isChecked())? out << ui->specialtyCheck->text() + "\n" : out << ui->specialty->text() + "\n";

    out << ui->post->text() + "\n";

    (ui->moneyCheck->isChecked())? out << ui->moneyCheck->text() + "\n" :  out << ui->money->text() + "\n";

    (ui->holidayCheck->isChecked())? out << ui->holidayCheck->text() + "\n" : out << ui->holiday->text() + "\n";

    out << ui->educationBox->currentText() + "\n";
    out << ui->minAge->cleanText() + "\n";
    out << ui->maxAge->cleanText() + "\n\n";

    txtCompanies->close();

    QMessageBox::information(this, "Компания успешно добавлена", "Вы можете закрыть окно или продолжить добавление");

    Q_EMIT addSignal();
    }

    else {
        QMessageBox::critical(this, "Ошибка", "Проверьте корректность введённых данных");
    }
}

bool AddCompany::checkCorrect()
{
    if(ui->companyName->text().isEmpty()) {
        return false;
    }

    else if(ui->specialty->text().isEmpty() && !ui->specialtyCheck->isChecked()) {
        return false;
    }

    else if(ui->post->text().isEmpty()) {
        return false;
    }

    else if((ui->money->text().isEmpty() && !ui->moneyCheck->isChecked()) ||
             ui->money->text().toDouble() <= 0) {
        return false;
    }

    else if((ui->holiday->text().isEmpty() && !ui->holidayCheck->isChecked())||
             ui->holiday->text().toInt() <= 0) {
        return false;
    }

    return true;
}

