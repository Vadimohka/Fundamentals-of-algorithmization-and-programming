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

void MainWindow::on_bnt_memcpy_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* str1 = new char[n + 1];
    cstring->memcpy(str1, byteArray1.constData(), n + 1);
    str1[n] = '\0';
    ui->ln_ans->setText(str1);
    delete[] str1;
    QMessageBox::information(nullptr, "Результат", QString("С помощью метода memcpy n символов было скопировано из String1 в QLineEdit"));
}


void MainWindow::on_bnt_memmove_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    char* str1 = new char[byteArray1.size() + 1];
    cstring->memmove(str1, byteArray1.constData(), byteArray1.size());
    str1[byteArray1.size()] = '\0';
    ui->ln_ans->setText(str1);
    delete[] str1;
    QMessageBox::information(nullptr, "Результат", QString("С помощью метода memmove данные были перемещены из String1 в QLineEdit"));
}


void MainWindow::on_bnt_strcpy_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    char* src = new char[byteArray.size() + 1];
    cstring->memcpy(src, byteArray.constData(), byteArray.size());
    src[byteArray.size()] = '\0';

    char dest[100];
    cstring->strcpy(dest, src);
    ui->ln_ans->setText(dest);

    delete[] src;
    QMessageBox::information(nullptr, "Результат", QString("С помощью метода strcpy данные были перемещены из String1 в QLineEdit"));
}


void MainWindow::on_bnt_strncpy_clicked()
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
    QMessageBox::information(nullptr, "Результат", QString("С помощью метода strncpy n символов было скопировано из String1 в QLineEdit"));
}


void MainWindow::on_bnt_strcat_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    char* str = new char[byteArray1.size() + byteArray2.size() + 1];
    cstring->memcpy(str, byteArray1.constData(), byteArray1.size());

    str[byteArray1.size()] = '\0';

    cstring->strcat(str, byteArray2.constData());

    ui->ln_ans->setText(str);

    delete[] str;

    QMessageBox::information(nullptr, "Результат", QString("Строки были успешно объединены"));
}


void MainWindow::on_bnt_memset_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Результат", QString("Заполните поля String!!!"));
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

    QMessageBox::information(nullptr, "Результат", QString("Строка была успешно заполнена первым символом String 2"));
}


void MainWindow::on_bnt_strtok_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Результат", QString("Заполните поля String!!!"));
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

    ui->ln_ans->setText(result);

    QMessageBox::information(nullptr, "Результат", QString("Строка была успешно разбита на токены"));
}


void MainWindow::on_bnt_strcoll_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();

    int result = cstring->strcoll(byteArray1.constData(), byteArray2.constData());


    QString message;
    if (result == 0) {
        message = "Строки равны";
    } else if (result < 0) {
        message = "Первая строка меньше второй";
    } else {
        message = "Первая строка больше второй";
    }


    QMessageBox::information(nullptr, "Результат", message);
}


void MainWindow::on_bnt_strxfrm_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t n = ui->spb_N->value();
    char* dest = new char[n + 1];

    size_t result = cstring->strxfrm(dest, byteArray.constData(), n);
    if (result < n) {
        ui->ln_ans->setText(dest);
    } else {
        ui->ln_ans->setText("Строка не умещается в заданный буфер");
    }

    delete[] dest;

    QMessageBox::information(nullptr, "Результат", QString("Строка была успешно преобразована"));
}


void MainWindow::on_bnt_strlen_clicked()
{
    QByteArray byteArray = ui->ln_str1->text().toUtf8();
    size_t length = cstring->strlen(byteArray.constData());
    ui->ln_ans->setText(QString::number(length));
    QMessageBox::information(nullptr, "Результат", QString("Длина строки: %1").arg(length));
}


void MainWindow::on_bnt_strcmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    int result = cstring->strcmp(byteArray1.constData(), byteArray2.constData());
    QString message;
    if (result == 0) {
        message = "Строки равны";
    } else if (result < 0) {
        message = "Первая строка меньше второй";
    } else {
        message = "Первая строка больше второй";
    }
    QMessageBox::information(nullptr, "Результат", message);
}


void MainWindow::on_bnt_strncmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = cstring->strncmp(byteArray1.constData(), byteArray2.constData(), n);
    QString message;
    if (result == 0) {
        message = "Первые " + QString::number(n) + " символов равны";
    } else if (result < 0) {
        message = "Первые " + QString::number(n) + " символов первой строки меньше второй";
    } else {
        message = "Первые " + QString::number(n) + " символов первой строки больше второй";
    }
    QMessageBox::information(nullptr, "Результат", message);
}


void MainWindow::on_bnt_memcmp_clicked()
{
    QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
    QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
    size_t n = ui->spb_N->value();
    int result = cstring->memcmp(byteArray1.constData(), byteArray2.constData(), n);
    QString message;
    if (result == 0) {
        message = "Первые " + QString::number(n) + " байт равны";
    } else if (result < 0) {
        message = "Первые " + QString::number(n) + " байт первой строки меньше второй";
    } else {
        message = "Первые " + QString::number(n) + " байт первой строки больше второй";
    }
    QMessageBox::information(nullptr, "Результат", message);
}


void MainWindow::on_bnt_strncat_clicked()
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
    QMessageBox::information(nullptr, "Результат", QString("Строки были успешно объединены"));
}
