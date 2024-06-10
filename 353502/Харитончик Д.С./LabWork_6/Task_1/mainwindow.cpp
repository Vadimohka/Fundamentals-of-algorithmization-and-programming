#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Plant& plant2 = _plant2;

    plant = {10, 1.5, 'A', true, "Sunflower", {1, 2, 3, 4, 5}};
    ui->label->setText("10 | 1.5 | A | true | SunFlower | 1, 2, 3, 4, 5");
    plant.age = 5;
    _plant.height = 0.8;
    _plant.category = 'B';
    _plant.isHealthy = false;
    qstrcpy(_plant.name, "Rose");
    _plant.humidity[0] = 10;
    _plant.humidity[1] = 20;
    _plant.humidity[2] = 30;
    _plant.humidity[3] = 40;
    _plant.humidity[4] = 50;
    ui->label_2->setText("5 | 0.8 | B | false | Rose | 10, 20, 30, 40, 50");

    plant1 = &_plant1;
    plant1->age = 3;
    plant1->height = 0.4;
    plant1->category = 'C';
    plant1->isHealthy = true;
    qstrcpy(plant1->name, "Tulip");
    plant1->humidity[0] = 100;
    plant1->humidity[1] = 200;
    plant1->humidity[2] = 300;
    plant1->humidity[3] = 400;
    plant1->humidity[4] = 500;
    ui->label_3->setText("3 | 0.4 | C | true | Tulip | 100, 200, 300, 400, 500");
    plant2.age = 2;
    plant2.height = 0.3;
    plant2.category = 'D';
    plant2.isHealthy = false;
    qstrcpy(plant2.name, "Daisy");
    plant2.humidity[0] = 1000;
    plant2.humidity[1] = 2000;
    plant2.humidity[2] = 3000;
    plant2.humidity[3] = 4000;
    plant2.humidity[4] = 5000;
    ui->label_4->setText("2 | 0.3 | D | false | Daisy | 1000, 2000, 3000, 4000, 5000");

    QObject::connect(ui->pushButton, &QPushButton::clicked, [&]() {
        Plant plant;
        plant.age = ui->lineEdit->text().toInt();
        plant.height = ui->lineEdit_2->text().toDouble();
        plant.category = ui->lineEdit_3->text().toLatin1().at(0);
        plant.isHealthy = (ui->lineEdit_4->text().toInt() != 0);
        qstrcpy(plant.name, ui->lineEdit_5->text().toLatin1().data());

        QStringList numbersList = ui->lineEdit_6->text().split(' ');
        for (int i = 0; i < 50; ++i) {
            if (i < numbersList.size()) {
                plant.humidity[i] = numbersList.at(i).toInt();
            } else {
                plant.humidity[i] = 0;
            }
        }

        QString output = QString("Age: %1 | Height: %2 | Category: %3 | Healthy: %4 | Name: %5 | Numbers: ")
            .arg(plant.age).arg(plant.height).arg(plant.category).arg(plant.isHealthy).arg(plant.name);

        for (int i = 0; i < 50; ++i) {
            output += QString::number(plant.humidity[i]) + " ";
        }

        QMessageBox::information(nullptr, "Plant Information", output);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printArr(int *arr, int n)
{

}

