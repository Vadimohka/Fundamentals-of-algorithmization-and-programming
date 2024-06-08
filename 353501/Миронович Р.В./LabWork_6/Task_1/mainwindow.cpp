#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "plant.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , plantReference(plant) // Инициализируем ссылку объектом plany
{
    ui->setupUi(this);
    plantPointer = &plant; // Инициализируем указатель ссылкой на plant
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_explicitInit_clicked()
{
    // Явная инициализация
    plant.area = 1000;
    plant.averageHeight = 500.5;
    plant.firstLetter = 'M';
    plant.fruit = true;
    strcpy(plant.name, "Moh");
    for (int i = 0; i < Plant::climateDataSize; ++i) {
        plant.climateData[i] = i * 10;
    }
}

void MainWindow::on_userInput_clicked()
{
    // Ввод с клавиатуры
    bool ok; // Переменная для проверки корректности ввода
    int area = ui->areaInput->text().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Площадь занимаемого пространства должна быть числом.");
        ui->areaInput->clear();
        return;
    }
    plant.area = area;

    double averageHeight = ui->heightInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Средняя высота занимаемого пространства должна быть числом.");
        ui->heightInput->clear();
        return;
    }
    plant.averageHeight = averageHeight;
    char firstLetter = ui->firstLetterInput->text().at(0).toLatin1();
    if (!(firstLetter >= 'A' && firstLetter <= 'Z') && !(firstLetter >= 'a' && firstLetter <= 'z')) {
        QMessageBox::critical(this, "Ошибка", "Введите только одну букву в поле для первой буквы названия растения.");
        ui->firstLetterInput->clear();
        return;
    }
    plant.firstLetter = firstLetter;

    // Проверка на допустимые буквы для названия растения
    if (!(firstLetter >= 'A' && firstLetter <= 'Z') && !(firstLetter >= 'a' && firstLetter <= 'z')) {
        QMessageBox::critical(this, "Ошибка", "Название растения должно быть одной буквой латинского алфавита.");
        ui->firstLetterInput->clear();
        return;
    }
    // Проверка на допустимые названия растений
    QStringList validContinents = {"Ris", "Kartoshka", "Dub", "Bereza", "Yablonya", "Moh"};
    // Проверка на допустимые названия материков
    QString plantName = ui->nameInput->text();
    if (!validContinents.contains(plantName)) {
        QMessageBox::critical(this, "Ошибка", "Введите корректное название материка(Eurasia, Africa, North America, South America, Australia, Antarctica)");
        ui->nameInput->clear();
        return;
    }
    strcpy(plant.name, plantName.toStdString().c_str());
    QStringList climateDataInput = ui->climateDataInput->text().split(".");
    if (climateDataInput.size() != Plant::climateDataSize) {
        qDebug() << "Неверное количество климатических данных. Ожидалось " << Plant::climateDataSize;
        return;
    }

    // Считываем климатические данные
    for (int i = 0; i < Plant::climateDataSize; ++i) {
        plant.climateData[i] = climateDataInput[i].toInt();
    }
}

void MainWindow::on_pointerInit_clicked()
{
    // Инициализация через указатель
    plantPointer->area = 2000;
    plantPointer->averageHeight = 600.5;
    plantPointer->firstLetter = 'R';
    plantPointer->fruit = false;
    strcpy(plantPointer->name, "Ris");
    for (int i = 0; i < Plant::climateDataSize; ++i) {
        plantPointer->climateData[i] = i * 20;
    }
}

void MainWindow::on_referenceInit_clicked()
{
    // Инициализация через ссылку
    plantReference.area = 3000;
    plantReference.averageHeight = 700.5;
    plantReference.firstLetter = 'Y';
    plantReference.fruit = false;
    strcpy(plantReference.name, "Yablonya");
    for (int i = 0; i < Plant::climateDataSize; ++i) {
        plantReference.climateData[i] = i * 30;
    }
}

void MainWindow::on_print_clicked()
{
    // Вывод данных
    QString output = QString::number(plant.area) + " | " +
                     QString::number(plant.averageHeight) + " | " +
                     plant.firstLetter + " | " +
                     (plant.fruit ? "true" : "false") + " | " +
                     plant.name + " | ";
    for (int i = 0; i < Plant::climateDataSize; ++i) {
        output += QString::number(plant.climateData[i]);
        if (i < Plant::climateDataSize - 1) output += ", ";
    }
    ui->outputText->setText(output);
}
