#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->checkBox, &QCheckBox::clicked, this, &MainWindow::onCheckBox1Clicked);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &MainWindow::onCheckBox2Clicked);
    connect(ui->checkBox_3, &QCheckBox::clicked, this, &MainWindow::onCheckBox3Clicked);
    connect(ui->checkBox_4, &QCheckBox::clicked, this, &MainWindow::onCheckBox4Clicked);
    // char a[Smartphone::MAX_CHAR_ARRAY_SIZE] = "xyz";
    // for (int i = 0; i < Smartphone::MAX_CHAR_ARRAY_SIZE; ++i) {
    //     Smartphone::mode[i] = a[i];
    // }
    // for (int i = 0; i < Smartphone::MAX_INT_ARRAY_SIZE; ++i) {
    //     Smartphone::my_phone_numbers[i] = i + 1;
    //     intArray += QString::number(Smartphone::my_phone_numbers[i]) + " ";
    // }
    smartphone1 = {2023, 1500, 6.1,'H', true};
    for (int i = 0; i < Smartphone::MAX_INT_ARRAY_SIZE; i++) {
        smartphone1.my_phone_numbers[i] = rand() % 9999999 + 1000000;
    }

    smartphone2.release_year = 2014;
    smartphone2.price = 200;
    smartphone2.diag = 5.9;
    smartphone2.eco_class = 'A';
    smartphone2.IsNew = false;
    for (int i = 0; i < 2; ++i) {
        smartphone2.my_phone_numbers[i] = rand() % 9999999 + 1000000;
    }

    smartPtr->release_year = 2018;
    smartPtr->price = 450;
    smartPtr->diag = 5.7;
    smartPtr->eco_class = 'H';
    smartPtr->IsNew = false;
    for (int i = 0; i < 1; i++) {
        smartPtr->my_phone_numbers[i] = rand() % 9999999 + 1000000;
    }

    smartRef.release_year = 2021;
    smartRef.price = 800;
    smartRef.diag = 7.2;
    smartRef.eco_class = 'H';
    smartRef.IsNew = true;
    for (int i = 0; i < 1; i++) {
        smartRef.my_phone_numbers[i] = rand() % 9999999 + 1000000;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCheckBox1Clicked() {
    if (ui->checkBox->isChecked()) {
        ui->checkBox_2->setChecked(false);
    }
}

void MainWindow::onCheckBox2Clicked() {
    if (ui->checkBox_2->isChecked()) {
        ui->checkBox->setChecked(false);
    }
}

void MainWindow::onCheckBox3Clicked() {
    if (ui->checkBox_3->isChecked()) {
        ui->checkBox_4->setChecked(false);
    }
}

void MainWindow::onCheckBox4Clicked() {
    if (ui->checkBox_4->isChecked()) {
        ui->checkBox_3->setChecked(false);
    }
}

void MainWindow::on_print_result_clicked()
{
    ui->label_answer->setText(QString::fromStdString(smartphone1.GetInfo()));
    ui->label_answer->setText(ui->label_answer->text() + "<br>" + QString::fromStdString(smartphone2.GetInfo()));
    ui->label_answer->setText(ui->label_answer->text() + "<br>" + QString::fromStdString(smartPtr->GetInfo()));
    ui->label_answer->setText(ui->label_answer->text() + "<br>" + QString::fromStdString(smartRef.GetInfo()));
}


void MainWindow::on_pushButton_clicked()
{
    Smartphone smart;
    QString release_year1 = ui->spinBox_year->text();
    QString price1 = ui->spinBox_price->text();
    QString diag1 = ui->doubleSpinBox_diag->text();
    QString eco_class1;
    if (ui->checkBox->isChecked()) {
        eco_class1 = ui->checkBox->text();
    } else if (ui->checkBox_2->isChecked()) {
        eco_class1 = ui->checkBox_2->text();
    }
    QString IsNew1;
    if (ui->checkBox_3->isChecked()) {
        IsNew1 = ui->checkBox_3->text();
    } else if (ui->checkBox_4->isChecked()) {
        IsNew1 = ui->checkBox_4->text();
    }
    ui->label_answer1->setText("Year: " + release_year1 + " | "+ "Price: " + price1 + "$ | " + "Diag: " + diag1 + "'' | " + "Eco class: " + eco_class1 + " | " + "New: "  + IsNew1);
}

