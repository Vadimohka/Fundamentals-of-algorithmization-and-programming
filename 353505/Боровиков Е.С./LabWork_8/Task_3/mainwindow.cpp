#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_pushButton_s_add_clicked()
{
    set.add(ui->spinBox->value());
    display();
}


void MainWindow::on_pushButton_s_check_clicked()
{
    ui->textEdit->setPlainText(set.contains(ui->spinBox->value()) ? "Yes" : "No");
    display();
}


void MainWindow::on_pushButton_s_clear_clicked()
{
    set.clear();
    display();
}


void MainWindow::on_pushButton_s_remove_clicked()
{
    set.remove(ui->spinBox->value());
    display();
}


void MainWindow::on_pushButton_m_add_clicked()
{
    map.add(ui->spinBox->value(), ui->spinBox_val->value());
    display();
}


void MainWindow::on_pushButton_m_check_clicked()
{
    ui->textEdit->setPlainText(map.contains(ui->spinBox->value()) ? "Yes" : "No");
    display();
}


void MainWindow::on_pushButton_m_get_clicked()
{
    ui->textEdit->setPlainText(QString::number(map.get(ui->spinBox->value())));
    display();
}


void MainWindow::on_pushButton_m_clear_clicked()
{
    map.clear();
    display();
}


void MainWindow::on_pushButton_m_remove_clicked()
{
    map.remove(ui->spinBox->value());
    display();
}


void MainWindow::on_pushButton_m_set_clicked()
{
    map[ui->spinBox->value()] = ui->spinBox_val->value();
    display();
}

void MainWindow::display()
{
    QString str;
    str += "Tree Iterator:\n";
    auto treeIter_set = set.GetIterator();
    while (treeIter_set.current) {
        str += QString::number(treeIter_set.Key()) + " ";
        treeIter_set.Next();
    }

    str += "\nList Iterator:\n";
    auto listIter_set = set.GetListIterator();
    while (listIter_set.current) {
        str += QString::number(listIter_set.Key()) + " ";
        listIter_set.Next();
    }
    ui->textEdit_set->setText(str);
    str.clear();


    str += "Tree Iterator:\n";
    auto treeIter_map = map.GetIterator();
    while (treeIter_map.current) {
        str += "(" + QString::number(treeIter_map.Key()) + ", " + QString::number(treeIter_map.current->value()) + ") ";
        treeIter_map.Next();
    }

    str += "\nList Iterator:\n";
    auto listIter_map = map.GetListIterator();
    while (listIter_map.current) {
        str += "(" + QString::number(listIter_map.Key()) + ", " + QString::number(listIter_map.Value()) + ") ";
        listIter_map.Next();
    }
    ui->textEdit_map->setText(str);
}

