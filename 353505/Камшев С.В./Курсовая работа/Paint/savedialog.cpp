#include "savedialog.h"

SaveDialog::SaveDialog(int x, int y) {

    YesButton = new QPushButton(this);
    YesButton->setText("Да");
    YesButton->setGeometry(10, 80, 80, 30);

    NoButton = new QPushButton(this);
    NoButton->setText("Нет");
    NoButton->setGeometry(100, 80, 80, 30);

    CanelButton = new QPushButton(this);
    CanelButton->setText("Отмена");
    CanelButton->setGeometry(190, 80, 80, 30);

    this->setGeometry(x + 200, y +  200, 280, 130);
    this->setFixedSize(280, 130);
    this->setWindowTitle("Окно сохранения");

    textLabel = new QLabel(this);
    textLabel->setText("Желаете сохранить файл?");
    textLabel->setGeometry(45, 30, 200, 30);

    SaveDialog::connect(YesButton, SIGNAL(pressed()), this, SLOT(on_YesButton_clicked()));
    SaveDialog::connect(NoButton, SIGNAL(pressed()), this, SLOT(on_NoButton_clicked()));
    SaveDialog::connect(CanelButton, SIGNAL(pressed()), this, SLOT(on_CanelButton_clicked()));
}

void SaveDialog::on_YesButton_clicked()
{
    ans = 1;
    this->hide();
}

void SaveDialog::on_NoButton_clicked()
{
    ans = -1;
    this->hide();
}

void SaveDialog::on_CanelButton_clicked()
{
    ans = 0;
    this->hide();
}

