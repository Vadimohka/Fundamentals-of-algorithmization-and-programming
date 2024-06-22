#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    runButton = new QPushButton("Transform", this);
    input = new QLineEdit(this);
    res = new QLabel("", this);
    ui->gridLayout->addWidget(input, 1, 0, 1, 2);
    ui->gridLayout->addWidget(runButton, 1, 2);
    ui->gridLayout->addWidget(res, 2, 0, 1, 3);
    connect(runButton, SIGNAL(clicked()), this, SLOT(getNum()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getNum()
{
    bool ok;
    int number10 = input->text().toInt(&ok);
    res->setText("");
    if (!ok)
    {
        res->setText("Invalid input!");
        return;
    }

    QString binaryResult = calculate(number10);
    res->setText(binaryResult);
}

QString MainWindow::calculate(int number10)
{
    if (number10 == 0)
        return "0";
    else
    {
        int remainder = number10 % 2;
        QString binary = calculate(number10 / 2);
        return binary.append(QString::number(remainder));
    }
}

