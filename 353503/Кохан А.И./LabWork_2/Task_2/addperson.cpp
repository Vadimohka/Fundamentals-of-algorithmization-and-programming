#include "addperson.h"
#include "ui_addperson.h"

#include <QMessageBox>

AddPerson::AddPerson(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddPerson)
{
    ui->setupUi(this);
    txtPeople = new QFile("//home/artem_kokhan/QT/OAIP(QT - 2 sem)/LabWork_2/Task_2/People.txt");
}

AddPerson::~AddPerson()
{
    delete ui;
}

QFile *AddPerson::getTxt()
{
    return this->txtPeople;
}

void AddPerson::on_buttonBox_accepted()
{
    if(checkCorrect()) {
        txtPeople->open(QIODevice::Append | QIODevice::Text);
        QTextStream out(txtPeople);

        out << ui->surname->text() + "\n";

        out << ui->name->text() + "\n";

        (ui->checkPatronymic->isChecked())? out << ui->checkPatronymic->text() + "\n" : out << ui->patronymic->text() + "\n";

        out << ui->date->text() + "\n";

        out << ui->educationBox->currentText() + "\n";

        (ui->checkSpecialty->isChecked())? out << ui->checkSpecialty->text() + "\n" : out << ui->specialty->text() + "\n";

        out << ui->post->text() + "\n";

        (ui->checkMoney->isChecked())? out << ui->checkMoney->text() + "\n\n" :  out << ui->money->text() + "\n\n";

        txtPeople->close();

        QMessageBox::information(this, "Кандидат успешно добавлен", "Вы можете закрыть окно или продолжить добавление");

        Q_EMIT addSignal();
    }

    else {
        QMessageBox::critical(this, "Ошибка", "Проверьте корректность введённых данных");
    }
}

bool AddPerson::checkCorrect()
{
    if(ui->surname->text().isEmpty() || ui->name->text().isEmpty()) {
        return false;
    }

    else if(ui->patronymic->text().isEmpty() && !ui->checkPatronymic->isChecked()) {
        return false;
    }

    else if(ui->specialty->text().isEmpty() && !ui->checkSpecialty->isChecked()) {
        return false;
    }

    else if(ui->post->text().isEmpty()) {
        return false;
    }

    else if((ui->money->text().isEmpty() && !ui->checkMoney->isChecked()) ||
             ui->money->text().toDouble() <= 0) {
        return false;
    }

    return true;
}

