#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(2);
    ui->tableWidget->setColumnCount(4);

    // Название функции
    QTableWidgetItem* functionNameItem = new QTableWidgetItem("strcat");
    ui->tableWidget->setItem(0, 0, functionNameItem);

    // Исходная строка 1
    char str1[20] = "Hello ";
    QTableWidgetItem* str1Item = new QTableWidgetItem(str1);
    ui->tableWidget->setItem(0, 1, str1Item);

    // Исходная строка 2
    char str2[] = "world!";
    QTableWidgetItem* str2Item = new QTableWidgetItem(str2);
    ui->tableWidget->setItem(0, 2, str2Item);

    // Результат
    MyString::strcat(str1, str2);
    QTableWidgetItem* resultItem = new QTableWidgetItem(str1);
    ui->tableWidget->setItem(0, 3, resultItem);
    ///////////////////////////////////////////

    // Название функции
    QTableWidgetItem* functionNameItem1 = new QTableWidgetItem("erase");
    ui->tableWidget->setItem(1, 0, functionNameItem1);

    // Исходная строка
    MyString originalStr("Hello World");
    QTableWidgetItem* originalStrItem = new QTableWidgetItem(originalStr.c_str());
    ui->tableWidget->setItem(1, 1, originalStrItem);

    // Количество символов для удаления
    QTableWidgetItem* numErasedItem = new QTableWidgetItem("6 первых");
    ui->tableWidget->setItem(1, 2, numErasedItem);

    // Преобразованная строка
    originalStr.erase(0, 6);
    QTableWidgetItem* transformedStrItem = new QTableWidgetItem(originalStr.c_str());
    ui->tableWidget->setItem(1, 3, transformedStrItem);

}

MainWindow::~MainWindow()
{
    delete ui;
}
