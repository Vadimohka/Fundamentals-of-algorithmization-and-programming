#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input3->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_set_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    std::string s1 = ui->input1->text().toStdString();
    std::string s2 = ui->input2->text().toStdString();
    str1 = new char[s1.size() - 1];
    str2 = new char[s2.size() - 1];
    std::strcpy(str1, s1.c_str());
    std::strcpy(str2, s2.c_str());
    n = ui->input3->text().toInt();
    ui->strcat->setEnabled(true);
    ui->strncmp->setEnabled(true);
    ui->strcpy->setEnabled(true);
    ui->memcpy->setEnabled(true);
    ui->memmove->setEnabled(true);
    ui->memcmp->setEnabled(true);
    ui->strncat->setEnabled(true);
    ui->strncpy->setEnabled(true);
    ui->strcmp->setEnabled(true);
}


void MainWindow::on_memcpy_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.strlen(s2) < n)
    {
        ui->output3->setText("Wrong n");
        return;
    }
    s.memcpy(s1, s2, n);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}


void MainWindow::on_memmove_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.strlen(s2) < n)
    {
        ui->output3->setText("Wrong n");
        return;
    }
    s.memmove(s1, s2, n);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}


void MainWindow::on_strcpy_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    s.strcpy(s1, s2);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}


void MainWindow::on_strncpy_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.strlen(s2) < n)
    {
        ui->output3->setText("Wrong n");
        return;
    }
    s.strncpy(s1, s2, n);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}


void MainWindow::on_memcmp_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.memcmp(s1, s2, n) == 0)
    {
        ui->output3->setText("Same");
    }
    if (s.memcmp(s1, s2, n) == 1)
    {
        ui->output3->setText(">");
    }
    else if (s.memcmp(s1, s2, n) == -1)
    {
        ui->output3->setText("<");
    }
    s.memcmp(s1, s2, n);
}


void MainWindow::on_strcmp_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    s.strcmp(s1, s2);
    if (s.strcmp(s1, s2) == 0)
    {
        ui->output3->setText("Same");
    }
    if (s.strcmp(s1, s2) == 1)
    {
        ui->output3->setText(">");
    }
    else if (s.strcmp(s1, s2) == -1)
    {
        ui->output3->setText("<");
    }
}


void MainWindow::on_strcat_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    s.strcat(s1, s2);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}


void MainWindow::on_strncmp_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.strncmp(s1, s2, n) == 0)
    {
        ui->output3->setText("Same");
    }
    if (s.strncmp(s1, s2, n) == 1)
    {
        ui->output3->setText(">");
    }
    else if (s.strncmp(s1, s2, n) == -1)
    {
        ui->output3->setText("<");
    }
}


void MainWindow::on_strncat_clicked()
{
    ui->output1->clear();
    ui->output2->clear();
    ui->output3->clear();
    char *s1 = new char[s.strlen(str1) - 1];
    char *s2 = new char[s.strlen(str2) - 1];
    std::strcpy(s1, str1);
    std::strcpy(s2, str2);
    if (s.strlen(s2) < n)
    {
        ui->output3->setText("Wrong n");
        return;
    }
    s.strncat(s1, s2, n);
    ui->output1->setText(s1);
    ui->output2->setText(s2);
}

