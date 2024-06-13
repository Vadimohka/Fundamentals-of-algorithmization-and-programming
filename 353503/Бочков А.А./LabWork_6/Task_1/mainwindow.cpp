#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::print()
{
    workers_age = "\nВозраста всех раюотников: ";
    for (int i = 0; i < MyFactory.workers_amount; i++) {
        workers_age += QString::number(MyFactory.workers_age[i]) + " ";
    }
    ui->textEdit->setText("Количество работников: " + QString::number(MyFactory.workers_amount)
                          + "\nИх зарплата: " + QString::number(MyFactory.salary)
                          + "\nЗаглавный символ предприятия: " + MyFactory.first_letter
                          + "\nПравда ли, что сейчас завод работает: "
                          + (MyFactory.work ? "Да" : "Нет")
                          + "\nНазвание предприятия: " + MyFactory.name + workers_age);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qDebug() << ui->pushButton->isEnabled();
    MyFactory = {5, 12.5, 'S', true, "The best", {11, 12, 13, 14, 15}};

    print();

    //qDebug() << ui->pushButton->isEnabled();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    switch (typeact) {
    case 0:
        MyFactory.first_letter = 'A';
        MyFactory.name = "second";
        MyFactory.salary = 0.2;
        MyFactory.work = false;
        MyFactory.workers_amount = 3;
        for (int i = 0; i < 3; i++) {
            MyFactory.workers_age[i] = i + 1;
        }
        print();
        typeact = 1;
        ui->lineEdit->setText("Введите количество работников");
        break;
    case 1:
        ptr->first_letter = 'A';
        ptr->name = "fourth";
        ptr->salary = 0.2;
        ptr->work = false;
        ptr->workers_amount = 3;
        for (int i = 0; i < 3; i++) {
            ptr->workers_age[i] = i + 1;
        }
        print();
        typeact = 2;
        break;
    default:
        ref.first_letter = 'B';
        ref.name = "fifth";
        ref.salary = 1.2;
        ref.work = true;
        ref.workers_amount = 4;
        for (int i = 0; i < 4; i++) {
            ref.workers_age[i] = 40 - i;
        }
        print();
        break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    switch (typeinput) {
    case 0:
        MyFactory.workers_amount = ui->lineEdit_2->text().toInt(&ok);
        if (!ok || MyFactory.workers_amount <= 0) {
            msgbox.setText("Неверный ввод");
            msgbox.exec();
        } else {
            typeinput = 1;
            ui->lineEdit->setText("Введите зарплату");
            ui->lineEdit_2->clear();
        }
        break;
    case 1:
        MyFactory.salary = ui->lineEdit_2->text().toDouble(&ok);
        if (!ok || MyFactory.workers_amount <= 0) {
            msgbox.setText("Неверный ввод");
            msgbox.exec();
        } else {
            typeinput = 2;
            ui->lineEdit->setText("Введите заглавный символ предприятия");
            ui->lineEdit_2->clear();
        }
        break;
    case 2:
        MyFactory.first_letter = ui->lineEdit_2->text()[0];
        if (ui->lineEdit_2->text().size() > 1) {
            msgbox.setText("Неверный ввод");
            msgbox.exec();
        } else {
            typeinput = 3;
            ui->lineEdit->setText("Введите, работает ли завод(да или нет)");
            ui->lineEdit_2->clear();
        }
        break;
    case 3:
        input = ui->lineEdit_2->text();
        if (input != "да" && input != "нет") {
            msgbox.setText("Неверный ввод");
            msgbox.exec();
        } else {
            if (input == "да") {
                MyFactory.work = true;
            } else {
                MyFactory.work = false;
            }
            typeinput = 4;
            ui->lineEdit->setText("Введите название завода");
            ui->lineEdit_2->clear();
        }
        break;
    case 4:
        MyFactory.name = ui->lineEdit_2->text();
        typeinput = 5;
        ui->lineEdit->setText("Введите возраст следующего работника");
        ui->lineEdit_2->clear();
        break;
    default:
        MyFactory.workers_age[typeinput - 5] = ui->lineEdit_2->text().toInt(&ok);
        if (!ok || MyFactory.workers_amount <= 0) {
            msgbox.setText("Неверный ввод");
            msgbox.exec();
        } else {
            typeinput++;
            if (typeinput - 5 == MyFactory.workers_amount) {
                ui->lineEdit->clear();
                print();
            }
            ui->lineEdit_2->clear();
        }
        break;
    }
}
