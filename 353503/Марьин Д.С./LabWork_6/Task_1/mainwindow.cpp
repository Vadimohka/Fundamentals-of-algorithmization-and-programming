#include "mainwindow.h"
#include "toyinfodialog.h"
#include "ui_mainwindow.h"

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

void MainWindow::getInputForToy()
{
    bool ok;
    int age = QInputDialog::getInt(nullptr, "Set Toy", "Enter the age of the toy:", 1, 1, 100, 1, &ok);
    if (ok)
    {
        toy._age = age;
    }

    double price = QInputDialog::getDouble(nullptr, "Set Toy", "Enter the price of the toy:", 0, 0, 10000, 2, &ok);
    if (ok)
    {
        toy._price = price;
    }

    QString name = QInputDialog::getText(nullptr, "Set Toy", "Enter the name of the toy:", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        toy._name = name.toStdString();
    }

    QStringList items;
    items << "Yes" << "No";
    QString available = QInputDialog::getItem(nullptr, "Set Toy", "Is the toy for Children?", items, 0, false, &ok);
    if (ok)
    {
        toy._isForChildern = (available == "Yes");
    }
}

void MainWindow::outputInfo()
{
     qDebug() << toy._age << " | " << toy._price << " | " << toy._name << " | " << toy._isForChildern << "\n";
}

void MainWindow::on_pushButton_clicked()
{
    getInputForToy();
    outputInfo();
}

void MainWindow::on_pushButton_3_clicked()
{
     ToyInfoDialog dialog(toy);
     dialog.setFixedSize(200,150);
     dialog.exec();
}

