#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Motorbike bike{100124, 240, 'R', true, "Yamaha", {3000,1000, 1500}};
    ui->lineEdit->setText(bike.toQString('|'));

    Motorbike* bikePtr = new Motorbike{768594, 180, 'G', false, "Yamaha", {2800,900, 1350}};
    ui->lineEdit_2->setText(bikePtr->toQString('|'));

    Motorbike& bikeRef = bike;
    ui->lineEdit_3->setText(bikeRef.toQString('|'));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddBike_clicked()
{
    if(ui->lineEditColor->text().length() > 1 || ui->lineEditColor->text().length() == 0){
        QMessageBox::critical(this, "Wrong Color!", "Wrong Color!\nInput only the first symbol of the color!");
        return;
    }
    Motorbike bike{
    ui->spinBoxSerialNumber->value(),
    ui->doubleSpinBoxMaxSpeed->value(),
    ui->lineEditColor->text().at(0).toLatin1(),
    ui->checkBox->isCheckable(),
    ui->lineEditName->text().toLatin1(),
    {ui->spinBoxLength->value(), ui->spinBoxWidth->value(), ui->spinBoxHeight->value()},
    };
    ui->lineEditYourBike->setText(bike.toQString('|'));
}

