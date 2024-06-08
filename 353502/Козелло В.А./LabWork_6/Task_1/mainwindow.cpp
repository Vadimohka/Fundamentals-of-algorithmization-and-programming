#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->form->hide();
    ui->serialLetter->setMaxLength(1);

    rollex = {6, 25, 15, "Rollex", 'A', 5516159987, true, {1, 2, 3, 4, 5}};

    luch.hours = 1;
    luch.minutes = 20;
    luch.seconds = 1;
    luch.name = "Луч";
    luch.serialLetter = 'F';
    luch.serialNumber = 123456789;
    luch.waterResistance = false;
    luch.detailsNumbers[0] = 11;
    luch.detailsNumbers[1] = 52;
    luch.detailsNumbers[2] = 25;
    luch.detailsNumbers[3] = 11111;
    luch.detailsNumbers[4] = 88;

    Watches *ptr = &apple;
    ptr->hours = 5;
    ptr->minutes = 55;
    ptr->seconds = 55;
    ptr->name = "Apple watch 7";
    ptr->serialLetter = 'A';
    ptr->serialNumber = 88005553535;
    ptr->waterResistance = true;
    ptr->detailsNumbers[0] = 4398751;
    ptr->detailsNumbers[1] = 3948756;
    ptr->detailsNumbers[2] = 2439411;
    ptr->detailsNumbers[3] = 2395511;
    ptr->detailsNumbers[4] = 8435658;

    Watches &link = casio;
    link.hours = 0;
    link.minutes = 0;
    link.seconds = 0;
    link.name = "Casio";
    link.serialLetter = 'J';
    link.serialNumber = 4875234;
    link.waterResistance = false;
    link.detailsNumbers[0] = 999991;
    link.detailsNumbers[1] = 999992;
    link.detailsNumbers[2] = 999993;
    link.detailsNumbers[3] = 999994;
    link.detailsNumbers[4] = 999995;

    ui->textEdit->setText(rollex.toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_task_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->form->hide();
        ui->textEdit->setText(rollex.toString());
        break;
    case 1:
        ui->form->hide();
        ui->textEdit->setText(luch.toString());
        break;
    case 2:
        ui->form->show();
        break;
    case 3:
        ui->form->hide();
        ui->textEdit->setText(apple.toString());
        break;
    case 4:
        ui->form->hide();
        ui->textEdit->setText(casio.toString());
        break;
    }
}

void MainWindow::on_submit_clicked()
{
    ui->textEdit->clear();
    if (isEnglish(ui->name->text()) && isEnglish(ui->serialLetter->text())) {
        Watches temp;
        temp.hours = ui->hours->value();
        temp.minutes = ui->minutes->value();
        temp.seconds = ui->seconds->value();

        temp.name = ui->name->text().toStdString().c_str();
        temp.serialLetter = *ui->serialLetter->text().toStdString().c_str();

        temp.serialNumber = ui->serialNumber->value();
        temp.waterResistance = ui->waterResistance->currentIndex();
        temp.detailsNumbers[0] = ui->detail_1->value();
        temp.detailsNumbers[1] = ui->detail_2->value();
        temp.detailsNumbers[2] = ui->detail_3->value();
        temp.detailsNumbers[3] = ui->detail_4->value();
        temp.detailsNumbers[4] = ui->detail_5->value();

        ui->textEdit->setText(temp.toString());

    } else {
        QMessageBox::critical(
            this, "", "Неверно введены данные, строки могут содержать только английские символы");
    }
}
