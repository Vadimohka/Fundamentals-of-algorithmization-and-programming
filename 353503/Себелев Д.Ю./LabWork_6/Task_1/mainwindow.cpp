#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputDialog(new InputDialog)
    , animalRef(animal)
{
    ui->setupUi(this);

    animalPointer = &animal;

    strcpy(animal.name, "Elephant");
    animal.age = 15;
    animal.gender = 'M';
    animal.isAlive = true;
    animal.weight = 500.0;
    animal.sizes[0] = 300;
    animal.sizes[1] = 200;
    animal.sizes[2] = 100;

    connect(ui->animal_cmbbox, &QComboBox::currentIndexChanged,
            this, &MainWindow::onAnimalChanged);
    connect(inputDialog, &InputDialog::animalEntered,
            this, &MainWindow::getInfo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAnimalChanged(int index)
{
    switch(index) {
    case 0:
        ui->output_widget->addItem("Name: " + QString(animal.name));
        ui->output_widget->addItem("Age: " + QString::number(animal.age));
        ui->output_widget->addItem("Gender: " + QString(animal.gender));
        ui->output_widget->addItem("Weight: " + QString::number(animal.weight));
        ui->output_widget->addItem("Alive: " + QString(animal.isAlive ? "Yes" : "No"));
        ui->output_widget->addItem("Sizes: " + QString::number(animal.sizes[0]) + " " +
                                   QString::number(animal.sizes[1]) + " " +
                                   QString::number(animal.sizes[2]) + '\n');
        break;
    case 1:
        inputDialog->show();
        break;
    case 2:
        ui->output_widget->addItem("Name: " + QString(animalPointer->name));
        ui->output_widget->addItem("Age: " + QString::number(animalPointer->age));
        ui->output_widget->addItem("Gender: " + QString(animalPointer->gender));
        ui->output_widget->addItem("Weight: " + QString::number(animalPointer->weight));
        ui->output_widget->addItem("Alive: " + QString(animalPointer->isAlive ? "Yes" : "No"));
        ui->output_widget->addItem("Sizes: " + QString::number(animalPointer->sizes[0]) + " " +
                                   QString::number(animalPointer->sizes[1]) + " " +
                                   QString::number(animalPointer->sizes[2]) + '\n');
        break;
    case 3:
        ui->output_widget->addItem("Name: " + QString(animalRef.name));
        ui->output_widget->addItem("Age: " + QString::number(animalRef.age));
        ui->output_widget->addItem("Gender: " + QString(animalRef.gender));
        ui->output_widget->addItem("Weight: " + QString::number(animalRef.weight));
        ui->output_widget->addItem("Alive: " + QString(animalRef.isAlive ? "Yes" : "No"));
        ui->output_widget->addItem("Sizes: " + QString::number(animalRef.sizes[0]) + " " +
                                   QString::number(animalRef.sizes[1]) + " " +
                                   QString::number(animalRef.sizes[2]) + '\n');
    }
}

void MainWindow::getInfo(Animal tempAnimal)
{
    animal = tempAnimal;
    ui->output_widget->addItem("Name: " + QString(animal.name));
    ui->output_widget->addItem("Age: " + QString::number(animal.age));
    ui->output_widget->addItem("Gender: " + QString(animal.gender));
    ui->output_widget->addItem("Weight: " + QString::number(animal.weight));
    ui->output_widget->addItem("Alive: " + QString(animal.isAlive ? "Yes" : "No"));
    ui->output_widget->addItem("Sizes: " + QString::number(animal.sizes[0]) + " " +
                               QString::number(animal.sizes[1]) + " " +
                               QString::number(animal.sizes[2]) + '\n');
}
