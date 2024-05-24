#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    str = new MyCString();


    connect(ui->pushButton_memcpy, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        size_t n = ui->spb_N->value();
        char* str1 = new char[n + 1];
        str->memcpy(str1, byteArray1.constData(), n + 1);
        str1[n] = '\0';
        ui->ln_ans->setText(str1);
        delete[] str1;

    });

    connect(ui->pushButton_memmove, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        char* str1 = new char[byteArray1.size() + 1];
        str->memmove(str1, byteArray1.constData(), byteArray1.size());
        str1[byteArray1.size()] = '\0';
        ui->ln_ans->setText(str1);
        delete[] str1;

    });

    connect(ui->pushButton_memcmp, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        size_t n = ui->spb_N->value();
        int result = str->memcmp(byteArray1.constData(), byteArray2.constData(), n);
        QString message;
        if (result == 0)
        {
            message = "Первые " + QString::number(n) + " байт равны";
        }
        else if (result < 0)
        {
            message = "Первые " + QString::number(n) + " байт первой строки меньше второй";
        } else
        {
            message = "Первые " + QString::number(n) + " байт первой строки больше второй";
        }
    });

    connect(ui->pushButton_strncat, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        size_t n = ui->spb_N->value();
        char* arr = new char[byteArray1.size() + n + 1];
        str->strncpy(arr, byteArray1.constData(), byteArray1.size());
        str->strncat(arr, byteArray2.constData(), n);
        arr[byteArray1.size() + n] = '\0';
        ui->ln_ans->setText(arr);
        delete[] str;
    });

    connect(ui->pushButton_strncmp, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        size_t n = ui->spb_N->value();
        int result = str->strncmp(byteArray1.constData(), byteArray2.constData(), n);
        QString message;
        if (result == 0)
        {
            message = "Первые " + QString::number(n) + " символов равны";
        }
        else if (result < 0)
        {
            message = "Первые " + QString::number(n) + " символов первой строки меньше второй";
        }
        else
        {
            message = "Первые " + QString::number(n) + " символов первой строки больше второй";
        }
        ui->ln_ans->setText(message);
    });

    connect(ui->pushButton_strcoll, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        int result = str->strcoll(byteArray1.constData(), byteArray2.constData());
        QString message;
        if (result == 0)
        {
            ui->ln_ans->setText("Строки равны");
        }
        else if (result < 0)
        {
            ui->ln_ans->setText("Первая строка меньше второй");
        }
        else
        {
            ui->ln_ans->setText("Первая строка больше второй");
        }
    });

    connect(ui->pushButton_strtok, &QPushButton::clicked, this, [this](){
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

        ui->ln_ans->setText(result);
    });

    connect(ui->pushButton_memset, &QPushButton::clicked, this, [this](){

        QByteArray byteArray = ui->ln_str1->text().toUtf8();
        if (ui->ln_str2->text().isEmpty() || ui->ln_str1->text().isEmpty())
        {
            return;
        }
        char value = ui->ln_str2->text().toUtf8().at(0);
        size_t n = ui->spb_N->value();
        char* arr = new char[byteArray.size() + 1];
        str->memcpy(arr, byteArray.constData(), byteArray.size());
        str->memset(arr + byteArray.size(), value, n);
        arr[byteArray.size() + n] = '\0';
        ui->ln_ans->setText(arr);
        delete[] str;
    });

    connect(ui->pushButton_strcat, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        char* arr = new char[byteArray1.size() + byteArray2.size() + 1];
        str->memcpy(str, byteArray1.constData(), byteArray1.size());
        arr[byteArray1.size()] = '\0';
        str->strcat(arr, byteArray2.constData());
        ui->ln_ans->setText(arr);
        delete[] str;

    });

    connect(ui->pushButton_strncpy, &QPushButton::clicked, this, [this](){
        QByteArray byteArray = ui->ln_str1->text().toUtf8();
        char* src = new char[byteArray.size() + 1];
        str->memcpy(src, byteArray.constData(), byteArray.size());
        src[byteArray.size()] = '\0';
        size_t n = ui->spb_N->value();
        char dest[n + 1];
        str->strncpy(dest, src, n);
        dest[n] = '\0';
        ui->ln_ans->setText(dest);
        delete[] src;
    });

    connect(ui->pushButton_strcpy, &QPushButton::clicked, this, [this](){
        QByteArray byteArray = ui->ln_str1->text().toUtf8();
        char* src = new char[byteArray.size() + 1];
        str->memcpy(src, byteArray.constData(), byteArray.size());
        src[byteArray.size()] = '\0';
        char dest[100];
        str->strcpy(dest, src);
        ui->ln_ans->setText(dest);
        delete[] src;
    });

    connect(ui->pushButton_strxfrm, &QPushButton::clicked, this, [this](){
        QByteArray byteArray = ui->ln_str1->text().toUtf8();
        size_t n = ui->spb_N->value();
        char* dest = new char[n + 1];

        size_t result = str->strxfrm(dest, byteArray.constData(), n);
        if (result < n) {
            ui->ln_ans->setText(dest);
        } else {
            ui->ln_ans->setText("Строка не умещается в заданный буфер");
        }

        delete[] dest;
    });

    connect(ui->pushButton_strcmp, &QPushButton::clicked, this, [this](){
        QByteArray byteArray1 = ui->ln_str1->text().toUtf8();
        QByteArray byteArray2 = ui->ln_str2->text().toUtf8();
        int result = str->strcmp(byteArray1.constData(), byteArray2.constData());
        QString message;
        if (result == 0)
        {
            message = "Строки равны";
        }
        else if (result < 0)
        {
            message = "Первая строка меньше второй";
        }
        else
        {
            message = "Первая строка больше второй";
        }
        ui->ln_ans->setText(message);
    });

    connect(ui->pushButton_strlen, &QPushButton::clicked, this, [this](){
        QByteArray byteArray = ui->ln_str1->text().toUtf8();
        size_t length = str->strlen(byteArray.constData());
        ui->ln_ans->setText("Длина строки: " + QString::number(length));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete str;
}
