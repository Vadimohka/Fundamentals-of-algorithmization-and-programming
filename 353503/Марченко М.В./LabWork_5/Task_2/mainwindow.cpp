#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mystring = new MyString();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mystring;
}

void MainWindow::on_bnt_memcpy_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* str1 = new char[n + 1];
    mystring->memcpy(str1, byteArray1.constData(), n + 1);
    str1[n] = '\0';
    ui->result->setText(str1);
    delete[] str1;
}


void MainWindow::on_bnt_memmove_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    char* str1 = new char[byteArray1.size() + 1];
    mystring->memmove(str1, byteArray1.constData(), byteArray1.size());
    str1[byteArray1.size()] = '\0';
    ui->result->setText(str1);
    delete[] str1;

}


void MainWindow::on_bnt_strcpy_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    char* src = new char[byteArray.size() + 1];
    mystring->memcpy(src, byteArray.constData(), byteArray.size());
    src[byteArray.size()] = '\0';

    char dest[100];
    mystring->strcpy(dest, src);
    ui->result->setText(dest);

    delete[] src;
}


void MainWindow::on_bnt_strncpy_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    char* src = new char[byteArray.size() + 1];
    mystring->memcpy(src, byteArray.constData(), byteArray.size());
    src[byteArray.size()] = '\0';

    size_t n = ui->spb_N->value();
    char dest[n + 1];
    mystring->strncpy(dest, src, n);
    dest[n] = '\0';
    ui->result->setText(dest);

    delete[] src;
}


void MainWindow::on_bnt_strcat_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    char* str = new char[byteArray1.size() + byteArray2.size() + 1];
    mystring->memcpy(str, byteArray1.constData(), byteArray1.size());

    str[byteArray1.size()] = '\0';

    mystring->strcat(str, byteArray2.constData());

    ui->result->setText(str);

    delete[] str;
}


void MainWindow::on_bnt_memset_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        return;
    }
    char value = ui->ln_str2->text().toUtf8().at(0);

    size_t n = ui->spb_N->value();

    char* str = new char[byteArray.size() + 1];

    mystring->memcpy(str, byteArray.constData(), byteArray.size());

    mystring->memset(str + byteArray.size(), value, n);

    str[byteArray.size() + n] = '\0';

    ui->result->setText(str);

    delete[] str;
}


void MainWindow::on_bnt_strtok_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        return;
    }
    char delimiter = ui->ln_str2->text().toUtf8().at(0);
    char* str = byteArray.data();
    char* token = strtok(str, &delimiter);

    QString result;
    while (token != nullptr) {
        result.append(token).append("===");
        token = strtok(nullptr, &delimiter);
    }

    ui->result->setText(result);
}


void MainWindow::on_bnt_strcoll_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    int result = mystring->strcoll(byteArray1.constData(), byteArray2.constData());

    if (result == 0) {
       ui->result->setText("Строки равны");
    } else if (result < 0) {
        ui->result->setText("Первая строка меньше второй");
    } else {
         ui->result->setText("Первая строка больше второй");
    }
}


void MainWindow::on_bnt_strxfrm_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* dest = new char[n + 1];

    size_t result = mystring->strxfrm(dest, byteArray.constData(), n);
    if (result < n) {
        ui->result->setText(dest);
    } else {
        ui->result->setText("Строка не умещается в заданный буфер");
    }

    delete[] dest;
}


void MainWindow::on_bnt_strlen_clicked()
{
    ui->result->clear();
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t length = mystring->strlen(byteArray.constData());
    ui->result->setText(QString::number(length));
}


void MainWindow::on_bnt_strcmp_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    int result = mystring->strcmp(byteArray1.constData(), byteArray2.constData());
    if (result == 0) {
        ui->result->setText("Строки равны");
    } else if (result < 0) {
        ui->result->setText("Первая строка меньше второй");
    } else {
        ui->result->setText("Первая строка больше второй");
    }
}


void MainWindow::on_bnt_strncmp_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = mystring->strncmp(byteArray1.constData(), byteArray2.constData(), n);
    if (result == 0) {
       ui->result->setText("Первые " + QString::number(n) + " символов равны");
    } else if (result < 0) {
        ui->result->setText("Первые " + QString::number(n) + " символов первой строки меньше второй");
    } else {
        ui->result->setText("Первые " + QString::number(n) + " символов первой строки больше второй");
    }
}


void MainWindow::on_bnt_memcmp_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = mystring->memcmp(byteArray1.constData(), byteArray2.constData(), n);
    if (result == 0) {
        ui->result->setText("Первые " + QString::number(n) + " байт равны");
    } else if (result < 0) {
        ui->result->setText("Первые " + QString::number(n) + " байт первой строки меньше второй");
    } else {
        ui->result->setText("Первые " + QString::number(n) + " байт первой строки больше второй");
    }
}


void MainWindow::on_bnt_strncat_clicked()
{
    ui->result->clear();
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* str = new char[byteArray1.size() + n + 1];
    mystring->strncpy(str, byteArray1.constData(), byteArray1.size());
    mystring->strncat(str, byteArray2.constData(), n);
    str[byteArray1.size() + n] = '\0';
    ui->result->setText(str);
    delete[] str;
}

