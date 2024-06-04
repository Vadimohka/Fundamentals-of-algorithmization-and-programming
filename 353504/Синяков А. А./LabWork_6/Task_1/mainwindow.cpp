#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "continent.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , continentReference(continent) // Инициализируем ссылку объектом continent
{
    ui->setupUi(this);
    continentPointer = &continent; // Инициализируем указатель ссылкой на continent
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_explicitInit_clicked()
{
    // Явная инициализация
    continent.area = 1000;
    continent.averageHeight = 500.5;
    continent.firstLetter = 'E';
    continent.hasOceanCoast = true;
    strcpy(continent.name, "Europe");
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continent.climateData[i] = i * 10;
    }
}

void MainWindow::on_userInput_clicked()
{
    // Ввод с клавиатуры
    bool ok; // Переменная для проверки корректности ввода
    int area = ui->areaInput->text().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Площадь континента должна быть числом.");
        ui->areaInput->clear();
        return;
    }
    continent.area = area;

    double averageHeight = ui->heightInput->text().toDouble(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Ошибка", "Средняя высота континента должна быть числом.");
        ui->heightInput->clear();
        return;
    }
    continent.averageHeight = averageHeight;
    char firstLetter = ui->firstLetterInput->text().at(0).toLatin1();
    if (!(firstLetter >= 'A' && firstLetter <= 'Z') && !(firstLetter >= 'a' && firstLetter <= 'z')) {
        QMessageBox::critical(this, "Ошибка", "Введите только одну букву в поле для первой буквы названия материка.");
        ui->firstLetterInput->clear();
        return;
    }
    continent.firstLetter = firstLetter;

    // Проверка на допустимые буквы для названия материка
    if (!(firstLetter >= 'A' && firstLetter <= 'Z') && !(firstLetter >= 'a' && firstLetter <= 'z')) {
        QMessageBox::critical(this, "Ошибка", "Название материка должно быть одной буквой латинского алфавита.");
        ui->firstLetterInput->clear();
        return;
    }
    // Проверка на допустимые названия материков
    QStringList validContinents = {"Eurasia", "Africa", "North America", "South America", "Australia", "Antarctica"};
    // Проверка на допустимые названия материков
    QString continentName = ui->nameInput->text();
    if (!validContinents.contains(continentName)) {
        QMessageBox::critical(this, "Ошибка", "Введите корректное название материка(Eurasia, Africa, North America, South America, Australia, Antarctica)");
        ui->nameInput->clear();
        return;
    }
    strcpy(continent.name, continentName.toStdString().c_str());
    QStringList climateDataInput = ui->climateDataInput->text().split(".");
    if (climateDataInput.size() != Continent::climateDataSize) {
        qDebug() << "Неверное количество климатических данных. Ожидалось " << Continent::climateDataSize;
        return;
    }

    // Считываем климатические данные
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continent.climateData[i] = climateDataInput[i].toInt();
    }



}

void MainWindow::on_pointerInit_clicked()
{
    // Инициализация через указатель
    continentPointer->area = 2000;
    continentPointer->averageHeight = 600.5;
    continentPointer->firstLetter = 'A';
    continentPointer->hasOceanCoast = false;
    strcpy(continentPointer->name, "Asia");
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continentPointer->climateData[i] = i * 20;
    }
}

void MainWindow::on_referenceInit_clicked()
{
    // Инициализация через ссылку
    continentReference.area = 3000;
    continentReference.averageHeight = 700.5;
    continentReference.firstLetter = 'A';
    continentReference.hasOceanCoast = false;
    strcpy(continentReference.name, "Africa");
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        continentReference.climateData[i] = i * 30;
    }
}

void MainWindow::on_print_clicked()
{
    // Вывод данных
    QString output = QString::number(continent.area) + " | " +
                     QString::number(continent.averageHeight) + " | " +
                     continent.firstLetter + " | " +
                     (continent.hasOceanCoast ? "true" : "false") + " | " +
                     continent.name + " | ";
    for (int i = 0; i < Continent::climateDataSize; ++i) {
        output += QString::number(continent.climateData[i]);
        if (i < Continent::climateDataSize - 1) output += ", ";
    }
    ui->outputText->setText(output);
}
