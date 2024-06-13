#include "mainwindow.h"
#include "./ui_mainwindow.h"

char SPEC[] = {'E', 'B', 'T'};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int arr[] = {16, 24, 24, 24, 24, 16, 0};
    std::string city = "Minsk";
    for(int i = 0; i<7; ++i)
    {
        CarRepairShop::workingHours[i] = arr[i];
    }

    for(int i = 0; i<city.size(); ++i)
    {
        CarRepairShop::city[i] = city[i];
    }

    carShop1 = {6, 20, 'T', false};

    carShopPointer->numberOfEmployees = 10;
    carShopPointer->averageHourlyRate = 52.2;
    carShopPointer->specialization = 'B';
    carShopPointer->hasInsurance = true;

    carShopReference.numberOfEmployees = 20;
    carShopReference.averageHourlyRate = 100;
    carShopReference.specialization = 'E';
    carShopReference.hasInsurance = true;

    showInfo();

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        carShop1.hasInsurance  = ui->radioButton->isChecked();
        carShop1.averageHourlyRate = ui->doubleSpinBox->value();
        carShop1.numberOfEmployees = ui->spinBox->value();
        carShop1.specialization = SPEC[ui->comboBox->currentIndex()];
        for(int i = 0; i<ui->lineEdit->text().size() && i<30; ++i)
        {
            CarRepairShop::city[i] = ui->lineEdit->text()[i];
        }

        CarRepairShop::workingHours[0] = ui->spinBox_2->value();
        CarRepairShop::workingHours[1] = ui->spinBox_3->value();
        CarRepairShop::workingHours[2] = ui->spinBox_4->value();
        CarRepairShop::workingHours[3] = ui->spinBox_5->value();
        CarRepairShop::workingHours[4] = ui->spinBox_6->value();
        CarRepairShop::workingHours[5] = ui->spinBox_7->value();
        CarRepairShop::workingHours[6] = ui->spinBox_8->value();
        showInfo();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInfo()
{
    QString h = "";
    for (int i = 0; i < 7; ++i) {
        h += QString::number(CarRepairShop::workingHours[i]) + " | ";
    }
    ui->label_9->setText(QString::number(carShop1.numberOfEmployees) + " | " + QString::number(carShop1.averageHourlyRate) + " | " +
                         carShop1.specialization + " | " + (carShop1.hasInsurance ? "Есть страховка" : "Нет страховки") + " | " +
                         QString(reinterpret_cast<const QChar*>(CarRepairShop::city)) + " | " + h);
    ui->label->setText(QString::number(carShopPointer->numberOfEmployees) + " | " + QString::number(carShopPointer->averageHourlyRate) + " | " +
                         carShopPointer->specialization + " | " + (carShopPointer->hasInsurance ? "Есть страховка" : "Нет страховки") + " | " +
                         QString(reinterpret_cast<const QChar*>(CarRepairShop::city)) + " | " + h);
    ui->label_2->setText(QString::number(carShopReference.numberOfEmployees) + " | " + QString::number(carShopReference.averageHourlyRate) + " | " +
                         carShopReference.specialization + " | " + (carShopReference.hasInsurance ? "Есть страховка" : "Нет страховки") + " | " +
                         QString(reinterpret_cast<const QChar*>(CarRepairShop::city)) + " | " + h);
}
