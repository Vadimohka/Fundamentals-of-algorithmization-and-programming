#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

enum Functions {
    MEMCPY,
    MEMMOVE,
    MEMSET,
    STRCPY,
    STRNCPY,
    STRCAT,
    STRNCAT,
    MEMCMP,
    STRCMP,
    STRCOLL,
    STRNCMP,
    STRXFRM,
    STRTOK,
    STRERROR,
    STRLEN
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    str1 = nullptr;
    str2 = nullptr;

    connect(ui->enter_btn, SIGNAL(clicked()), this, SLOT(setInfo()));
    connect(ui->chooseFunc_cmbbox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFunction(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete str1;
    delete str2;
}

void MainWindow::setInfo()
{
    if (str1 != nullptr) {
        delete str1;
    }
    if (str2 != nullptr) {
        delete str2;
    }

    std::string s1 = ui->first_lEdit->text().toStdString();
    std::string s2 = ui->second_lEdit->text().toStdString();

    if (s1.empty() || s2.empty()) {
        QMessageBox::warning(this, "Error", "Enter strings first!");
        return;
    }

    str1 = new myString(s1.c_str());
    str2 = new myString(s2.c_str());
}

void MainWindow::chooseFunction(int index)
{
    if (str1 == nullptr || str2 == nullptr) {
        QMessageBox::warning(this, "Error", "Enter strings first!");
        return;
    }

    switch (index) {
    case MEMCPY:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::memcpy(str1->begin(), str2->begin(), strlen(str2->begin()));

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case MEMMOVE:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::memmove(str1->begin(), str2->begin(), strlen(str2->begin()));

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case MEMSET:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));

        myString::memset(str1->begin(), 87, strlen(str1->begin()));

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case STRCPY:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::strcpy(str1->begin(), str2->begin());

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case STRNCPY:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::strncpy(str1->begin(), str2->begin(), strlen(str2->begin()));

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case STRCAT:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::strcat(str1->begin(), str2->begin());

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case STRNCAT:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        myString::strncat(str1->begin(), str2->begin(), strlen(str2->begin()));

        ui->Info_list->addItem("Result string:" + QString(str1->begin()) + "\n");
        break;
    case MEMCMP:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::memcmp(str1->begin(), str2->begin(), strlen(str2->begin()))) + "\n");
        break;
    case STRCMP:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::strcmp(str1->begin(), str2->begin())) + "\n");
        break;
    case STRCOLL:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::strcoll(str1->begin(), str2->begin())) + "\n");
        break;
    case STRNCMP:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::strncmp(str1->begin(), str2->begin(), strlen(str2->begin()))) + "\n");
        break;
    case STRXFRM:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::strxfrm(str1->begin(), str2->begin(), strlen(str2->begin()))) + "\n");
        break;
    case STRTOK: {
        const char* delim = QInputDialog::getText(this, "Enter delimiter", "Enter delimiter", QLineEdit::Normal, QDir::home().dirName()).toStdString().c_str();

        ui->Info_list->addItem("First string:" + QString(str1->begin()));
        ui->Info_list->addItem("Second string:" + QString(str2->begin()));

        ui->Info_list->addItem("Result:" + QString(myString::strtok(str1->begin(), delim)));
        break;
    }
    case STRERROR:
        ui->Info_list->addItem("Error number:" + QString::number(0));

        ui->Info_list->addItem("Result:" + QString(myString::strerror(0)) + "\n");
        break;
    case STRLEN:
        ui->Info_list->addItem("First string:" + QString(str1->begin()));

        ui->Info_list->addItem("Result:" + QString::number(myString::strlen(str1->begin())) + "\n");
        break;
    default:
        break;
    }
}
