#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    std::string str = text.toStdString();
    const char *start = str.c_str();
    char *end;
    long double value = strtold(start, &end);

    if (*end != '\0')
    {
        ui->label_binary->setText("Enter valid number!");
    }
    else if (str.empty())
    {
        ui->label_binary->setText("");
    }
    else
    {
        ui->label_binary->setText(Binary::ToBin(value));
    }
}
