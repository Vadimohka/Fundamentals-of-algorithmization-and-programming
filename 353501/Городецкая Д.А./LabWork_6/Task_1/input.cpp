#include "input.h"
#include "ui_input.h"

Input::Input(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Input)
{
    ui->setupUi(this);
    setWindowTitle("Окно ввода данных о животном");
    setFixedSize(805, 465);
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        if (ui->spb_age->value() == 0 || ui->dspb_weight->value() == 0 || ui->ln_dietType->text() == "" || ui->ln_species->text() == "") {
            ui->bnt_send->setStyleSheet("background-color: gray;");
            ui->bnt_send->setEnabled(false);
        }
        else {
            ui->bnt_send->setStyleSheet("background-color: white;");
            ui->bnt_send->setEnabled(true);
        }
    });
    timer->start(30);
}

Input::~Input()
{
    delete ui;
    delete timer;
}

void Input::on_bnt_send_clicked()
{
    temp.age = ui->spb_age->value();
    temp.dietType = ui->ln_dietType->text()[0].toLatin1();
    temp.isMale = ui->checkBox->isChecked();
    temp.weight = ui->dspb_weight->value();
    QString speciesString = ui->ln_species->text();
    for (int i = 0; i < speciesString.length() && i < Animal::MAX_CHAR_ARRAY_SIZE; ++i) {
        temp.species[i] = speciesString.at(i);
    }
    if (speciesString.length() < Animal::MAX_CHAR_ARRAY_SIZE) {
        temp.species[speciesString.length()] = QChar('\0');
    }
    temp.hoursOfSleep[0] = ui->spb_1->value();
    temp.hoursOfSleep[1] = ui->spb_2->value();
    temp.hoursOfSleep[2] = ui->spb_3->value();
    temp.hoursOfSleep[3] = ui->spb_4->value();
    temp.hoursOfSleep[4] = ui->spb_5->value();
    temp.hoursOfSleep[5] = ui->spb_6->value();
    temp.hoursOfSleep[6] = ui->spb_7->value();
    emit buttonClicked(temp);
    close();
}
