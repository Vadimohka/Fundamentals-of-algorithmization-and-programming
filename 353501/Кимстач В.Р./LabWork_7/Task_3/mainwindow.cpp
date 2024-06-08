

#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(add_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(find_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(delete_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(do_task()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(show_table()));

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::add_clicked() {
    auto t = stoi(ui->plainTextEdit->toPlainText().toStdString());
    my_hash.InsertValue(t);
    ui->plainTextEdit->clear();
}

void mainwindow::delete_clicked() {
    auto t = stoi(ui->plainTextEdit->toPlainText().toStdString());
    bool del = my_hash.RemoveValue(t);
    if(del)
    {
        ui->plainTextEdit->setPlainText("Успешно удалено.");
    }
    else
    {
        ui->plainTextEdit->setPlainText("Элемент не найден");
    }
}

void mainwindow::find_clicked() {
    auto t = stoi(ui->plainTextEdit->toPlainText().toStdString());
    bool del = my_hash.FindValue(t);
    if(del)
    {
        ui->plainTextEdit->setPlainText("Элемент найден.");
    }
    else
    {
        ui->plainTextEdit->setPlainText("Элемент не найден");
    }
}

void mainwindow::do_task() {
    int t = my_hash.FindMaxStack();
    ui->plainTextEdit_2->setPlainText("Номер стека с максимальным ключом " + QString::number(t));
}

void mainwindow::show_table() {
    auto t = my_hash.GetHashTable();
    ui->plainTextEdit_2->clear();
    for(auto x : t)
    {
        ui->plainTextEdit_2->appendPlainText(QString::number(x.first) + ": " + QString::fromStdString(x.second));
    }

}
