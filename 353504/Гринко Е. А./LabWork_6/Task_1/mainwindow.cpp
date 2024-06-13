#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->areaDBox->setMaximum(std::numeric_limits<double>::max());

    task();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::task()
{
    ui->textEdit->clear();

    City city1 = {1000000, 2500.75, 'A', true, "New York", {10, 20, 30} };
    write(city1, 1);

    City city2;
    city2.population = 500000;
    city2.area = 1800.25;
    city2.category = 'B';
    city2.isCapital = false;
    qstrcpy(city2.name, "Los Angeles");
    city2.features[0] = 5;
    city2.features[1] = 10;
    city2.features[2] = 15;
    write(city2, 2);

    City city3;
    city3.population = ui->populationBox->value();
    city3.area = ui->areaDBox->value();
    city3.category = ui->categoryBox->value();
    city3.isCapital = ui->checkBox->isChecked();
    strcpy(city3.name, ui->lineEdit->text().toStdString().c_str());
    city3.features[0] = ui->aBox->value();
    city3.features[1] = ui->bBox->value();
    city3.features[2] = ui->cBox->value();
    write(city3, 3);

    City city4;
    City* cityPtr = &city4;
    cityPtr->population = 2000000;
    cityPtr->area = 3500.50;
    cityPtr->category = 'C';
    cityPtr->isCapital = true;
    qstrcpy(cityPtr->name, "Chicago");
    cityPtr->features[0] = 15;
    cityPtr->features[1] = 25;
    cityPtr->features[2] = 35;
    write(city4, 4);

    City city5;
    City& cityRef5 = city5;
    cityRef5.population = 3000000;
    cityRef5.area = 5000.75;
    cityRef5.category = 'D';
    cityRef5.isCapital = false;
    qstrcpy(cityRef5.name, "Gomel");
    cityRef5.features[0] = 45;
    cityRef5.features[1] = 55;
    cityRef5.features[2] = 65;
    write(city5, 5);
}

void MainWindow::write(const City& city, int n)
{
    ui->textEdit->append("City " + QString::number(n) + ":\t");
    ui->textEdit->insertPlainText(QString::number(city.population) + " | ");
    ui->textEdit->insertPlainText(QString::number(city.area) + " | ");
    ui->textEdit->insertPlainText(QString(city.category) + " | ");
    ui->textEdit->insertPlainText(QString::number(city.isCapital) + " | ");
    ui->textEdit->insertPlainText(QString(city.name) + " | ");
    ui->textEdit->insertPlainText(QString::number(city.features[0]) + " | ");
    ui->textEdit->insertPlainText(QString::number(city.features[1]) + " | ");
    ui->textEdit->insertPlainText(QString::number(city.features[2]));
}

void MainWindow::on_pushButton_clicked()
{
    task();
}


void MainWindow::on_categoryBox_valueChanged(int arg1)
{
    ui->categotyLbl->setText("Category " + QString(static_cast<char>(arg1)));
}

