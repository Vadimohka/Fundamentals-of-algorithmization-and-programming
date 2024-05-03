#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string = *(new myString("a"));
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pe_clicked()
{
    string += *new myString(ui->lineEdit_pe->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}




void MainWindow::on_pushButton_equal_clicked()
{
    string = *new myString(ui->lineEdit_equal->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}


// void MainWindow::on_pushButton_pee_clicked()
// {
//     ui->label_eq->clear();
//     ui->label_less->clear();
//     ui->label_more->clear();
//     ui->label_eq->setText(string == *(new myString(ui->lineEdit_equal->text().toUtf8().constData())) ? "true" : "false");
// }





void MainWindow::on_pushButton_memcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myMemcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_memmove_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myMemmove(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_strcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrncpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strcat_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrcat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncat_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrncat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_memcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myMemcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strcoll_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrcoll(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strncmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrncmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_strxfrm_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrxfrm(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strtok_clicked()
{
    ui->lineEdit_ans->setText((char*)((myString::myStrtok(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strmemset_clicked()
{
    ui->lineEdit_ans->setText((char*)myString::myMemset(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().front().toLatin1(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strlen_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrlen(ui->lineEdit_str1->text().toUtf8().data()))));
}

