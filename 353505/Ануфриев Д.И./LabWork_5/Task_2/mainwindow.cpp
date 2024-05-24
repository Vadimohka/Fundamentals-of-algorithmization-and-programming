#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string = *(new String("a"));
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pe_clicked()
{
    string += *new String(ui->lineEdit_pe->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}




void MainWindow::on_pushButton_equal_clicked()
{
    string = *new String(ui->lineEdit_equal->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}


// void MainWindow::on_pushButton_pee_clicked()
// {
//     ui->label_eq->clear();
//     ui->label_less->clear();
//     ui->label_more->clear();
//     ui->label_eq->setText(string == *(new String(ui->lineEdit_equal->text().toUtf8().constData())) ? "true" : "false");
// }





void MainWindow::on_pushButton_memcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Memcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_memmove_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Memmove(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_strcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Strcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncpy_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Strncpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strcat_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Strcat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncat_clicked()
{
    ui->lineEdit_ans->setText((char *)String::Strncat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_memcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Memcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Strcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strcoll_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Strcoll(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strncmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Strncmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_strxfrm_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Strxfrm(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strtok_clicked()
{
    ui->lineEdit_ans->setText((char*)((String::Strtok(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strmemset_clicked()
{
    ui->lineEdit_ans->setText((char*)String::Memset(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().front().toLatin1(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strlen_clicked()
{
    ui->lineEdit_ans->setText(QString::number((String::Strlen(ui->lineEdit_str1->text().toUtf8().data()))));
}

