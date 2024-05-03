#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable()
{
    int64_t size = productsToShow->size();
    ui->tableWidget->setRowCount(size);

    for (int iterator = 0;iterator<size;iterator++)
    {
        int64_t currColumn = 0;
        ui->tableWidget->setItem(iterator, currColumn++, new QTableWidgetItem(QString::number(*productsToShow->at(iterator)->GetCode()), QTableWidgetItem::Type));
        ui->tableWidget->setItem(iterator, currColumn++, new QTableWidgetItem(*productsToShow->at(iterator)->GetName(), QTableWidgetItem::Type));
        ui->tableWidget->setItem(iterator, currColumn++, new QTableWidgetItem(*productsToShow->at(iterator)->GetGroup()->ToQString(), QTableWidgetItem::Type));
        ui->tableWidget->setItem(iterator, currColumn++, new QTableWidgetItem(QString::number(*productsToShow->at(iterator)->GetQuantity()), QTableWidgetItem::Type));
        ui->tableWidget->setItem(iterator, currColumn++, new QTableWidgetItem(QString::number(*productsToShow->at(iterator)->GetPrice()), QTableWidgetItem::Type));
    }
}

void MainWindow::updateGroups()
{
    ui->group_comboBox->clear();
    int64_t size = groupContainer->GetGroups()->size();

    for (int iterator = 0;iterator<size;iterator++)
    {
        ui->group_comboBox->addItem(*groupContainer->GetGroups()->at(iterator)->ToQString());
    }
}

void MainWindow::on_add_button_clicked()
{
    Product newProduct(ui->name_textEdit->toPlainText(),
                       ui->code_textEdit->toPlainText().toLongLong(),
                       groupContainer->GetGroupAtPos(ui->group_comboBox->currentIndex()),
                       ui->price_textEdit->toPlainText().toDouble(),
                       ui->quantity_textEdit->toPlainText().toLongLong());

    productContainer->AddProduct(newProduct);

    productsToShow = productContainer->GetAllProducts();

    updateTable();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    mode = editMode;

    positionToEdit = row;

    Group* groupOfProduct = new Group;

    groupOfProduct->FromQStringToInstance(new QString(ui->tableWidget->item(row, 2)->text()));
    groupOfProduct = groupContainer->GetGroups()->at(groupContainer->FindGroup(groupOfProduct));

    Product productToEdit(ui->tableWidget->item(row, 1)->text(),
                          ui->tableWidget->item(row, 0)->text().toLongLong(),
                          *groupOfProduct,
                          ui->tableWidget->item(row, 4)->text().toDouble(),
                          ui->tableWidget->item(row, 3)->text().toLongLong());

    positionToEdit = productContainer->FindProduct(productToEdit);

    ui->name_textEdit->setPlainText(*productToEdit.GetName());
    ui->code_textEdit->setPlainText(QString::number(*productToEdit.GetCode()));
    ui->quantity_textEdit->setPlainText(QString::number(*productToEdit.GetQuantity()));
    ui->price_textEdit->setPlainText(QString::number(*productToEdit.GetPrice()));
    ui->group_comboBox->setCurrentIndex(groupContainer->FindGroup(groupOfProduct));
}

void MainWindow::on_endEdit_button_clicked()
{
    mode = addMode;

    Product newProduct(ui->name_textEdit->toPlainText(),
                       ui->code_textEdit->toPlainText().toLongLong(),
                       groupContainer->GetGroupAtPos(ui->group_comboBox->currentIndex()),
                       ui->price_textEdit->toPlainText().toDouble(),
                       ui->quantity_textEdit->toPlainText().toLongLong());

    productContainer->EditProductAtPos(positionToEdit, newProduct);

    updateTable();
}

void MainWindow::on_find_with_button_clicked()
{
    productsToShow = productContainer->SearchWithName(new QString(ui->find_with_textEdit->toPlainText()));

    updateTable();
}

void MainWindow::on_less_then_button_clicked()
{
    productsToShow = productContainer->SearchWithLessQuantity(ui->less_then_textEdit->toPlainText().toLongLong());

    updateTable();
}

void MainWindow::on_sort_button_clicked()
{
    productContainer->SortProductsByCode();

    productsToShow = productContainer->GetAllProducts();

    updateTable();
}

void MainWindow::on_addGroup_textEdit_clicked()
{
    Group* newGroup = new Group;

    newGroup->SetName(new QString(ui->newGroup_textEdit->toPlainText()));

    ui->newGroup_textEdit->clear();

    groupContainer->AddGroup(newGroup);

    updateGroups();
}

void MainWindow::on_save_button_clicked()
{
    fileService->SaveDataIntoTheQFileDialog(this, *groupContainer);
    fileService->SaveDataIntoTheQFileDialog(this, *productContainer);
}

void MainWindow::on_open_button_clicked()
{
    fileService->GetDataFromTheQFileDialog(this, *groupContainer);
    fileService->GetDataFromTheQFileDialog(this, *productContainer);

    productsToShow = productContainer->GetAllProducts();

    updateGroups();
    updateTable();
}

