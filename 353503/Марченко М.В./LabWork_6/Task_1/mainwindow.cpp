#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Shoes.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::slot1);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::slot2);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::slot3);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::slot4);


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::printShoes(Shoes& shoes) {
    QString result = QString("%1 | %2 | %3 | %4 | %5 | %6")
                         .arg(QString::number(shoes.amount))
                         .arg(QString::number(shoes.price, 'f', 2))
                         .arg(shoes.gender)
                         .arg(shoes.inStock ? "в наличии" : "не в наличии")
                         .arg(Shoes::getMaterialsString())
                         .arg(Shoes::getSizesString());

    return result;
}

void MainWindow::slot1()
{
    ui->textEdit->clear();
    Shoes shoes1 = {5, 150.0, 'm', true};
    Shoes shoes2;
    shoes2.amount = 3;
    shoes2.price = 200.0;
    shoes2.gender = 'f';
    shoes2.inStock = false;
    QString output1 = printShoes(shoes1);
    QString output2 = printShoes(shoes2);

    ui->textEdit->setText(output1 + "\n" + output2);
}

void MainWindow::slot2()
{
    ui->textEdit->clear();
    QString textAmount = ui->lineEditAmount->text();
    QString textPrice = ui->lineEditPrice->text();
    QString textGender = ui->lineEditGender->text();
    QString textInStock = ui->lineEditInStock->text();
    if (textAmount.isEmpty()|| textPrice.isEmpty()||textGender.isEmpty()||textInStock.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        return;
    }
    Shoes shoes3;
    bool ok;
    shoes3.amount = textAmount.toInt(&ok);
    shoes3.price = textPrice.toDouble(&ok);
    if (!textGender.isEmpty()) {
        shoes3.gender = textGender.at(0).toLatin1();
    } else {
       QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        return;
    }
    if (textInStock.toLower() == "yes" || textInStock == "1") {
        shoes3.inStock = true;
    } else if (textInStock.toLower() == "no" || textInStock == "0") {
        shoes3.inStock = false;
    } else {
       QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        return;
    }
   if(shoes3.gender!='f' && shoes3.gender!='m'){
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        return;
    }
    if (ok) {
        QString output = printShoes(shoes3);
        ui->textEdit->setText(output);

    } else {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
        return;
    }

}

void MainWindow::slot3()
{
    Shoes shoes;
    Shoes* pshoes = &shoes;
    pshoes->amount = 10;
    pshoes->price = 49.99;
    pshoes->gender = 'm';
    pshoes->inStock = false;
    QString result = QString("%1 | %2 | %3 | %4 | %5 | %6")
                         .arg(pshoes->amount)
                         .arg(pshoes->price)
                         .arg(pshoes->gender)
                         .arg(pshoes->inStock ? "в наличии" : "не в наличии")
                         .arg(Shoes::getMaterialsString())
                         .arg(Shoes::getSizesString());

    ui->textEdit->setText(result);
}

void MainWindow::slot4()
{
    Shoes shoe;
    Shoes& shoeRef = shoe;

    shoeRef.amount = 100;
    shoeRef.price = 999.99;
    shoeRef.gender = 'f';
    shoeRef.inStock = true;

    QString result = QString("%1 | %2 | %3 | %4 | %5 | %6")
                           .arg(shoeRef.amount)
                           .arg(shoeRef.price)
                           .arg(shoeRef.gender)
                           .arg(shoeRef.inStock ? "в наличии" : "не в наличии")
                           .arg(Shoes::getMaterialsString())
                           .arg(Shoes::getSizesString());
    ui->textEdit->setText(result);

}

