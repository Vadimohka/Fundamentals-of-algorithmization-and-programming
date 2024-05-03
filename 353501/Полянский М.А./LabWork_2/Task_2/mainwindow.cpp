#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    connect(ui->addprod, &QPushButton::clicked, this, &MainWindow::onAddProductButtonClicked);
    connect(ui->order, &QPushButton::clicked, this, &MainWindow::writeToFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddProductButtonClicked() {
    QString code = ui->code->toPlainText();
    QString name = ui->name->toPlainText();
    double price = ui->price->value();
    int quantity = ui->quality->value();

    Product newProd(code, name, price, quantity);
    products.append(newProd);

    updateTable(products);
    countPrice(products, total);
    ui->code->setText("");
    ui->name->setText("");
    ui->price->setValue(0);
    ui->quality->setValue(0);

 
}

void MainWindow::updateTable(const QList<Product> &products) {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(products.size());

    for (int i = 0; i < products.size(); ++i) {
        const Product &product = products.at(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(product.getCode()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(product.getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(product.getPrice())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(product.getQuantity())));
    }
}

void MainWindow::countPrice(const QList<Product> &products, double &total) {
    total = 0;
    for (int i = 0; i < products.size(); i++) {
        total += products[i].getPrice() * products[i].getQuantity();
    }
    QString t = QString::number(total);
    ui->label_6->setText(t);
}

void MainWindow::writeToFile() {
    // Get file name from user
    QString fileName = "order.txt";

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("File name cannot be empty."));
        return;
    }

   
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to open file for writing."));
        return;
    }

    QTextStream out(&file);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    out << "Order Date: " << currentDateTime.toString(Qt::ISODate) << "\n";

    for (const Product &product : products) {
        out << "Code: " << product.getCode() << ", Name: " << product.getName() << ", Price: " << product.getPrice()
            << ", Quantity: " << product.getQuantity() << "\n";
    }

    
    out << "Total Price: " << total << "\n";

   
    file.close();

    
    ui->tableWidget->clear();
    total = 0;
    products.clear();

    QMessageBox::information(this, tr("Success"), tr("order placed"));
}
