#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cstring = new CString();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cstring;
}

void MainWindow::on_btn_memcpy_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* str1 = new char[n + 1];
    cstring->memcpy(str1, byteArray1.constData(), n + 1);
    str1[n] = '\0';
    ui->ln_ans->setText(str1);
    delete[] str1;
    ui->lineEdit_2->setText("Using memcpy method, n characters were copied from String1 to QLineEdit");
}


void MainWindow::on_btn_memmove_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    char* str1 = new char[byteArray1.size() + 1];
    cstring->memmove(str1, byteArray1.constData(), byteArray1.size());
    str1[byteArray1.size()] = '\0';
    ui->ln_ans->setText(str1);
    delete[] str1;
    ui->lineEdit_2->setText("Using memmove method, data was moved from String1 to QLineEdit");
}


void MainWindow::on_btn_strcpy_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    char* src = new char[byteArray.size() + 1];
    cstring->memcpy(src, byteArray.constData(), byteArray.size());
    src[byteArray.size()] = '\0';
    char dest[250];
    cstring->strcpy(dest, src);
    ui->ln_ans->setText(dest);

    delete[] src;
    ui->lineEdit_2->setText("Using strcpy method, data was copied from String1 to QLineEdit");
}


void MainWindow::on_btn_strncpy_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    char* src = new char[byteArray.size() + 1];
    cstring->memcpy(src, byteArray.constData(), byteArray.size());
    src[byteArray.size()] = '\0';

    size_t n = ui->spb_N->value();
    char dest[n + 1];
    cstring->strncpy(dest, src, n);
    dest[n] = '\0';
    ui->ln_ans->setText(dest);
    delete[] src;
    ui->lineEdit_2->setText("Using strncpy method, n characters were copied from String1 to QLineEdit");
}

void MainWindow::on_btn_strcat_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    char* str = new char[byteArray1.size() + byteArray2.size() + 1];
    cstring->memcpy(str, byteArray1.constData(), byteArray1.size());
    str[byteArray1.size()] = '\0';
    cstring->strcat(str, byteArray2.constData());
    ui->ln_ans->setText(str);
    delete[] str;
    ui->lineEdit_2->setText("Strings were successfully concatenated");
}

void MainWindow::on_btn_memset_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        ui->lineEdit_2->setText("Fill in the String fields");
        return;
    }
    char value = ui->ln_str2->text().toUtf8().at(0);
    size_t n = ui->spb_N->value();
    char* str = new char[byteArray.size() + 1];
    cstring->memcpy(str, byteArray.constData(), byteArray.size());
    cstring->memset(str + byteArray.size(), value, n);
    str[byteArray.size() + n] = '\0';
    ui->ln_ans->setText(str);
    delete[] str;
    ui->lineEdit_2->setText("String was successfully filled with the first character of String2");
}

void MainWindow::on_btn_strtok_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        ui->lineEdit_2->setText("Fill in the String fields");
        return;
    }
    char firstCh = ui->ln_str2->text().toUtf8().at(0);
    char* str = byteArray.data();
    char* token = strtok(str, &firstCh);

    QString result;
    while (token != nullptr) {
        result.append(token);
        result.append(" <-> ");
        token = strtok(nullptr, &firstCh);
    }

    ui->ln_ans->setText(result);

    ui->lineEdit_2->setText(QString((QString)"String was successfully divided (token = " +  (QString)firstCh + (QString)")"));
}

// Compares the C string str1 to the C string str2, both interpreted appropriately according
// to the LC_COLLATE category of the C locale currently selected.
void MainWindow::on_btn_strcoll_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    int result = cstring->strcoll(byteArray1.constData(), byteArray2.constData());


    QString message;
    if (result == 0) {
        message = "Strings are equal";
    } else if (result < 0) {
        message = "The first string is less than the second";
    } else {
        message = "The first string is greater than the second";
    }

    ui->lineEdit_2->setText(message);
}

void MainWindow::on_btn_strxfrm_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* dest = new char[n + 1];
    size_t result = cstring->strxfrm(dest, byteArray.constData(), n);
    if (result < n) {
        ui->ln_ans->setText(dest);
    } else {
        ui->ln_ans->setText("String is smaller than buffer");
    }
    delete[] dest;
    ui->lineEdit_2->setText("String converted successfully");
}

void MainWindow::on_btn_strlen_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t length = cstring->strlen(byteArray.constData());
    ui->ln_ans->setText(QString::number(length));
    ui->lineEdit_2->setText("Length = " + QString::number(length));
}

void MainWindow::on_btn_strcmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    int result = cstring->strcmp(byteArray1.constData(), byteArray2.constData());
    QString message;
    if (result == 0) {
        message = "Equal";
    } else if (result < 0) {
        message = "l1.size() < l2.size()";
    } else {
        message = "l1.size() > l2.size()";
    }
    ui->lineEdit_2->setText(message);
}


void MainWindow::on_btn_strncmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = cstring->strncmp(byteArray1.constData(), byteArray2.constData(), n);
    QString message;
    if (result == 0) {
        message = "The first " + QString::number(n) + " characters are equal";
    }else if (result < 0) {
        message = "The first " + QString::number(n) + " characters of the first string are less than the second";
    } else {
        message = "The first " + QString::number(n) + " characters of the first string are greater than the second";
    }
    ui->lineEdit_2->setText(message);
}


void MainWindow::on_btn_memcmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = cstring->memcmp(byteArray1.constData(), byteArray2.constData(), n);
    QString message;
    if (result == 0) {
        message = "The first " + QString::number(n) + " bytes are equal";
    } else if (result < 0) {
        message = "The first " + QString::number(n) + " bytes of the first string are less than the second";
    } else {
        message = "The first " + QString::number(n) + " bytes of the first string are greater than the second";
    }
    ui->lineEdit_2->setText(message);
}


void MainWindow::on_btn_strncat_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* str = new char[byteArray1.size() + n + 1];
    cstring->strncpy(str, byteArray1.constData(), byteArray1.size());
    cstring->strncat(str, byteArray2.constData(), n);
    str[byteArray1.size() + n] = '\0';
    ui->ln_ans->setText(str);
    delete[] str;
    ui->lineEdit_2->setText("Strings were successfully concatenated");
}
